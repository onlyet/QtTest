#include "common.h"
#include <qpushbutton.h>
#include <qmenu.h>
#include <qaction.h>

void QMenu_demo()
{
    QPushButton *mybtn = new QPushButton(QStringLiteral("����һ����ť"));
    QMenu *mymenu = new QMenu;
    QAction *click = new QAction(QStringLiteral("�½��ʼ�"));
    QAction *click2 = new QAction(QStringLiteral("�½��ļ���"));
    mymenu->addAction(click);
    mymenu->addAction(click2);

    mymenu->exec(QCursor::pos());

    mybtn->setMenu(mymenu);
    //QHBoxLayout *mainLayout = new QHBoxLayout(this);
    //mainLayout->addWidget(mybtn);
    mybtn->show();
}