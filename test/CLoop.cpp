#include "CLoop.h"
#include <qdebug.h>
#include <QEventLoop>
#include <qtimer.h>

CLoop::CLoop(QObject* parent)
    : QObject(parent)
{
}

CLoop::~CLoop()
{
    qDebug() << "CLoop::~CLoop()";
}


static void deleteLaterTest1() {
    CLoop *c = new CLoop;
    QEventLoop l;
    c->deleteLater();
    int ret = l.exec();
}

static void deleteLaterTest2() {
    QTimer::singleShot(100, []() {
        CLoop* c = new CLoop;
        QEventLoop l;
        c->deleteLater();
        QTimer* t = new QTimer;
        t->setSingleShot(true);
        QObject::connect(t, &QTimer::timeout, [&l]() {
            l.exit(1);
            });
        t->start(3000);
        int ret = l.exec();
        int a = 1 + 2;
        QTimer::singleShot(0, []() {
            qDebug() << "end";
            });
        });
}

void deleteLaterTest() {
    //deleteLaterTest1();
    deleteLaterTest2();
}