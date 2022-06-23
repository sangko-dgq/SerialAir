/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainwindow
{
public:
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionPause_plot;
    QAction *actionClearPlot;
    QAction *actionGuide;
    QAction *actionRecord_stream;
    QAction *actionResetView;
    QAction *actionRefresh;
    QWidget *wMain;
    QGridLayout *gridLayout;
    QSplitter *splitter_2;
    QWidget *wLeft;
    QGridLayout *gridLayout_3;
    QSplitter *splitter_4;
    QSplitter *splitter_3;
    QWidget *wPortControls;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelPort;
    QComboBox *comboPort;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelBaud;
    QComboBox *comboBaud;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelData;
    QComboBox *comboData;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelParity;
    QComboBox *comboParity;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelStop;
    QComboBox *comboStop;
    QWidget *wBnRefush;
    QWidget *wPlotControls;
    QWidget *wTRCtrl;
    QWidget *wRight;
    QGridLayout *gridLayout_2;
    QSplitter *splitter;
    QWidget *wPlotView;
    QWidget *wReceive;
    QGridLayout *gridLayout_5;
    QTextEdit *editReceive;
    QWidget *wAppbar;
    QStatusBar *statusBar;
    QMenuBar *menubar;
    QMenu *menuSerial;
    QMenu *menuPlot;
    QMenu *menuGuide;
    QMenu *menuFile;
    QMenu *menuGuide_2;

    void setupUi(QMainWindow *mainwindow)
    {
        if (mainwindow->objectName().isEmpty())
            mainwindow->setObjectName(QString::fromUtf8("mainwindow"));
        mainwindow->resize(965, 683);
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        mainwindow->setFont(font);
        mainwindow->setLayoutDirection(Qt::LeftToRight);
        mainwindow->setStyleSheet(QString::fromUtf8(""));
        actionConnect = new QAction(mainwindow);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        actionDisconnect = new QAction(mainwindow);
        actionDisconnect->setObjectName(QString::fromUtf8("actionDisconnect"));
        actionPause_plot = new QAction(mainwindow);
        actionPause_plot->setObjectName(QString::fromUtf8("actionPause_plot"));
        actionClearPlot = new QAction(mainwindow);
        actionClearPlot->setObjectName(QString::fromUtf8("actionClearPlot"));
        actionGuide = new QAction(mainwindow);
        actionGuide->setObjectName(QString::fromUtf8("actionGuide"));
        actionRecord_stream = new QAction(mainwindow);
        actionRecord_stream->setObjectName(QString::fromUtf8("actionRecord_stream"));
        actionResetView = new QAction(mainwindow);
        actionResetView->setObjectName(QString::fromUtf8("actionResetView"));
        actionRefresh = new QAction(mainwindow);
        actionRefresh->setObjectName(QString::fromUtf8("actionRefresh"));
        wMain = new QWidget(mainwindow);
        wMain->setObjectName(QString::fromUtf8("wMain"));
        wMain->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(wMain);
        gridLayout->setSpacing(2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(2, 2, 2, 2);
        splitter_2 = new QSplitter(wMain);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setEnabled(true);
        splitter_2->setMaximumSize(QSize(16777215, 16777215));
        splitter_2->setOrientation(Qt::Horizontal);
        splitter_2->setHandleWidth(2);
        wLeft = new QWidget(splitter_2);
        wLeft->setObjectName(QString::fromUtf8("wLeft"));
        wLeft->setMaximumSize(QSize(224, 16777215));
        gridLayout_3 = new QGridLayout(wLeft);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        splitter_4 = new QSplitter(wLeft);
        splitter_4->setObjectName(QString::fromUtf8("splitter_4"));
        splitter_4->setOrientation(Qt::Vertical);
        splitter_4->setHandleWidth(2);
        splitter_4->setChildrenCollapsible(false);
        splitter_3 = new QSplitter(splitter_4);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Vertical);
        splitter_3->setHandleWidth(2);
        splitter_3->setChildrenCollapsible(false);
        wPortControls = new QWidget(splitter_3);
        wPortControls->setObjectName(QString::fromUtf8("wPortControls"));
        wPortControls->setMinimumSize(QSize(0, 0));
        wPortControls->setMaximumSize(QSize(16777215, 256));
        wPortControls->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 127);\n"
"border:2px solid rgb(0,0,0);"));
        gridLayout_4 = new QGridLayout(wPortControls);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelPort = new QLabel(wPortControls);
        labelPort->setObjectName(QString::fromUtf8("labelPort"));
        labelPort->setStyleSheet(QString::fromUtf8("border:0px solid rgb(0,0,0);"));

        horizontalLayout->addWidget(labelPort);

        comboPort = new QComboBox(wPortControls);
        comboPort->setObjectName(QString::fromUtf8("comboPort"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboPort->sizePolicy().hasHeightForWidth());
        comboPort->setSizePolicy(sizePolicy);
        comboPort->setMinimumSize(QSize(148, 24));
        comboPort->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border:1px solid rgb(0,0,0);"));

        horizontalLayout->addWidget(comboPort);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelBaud = new QLabel(wPortControls);
        labelBaud->setObjectName(QString::fromUtf8("labelBaud"));
        labelBaud->setStyleSheet(QString::fromUtf8("border:0px solid rgb(0,0,0);"));

        horizontalLayout_2->addWidget(labelBaud);

        comboBaud = new QComboBox(wPortControls);
        comboBaud->setObjectName(QString::fromUtf8("comboBaud"));
        sizePolicy.setHeightForWidth(comboBaud->sizePolicy().hasHeightForWidth());
        comboBaud->setSizePolicy(sizePolicy);
        comboBaud->setMinimumSize(QSize(148, 24));
        comboBaud->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border:1px solid rgb(0,0,0);"));

        horizontalLayout_2->addWidget(comboBaud);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelData = new QLabel(wPortControls);
        labelData->setObjectName(QString::fromUtf8("labelData"));
        labelData->setStyleSheet(QString::fromUtf8("border:0px solid rgb(0,0,0);"));

        horizontalLayout_3->addWidget(labelData);

        comboData = new QComboBox(wPortControls);
        comboData->setObjectName(QString::fromUtf8("comboData"));
        sizePolicy.setHeightForWidth(comboData->sizePolicy().hasHeightForWidth());
        comboData->setSizePolicy(sizePolicy);
        comboData->setMinimumSize(QSize(148, 24));
        comboData->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border:1px solid rgb(0,0,0);"));

        horizontalLayout_3->addWidget(comboData);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        labelParity = new QLabel(wPortControls);
        labelParity->setObjectName(QString::fromUtf8("labelParity"));
        labelParity->setStyleSheet(QString::fromUtf8("border:0px solid rgb(0,0,0);"));

        horizontalLayout_4->addWidget(labelParity);

        comboParity = new QComboBox(wPortControls);
        comboParity->setObjectName(QString::fromUtf8("comboParity"));
        sizePolicy.setHeightForWidth(comboParity->sizePolicy().hasHeightForWidth());
        comboParity->setSizePolicy(sizePolicy);
        comboParity->setMinimumSize(QSize(148, 24));
        comboParity->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border:1px solid rgb(0,0,0);"));

        horizontalLayout_4->addWidget(comboParity);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        labelStop = new QLabel(wPortControls);
        labelStop->setObjectName(QString::fromUtf8("labelStop"));
        labelStop->setStyleSheet(QString::fromUtf8("border:0px solid rgb(0,0,0);"));

        horizontalLayout_5->addWidget(labelStop);

        comboStop = new QComboBox(wPortControls);
        comboStop->setObjectName(QString::fromUtf8("comboStop"));
        sizePolicy.setHeightForWidth(comboStop->sizePolicy().hasHeightForWidth());
        comboStop->setSizePolicy(sizePolicy);
        comboStop->setMinimumSize(QSize(148, 24));
        comboStop->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"border:1px solid rgb(0,0,0);"));

        horizontalLayout_5->addWidget(comboStop);


        verticalLayout->addLayout(horizontalLayout_5);


        gridLayout_4->addLayout(verticalLayout, 2, 0, 1, 1);

        wBnRefush = new QWidget(wPortControls);
        wBnRefush->setObjectName(QString::fromUtf8("wBnRefush"));
        wBnRefush->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(wBnRefush->sizePolicy().hasHeightForWidth());
        wBnRefush->setSizePolicy(sizePolicy1);
        wBnRefush->setMaximumSize(QSize(256, 48));
        wBnRefush->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"border:0px solid rgb(0,0,0);"));

        gridLayout_4->addWidget(wBnRefush, 1, 0, 1, 1);

        splitter_3->addWidget(wPortControls);
        wPlotControls = new QWidget(splitter_3);
        wPlotControls->setObjectName(QString::fromUtf8("wPlotControls"));
        wPlotControls->setMinimumSize(QSize(0, 10));
        wPlotControls->setMaximumSize(QSize(16777215, 16777215));
        wPlotControls->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 255);\n"
