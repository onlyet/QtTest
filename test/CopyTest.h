#pragma once

#include <QObject>

class CCopyable
{
public:
    // qRegisterMetaType的类需要默认构造函数
    CCopyable();
    CCopyable(int id, const QString &name);
    CCopyable(const CCopyable &rhs);
    ~CCopyable();
    CCopyable &operator=(const CCopyable &rhs);

private:
    int m_id;
    QString m_name;
};

class CSender : public QObject
{
    Q_OBJECT
public:
    CSender(QObject *parent = nullptr);
    ~CSender() {}

    void sendSignal();

signals:
    void sendConstRef(const CCopyable &c);
    void sendValue(CCopyable c);

    void testSig(QString);
    void testSig(QString, int);
    //void testSig(const QString&);
};

class CReceiver : public QObject
{
    Q_OBJECT
public:
    CReceiver(QObject *parent = nullptr);
    ~CReceiver() {}

public slots:
    void receiveConstRef(const CCopyable &c);
    void receiveValue(CCopyable c);
};


void signalSlotCopyTest();