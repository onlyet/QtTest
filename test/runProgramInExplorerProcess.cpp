#include "common.h"
#include <QProcess>
#include <QDir>
#include <QApplication>

void runProgramInExplorerProcess()
{
    QProcess* pProcess = new QProcess;
    QStringList args;
    //args << "C:\Windows\System32\WindowsPowerShell\v1.0";

    //pProcess->startDetached("explorer", args);
    //pProcess->startDetached("C:\Windows\System32\WindowsPowerShell\v1.0\powershell.exe");
    //pProcess->startDetached("C:\Software\Git\git-bash.exe");

    //args << "C:\\Software\\Git\\git-bash.exe";
    QString s = "D:/dev/loadDll/Win32/Debug/loadDll.exe";
    args << QDir::toNativeSeparators(s);
    //QString path = QCoreApplication::applicationDirPath() + "/CoursewareDetector.exe";
    //QString tmp = QDir::toNativeSeparators(path);

    pProcess->startDetached("explorer", args);
    //pProcess->startDetached("D:\\dev\\loadDll\\Win32\\Debug\\loadDll.exe");

}