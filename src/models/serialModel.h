
#pragma once

#include <QObject>

#include "appconfig.h"
#include "appdata.h"

class serialModel : public QObject /*connect的sender和receiver两者对象均要public继承QObject对象, 而不允许private(默认)继承*/
{
    Q_OBJECT

public:
    serialModel();
    ~serialModel();

    /*打开串口*/
    void openPort(QSerialPortInfo portInfo, int baudRate, QSerialPort::DataBits dataBits, QSerialPort::Parity parity, QSerialPort::StopBits stopBits);

   
private:
signals:
    /*models - serialModel*/
    void sg_portOpenFail(); /*串口打开成功信号*/
    void sg_portOpenOK();   /*串口打开失败信号*/

    

public slots:
    /*SLOT_打开串口*/
    void st_openPort(QSerialPortInfo portInfo, int baudRate, QSerialPort::DataBits dataBits, QSerialPort::Parity parity, QSerialPort::StopBits stopBits);
    /*读取串口数据*/
   void st_readPortData();

};
