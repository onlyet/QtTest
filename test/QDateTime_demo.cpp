#include "common.h"
#include <qdatetime.h>
#include <qdebug.h>


void QDateTime_demo()
{
	QString s = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
	qDebug() << s;
}