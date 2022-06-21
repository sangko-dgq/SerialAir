
#include "../../mainwindow.h"


/*Button Trigger*/
/*当 刷新串口 按钮按下*/
void mainwindow::on_m_rBn_Refresh_triggered()
{
    initPortControlsUI();
}
/*当 打开串口连接 按钮按下*/
void mainwindow::on_ibn_Connect_triggered()
{
    /*已连接*/
    if (connected) /*防止连接成功后，再点击请求连接*/
    {
        m_ibn_Connect->setEnabled(false);
        return;
    }

    /*未连接*/
    /* Get parameters from controls first */
    QSerialPortInfo portInfo(ui->comboPort->currentText()); // Temporary object, needed to create QSerialPort
    int baudRate = ui->comboBaud->currentText().toInt();    // Get baud rate from combo box
    int dataBitsIndex = ui->comboData->currentIndex();      // Get index of data bits combo box
    int parityIndex = ui->comboParity->currentIndex();      // Get index of parity combo box
    int stopBitsIndex = ui->comboStop->currentIndex();      // Get index of stop bits combo box
    QSerialPort::DataBits dataBits;
    QSerialPort::Parity parity;
    QSerialPort::StopBits stopBits;

    /* Set data bits according to the selected index */
    switch (dataBitsIndex)
    {
    case 0:
        dataBits = QSerialPort::Data8;
        break;
    default:
        dataBits = QSerialPort::Data7;
    }

    /* Set parity according to the selected index */
    switch (parityIndex)
    {
    case 0:
        parity = QSerialPort::NoParity;
        break;
    case 1:
        parity = QSerialPort::OddParity;
        break;
    default:
        parity = QSerialPort::EvenParity;
    }

    /* Set stop bits according to the selected index */
    switch (stopBitsIndex)
    {
    case 0:
        stopBits = QSerialPort::OneStop;
        break;
    default:
        stopBits = QSerialPort::TwoStop;
    }

    /* 更新全局变量：serialPort */
    serialPort = new QSerialPort(portInfo, nullptr);

    /*UI取bride里的信号，发送到model*/
    qDebug() << "[UI] emit signal : openPort";
    qDebug() << "[UI] SerialPort Status : " + QString::number(serialPort->isOpen());
    emit Singleton<bridge>::getInstance().sg_openPort(portInfo, baudRate, dataBits, parity, stopBits);
}
/*当 关闭串口连接 按钮按下*/
void mainwindow::on_ibn_Disconnect_triggered()
{
    if (connected)
    {       
        emit Singleton<bridge>::getInstance().sg_closePort();                                                    

        ui->statusBar->showMessage ("Disconnected!");                                                       
        ui->actionConnect->setEnabled (true);
        

    }
}
