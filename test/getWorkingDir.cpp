#include <qdebug.h>
#include <qdir.h>
#include <qcoreapplication.h>
#include <qtextbrowser.h>

void getWorkingDir()
{
    qDebug() << "cur dir: " << QDir::currentPath();
    qDebug() << "work dir: " << QCoreApplication::applicationDirPath();
    QTextBrowser* tb = new QTextBrowser;
    tb->setFixedSize(400, 400);
    tb->append(QDir::currentPath());
    tb->append(QCoreApplication::applicationDirPath());
    tb->show();
}