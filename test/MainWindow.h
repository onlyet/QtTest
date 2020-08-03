#pragma once

#include <QObject>

class MainWindow : public QObject
{
    Q_OBJECT

public:
    MainWindow(QObject *parent = nullptr);
    ~MainWindow();

signals:
    void stopTestWorker();
};
