

#include "../../mainwindow.h"

#include "common.h"

common *m_common;

void mainwindow::initUI()
{
    
    m_common = new common;

    /*--------------------------------------------顶部菜单栏Appbar初始化--------------------------------*/
    /*appbar*/
    QtMaterialAppBar *m_appBar = new QtMaterialAppBar;
    m_common->fullOnParent(m_appBar, ui->wAppbar);
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

    /*按钮事件绑定*/
    connect(m_ibn_Connect, &QPushButton::pressed, this, [=]()
            { on_ibn_Connect_triggered(); });
    connect(m_ibn_DisConnect, &QPushButton::pressed, this, [=]()
            { on_ibn_Disconnect_triggered(); });

    /*刷新按钮初始化*/
    QtMaterialRaisedButton *m_rBn_Refresh = new QtMaterialRaisedButton("Refresh");
    m_rBn_Refresh->setBackgroundColor("#00c853");
    m_common->fullOnParent(m_rBn_Refresh, ui->wBnRefush);
    connect(m_rBn_Refresh, &QPushButton::pressed, this, [&]
            { on_m_rBn_Refresh_triggered(); });

    /*------------------------------------------------------接收区初始化---------------------------------------------------*/
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
    
    
    /*--------------------------------------------------初始化串口控制面板UI-----------------------------------------------*/
    initPortControlsUI();
}


/*初始化串口控制面板UI*/
void mainwindow::initPortControlsUI()
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
