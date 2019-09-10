#pragma once
#include <QObject>
#include <QDebug>

class Worker : public QObject 
{
    Q_OBJECT
public:
    Worker() {}
    ~Worker();

signals:
    void finished();
    void error(QString err);

    public slots:
    void process() {}
    void emitAfterMainExecResult() { qDebug() << "emitAfterMainExec triggered!"; }

private:
    // add your variables here
};

class Boss : public QObject
{
    Q_OBJECT
public:
    Boss();
    ~Boss();

    void init();

signals:
    void emitAfterMainExec();


    public slots:
    void errorString(QString) {}
};