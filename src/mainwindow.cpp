
#include "mainwindow.h"

mainwindow::mainwindow(QWidget *parent) : QMainWindow(parent), ui(new Ui_mainwindow)
{
    ui->setupUi(this);

    /*Init UI*/
    initUI();

    /*Connect Bridge<->UI*/
    connect(&Singleton<bridge>::getInstance(),
            SIGNAL(sg_ui_openPortOK()),
            this,
            SLOT(st_ui_openPortOK()));
    connect(&Singleton<bridge>::getInstance(),
            SIGNAL(sg_ui_openPortOK()),
            this,
            SLOT(st_ui_openPortOK()));

    connect(&Singleton<bridge>::getInstance(),
            SIGNAL(sg_ui_dataAppendToUI(char*)),
            this,
            SLOT(st_ui_dataAppendToUI(char*)));
    
    connect(&Singleton<bridge>::getInstance(),
            SIGNAL(sg_ui_closePorkOK()), 
            this, 
        SLOT(st_ui_closePorkOK()));

    


#ifdef ClearDebugWidgetsStyle
    ui->wLeft->setStyleSheet("");
    ui->wMain->setStyleSheet("");
    ui->wPlotCtrl->setStyleSheet("");
    ui->wPlotView->setStyleSheet("");
    ui->wPortCtrl->setStyleSheet("");
    ui->wReceive->setStyleSheet("");
    ui->wRight->setStyleSheet("");
    ui->wTRCtrl->setStyleSheet("");
#endif
}

mainwindow::~mainwindow()
{
    delete ui;
}


