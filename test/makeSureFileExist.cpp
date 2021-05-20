#include "common.h"
#include <qfileinfo.h>
#include <qdir.h>

void makeSureFileExist()
{
    QString filepath = "D:/Video/tt/tt.txt";
    QFileInfo finfo(filepath);
    QString suffix = finfo.completeSuffix();
    QString name = finfo.baseName();
    QString path = finfo.absolutePath();
    QDir dir;
    bool b = dir.mkpath(path);
}