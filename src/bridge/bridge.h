
#pragma once

#include <QObject>
#include <QThread>
#include <QSerialPort>
#include <QSerialPortInfo>

#include "../models/serialModel.h"
#include "singleton.h"

class bridge : public QObject
{
    SINGLETON(bridge)
    Q_OBJECT

private:
    serialModel *m_serialModel;

    QThread *m_serialThread; /*处理串口模型相关的bride线程*/

    void initBridge();

public:

signals:
    void sg_openPort(QSerialPortInfo portInfo, int baudRate, QSerialPort::DataBits dataBits, QSerialPort::Parity parity, QSerialPort::StopBits stopBits); /*打开串口 信号*/
    void sg_done_model_openPort(bool isOpenSerialPortSuccess);
    void sg_showUI();

    /*Send to UI*/
    void sg_ui_openPortOK();
    void sg_ui_openPortFail();

public slots:
    /*串口线程*/
    void st_startSerialThread(QSerialPortInfo portInfo, int baudRate, QSerialPort::DataBits dataBits, QSerialPort::Parity parity, QSerialPort::StopBits stopBits);
    void st_quit_serialThread(bool isOpenSerialPortSuccess);
};
