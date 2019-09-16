#include "common.h"
#include <QByteArray>
#include <QDebug>

void base64_encode()
{
    QByteArray text("gdjy:gdjy2015");
    QByteArray text2 = text.toBase64();        // returns "UXQgaXMgZ3JlYXQh"
    qDebug() << text;
    qDebug() << text2;
    qDebug() << QByteArray::fromBase64(text2);
    
}