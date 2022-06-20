#include "common.h"
#include <QHBoxLayout>

common::common()
{
}

common::~common()
{
}

/*创建占满parentWidget的childWidget, 且将parentWidget透明化*/
void common::fullOnParent(QWidget *childWidget, QWidget *parentWidget)
{
    QHBoxLayout *layout = new QHBoxLayout(parentWidget);
    layout->setContentsMargins(0, 0, 0, 0); //外边距
    layout->addWidget(childWidget);
    parentWidget->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
}