#include "common.h"
#include <QPushButton>
#include <QApplication>
#include <QObject>

void qapplication_exit()
{
    QPushButton* btn = new QPushButton;
    QObject::connect(btn, &QPushButton::clicked, btn, &QPushButton::close);
    btn->show();
    //QApplication::instance();
}