//#include <QtCore/QCoreApplication>
#include <QApplication>
#include <QDebug>
#include <QStringList>
#include <QTime>
#include <QTimer>
#include <QWidget>


#include "Exercise.h"
#include "moc_test.h"
#include "property_system_test.h"

#include "common.h"

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
    //QTimer::singleShot(1000, ex, SLOT(showTopicATips(bool)));
    qDebug() << "topic index: " << ex->topicIndex();
    //ex->type();
}

void toLocal8Bit_test()
{
    QString s = "00-1B-10-31-01-82";
    QString s2 = s.toLocal8Bit().data();
    QString s3 = s2.toLocal8Bit().data();
    //char *
}

void moc_debug()
{
    Counter a, b;
    QObject::connect(&a, SIGNAL(valueChanged(int)),
        &b, SLOT(setValue(int)));

    a.setValue(12);
}

#include "signal_after_main_exec.h"
extern Boss b;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//test1();
    //test2();
    //testQMap();
    //testConnect();
    //toLocal8Bit_test();
    //moc_debug();
    //Property_Test();

    test();

 /*   QWidget w;
    w.show();*/

	return a.exec();

    //QObject::connect(&a, &QApplication::aboutToQuit, &b, &Boss::emitAfterMainExec);

    //b.init();
    //QTimer::singleShot(3000, [&a]() {
    //    a.exit();
    //});

    //int ret = a.exec();
    //qDebug() << "main exit begin";

    //return ret;
    //qDebug() << "main exit end";

}
