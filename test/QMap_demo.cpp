#include "common.h"
#include <qmap.h>
#include <qdebug.h>

void QMap_demo()
{
    int a = 1;
    int b;
    b = a++;

    QMap<qint64, QString> m;
    m.insert(1572591038100, "three");
    m.insert(1572591038101, "one");
    m.insert(1572591038102, "five");
    m.insert(1572591038103, "two");
    m.insert(1572591038104, "four");

    for (QMap<qint64, QString>::ConstIterator it = m.cbegin(); it != m.cend(); ++it)
    {
        qDebug() << it.key() << ", " << it.value();
    }

    //QVariantMap m2;
    //m2["1572591038102"] = "five";
    //m2["1572591038101"] = "one";
    //m2["1572591038104"] = "four";
    //m2["1572591038100"] = "three";
    //m2["1572591038103"] = "two";

    qDebug() << "---------------------------------------";
    
    QMapIterator<qint64, QString> it(m);
    while (it.hasNext())
    {
        it.next();
        if (it.key() == 1572591038100)
        {
            m.remove(it.key());
        }
    }

    for (QMap<qint64, QString>::ConstIterator it = m.cbegin(); it != m.cend(); ++it)
    {
        qDebug() << it.key() << ", " << it.value();
    }
}