/********************************************************************************
** Form generated from reading UI file 'QtGuiClass.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUICLASS_H
#define UI_QTGUICLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NameWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_name;
    QLabel *label;
    QLabel *colorLabel;
    QLabel *stateLabel;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *subjectBtn;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *NameWidget)
    {
        if (NameWidget->objectName().isEmpty())
            NameWidget->setObjectName(QString::fromUtf8("NameWidget"));
        NameWidget->resize(218, 22);
        horizontalLayout = new QHBoxLayout(NameWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        frame_4 = new QFrame(NameWidget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setMinimumSize(QSize(218, 0));
        frame_4->setMaximumSize(QSize(218, 16777215));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_4);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(5, 0, 0, 0);
        label_name = new QLabel(frame_4);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setStyleSheet(QString::fromUtf8("QLabel{color:#357BEC}"));

        horizontalLayout_2->addWidget(label_name);

        label = new QLabel(frame_4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(10, 0));
        label->setMaximumSize(QSize(16777215, 16777215));
        label->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"font-family:Microsoft YaHei;\n"
"font-weight:bold;\n"
"color:rgba(153,153,153,1);\n"
"line-height:20px;"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label);

        colorLabel = new QLabel(frame_4);
        colorLabel->setObjectName(QString::fromUtf8("colorLabel"));
        colorLabel->setMinimumSize(QSize(10, 10));
        colorLabel->setMaximumSize(QSize(10, 10));
        colorLabel->setStyleSheet(QString::fromUtf8("border-image: url(:/gray_ellipse.png);"));

        horizontalLayout_2->addWidget(colorLabel);

        stateLabel = new QLabel(frame_4);
        stateLabel->setObjectName(QString::fromUtf8("stateLabel"));
        stateLabel->setStyleSheet(QString::fromUtf8("width:78px;\n"
"height:15px;\n"
"font-size:14px;\n"
"font-family:Microsoft YaHei;\n"
"font-weight:bold;\n"
"color:rgba(153,153,153,1);\n"
"line-height:20px;"));

        horizontalLayout_2->addWidget(stateLabel);

        label_4 = new QLabel(frame_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(10, 0));
        label_4->setMaximumSize(QSize(10, 16777215));
        label_4->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"font-family:Microsoft YaHei;\n"
"font-weight:bold;\n"
"color:rgba(153,153,153,1);\n"
"line-height:20px;"));

        horizontalLayout_2->addWidget(label_4);

        horizontalSpacer_2 = new QSpacerItem(5, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        subjectBtn = new QPushButton(frame_4);
        subjectBtn->setObjectName(QString::fromUtf8("subjectBtn"));
        subjectBtn->setMinimumSize(QSize(12, 14));
        subjectBtn->setMaximumSize(QSize(12, 14));
        subjectBtn->setStyleSheet(QString::fromUtf8("border-image: url(:/subject_blue.png);"));

        horizontalLayout_2->addWidget(subjectBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        horizontalLayout->addWidget(frame_4);


        retranslateUi(NameWidget);

        QMetaObject::connectSlotsByName(NameWidget);
    } // setupUi

    void retranslateUi(QWidget *NameWidget)
    {
        NameWidget->setWindowTitle(QCoreApplication::translate("NameWidget", "Form", nullptr));
        label_name->setText(QCoreApplication::translate("NameWidget", "\345\247\223\345\220\215\357\274\232\345\274\240\344\270\211", nullptr));
        label->setText(QCoreApplication::translate("NameWidget", "  ( ", nullptr));
        colorLabel->setText(QString());
        stateLabel->setText(QCoreApplication::translate("NameWidget", " \346\234\252\350\277\236\346\216\245", nullptr));
        label_4->setText(QCoreApplication::translate("NameWidget", " ) ", nullptr));
        subjectBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class NameWidget: public Ui_NameWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUICLASS_H
