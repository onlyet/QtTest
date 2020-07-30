#pragma once

#include <QObject>

class TestWorker : public QObject
{
    Q_OBJECT

public:
    TestWorker(QObject *parent = nullptr);
    ~TestWorker();

signals:
    void finished();

public slots:
    void process();
    void stop();

private:
    bool m_stopped = false;
};
