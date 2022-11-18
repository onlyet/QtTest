#pragma once
#include <QObject>

class A : public QObject
{
    Q_OBJECT
signals:
    void sig(/*int a*/);
};

