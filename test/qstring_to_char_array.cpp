#include "common.h"
#include <vector>
#include <QString>
#include <QDebug>
#include <iostream>

using namespace std;


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
//    unsigned char macAddress[7] = { 0xD2, 0x24, 0x3F, 0x69, 0xA8, 0xE2, 0x00};
//    QString m_mac = QString::fromLocal8Bit((char*)macAddress);
//    char* mac = m_mac.toLocal8Bit().data();
//    char buf[1024] = { 1024 };
//    sprintf_s(buf, 1024, "mac %2X %02X %02X %02X %02X %02X \r\n", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
//
//}

void fromLocal8Bit_demo()
{
    unsigned char macAddress[7] = { 0x11, 0x24, 0x3F, 0x69, 0xA8, 0xE2, 0x00 };
    QString m_mac = QString::fromLocal8Bit((char*)macAddress);
    char* mac = m_mac.toLocal8Bit().data();
    char buf[1024] = { 0 };
    sprintf_s(buf, 1024, "mac %2X %02X %02X %02X %02X %02X \r\n", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);

}

//void fromLocal8Bit_demo()
//{
//    unsigned char macAddress[7] = { 0xD2, 0x24, 0x3F, 0x69, 0xA8, 0xE2, 0};
//    QString s = getStringFromUnsignedChar(macAddress);
//    char* c = s.toLocal8Bit().data();
//}

unsigned char* hexQstringToUnsignedCharArray(const QString& str)
{
    int len = str.size();
    if (len != 12)
        return nullptr;

    unsigned char* arr = new unsigned char[6];
    for (int i = 0; i < 6; ++i)
    {
        QString hexString = str.mid(i * 2, 2);
        bool ok = false;
        arr[i] = (unsigned char)hexString.toUShort(&ok, 16);
        if (!ok)
        {
            qDebug() << "convert failed";
            delete[] arr;
            return nullptr;
        }
    }
    return arr;
}


void hexQstringToUnsignedCharArray(const QString& strMac, QVector<unsigned char>& vecMac)
{
    for (int i = 0; i < strMac.size(); i += 2)
    {
        QString num = strMac.mid(i, 2);
        bool ok = false;
        vecMac.push_back(num.toUInt(&ok, 16));
        if (!ok)
        {
            qDebug() << "convert failed";
            vecMac.clear();
            return;
        }
    }
}

bool hexQstringToCharArray(const QString& strMac, QVector<char>& vecMac)
{
    if (strMac.size() != 12)
    {
        qDebug() << "mac format incorrect";
        return false;
    }
    for (int i = 0; i < strMac.size(); i += 2)
    {
        QString num = strMac.mid(i, 2);
        bool ok = false;
        vecMac.push_back(num.toInt(&ok, 16));
        if (!ok)
        {
            qDebug() << "convert failed";
            vecMac.clear();
            return false;
        }
    }
    return true;
}

//void qstringToUnsignedCharArray()
//{
//    //QString strMac = "D2243F69A8E2";
//    QString strMac = "F3C8EDF6C048";
//   
//    qDebug() << "origin mac: " << strMac;
//    unsigned char* mac = hexQstringToUnsignedCharArray(strMac);
//    if (mac)
//    {
//        char buf[1024] = { 1024 };
//        sprintf_s(buf, 1024, "%02X %02X %02X %02X %02X %02X", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
//        qDebug() << "transfered mac: " << buf;
//        delete[] mac;
//    }
//}

char* stringToCharArray(const QString &mac)
{
    char* macChar = new char[4];
    QStringList strs = mac.split("-");
    for (int i = strs.count() - 1; i >= 2; i--)
    {
        bool ok = false;
        macChar[strs.count() - 1 - i] = strs[i].toUInt(&ok, 16);
    }
    return macChar;
}

void qstringToUnsignedCharArray()
{
    {
        QString mac = "AA-BB-CC-DD-EE-FF";
        char* macChar = stringToCharArray(mac);

    }

    //QString strMac = "D2243F69A8E2";
    QString strMac = "F3C8EDF6C048";

    qDebug() << "origin mac: " << strMac;

    QVector<unsigned char> vecMac;
    hexQstringToUnsignedCharArray(strMac, vecMac);
    if (vecMac.size() != 6)
        return;

    const unsigned char* arr = vecMac.data();

    char buf[1024] = { 0 };
    //sprintf_s(buf, 1024, "%02X %02X %02X %02X %02X %02X", vecMac[0], vecMac[1], vecMac[2], vecMac[3], vecMac[4], vecMac[5]);
    sprintf_s(buf, 1024, "%02X %02X %02X %02X %02X %02X", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);
    qDebug() << "transfered mac: " << buf;
}

void qstringToCharArray()
{
    //QString strMac = "D2243F69A8E2";
    QString strMac = "F3C8EDF6C048";

    qDebug() << "origin mac: " << strMac;

    QVector<char> vecMac;
    hexQstringToCharArray(strMac, vecMac);
    if (vecMac.size() != 6)
        return;

    const char* arr = vecMac.data();

    char buf[1024] = { 0 };
    //sprintf_s(buf, 1024, "%02X %02X %02X %02X %02X %02X", vecMac[0], vecMac[1], vecMac[2], vecMac[3], vecMac[4], vecMac[5]);
    sprintf_s(buf, 1024, "%02X %02X %02X %02X %02X %02X", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);
    qDebug() << "transfered mac: " << buf;
}


