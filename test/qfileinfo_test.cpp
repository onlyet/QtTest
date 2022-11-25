#include "common.h"

#include <qfileinfo.h>
#include <qdebug>

void qfileinfo_test() {
    QFileInfo      frontInfo("E:/record/pcbt/test.flv");
    double frontSize = frontInfo.size() / (double)1048576;
    QString front = QString::number(frontSize, 'f', 2);
    QString front2 = QString::number(frontSize, 'e', 2);
    QString front3 = QString::number(frontSize, 'g', 2);
    qDebug() << "video size:" << front;
}