#include "common.h"
#include <qmutex.h>
#include <QTime>
#include <qdebug.h>
#include <qwaitcondition.h>

QMutex  m_mtxVFifoBuf;
QWaitCondition  m_wcVFifoBufNotFull;

void recursiveMutex()
{
	//QMutex mtx(QMutex::Recursive);

	//QMutexLocker lock(&mtx);

	//QTime t = QTime::currentTime();
	//qint64 sum = 0;
	//for (qint64 i = 1; i <= 100; ++i)
	//{
	//	for (qint64 j = 1; j <= 1000 * 1000; ++j)
	//	{
	//		sum += 1;
	//	}
	//}
	//qDebug() << "t: " << t.elapsed();

	//t.restart();
	//{
	//	QTime t2 = QTime::currentTime();
	//	QMutexLocker lock2(&mtx);
	//	qDebug() << "lock time: " << t2.elapsed();
	//	sum = 0;
	//	for (qint64 i = 1; i <= 100 * 1000 * 1000; ++i)
	//	{
	//		sum += i;
	//	}
	//	qDebug() << "t: " << t.elapsed();
	//}

	m_mtxVFifoBuf.lock();
	m_wcVFifoBufNotFull.wait(&m_mtxVFifoBuf);
	m_mtxVFifoBuf.unlock();
}