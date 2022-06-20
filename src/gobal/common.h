
#pragma once

#include <QObject>
#include <QWidget>

class common : public QObject
{
    Q_OBJECT

public:
    common();
    ~common();

    void fullOnParent(QWidget *childWidget, QWidget *parentWidget);

private:
};
