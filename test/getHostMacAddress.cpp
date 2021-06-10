//#include "common.h"
//#include <QNetworkInterface>
//#include <QList>
//#include <QDebug>
//
//QString getHostMacAddress_()
//{
//    QList<QNetworkInterface> nets = QNetworkInterface::allInterfaces();// 获取所有网络接口列表
//    int nCnt = nets.count();
//    QString strMacAddr = "";
//    for (int i = 0; i < nCnt; i++)
//    {
//        // 如果此网络接口被激活并且正在运行并且不是回环地址，则就是我们需要找的Mac地址
//        if (nets[i].flags().testFlag(QNetworkInterface::IsUp) && 
//            nets[i].flags().testFlag(QNetworkInterface::IsRunning) && 
//            !nets[i].flags().testFlag(QNetworkInterface::IsLoopBack) &&
//            nets[i].type() == QNetworkInterface::Ethernet)
//        {
//            strMacAddr = nets[i].hardwareAddress();
//            break;
//        }
//    }
//    return strMacAddr;
//}
//
//void getHostMacAddress()
//{
//    QString mac = getHostMacAddress_();
//}