
#include "serialModel.h"
#include <singleton.h>

#include "../bridge/bridge.h"


bool connected; /*串口连接状态*/
QSerialPort *serialPort;

serialModel::serialModel()
{
}

serialModel::~serialModel()
{
}

/***
 * @description:  打开串口
 * @param {QSerialPortInfo} portInfo
 * @param {int} baudRate
 * @param {DataBits} dataBits
 * @param {Parity} parity
 * @param {StopBits} stopBits
 * @return {*}
 */
void serialModel::openPort(QSerialPortInfo portInfo, int baudRate, QSerialPort::DataBits dataBits, QSerialPort::Parity parity, QSerialPort::StopBits stopBits)
{
     qDebug() << "[Model] start model : openPort";

    serialPort = new QSerialPort(portInfo, nullptr);

    if (serialPort->open(QIODevice::ReadWrite))
    {
        serialPort->setBaudRate(baudRate);
        serialPort->setParity(parity);
        serialPort->setDataBits(dataBits);
        serialPort->setStopBits(stopBits);

        qDebug() << "[Model] done model : openPort : ok";
        emit Singleton<bridge>::getInstance().sg_done_model_openPort(true);
    }
    else
    {
        qDebug() << "[Model] done model : openPort : fali";
        emit Singleton<bridge>::getInstance().sg_done_model_openPort(false);
    }


}

void serialModel::st_openPort(QSerialPortInfo portInfo, int baudRate, QSerialPort::DataBits dataBits, QSerialPort::Parity parity, QSerialPort::StopBits stopBits)
{
    qDebug() << "[Model] st_openPort";
    openPort(portInfo, baudRate, dataBits, parity, stopBits);
}