"border:2px solid rgb(0,0,0);"));
        splitter_3->addWidget(wPlotControls);
        splitter_4->addWidget(splitter_3);
        wTRCtrl = new QWidget(splitter_4);
        wTRCtrl->setObjectName(QString::fromUtf8("wTRCtrl"));
        wTRCtrl->setMinimumSize(QSize(0, 10));
        wTRCtrl->setMaximumSize(QSize(16777215, 96));
        wTRCtrl->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 170, 255);\n"
"border:2px solid rgb(0,0,0);"));
        splitter_4->addWidget(wTRCtrl);

        gridLayout_3->addWidget(splitter_4, 0, 0, 1, 1);

        splitter_2->addWidget(wLeft);
        wRight = new QWidget(splitter_2);
        wRight->setObjectName(QString::fromUtf8("wRight"));
        wRight->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 0);"));
        gridLayout_2 = new QGridLayout(wRight);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(wRight);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setFrameShadow(QFrame::Plain);
        splitter->setOrientation(Qt::Vertical);
        splitter->setOpaqueResize(true);
        splitter->setHandleWidth(2);
        splitter->setChildrenCollapsible(false);
        wPlotView = new QWidget(splitter);
        wPlotView->setObjectName(QString::fromUtf8("wPlotView"));
        wPlotView->setMinimumSize(QSize(0, 256));
        wPlotView->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 127);\n"
