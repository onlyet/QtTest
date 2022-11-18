#ifndef UICHINACITY_H
#define UICHINACITY_H

#include <QObject>
#include <QMap>
class UIChinaCity : public QObject
{
    Q_OBJECT

public:
    UIChinaCity(QObject *parent = nullptr);
    ~UIChinaCity();

    struct CityInfo
    {
        QString cityName;                   // ��������
        QList<QString> regionName;          // �����µ���������
    };

    // ��ȡ���е�ʡ��
    QList<QString> getProvinceName(void);
    // ��ȡĳ��ʡ�µ����еĳ���
    QList<QString> getCitysName(QString);
    // ��ȡĳ��ʡ�µ�ĳ�����µ����е���
    QList<QString> getRegionsName(QString, QString);

private:
    // ���������б�
    void disposeCityList(void);

    QMap<QString, QList<CityInfo>> m_ChinaCityInfo;
};

#endif
