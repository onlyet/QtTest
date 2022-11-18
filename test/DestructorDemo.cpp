#include "DestructorDemo.h"
#include <QDebug>

Parent::Parent(QObject *parent)
    : QObject(parent)
{
    qDebug() << "Parent ctor";
}

Parent::~Parent()
{
    qDebug() << "Parent dtor";
}

Son::Son(QObject *parent)
    : Parent(parent)
{
    qDebug() << "Son ctor";
}

Son::~Son()
{
    qDebug() << "Son dtor";
}

void destructorDemo()
{
    Son *son = new Son;
    delete son;
}
