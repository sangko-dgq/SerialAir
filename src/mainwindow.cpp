
#include "mainwindow.h"

#include "bridge/bridge.h"
#include <singleton.h>

mainwindow::mainwindow(QWidget *parent) : QMainWindow(parent), ui(new Ui_mainwindow)
{
    ui->setupUi(this);

    // connect(&Singleton<bridge>::getInstance(), Singleton<bridge>::getInstance().sg_show_portOpenOK(),
    //         this, st_show_portOpenOK);


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

    /*顶部菜单栏初始化*/
    /*appbar*/
    QtMaterialAppBar *m_appBar = new QtMaterialAppBar;
    FullOnParent(m_appBar, ui->wAppbar);
    /*iconbutton*/
    m_ibn_Connect = new QtMaterialIconButton(QtMaterialTheme::icon("av", "play_circle_filled"));
    m_ibn_DisConnect = new QtMaterialIconButton(QtMaterialTheme::icon("av", "stop"));

    m_ibn_Connect->setIconSize(QSize(26, 26));
    m_ibn_DisConnect->setIconSize(QSize(26 + 8, 26 + 8)); //+8： 补充视差

    m_ibn_Connect->setColor(Qt::white);
    m_ibn_DisConnect->setColor(Qt::white);

    m_ibn_Connect->setFixedWidth(42);
    m_ibn_DisConnect->setFixedWidth(42);

    m_appBar->setMaximumHeight(ui->wAppbar->maximumHeight());
    m_appBar->appBarLayout()->addWidget(m_ibn_Connect);
    m_appBar->appBarLayout()->addWidget(m_ibn_DisConnect);
    m_appBar->appBarLayout()->addStretch(1); /*必须放到最后*/

    /*event*/
    connect(m_ibn_Connect, &QPushButton::pressed, this, on_ibn_Connect_triggered);
    connect(m_ibn_DisConnect, &QPushButton::pressed, this, on_ibn_Disconnect_triggered);

    /*刷新按钮初始化*/
    QtMaterialRaisedButton *m_rBn_Refresh = new QtMaterialRaisedButton("Refresh");
    m_rBn_Refresh->setBackgroundColor("#00c853");
    FullOnParent(m_rBn_Refresh, ui->wBnRefush);

    connect(m_rBn_Refresh, &QPushButton::pressed, this, [&]
    { on_m_rBn_Refresh_triggered(); });

    /*connet必须放在ui后面*/
    connect(&Singleton<bridge>::getInstance(), SIGNAL(sg_show_portOpenOK()), this, SLOT(st_show_portOpenOK()));


    /*接收区初始化*/
    QtMaterialScrollBar *m_H_sBar = new QtMaterialScrollBar;
    QtMaterialScrollBar *m_V_sBar = new QtMaterialScrollBar;
    m_V_sBar->setHideOnMouseOut(false);
    m_H_sBar->setHideOnMouseOut(false);
    m_H_sBar->setOrientation(Qt::Horizontal);
    ui->editReceive->setTextColor(Qt::white);
    ui->editReceive->setText(
                "<p>001-The distinction between the subjects of syntax and semantics has its origin in the study of natural languages.</p>"
                "<p>002-The distinction between the subjects of syntax and semantics has its origin in the study of natural languages.</p>"
                "<p>003-The distinction between the subjects of syntax and semantics has its origin in the study of natural languages.</p>"
                "<p>004-The distinction between the subjects of syntax and semantics has its origin in the study of natural languages.</p>"
                "<p>005-The distinction between the subjects of syntax and semantics has its origin in the study of natural languages.</p>"
                "<p>006-The distinction between the subjects of syntax and semantics has its origin in the study of natural languages.</p>"
                "<p>007-The distinction between the subjects of syntax and semantics has its origin in the study of natural languages.</p>"
                "<p>008-The distinction between the subjects of syntax and semantics has its origin in the study of natural languages.</p>");
    ui->editReceive->setTextColor(Qt::white);
    ui->editReceive->setLineWrapMode(QTextEdit::NoWrap);
    ui->editReceive->update();
    ui->editReceive->setVerticalScrollBar(m_V_sBar);
    ui->editReceive->setHorizontalScrollBar(m_H_sBar);

    /*Init Serial Controls*/
    initPortControls();
}

mainwindow::~mainwindow()
{
    delete ui;
}

/*创建占满parentWidget的childWidget, 且将parentWidget透明化*/
void mainwindow::FullOnParent(QWidget *childWidget, QWidget *parentWidget)
{
    QHBoxLayout *layout = new QHBoxLayout(parentWidget);
    layout->setContentsMargins(0, 0, 0, 0); //外边距
    layout->addWidget(childWidget);
    parentWidget->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
}

/*初始化串口控制面板*/
void mainwindow::initPortControls()
{
    ui->comboPort->clear();
    /*no availablePorts*/
    if (QSerialPortInfo::availablePorts().size() == 0)
    {
        ui->statusBar->showMessage("No available ports.");
        return;
    }
    /*exsit availablePorts*/
    foreach (auto port, QSerialPortInfo::availablePorts())
    {
        ui->comboPort->addItem(port.portName());
    }
    /* Populate baud rate combo box with standard rates */
    ui->comboBaud->addItem("1200");
    ui->comboBaud->addItem("2400");
    ui->comboBaud->addItem("4800");
    ui->comboBaud->addItem("9600");
    ui->comboBaud->addItem("19200");
    ui->comboBaud->addItem("38400");
    ui->comboBaud->addItem("57600");
    ui->comboBaud->addItem("115200");
    /* And some not-so-standard */
    ui->comboBaud->addItem("128000");
    ui->comboBaud->addItem("153600");
    ui->comboBaud->addItem("230400");
    ui->comboBaud->addItem("256000");
    ui->comboBaud->addItem("460800");
    ui->comboBaud->addItem("921600");

    /* Select 115200 bits by default */
    ui->comboBaud->setCurrentIndex(7);

    /* Populate data bits combo box */
    ui->comboData->addItem("8 bits");
    ui->comboData->addItem("7 bits");

    /* Populate parity combo box */
    ui->comboParity->addItem("none");
    ui->comboParity->addItem("odd");
    ui->comboParity->addItem("even");

    /* Populate stop bits combo box */
    ui->comboStop->addItem("1 bit");
    ui->comboStop->addItem("2 bits");
}

/*Trigger*/
/*当 刷新串口 按钮按下*/
void mainwindow::on_m_rBn_Refresh_triggered()
{
    initPortControls();
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
}

/*SLOTS*/
/*串口打开成功*/
void mainwindow::st_show_portOpenOK()
{
    ui->wPlotView->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->statusBar->showMessage("Connected!");
    connected = true;
}
/*串口打开失败*/
void mainwindow::st_show_portOpenFail()
{
    // qDebug() << "Port cannot be open signal received!";
    ui->statusBar->showMessage("Cannot open port!");
}
