#include "common.h"
#include <qSTRING>
#include <qprocess.h>

QString getWMIC(const QString &cmd)
{
    //��ȡcpu���ƣ�wmic cpu get Name
    //��ȡcpu��������wmic cpu get NumberOfCores
    //��ȡcpu�߳�����wmic cpu get NumberOfLogicalProcessors
    //��ѯcpu���кţ�wmic cpu get processorid
    //��ѯ�������кţ�wmic baseboard get serialnumber
    //��ѯBIOS���кţ�wmic bios get serialnumber
    //�鿴Ӳ�̣�wmic diskdrive get serialnumber
    QProcess p;
    p.start(cmd);
    bool success = p.waitForFinished();
    if (!success)
    {
        return QString();
    }
    QString result = QString::fromLocal8Bit(p.readAllStandardOutput());
    QStringList list = cmd.split(" ");
    result = result.remove(list.last(), Qt::CaseInsensitive);
    result = result.replace("\r", "");
    result = result.replace("\n", "");
    result = result.simplified();
    return result;
}

//QString getCpuName()
//{
//    return getWMIC("wmic cpu get name");
//}
//
//QString getCpuId()
//{
//    return getWMIC("wmic cpu get processorid");
//}
//
//QString getDiskNum()
//{
//    return getWMIC("wmic diskdrive where index=0 get serialnumber");
//}
//
//QString getDiskNum()
//{
//    return getWMIC("wmic diskdrive where index=0 get serialnumber");
//}

void wmic_demo()
{
    QString s = getWMIC("wmic baseboard get serialnumber");
}