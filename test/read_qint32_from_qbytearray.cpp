#include "common.h"
#include <QDataStream>

void read_qint32_from_qbytearray()
{
    QByteArray ba;
    QDataStream out(&ba, QIODevice::WriteOnly);
    qint32 magic = 123456;
    qint32 len = 0;
    qint32 cmd = 1;
    QString s = "pcbt start exam!";
    out << magic << len << cmd << s;
    qDebug() << ba;

    qint32 magic2;
    qint32 len2;
    qint32 cmd2;
    QString s2;
    QByteArray ba2;
    ba2.append((char*)&magic, 4);
    ba2.append((char*)&len, 4);
    ba2.append((char*)&cmd, 4);
    //QDataStream in(&ba2, QIODevice::ReadOnly);
    ba2 = ba;
    qDebug() << ba2;
    QDataStream in(ba2);
    in >> magic2 >> len2 >> cmd2 >> s2;
    //in << magic2;
    qDebug() << ba2;
}