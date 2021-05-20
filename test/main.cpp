#include <QApplication>
#include <QDebug>
#include <QStringList>
#include <QTime>
#include <QTimer>
#include <QWidget>
#include "common.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

    test();

    //QObject::connect(&a, &QApplication::aboutToQuit, &b, &Boss::emitAfterMainExec);
	return a.exec();
}
