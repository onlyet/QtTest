#include "UIChinaCity.h"
#include <QDomDocument>
#include <QDomElement>
#include <QFile>
#include <qdebug.h>

void outputCitys()
{
    UIChinaCity c;
}

UIChinaCity::UIChinaCity(QObject *parent)
    :QObject(parent)
{
    disposeCityList();

    QStringList provinceList = getProvinceName();
    QStringList cityList = getCitysName(QStringLiteral("广东"));
    QStringList regionsList = getRegionsName(QStringLiteral("广东"), QStringLiteral("广州"));

}

UIChinaCity::~UIChinaCity()
{

}

void UIChinaCity::disposeCityList(void)
{
    QFile file(":/LocList.xml");
    if (!file.open(QFile::ReadOnly))
        return;

    QDomDocument doc;
    if (!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();

    QString docStr = doc.toString();

    QDomElement rootElement = doc.documentElement();

    //{
    //    QDomNode n = rootElement.firstChild();
    //    while (!n.isNull()) {
    //        QDomElement e = n.toElement(); // try to convert the node to an element.
    //        if (!e.isNull()) {
    //            qDebug() << qPrintable(e.tagName()); // the node really is an element.
    //        }
    //        n = n.nextSibling();
    //    }

    //}


    QString tag = rootElement.tagName();
    if (rootElement.tagName() != "Location")
        return;

    QDomElement chinaElement;
    QDomNodeList nodeLsit = rootElement.childNodes();
    for (int i = 0; i < nodeLsit.count(); ++i)
    {
        QDomElement element = nodeLsit.at(i).toElement();
        qDebug() << element.attribute("Name");
        if (element.attribute("Name") == QStringLiteral("中国"))
        {
            chinaElement = element;
            break;
        }
    }

    if (chinaElement.isNull())
        return;

    QDomNodeList chinaNodeList = chinaElement.childNodes();
    for (int i = 0; i < chinaNodeList.count(); ++i)
    {
        // 解析省/直辖市
        QDomElement element = chinaNodeList.at(i).toElement();
        QString stateName = element.attribute("Name");
        QList<CityInfo> cityInfoList;
        cityInfoList.clear();

        // 解析城市
        QDomNodeList cityNodeList = element.childNodes();
        for (int j = 0; j < cityNodeList.count(); ++j)
        {
            QDomElement cityElement = cityNodeList.at(j).toElement();
            QString cityName = cityElement.attribute("Name");

            CityInfo cityInfo;
            cityInfo.cityName = cityName;
            QList<QString> regionNameList;
            regionNameList.clear();

            // 解析区
            QDomNodeList regionNodeList = cityElement.childNodes();
            for (int k = 0; k < regionNodeList.count(); ++k)
            {
                QDomElement regionElement = regionNodeList.at(k).toElement();

                QString regionName = regionElement.attribute("Name");
                regionNameList.push_back(regionName);
            }

            cityInfo.regionName = regionNameList;
            cityInfoList.push_back(cityInfo);
        }

        m_ChinaCityInfo.insert(stateName, cityInfoList);
    }
}

QList<QString> UIChinaCity::getProvinceName(void)
{
    QList<QString> provinceNameList;
    provinceNameList.clear();
    for (auto itor = m_ChinaCityInfo.begin(); itor != m_ChinaCityInfo.end(); ++itor)
    {
        provinceNameList.push_back(itor.key());
    }
    return provinceNameList;
}

QList<QString> UIChinaCity::getCitysName(QString name)
{
    auto itor = m_ChinaCityInfo.find(name);
    if (itor == m_ChinaCityInfo.end())
    {
        return QStringList();
    }
    QList<CityInfo> cityList = itor.value();
    QList<QString> cityNameList;
    cityNameList.clear();
    for (int i = 0; i < cityList.count(); ++i)
    {
        cityNameList.push_back(cityList.at(i).cityName);
    }

    return cityNameList;
}

QList<QString> UIChinaCity::getRegionsName(QString stateName, QString cityName)
{
    auto itor = m_ChinaCityInfo.find(stateName);
    if (itor == m_ChinaCityInfo.end())
    {
        return QStringList();
    }
    QList<CityInfo> cityList = itor.value();
    QList<QString> regionNameList;
    regionNameList.clear();
    for (int i = 0; i < cityList.count(); ++i)
    {
        if (cityList.at(i).cityName == cityName)
            return cityList.at(i).regionName;
    }

    return regionNameList;
}
