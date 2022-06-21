#ifndef APPDATA_H
#define APPDATA_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>


extern bool connected; /*串口连接状态*/
extern bool isReadyRead;
extern QSerialPort *serialPort;

#include "common.h"
extern common *m_common;



#endif // !APPDATA_H
