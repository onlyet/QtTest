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


    QString s3 = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    qint64 dt2 = QDateTime::fromString(s3, "yyyy-MM-dd hh:mm:ss").toMSecsSinceEpoch();

    qint64 t = QDateTime::currentMSecsSinceEpoch();
    QString s4 = QDateTime::fromMSecsSinceEpoch(t).toString("yyyy-MM-dd hh:mm:ss");
    QString s5 = QDateTime::fromMSecsSinceEpoch(t).toString("yyyy-MM-dd hh:mm:ss.zzz");

    //qint64 folderId = QDateTime::currentMSecsSinceEpoch();  //13Î»Êý
    //QString id = QString::number(folderId);
    //qint64 f2 = id.toLongLong();
    //QString s6 = QDateTime::fromMSecsSinceEpoch(id.toLongLong()).toString("yyyy-MM-dd hh:mm:ss");


    QString folderId = QString::number(QDateTime::currentMSecsSinceEpoch());
    QString cjsj = QDateTime::fromMSecsSinceEpoch(folderId.toLongLong()).toString("yyyy-MM-dd hh:mm:ss");

    QString dd1 = "1572623374871";
    QString dd2 = "1572623374873";
    qDebug() << (dd1 > dd2 ? ">" : "<");

    QVariantMap vm;
    vm.insert("id", "1");
    vm.insert("name", "hello");
    QVariantMap vm2;
    vm2.insert("id", "2");
    vm2.insert("name", "world");
    QVariantMap vm3;
    vm3.insert("id", "3");
    vm3.insert("name", "!!!");
    QVariantMap pagesInfo;
    pagesInfo.insert("1", vm);
    pagesInfo.insert("2", vm2);
    pagesInfo.insert("3", vm3);

    for (auto& item : pagesInfo)
    {
        QVariantMap pageInfo = item.toMap();
        pageInfo["name"] = "shit";
        item = pageInfo;
    }
}

