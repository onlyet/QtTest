#include "common.h"
#include <qapplication.h>
#include <qstring.h>
#include <qdir.h>

#include <client/windows/sender/crash_report_sender.h>
#include <exception_handler.h>

#include "Dump.h"


bool dumpProcessor(const wchar_t* path,
    const wchar_t* minidumpID,
    void* context,
    EXCEPTION_POINTERS* exinfo,
    MDRawAssertionInfo* assertion,
    bool succeeded)
{

#ifdef _WIN32
    MessageBox(NULL, TEXT("AI�����ˣ�����ϵ����֧����Ա"), TEXT("������ʾ"), 0);
#endif // _WIN32

    return succeeded;
}

void google_breakpad_test()
{
//    // ע���쳣������
////QString dumpDir = BaseUtil::modulePath() + "/dumps/";
//    QString dumpDir = QApplication::applicationDirPath();
//    QDir dir(dumpDir);
//    if (!dir.exists())
//    {
//        if (!dir.mkpath(dumpDir))
//        {
//            //Toast::showMessage(qstr("�����쳣����ģ��ʧ��: �޷������洢Ŀ¼"), nullptr, 2000);
//        }
//    }
//    google_breakpad::ExceptionHandler *crashHandler =
//        new google_breakpad::ExceptionHandler(dumpDir.toStdWString(),
//            NULL,
//            dumpProcessor,
//            NULL,
//            google_breakpad::ExceptionHandler::HandlerType::HANDLER_ALL);
//    if (nullptr == crashHandler)
//    {
//        //Toast::showMessage(qstr("�����쳣����ģ��ʧ��!"), nullptr, 2000);
//        int i = 1;
//
//    }
//
//    int *p = nullptr;
    //*p = 3;

    DumpInit();

    RaiseException(0xc0000374, 0, 0, NULL);
}