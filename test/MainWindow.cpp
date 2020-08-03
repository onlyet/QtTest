#include "MainWindow.h"
#include "TestWorker.h"
#include <QThread>
#include <QTimer>

MainWindow::MainWindow(QObject *parent)
    : QObject(parent)
{
    TestWorker* tw = new TestWorker;
    QThread* t = new QThread;
    tw->moveToThread(t);
    connect(t, &QThread::started, tw, &TestWorker::process);
    connect(this, &MainWindow::stopTestWorker, tw, &TestWorker::stop, Qt::DirectConnection);
    connect(tw, &TestWorker::finished, tw, &TestWorker::deleteLater);
    connect(tw, &TestWorker::finished, t, &QThread::quit);
    connect(t, &QThread::finished, t, &QThread::deleteLater);

    QTimer::singleShot(3000, [this]() {
        emit stopTestWorker();
    });
    t->start();

}

MainWindow::~MainWindow()
{
}


void workerSlot()
{
    MainWindow* w = new MainWindow;
}
