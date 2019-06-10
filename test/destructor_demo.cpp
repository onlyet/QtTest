#include "common.h"
#include <QWidget>
#include <QLabel>
#include <QDebug>

#include <vector>

using namespace std;

class MyWidget : public QWidget {
public:
    MyWidget(QWidget* parent = Q_NULLPTR) {
        qDebug() << "MyWidget()";
    }
    ~MyWidget() {
        qDebug() << "~MyWidget()";
    }
};

class MyLabel : public QLabel {
public:
    MyLabel(QWidget* parent = Q_NULLPTR) {
        qDebug() << "MyLabel()";
    }
    ~MyLabel() {
        qDebug() << "~MyLabel()";
    }
};

//void destructor_demo()
//{
//    QLabel label("Hello Qt!");
//    QWidget w;
//    label.setParent(&w);
//    w.show();
//}

void destructor_demo_2()
{
    QLabel* label = new QLabel("Hello Qt!");
    QWidget w;
    label->setParent(&w);
    w.show();
}

//void destructor_demo_3()
//{
//    MyLabel l;
//    {
//        MyWidget w;
//        l.setParent(&w);
//        w.show();
//    }
//    qDebug() << "line_________________________________________end";
//}

void destructor_demo_3()
{
    {
        MyLabel* l = new MyLabel;
        {
            MyWidget w;
            l->setParent(&w);
            w.show();
        }
        qDebug() << "line_________________________________________end";
    }
}

void destructor_demo_4()
{
    {
        MyWidget w;
        MyLabel l(&w);
        qDebug() << "line_________________________________________end";
    }
}

