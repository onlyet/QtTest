#pragma once

#include <QObject>

class Parent : public QObject
{
    Q_OBJECT

public:
    Parent(QObject *parent = nullptr);
    ~Parent();
};

class Son : public Parent
{
    Q_OBJECT

public:
    Son(QObject *parent = nullptr);
    ~Son();
};

void destructorDemo();
