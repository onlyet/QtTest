#include "common.h"
#include <qpushbutton.h>
#include <qmenu.h>
#include <qaction.h>

void QMenu_demo()
{
    QPushButton *mybtn = new QPushButton(QStringLiteral("这是一个按钮"));
    QMenu *mymenu = new QMenu;
    QAction *click = new QAction(QStringLiteral("新建笔记"));
    QAction *click2 = new QAction(QStringLiteral("新建文件夹"));
    mymenu->addAction(click);
    mymenu->addAction(click2);

    mymenu->exec(QCursor::pos());

    mybtn->setMenu(mymenu);
    //QHBoxLayout *mainLayout = new QHBoxLayout(this);
    //mainLayout->addWidget(mybtn);
    mybtn->show();
}