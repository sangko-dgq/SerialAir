#include "serialModel.h"

#include <singleton.h>
#include "../bridge/bridge.h"

bool connected;           /*串口连接状态*/
bool isReadyRead = false; /*数据监听开启*/
QSerialPort *serialPort;

serialModel::serialModel() {}
serialModel::~serialModel() {}

/*-------------------------------------------------------OpenPort---------------------------------------------------*/
/***
 * @description:  打开串口
 * @param {QSerialPortInfo} portInfo
 * @param {int} baudRate
 * @param {DataBits} dataBits
 * @param {Parity} parity
 * @param {StopBits} stopBits
 * @return {*}
 */
void serialModel::openPort(QSerialPortInfo portInfo, int baudRate,
                           QSerialPort::DataBits dataBits,
                           QSerialPort::Parity parity,
                           QSerialPort::StopBits stopBits) {
  qDebug() << "[Model] start model : openPort";

  serialPort = new QSerialPort(portInfo, nullptr);

  serialPort->setBaudRate(baudRate);
  serialPort->setParity(parity);
  serialPort->setDataBits(dataBits);
  serialPort->setStopBits(stopBits);

  if (serialPort->open(QIODevice::ReadWrite)) {
    //        serialPort->setBaudRate(baudRate);
    //        serialPort->setParity(parity);
    //        serialPort->setDataBits(dataBits);
    //        serialPort->setStopBits(stopBits);

    qDebug() << "[Model] done model : openPort : ok";
    emit Singleton<bridge>::getInstance().sg_done_model_openPort(true);
  } else {
    qDebug() << "[Model] done model : openPort : fali";
    emit Singleton<bridge>::getInstance().sg_done_model_openPort(false);
  }
}

/***
 * @description: 关闭串口
 * @return {*}
 */
void serialModel::closePort() {
  serialPort->close();

  if (!serialPort->isOpen()) //如果串口被关闭了
    emit Singleton<bridge>::getInstance().sg_done_model_closePort();
}

/*-------------------------------------------------------readData
 * Thread---------------------------------------------------*/
/*读取串口数据*/
void serialModel::readPortData() {
  qDebug() << "[Model] readyRead from : " + serialPort->portName() +
                  ": ready : " + QString::number(isReadyRead);
  qDebug() << QString::number(
      serialPort->bytesAvailable()); // bytesAvailable为收到的数据总量

  if (!serialPort->bytesAvailable())
    return;

  /*bytes is Available*/
  QByteArray arr_dataReceive = serialPort->readAll();
  if (arr_dataReceive.isEmpty())
    return;

  /*数组里有数据*/
  char *temp = arr_dataReceive.data(); // 得到一个'\0' 的终止char *数据

  /*发送UI操作*/
  emit Singleton<bridge>::getInstance().sg_ui_dataAppendToUI(temp);
}
