#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QStringList>
#include <QTime>
#include <QTimer>

#include "Exercise.h"

void test1()
{
	QStringList l;
	QString s = l.first();
	qDebug() << l.first();
}

void test2()
{
    QString s = QString::number(QTime(0, 0, 0).msecsTo(QTime::currentTime()));
    qDebug() << s.toUtf8() << ", " << s.toLocal8Bit();
}

void testQMap()
{
    QMap<int, int> m;
    m.insert(1,  1);
    m.insert(1, 2);
    qDebug() << m.size();

    //QMapIterator<int, int> i(m);
    //while (i.hasNext()) {
    //    i.next();
    //    qDebug() << i.key() << ": " << i.value();
    //}
    QMap<int, int>::ConstIterator it = m.constBegin();
    while (it != m.end())
    {
        qDebug() << it.key() << ": " << it.value();
        ++it;
    }
}

void testConnect()
{
    Exercise* ex = new ExerciseA(3);
    QTimer::singleShot(1000, ex, SLOT(type()));
    qDebug() << "topic index: " << ex->topicIndex();
    //ex->type();
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	//test1();
    //test2();
    //testQMap();
    testConnect();

	return a.exec();
}
