#include "../../mainwindow.h"

/*串口打开成功*/
void mainwindow::st_ui_openPortOK()
{
    qDebug() << "[UI] openPort : OK";
    ui->wPlotView->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->statusBar->showMessage("Connected!");
    connected = true;
    enable_or_disable_portControls(false);

    ui->editReceive->clear();
    ui->editReceive->setFontWeight(96);
    ui->editReceive->setText("---------------------" + serialPort->portName() + " : " +
                            QString::number(serialPort->baudRate()) + "---------------------");

    /*请求开启 串口数据监听*/
    qDebug() << "[UI] Request readPortData thread";
    emit Singleton<bridge>::getInstance().sg_enable_PortDataListener();

}
/*串口打开失败*/
void mainwindow::st_ui_openPortFail()
{
    qDebug() << "[UI] openPort : Fail";
    // qDebug() << "Port cannot be open signal received!";
    ui->statusBar->showMessage("Cannot open port!");
    enable_or_disable_portControls(true);
}

void mainwindow::st_ui_dataAppendToUI(char * data)
{
    ui->editReceive->append(data);
    
    #ifdef m_V_sBar_autoScroll
    m_V_sBar->setValue(m_V_sBar->maximum());
    #endif

}

/*串口关闭成功*/
void mainwindow::st_ui_closePorkOK()
{
    /*enable port controls*/
    enable_or_disable_portControls(true);
}

/*使能或禁用portControls*/
void mainwindow::enable_or_disable_portControls(bool enable)
{
    /* Com port properties */
    ui->comboBaud->setEnabled (enable);
    ui->comboData->setEnabled (enable);
    ui->comboParity->setEnabled (enable);
    ui->comboPort->setEnabled (enable);
    ui->comboStop->setEnabled (enable);

    /* Toolbar elements */
    m_ibn_Connect ->setEnabled (enable);
    m_ibn_DisConnect->setEnabled (!enable);
}












