#pragma once
#include <QObject>

class Counter : public QObject
{
    Q_OBJECT
public:
    int value() const { return m_value; }

signals:
    void valueChanged(int newValue);
    void display();

    public slots :
    void setValue(int value);

private:
    int m_value;
};