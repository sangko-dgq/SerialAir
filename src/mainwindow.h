#pragma once
#include "ui_mainwindow.h"
#include <QMainWindow>

#include <QTextEdit>
//@tag 2. 包含SerialPort库文件
#include <QSerialPort>
#include <QSerialPortInfo>

/*libs*/
#include <qtmaterialappbar.h>
#include <qtmaterialiconbutton.h>
#include <qtmaterialraisedbutton.h>
#include <qtmaterialscrollbar.h>
#include <qtmaterialtoggle.h>

/*gobal*/
#include "appconfig.h"
#include "appdata.h"
#include "common.h"

/*singlton - bridge*/
#include "bridge/bridge.h"
#include <singleton.h>

class mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    mainwindow(QWidget *parent = nullptr);
    ~mainwindow();

    /*mainwindow_initUI*/
    void initUI();
    /*初始化串口控制面板UI*/
    void initPortControlsUI();

    /*mainwindow_buttonTrigger*/
    void on_m_rBn_Refresh_triggered();
    void on_ibn_Connect_triggered();
    void on_ibn_Disconnect_triggered();

private:
    Ui_mainwindow *ui;

    QtMaterialIconButton *m_ibn_Connect;
    QtMaterialIconButton *m_ibn_DisConnect;

signals:

public slots:
    /*mainwindow_slots*/
    void st_ui_openPortOK();
    void st_ui_openPortFail();
};
