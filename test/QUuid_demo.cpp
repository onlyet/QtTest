#include "common.h"
#include <quuid.h>
#include <qdebug.h>

void QUuid_demo()
{
    //return QUuid::createUuid().toString(QUuid::Id128);
    QString uuid = QUuid::createUuid().toString();
    //QString newUuid = uuid.
    //uuid.remove(0, 1);
    //uuid.remove(uuid.length() - 1, 1);
    //uuid.remove(8, 1);
    uuid.remove('{');
    uuid.remove('}');
    uuid.remove('-');
    qDebug() << uuid;
}