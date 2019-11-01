#include "common.h"
#include <QList>
#include <qvariant.h>
#include <qvector.h>
#include <qdebug.h>
#include <qdatetime.h>

void QList_demo()
{
    //QList<int> l1 = { 1,2,3 };
    //QList<int> l2 = { 5,6,7 };
    //QList<QList<int>> ll;
    //ll.append(l1);
    //ll.append(l2);
    //QVariantList l1 = { 1,2,3 };
    //QVariantList l2 = { 4,5,6 };
    //QVariantList ll;
    //ll.append(l1);
    //ll.append(l2);

    //QList<QVariantList> lst;
    //lst.append(l1);
    //lst.append(l2);

    //QVector<int> v;
    ////v.reserve(10);
    ////v[3] = 11;
    //v.resize(10);
    //v[9] = 100;
    //qDebug() << v.size();

    QString s = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QDateTime dt = QDateTime::fromString(s, "yyyy-MM-dd hh:mm:ss");
    QString s2 = dt.toString("yyyy-MM-dd hh:mm:ss");
    int secs = dt.toSecsSinceEpoch();
    int secs2 = dt.toTime_t();

    QString tt = ("2019-10-17 16:35:59");
    int secs_tt = QDateTime::fromString(tt, "yyyy-MM-dd hh:mm:ss").toSecsSinceEpoch();

}