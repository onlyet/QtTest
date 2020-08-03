#include "TestWorker.h"
#include <QDebug>

TestWorker::TestWorker(QObject *parent)
    : QObject(parent)
{
}

TestWorker::~TestWorker()
{
}

void TestWorker::stop()
{
    m_stopped = true;
}

void TestWorker::process()
{
    while (1)
    {
        if (m_stopped)
        {
            break;
        }
        int cnt = 0;
        for (int i = 0; i < 1000 * 1000; ++i)
        {
            ++cnt;
        }
        //qDebug() << ""
    }
    emit finished();
    qDebug() << "TestWorker exit";
}
