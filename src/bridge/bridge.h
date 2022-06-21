
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

     /*处理串口模型相关的bride线程*/
    QThread *m_openPortThread;
    QThread *m_readPortDataThread;

    void initBridge();

public:

signals:
    /*openPort thread*/
    void sg_openPort(QSerialPortInfo portInfo, int baudRate, QSerialPort::DataBits dataBits, QSerialPort::Parity parity, QSerialPort::StopBits stopBits); /*打开串口 信号*/
    void sg_done_model_openPort(bool isOpenSerialPortSuccess);
    void sg_showUI();
    /*readData thread*/
    void sg_enable_PortDataListener();


    /*Send to UI*/
    void sg_ui_openPortOK();
    void sg_ui_openPortFail();

    void sg_ui_dataAppendToUI(char *data);



public slots:
    /*串口线程*/
    void st_on_openPortThread(QSerialPortInfo portInfo, int baudRate, QSerialPort::DataBits dataBits, QSerialPort::Parity parity, QSerialPort::StopBits stopBits);
    void st_off_openPortThread(bool isOpenSerialPortSuccess);

    void st_on_readDataThread();

};
