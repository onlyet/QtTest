#include "common.h"

#include <QtCore/QTextCodec>
#include <QTreeWidget>
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>

void QTreeWidget_demo()
{
    {
        QTreeWidgetItem* item = new QTreeWidgetItem;
        item->setData(0, Qt::UserRole, QStringLiteral("����˭"));
        QString name = item->data(0, Qt::UserRole).toString();
    }

    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("gb18030"));
    QTreeWidget *tree = new QTreeWidget;
    tree->setColumnCount(1);
    //QStringList headers;
    //headers << QStringLiteral("��Ŀ") << QStringLiteral("����");
    //tree->setHeaderLabels(headers);
    tree->setHeaderHidden(true);
    //tree->setRootIsDecorated(false);


    QStringList zhangsan;
    zhangsan << QStringLiteral("�ҵıʼ�");
    QTreeWidgetItem *zhangsanroot = new QTreeWidgetItem(tree, zhangsan);
    //zhangsanroot->set
    //tree->setItemWidget()
    zhangsanroot->setIcon(0, QIcon("C:\\dev\\test\\QtTest\\test\\resource\\myNote2x.png"));
    //zhangsanroot->
    //zhangsanroot->setTextAlignment(0, Qt::AlignCenter);
    //zhangsanroot->



    QStringList lisi;
    lisi << QStringLiteral("�����ʼ�");
    QTreeWidgetItem *lisiroot = new QTreeWidgetItem(tree, lisi);

    QStringList classNote;
    classNote << QStringLiteral("���ñʼ�");
    QTreeWidgetItem *classNoteItem = new QTreeWidgetItem(tree, classNote);

    tree->addTopLevelItem(zhangsanroot);
    tree->addTopLevelItem(lisiroot);
    tree->addTopLevelItem(classNoteItem);

    //QStringList zhangsanChinese;
    //zhangsanChinese << QStringLiteral("��ѧ�ʼ�");
    //QTreeWidgetItem *leaf1 = new QTreeWidgetItem(zhangsanroot, zhangsanChinese);

    //zhangsanroot->addChild(leaf1);
    //QStringList zhangsanMath;
    //zhangsanMath << QStringLiteral("��ʽ��¼");
    //QTreeWidgetItem *leaf2 = new QTreeWidgetItem(zhangsanroot, zhangsanMath);
    //zhangsanroot->addChild(leaf2);

    //QStringList lisiChinese;
    //lisiChinese << QStringLiteral("����");
    //leaf1 = new QTreeWidgetItem(lisiroot, lisiChinese);
    //lisiroot->addChild(leaf1);
    //QStringList lisiMath;
    //lisiMath << QStringLiteral("��ѧ");
    //leaf2 = new QTreeWidgetItem(lisiroot, lisiMath);
    //lisiroot->addChild(leaf2);


    QHBoxLayout *mainlayout = new QHBoxLayout;
    mainlayout->addWidget(tree);
    QWidget *widget = new QWidget;
    widget->setLayout(mainlayout);
    widget->setWindowTitle(QStringLiteral("QTreeWidget Demo"));
    widget->show();

    //QPushButton* btn = new QPushButton(QIcon("C:\\dev\\test\\QtTest\\test\\resource\\disconnect2x.png"), QStringLiteral("������д��"));
    //btn->show();
}