void vectorDemo()
{
    const char* str = "hello";
    vector<char> v(str, str + strlen(str));
    //const unsigned char* s2 = "hello";
    //vector<unsigned char> v2(s2, s2 + 5);

    //QVector<unsigned char> v3(s2, s2 + 5);
}


bool byteArrayToHexString(const QVector<unsigned char>& vecMac, QString& strMac)
{
    if (vecMac.size() != 6 || !strMac.isEmpty())
    {
        qDebug() << "input parameters incorrect";
        return false;
    }
    foreach(const unsigned char& c, vecMac)
    {
        strMac.append(QString::number(static_cast<unsigned int>(c), 16).toUpper());
    }

    return true;
}

bool byteArrayToHexString(unsigned char* mac, QString& strMac)
{
    if (!strMac.isEmpty())
    {
        qDebug() << "input parameters incorrect";
        return false;
    }
    for (int i = 0; i < 6; ++i)
    {
        strMac.append(QString::number(mac[i], 16).toUpper());
    }

    return true;
}

void byteArrayToHexStringDemo()
{
    QString strMac;
    //F3C8EDF6C048
    //QVector<unsigned char> vecMac = { 0xF3, 0xC8, 0xED, 0xF6, 0xC0, 0x48 };
    //bool ret = byteArrayToHexString(vecMac, strMac);

    unsigned char mac[] = { 0xF3, 0xC8, 0xED, 0xF6, 0xC0, 0x48 };
    bool ret = byteArrayToHexString(mac, strMac);
    if (ret)
    {
        qDebug() << "transfered mac: " << strMac;
    }
}

#define QT_NO_CAST_FROM_ASCII

void QStringToConstCharPointer()
{
    QString path = "D:/gdjy_svn/SmartClass/Code/WisdomClassForPC/Win32/Debug/WisdomClassForPC.exe";
    QByteArray ba = path.toLocal8Bit();
    const char* p = ba.data();

    QByteArray ba2 = path.toLocal8Bit();
    const char* p2 = ba2.data();

    string s = path.toStdString();
    const char* p3 = s.c_str();

    QString chinese = "中国人isgood";
    QByteArray ba4 = chinese.toLocal8Bit();
    const char* p4 = ba4.data();

    QString chinese2 = QStringLiteral("中国人isgood");
    QByteArray ba5 = chinese2.toLocal8Bit();
    const char* p5 = ba5.data();

    qDebug() << "1";
}

unsigned char ch2hex(char ch)
{
    static const char *hex = "0123456789ABCDEF";
    for (unsigned char i = 0; i != 16; ++i)
        if (ch == hex[i])
            return i;
    return 0;
}

string tohex(const string& str)
{
    string ret;
    static const char *hex = "0123456789ABCDEF";
    for (int i = 0; i != str.size(); ++i)
    {
        ret.push_back(hex[(str[i] >> 4) & 0xf]);
        ret.push_back(hex[str[i] & 0xf]);
    }
    return ret;
}

void chineseToHexInteger()
{
    //cout << tohex("中国人") << endl;
    //qDebug() << QString::fromStdString(tohex("中"));
    qDebug() << QString::fromStdString(tohex("别"));
}


// 17位16进制mac字符串转为6位字节数组
// demo: unsigned char* byteArr = hexStringToByteArray(QString("A1-B2-C3-D4-E5-F6")).data();
QVector<unsigned char> hexStringToByteArray(const QString& strMac)
{
    QVector<unsigned char> vecMac;
    unsigned char* p = vecMac.data();
    if (strMac.size() != 17)
    {
        return vecMac;
    }
    for (int i = 0; i < strMac.size(); i += 3)
    {
        QString num = strMac.mid(i, 2);
        bool ok = false;
        vecMac.push_back(num.toUInt(&ok, 16));
        if (!ok)
        {
            return QVector<unsigned char>();
        }
    }
    return vecMac;
}

//6位字节数组转17位16进制QString
QString byteArrayToHexString(unsigned char* str)
{
    QString result = "";
    //int lengthOfString = strlen(reinterpret_cast<const char*>(str));
    int lengthOfString = 6;

    QString s;
    for (int i = 0; i < lengthOfString; ++i)
    {
        s = QString("%1").arg(str[i], 0, 16);

        // account for single-digit hex values (always must serialize as two digits)
        if (s.length() == 1)
            result.append("0");

        result.append(s.toUpper());
        result.append('-');
    }

    //删除最后一个'-'
    result.chop(1);

    return result;
}

void testHexQStringToByteArray()
{
    QString s_font_code = QString("A1-B2-C3-D4-E5-F6");
    QString s_font_code2 = QStringLiteral("填空题");
    QString s_font_code3 = QStringLiteral("判断题");
    //PBYTE font_code = mixCharArray(s_font_code.toLocal8Bit().data());
    //PBYTE font_code2 = mixCharArray(s_font_code2.toLocal8Bit().data());
    //PBYTE font_code3 = mixCharArray(s_font_code3.toLocal8Bit().data());

    QVector<unsigned char> byteArr1 = hexStringToByteArray(s_font_code);
    QVector<unsigned char> byteArr2 = hexStringToByteArray(s_font_code2);
    QVector<unsigned char> byteArr3 = hexStringToByteArray(s_font_code3);

    unsigned char* pByte1 = byteArr1.data();
    unsigned char* pByte2 = byteArr2.data();
    unsigned char* pByte3 = byteArr3.data();

}