

#include "bridge.h"

bridge::bridge()
{
    initBridge();
}

bridge::~bridge()
{
}

void bridge::initBridge()
{
    connect(this,
            SIGNAL(sg_openPort(QSerialPortInfo, int, QSerialPort::DataBits, QSerialPort::Parity, QSerialPort::StopBits)),
            this,
            SLOT(st_startSerialThread(QSerialPortInfo, int, QSerialPort::DataBits, QSerialPort::Parity, QSerialPort::StopBits)));

}

/*串口线程*/
void bridge::st_startSerialThread(QSerialPortInfo portInfo, int baudRate, QSerialPort::DataBits dataBits, QSerialPort::Parity parity, QSerialPort::StopBits stopBits)
{


   /*------------------------------------------线程初始化和Connect----------------------------------------*/
    /*新建支线程*/
    m_serialThread = new QThread;
    m_serialModel = new serialModel;
    m_serialModel->moveToThread(m_serialThread);

    /*模型层的测试槽函数执行完成,执行退出线程槽函数*/
    connect(this, SIGNAL(sg_done_model_openPort(bool)), this, SLOT(st_quit_serialThread(bool)));

    /*当线程完成(已经完成退出线程),*/
    /*当线程完成(线程已经退出)-自动销毁线程*/
    connect(m_serialThread, SIGNAL(finished()), m_serialThread, SLOT(deleteLater()));


     /*-----------------------------------------线程开启----------------------------------------*/
    qDebug() << "[Bridge] Start Serial Thread...";
    m_serialThread->start();

    /*当线程开启, 执行模型层的测试槽函数*/
    /*这里started信号参数和st_openPort不一致，不能绑定，需要再创建一个中间槽函数来实现*/
    /*
     * 中转方式-1
     * 线程started()信号触发model里的slot;
     * 注意：由于Strated无参数，基于Qt信号与槽绑定法则（信号参数个数 >= 槽参数个数）
     * 故该方式，仅仅适合无参数的槽函数
     *以下写法会报错
     */
    //    connect(m_serialThread,
    //            SIGNAL(started()),
    //            m_serialModel,
    //            SLOT(st_openPort(QSerialPortInfo, int, QSerialPort::DataBits, QSerialPort::Parity, QSerialPort::StopBits)));

    /*
     * 中转方式-2
     * 如果判断线程是否Running（线程start成功就Running），来直接调用model里的slot;
     * 适合无参数/有参数的槽函数
     */
    if (!m_serialThread->isRunning())
        return;

    qDebug() << "[Bridge] m_serialThread is Running...";

    qDebug() << "[Bridge] Call model : openPort...";
    m_serialModel->openPort(portInfo, baudRate, dataBits, parity, stopBits);

}

/*退出线程*/
void bridge::st_quit_serialThread(bool isOpenSerialPortSuccess)
{
    qDebug() << "[Bridge] Quit m_serialThread...";
    m_serialThread->quit();
    m_serialThread->wait();

    if(!m_serialThread->isFinished()) return;

    qDebug() << "[Bridge] m_serialThread is Finished...";

    m_serialThread->deleteLater();
    qDebug() << "[Bridge] m_serialThread is Deleted...";

    if(isOpenSerialPortSuccess == true)
    {
        qDebug() << "[Bridge] Done Model : portOpenOK";
        qDebug() << "[Bridge] SerialPort Status : " + QString::number(serialPort->isOpen());
    }
    else if(isOpenSerialPortSuccess == false)
    {
        qDebug() << "[Bridge] Done Model : portOpenFail";
    }

}


