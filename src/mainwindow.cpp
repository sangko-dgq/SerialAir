

#include "mainwindow.h"

mainwindow::mainwindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui_mainwindow)
{
        ui->setupUi(this);

        /*Init UI*/
        initUI();

        /*Connect Bridge<->UI*/
        connect(&Singleton<bridge>::getInstance(), SIGNAL(sg_ui_openPortOK()), this,
                SLOT(st_ui_openPortOK()));
        connect(&Singleton<bridge>::getInstance(), SIGNAL(sg_ui_openPortOK()), this,
                SLOT(st_ui_openPortOK()));

        connect(&Singleton<bridge>::getInstance(),
                SIGNAL(sg_ui_dataAppendToUI(char *)), this,
                SLOT(st_ui_dataAppendToUI(char *)));

        connect(&Singleton<bridge>::getInstance(), SIGNAL(sg_ui_closePorkOK()), this,
                SLOT(st_ui_closePorkOK()));

        QString leaveQss = "border:1px solid rgb(0,0,0); border-radius:4px; background-color: rgb(0, 188, 212)";

#ifdef ClearDebugWidgetsStyle
        ui->wAppbar->setStyleSheet("");
        ui->wLeft->setStyleSheet("");
        ui->wRight->setStyleSheet("");
        ui->wMain->setStyleSheet("");

        ui->wPlotControls->setStyleSheet(leaveQss);
        ui->wPlotView->setStyleSheet(leaveQss);

        ui->wPortControls->setStyleSheet(leaveQss);
        ui->wReceive->setStyleSheet(leaveQss);

        ui->wTRCtrl->setStyleSheet(leaveQss);

        /*refix*/
        ui->wBnRefush->setStyleSheet("border:0px solid rgb(0,0,0)");

#endif
}

mainwindow::~mainwindow() { delete ui; }
