
#include "bridge.h"

bridge::bridge() { initBridge(); }
bridge::~bridge(){};

void bridge::initBridge() 
{
  connect(this,
          SIGNAL(sg_openPort(QSerialPortInfo, int, QSerialPort::DataBits,
                             QSerialPort::Parity, QSerialPort::StopBits)),
          this,
          SLOT(st_bridge_openPort(QSerialPortInfo, int, QSerialPort::DataBits,
                                  QSerialPort::Parity, QSerialPort::StopBits)));

  connect(this, SIGNAL(sg_enable_PortDataListener()), this,
          SLOT(st_on_readDataThread()));

  connect(this, SIGNAL(sg_closePort()), this, SLOT(st_bridge_closePort()));

  /*完成关闭串口模型*/
  connect(this, &bridge::sg_done_model_closePort, this, [&]() {
    /*当线程完成(线程已经退出)-自动销毁线程对象*/
    connect(m_readPortDataThread, SIGNAL(finished()), m_readPortDataThread,
            SLOT(deleteLater()));

    /*退出数据接收线程*/
    m_readPortDataThread->quit();
    m_readPortDataThread->wait();

    /*销毁对象*/
    connected = false;
    delete serialPort;
    serialPort = nullptr;

    emit sg_ui_closePorkOK();
  });
}

/**********************************打开串口*************************************/
void bridge::st_bridge_openPort(QSerialPortInfo portInfo, int baudRate,
                                QSerialPort::DataBits dataBits,
                                QSerialPort::Parity parity,
                                QSerialPort::StopBits stopBits) {
  m_serialModel = new serialModel;
  connect(this, SIGNAL(sg_done_model_openPort(bool)), this,
          SLOT(st_bridge_returnOpenPortRes(bool)));

  qDebug() << "[Bridge] Call model : openPort...";
  m_serialModel->openPort(portInfo, baudRate, dataBits, parity, stopBits);
}

/******************************返回是否打开串口成功**************************/
void bridge::st_bridge_returnOpenPortRes(bool isOpenSerialPortSuccess) {
  if (isOpenSerialPortSuccess == true) {
    qDebug() << "[Bridge] Done Model : portOpenOK";
    qDebug() << "[Bridge] SerialPort Status : " +
                    QString::number(serialPort->isOpen());

    emit sg_ui_openPortOK();
  } else if (isOpenSerialPortSuccess == false) {
    qDebug() << "[Bridge] Done Model : portOpenFail";
    emit sg_ui_openPortFail();
  }
}

/****************************打开"读取串口数据"线程****************************/
void bridge::st_on_readDataThread() {

  /*-------------线程初始化----------------*/
  /*新建支线程*/
  m_readPortDataThread = new QThread;
  m_serialModel = new serialModel;
  m_serialModel->moveToThread(m_readPortDataThread);

  /*------------线程开启------------ -----*/
  qDebug() << "[Bridge] Start m_readPortDataT Thread...";
  m_readPortDataThread->start();

  /*当线程开启, 直接调用执行model层的槽函数*/
  if (!m_readPortDataThread->isRunning())
    return;

  qDebug() << "[Bridge] m_readPortDataThread is Running...";

  qDebug() << "[Bridge] Call model : readPortData...";

  /* 使能监听
  ** 每一次新数据来，readyRead就会触发一次，readPortData()函数触发一次；因此是readPortData()会不断被调用的
  ** 这里还是采用Lamda表达式直接调用model里的readPortData()函数。
  ** 保证了model全是供外面调用的接口函数，而不是槽函数
  **/
  connect(serialPort, &QSerialPort::readyRead, this, [&]() {
    isReadyRead = true;
    m_serialModel->readPortData();
  });
}

/**********************************Bridge-关闭串口**********************************/
void bridge::st_bridge_closePort() {
  if (!connected)
    return;
  /*调用Model层closePort接口函数*/
  m_serialModel->closePort();
}
