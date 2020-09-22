#pragma once

#include <QObject>
//#include <QVariant>
#include <QMap>
#include <QString>
#include <atomic>

class QThread;

class IWorker : public QObject
{
    Q_OBJECT

public:
    enum State {
        Stopped = 0,
        Started,
        Paused
    };

    IWorker(QObject *parent = nullptr);
    virtual ~IWorker();

signals:
    void finished();

public slots:
    virtual void process();
    virtual void start();
    virtual void stop();
    virtual void pause();

protected:
    virtual void step1();
    virtual void step2();
    virtual void step3();

private:
    QThread* m_thread;
    std::atomic<int> m_state = Paused;
};

class ReadIpcFrameWorker : public IWorker
{
    Q_OBJECT
public:
    //QVariantMap map;
    //ReadIpcFrameWorker
    ReadIpcFrameWorker(QVariantMap params, QObject *parent = nullptr);
    ~ReadIpcFrameWorker();

public slots:
#if 0
    void process() override;
#endif
    void start() override;

};
