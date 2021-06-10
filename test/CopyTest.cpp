#include "CopyTest.h"
#include <QDebug>
#include <QThread>
#include <QTimer>


#define CaseNum   4
#define EnableQueuedConnection 

CCopyable::CCopyable()
{
}

CCopyable::CCopyable(int id, const QString &name)
    : m_id(id)
    , m_name(name)
{
}

CCopyable::~CCopyable()
{
}

CCopyable::CCopyable(const CCopyable &rhs)
{
    qDebug() << "copy construct";
    m_id = rhs.m_id;
    m_name = rhs.m_name;
}

CCopyable& CCopyable::operator=(const CCopyable &rhs)
{
    qDebug() << "assign";
    if (this == &rhs)
    {
        return *this;
    }
    m_id = rhs.m_id;
    m_name = rhs.m_name;
    return *this;
}

CSender::CSender(QObject *parent)
    : QObject(parent)
{
}

CReceiver::CReceiver(QObject * parent)
    : QObject(parent)
{
    QThread *t = new QThread;
    moveToThread(t);
    t->start();
}

void CReceiver::receiveConstRef(const CCopyable &c)
{
    qDebug() << "receiveConstRef";
}

void CReceiver::receiveValue(CCopyable c)
{
    qDebug() << "receiveValue";
}

void signalSlotCopyTest()
{
    CSender *sender = new CSender;
    CReceiver* receiver = new CReceiver;

#ifdef EnableQueuedConnection
    qRegisterMetaType<CCopyable>("CCopyable");
    Qt::ConnectionType ctype = Qt::QueuedConnection;
#else
    Qt::ConnectionType ctype = Qt::DirectConnection;
#endif // EnableQueuedConnection

    switch (CaseNum)
    {
    case 1:
        QObject::connect(sender, &CSender::sendConstRef, receiver, &CReceiver::receiveConstRef, ctype);
        break;
    case 2:
        QObject::connect(sender, &CSender::sendValue, receiver, &CReceiver::receiveConstRef, ctype);
        break;
    case 3:
        QObject::connect(sender, &CSender::sendConstRef, receiver, &CReceiver::receiveValue, ctype);
        break;
    case 4:
        QObject::connect(sender, &CSender::sendValue, receiver, &CReceiver::receiveValue, ctype);
        break;
    default:
        break;
    }

    QTimer::singleShot(1000, [sender]() {
        sender->sendSignal();
    });
}

void CSender::sendSignal()
{
    CCopyable copyable(1,"momo");

    switch (CaseNum)
    {
    case 1:
        emit sendConstRef(copyable);
        break;
    case 2:
        emit sendValue(copyable);
        break;
    case 3:
        emit sendConstRef(copyable);
        break;
    case 4:
        emit sendValue(copyable);
        break;
    default:
        break;
    }
}
