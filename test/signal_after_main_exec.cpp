#include "signal_after_main_exec.h"
#include "common.h"
#include <QThread>
#include <QDebug>
#include <QTimer>

Boss b;

Worker::~Worker()
{
}

Boss::Boss()
{
    qDebug() << "Boss()";
}

//void signal_after_main_exec()
//{
//    
//}

Boss::~Boss()
{
    qDebug() << "~Boss()";
    emit emitAfterMainExec();
}

void Boss::init()
{

    QThread* thread = new QThread;
    Worker* worker = new Worker;
    worker->moveToThread(thread);
    //connect(worker, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
    connect(thread, SIGNAL(started()), worker, SLOT(process()));
    connect(worker, SIGNAL(finished()), thread, SLOT(quit()));
    connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    //connect(worker, &Worker::emitAfterMainExec, this, )
    connect(this, &Boss::emitAfterMainExec, worker, &Worker::emitAfterMainExecResult);
    //QTimer::singleShot(1000, [this]() {
    //    emit emitAfterMainExec();
    //});

    thread->start();
}
