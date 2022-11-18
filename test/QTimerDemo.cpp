#include "common.h"
#include <QTimer>
#include <QDebug>
#include <QObject>

void QTimerDemo()
{
    QTimer *timer = new QTimer();
    QObject::connect(timer, &QTimer::timeout, []() {
        qDebug() << "timeout";
    });
    timer->start(5000);
    //timer->stop();
}