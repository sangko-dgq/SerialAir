

#include "serialModel.h"
#include <singleton.h>

#include "../bridge/bridge.h"

bool connected; /*串口连接状态*/
QSerialPort *serialPort;

serialModel::serialModel() {}

serialModel::~serialModel() {}

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

    qDebug() << "portInfo" + portInfo.portName();
    qDebug() << "baudRate" + QString::number(serialPort->baudRate());

    connect(serialPort, SIGNAL(readyRead()), this, SLOT(st_readPortData()));

    if (serialPort->open(
                QIODevice::ReadWrite)) /*PS：serialPort的readyRead信号被触发*/
    {
//        serialPort->setBaudRate(baudRate);
//        serialPort->setParity(parity);
//        serialPort->setDataBits(dataBits);
//        serialPort->setStopBits(stopBits);

        qDebug() << QString::number(serialPort ->bytesAvailable());

        qDebug() << "[Model] done model : openPort : ok";
        emit Singleton<bridge>::getInstance().sg_done_model_openPort(true);
    } else {
        qDebug() << "[Model] done model : openPort : fali";
        emit Singleton<bridge>::getInstance().sg_done_model_openPort(false);
    }
}

void serialModel::st_openPort(QSerialPortInfo portInfo, int baudRate,
                              QSerialPort::DataBits dataBits,
                              QSerialPort::Parity parity,
                              QSerialPort::StopBits stopBits) {
    qDebug() << "[Model] st_openPort";
    openPort(portInfo, baudRate, dataBits, parity, stopBits);
}

/*读取串口数据*/
void serialModel::st_readPortData()
{
    qDebug() << "[Model] readyRead from : " + serialPort->portName();
}
