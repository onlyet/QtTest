#include "common.h"
#include <QWidget>
#include <qpushbutton.h>
#include <qgridlayout.h>
#include <qformlayout.h>
#include <qlineedit.h>

void QGridLayout_demo()
{
	QWidget* widget = new QWidget;
	QPushButton* btn = new QPushButton("one");
	QPushButton* btn2 = new QPushButton("two");
	QPushButton* btn3 = new QPushButton("three");
	QPushButton* btn4 = new QPushButton("four");
	QPushButton* btn5 = new QPushButton("five");
	btn->setFixedSize(100, 100);
	btn2->setFixedSize(100, 100);
	btn3->setFixedSize(100, 200);
	btn4->setFixedSize(100, 100);
	btn5->setFixedSize(200, 100);

	QGridLayout* layout = new QGridLayout;
	layout->addWidget(btn, 0, 0, 1, 1);
	layout->addWidget(btn2, 0, 1, 1, 1);
	layout->addWidget(btn3, 1, 0, 2, 1);
	layout->addWidget(btn4, 1, 1, 1, 1);
	layout->addWidget(btn5, 3, 0, 1, 2);

	widget->setLayout(layout);
	widget->show();
}

void QFormLayout_demo()
{
	QWidget *window = new QWidget;
	QPushButton *button1 = new QPushButton("One");
	QLineEdit *lineEdit1 = new QLineEdit();
	QPushButton *button2 = new QPushButton("Two");
	QLineEdit *lineEdit2 = new QLineEdit();
	QPushButton *button3 = new QPushButton("Three");
	QLineEdit *lineEdit3 = new QLineEdit();

	QFormLayout *layout = new QFormLayout;
	//layout->addRow(button1, lineEdit1);
	//layout->addRow(button2, lineEdit2);
	//layout->addRow(button3, lineEdit3);
	layout->addRow("aaa", lineEdit1);
	layout->addRow("aaa", lineEdit2);
	layout->addRow("aaa", lineEdit3);

	window->setLayout(layout);
	window->show();
}