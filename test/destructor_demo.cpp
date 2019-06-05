#include "common.h"
#include <QWidget>
#include <QLabel>
#include <QDebug>

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

QString getStringFromUnsignedChar(unsigned char *str) 
{
    QString result = "";
    int lengthOfString = strlen(reinterpret_cast<const char*>(str));

    // print string in reverse order
    QString s;
    for (int i = 0; i < lengthOfString; i++) 
    {
        s = QString("%1").arg(str[i], 0, 16);

        // account for single-digit hex values (always must serialize as two digits)
        if (s.length() == 1)
            result.append("0");

        result.append(s);
    }

    return result;
}

//void fromLocal8Bit_demo()
//{
//    unsigned char macAddress[6] = { 0xD2, 0x24, 0x3F, 0x69, 0xA8, 0xE2 };
//    QString m_mac = QString::fromLocal8Bit((char*)macAddress);
//    char* mac = m_mac.toLocal8Bit().data();
//    char buf[1024] = { 1024 };
//    sprintf_s(buf, 1024, "mac %2X %02X %02X %02X %02X %02X \r\n", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
//
//}

void fromLocal8Bit_demo()
{
    unsigned char macAddress[7] = { 0xD2, 0x24, 0x3F, 0x69, 0xA8, 0xE2, 0};
    QString s = getStringFromUnsignedChar(macAddress);
    char* c = s.toLocal8Bit().data();
}
