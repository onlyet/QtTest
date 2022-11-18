#pragma once

#include <QObject>

class CLoop : public QObject
{
    Q_OBJECT

public:
    CLoop(QObject *parent = nullptr);
    ~CLoop();
};
