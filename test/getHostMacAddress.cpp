//#include "common.h"
//#include <QNetworkInterface>
//#include <QList>
//#include <QDebug>
//
//QString getHostMacAddress_()
//{
//    QList<QNetworkInterface> nets = QNetworkInterface::allInterfaces();// ��ȡ��������ӿ��б�
//    int nCnt = nets.count();
//    QString strMacAddr = "";
//    for (int i = 0; i < nCnt; i++)
//    {
//        // ���������ӿڱ�������������в��Ҳ��ǻػ���ַ�������������Ҫ�ҵ�Mac��ַ
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