#pragma once
#include <QObject>

class Counter : public QObject
{
    Q_OBJECT
        int m_value;
public:
    int value() const { return m_value; }
    public slots :
        void setValue(int value);
signals:
    void valueChanged(int newValue);
};