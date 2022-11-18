#include "common.h"
#include <qSTRING>
#include <qprocess.h>

QString getWMIC(const QString &cmd)
{
    //获取cpu名称：wmic cpu get Name
    //获取cpu核心数：wmic cpu get NumberOfCores
    //获取cpu线程数：wmic cpu get NumberOfLogicalProcessors
    //查询cpu序列号：wmic cpu get processorid
    //查询主板序列号：wmic baseboard get serialnumber
    //查询BIOS序列号：wmic bios get serialnumber
    //查看硬盘：wmic diskdrive get serialnumber
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