"\n"
"border:2px solid rgb(0,0,0);"));
        splitter->addWidget(wPlotView);
        wReceive = new QWidget(splitter);
        wReceive->setObjectName(QString::fromUtf8("wReceive"));
        wReceive->setMinimumSize(QSize(0, 64));
        wReceive->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 127);\n"
"\n"
"\n"
"border:2px solid rgb(0,0,0);"));
        gridLayout_5 = new QGridLayout(wReceive);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        editReceive = new QTextEdit(wReceive);
        editReceive->setObjectName(QString::fromUtf8("editReceive"));
        editReceive->setMinimumSize(QSize(0, 10));
        editReceive->setFont(font);
        editReceive->setStyleSheet(QString::fromUtf8(""));
        editReceive->setLineWidth(1);

        gridLayout_5->addWidget(editReceive, 0, 0, 1, 1);

        splitter->addWidget(wReceive);

        gridLayout_2->addWidget(splitter, 0, 0, 1, 1);

        splitter_2->addWidget(wRight);

        gridLayout->addWidget(splitter_2, 1, 0, 1, 1);

        wAppbar = new QWidget(wMain);
        wAppbar->setObjectName(QString::fromUtf8("wAppbar"));
        wAppbar->setMaximumSize(QSize(16777215, 48));
        wAppbar->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);"));

        gridLayout->addWidget(wAppbar, 0, 0, 1, 1);

        mainwindow->setCentralWidget(wMain);
        statusBar = new QStatusBar(mainwindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        mainwindow->setStatusBar(statusBar);
        menubar = new QMenuBar(mainwindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setEnabled(true);
        menubar->setGeometry(QRect(0, 0, 965, 22));
        menuSerial = new QMenu(menubar);
        menuSerial->setObjectName(QString::fromUtf8("menuSerial"));
        menuPlot = new QMenu(menubar);
        menuPlot->setObjectName(QString::fromUtf8("menuPlot"));
        menuGuide = new QMenu(menubar);
        menuGuide->setObjectName(QString::fromUtf8("menuGuide"));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuGuide_2 = new QMenu(menubar);
        menuGuide_2->setObjectName(QString::fromUtf8("menuGuide_2"));
        mainwindow->setMenuBar(menubar);

        menubar->addAction(menuSerial->menuAction());
        menubar->addAction(menuPlot->menuAction());
        menubar->addAction(menuGuide->menuAction());
        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuGuide_2->menuAction());
        menuSerial->addAction(actionConnect);
        menuSerial->addAction(actionDisconnect);
        menuSerial->addSeparator();
        menuSerial->addAction(actionRefresh);
        menuPlot->addAction(actionPause_plot);
        menuPlot->addAction(actionClearPlot);
        menuGuide->addAction(actionResetView);
        menuFile->addAction(actionRecord_stream);
        menuGuide_2->addAction(actionGuide);

        retranslateUi(mainwindow);

        QMetaObject::connectSlotsByName(mainwindow);
    } // setupUi

    void retranslateUi(QMainWindow *mainwindow)
    {
        mainwindow->setWindowTitle(QCoreApplication::translate("mainwindow", "mainwindow", nullptr));
        actionConnect->setText(QCoreApplication::translate("mainwindow", "Connect", nullptr));
        actionDisconnect->setText(QCoreApplication::translate("mainwindow", "Disconnect", nullptr));
        actionPause_plot->setText(QCoreApplication::translate("mainwindow", "Pause_plot", nullptr));
        actionClearPlot->setText(QCoreApplication::translate("mainwindow", "Clear_plot", nullptr));
        actionGuide->setText(QCoreApplication::translate("mainwindow", "HowToUse", nullptr));
        actionRecord_stream->setText(QCoreApplication::translate("mainwindow", "Record_stream", nullptr));
        actionResetView->setText(QCoreApplication::translate("mainwindow", "ResetView", nullptr));
        actionRefresh->setText(QCoreApplication::translate("mainwindow", "Refresh", nullptr));
        labelPort->setText(QCoreApplication::translate("mainwindow", "Port", nullptr));
        labelBaud->setText(QCoreApplication::translate("mainwindow", "Baud", nullptr));
        labelData->setText(QCoreApplication::translate("mainwindow", "Data", nullptr));
        labelParity->setText(QCoreApplication::translate("mainwindow", "Parity", nullptr));
        labelStop->setText(QCoreApplication::translate("mainwindow", "Stop", nullptr));
        menuSerial->setTitle(QCoreApplication::translate("mainwindow", "Serial", nullptr));
        menuPlot->setTitle(QCoreApplication::translate("mainwindow", "Plot", nullptr));
        menuGuide->setTitle(QCoreApplication::translate("mainwindow", "View", nullptr));
        menuFile->setTitle(QCoreApplication::translate("mainwindow", "File", nullptr));
        menuGuide_2->setTitle(QCoreApplication::translate("mainwindow", "Guide", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainwindow: public Ui_mainwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
