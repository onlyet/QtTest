#include "common.h"
#include "SignalTest.h"
#include <QString>
#include <qdebug.h>


void outputUrl(A* a, QString url)
{
    QMetaObject::Connection * const connection = new QMetaObject::Connection;
    *connection = QObject::connect(a, &A::sig, [connection, url]() {
        QObject::disconnect(*connection);
        delete connection;
        qDebug() << url;
    });
}

void SignalTest()
{
    A a1;

    QString url1 = "1";
    QString url2 = "2";
    QString url3 = "3";

    outputUrl(&a1, url1);
    outputUrl(&a1, url2);

    emit a1.sig();
    emit a1.sig();
}