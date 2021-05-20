#include "common.h"
#include "IWorker.h"
#include <QThread>
#include <QDebug>

IWorker::IWorker(QObject *parent)
    : QObject(parent)
{
    m_thread = new QThread;
    moveToThread(m_thread);


    connect(m_thread, &QThread::started, this, &IWorker::process);
    //connect(this, &MainWindow::startWorker, this, &IWorker::start);
    connect(this, &IWorker::finished, m_thread, &QThread::quit);
    connect(this, &IWorker::finished, this, &IWorker::deleteLater);
    connect(m_thread, &QThread::finished, m_thread, &QThread::deleteLater);
    m_thread->start();
}

IWorker::~IWorker()
{
    qDebug() << "~IWorker()";
}

void IWorker::start()
{
    m_state = Started;
}

void IWorker::stop()
{
    m_state = Stopped;
}

void IWorker::pause()
{
    m_state = Paused;
}

void IWorker::step1()
{
}

void IWorker::step2()
{
}

void IWorker::step3()
{
}

void IWorker::process()
{
    step1();

    while (1)
    {
        if (Stopped == m_state)
        {
            break;
        }
        else if (Paused == m_state)
        {
            QThread::msleep(10);
            continue;
        }

        step2();
    }

    step3();
    emit finished();
}

ReadIpcFrameWorker::ReadIpcFrameWorker(QVariantMap params, QObject *parent)
    : IWorker(parent)
{

}


ReadIpcFrameWorker::~ReadIpcFrameWorker()
{
}

#if 0
void ReadIpcFrameWorker::process()
{
    qDebug() << "ReadIpcFrameWorker::process";
}
#endif

void ReadIpcFrameWorker::start()
{
    qDebug() << "ReadIpcFrameWorker::start";
}


void IWorkerTest()
{
    QVariantMap params;
    ReadIpcFrameWorker *rifWorker = new ReadIpcFrameWorker(params);
    //connect(this)

}