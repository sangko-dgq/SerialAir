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



// class appevent;

class mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    mainwindow(QWidget *parent = nullptr);
    ~mainwindow();

    void FullOnParent(QWidget *childWidget, QWidget *parentWidget);

    void initPortControls();

    void on_m_rBn_Refresh_triggered();
    void on_ibn_Connect_triggered();
    void on_ibn_Disconnect_triggered();


signals:
    

public slots:
    void st_show_portOpenOK();
    void st_show_portOpenFail();

private:
    Ui_mainwindow *ui;

    QtMaterialIconButton *m_ibn_Connect;
    QtMaterialIconButton *m_ibn_DisConnect;
};
