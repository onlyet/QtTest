#include "common.h"
#include <QCoreApplication>
#include <QStorageInfo>
#include <QDebug>

void QStorageInfoDemo()
{
    //QList<QStorageInfo> list = QStorageInfo::mountedVolumes();
    //qDebug() << "Volume Num: " << list.size();
    //for (QStorageInfo& si : list)
    //{
    //    qDebug() << "Name: " << si.name();
    //    qDebug() << "Block Size: " << si.blockSize();
    //    qDebug() << "Bytes Avaliable: " << si.bytesAvailable();
    //    qDebug() << "Bytes Free: " << si.bytesFree();
    //    qDebug() << "Bytes Total: " << si.bytesTotal();
    //    qDebug() << "Display Name: " << si.displayName();
    //    qDebug() << "File System Type: " << si.fileSystemType();
    //    qDebug() << "Is ReadOnly: " << si.isReadOnly();
    //    qDebug() << "Is Root: " << si.isRoot();
    //}

    //qDebug() << QStorageInfo::root().device();

    QStorageInfo si;
    //si.setPath("C:/Users/Admin/Desktop/record");
    si.setPath("D:/QtProject");

    qDebug() << "Name: " << si.name();
    qDebug() << "Block Size: " << si.blockSize();
    qDebug() << "Bytes Avaliable: " << si.bytesAvailable();
    qDebug() << "Bytes Free: " << si.bytesFree();
    qDebug() << "Bytes Total: " << si.bytesTotal();
    qDebug() << "Display Name: " << si.displayName();
    qDebug() << "File System Type: " << si.fileSystemType();
    qDebug() << "Is ReadOnly: " << si.isReadOnly();
    qDebug() << "Is Root: " << si.isRoot();
}