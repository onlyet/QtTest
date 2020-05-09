#include "NameWidget.h"
#include "ui_NameWidget.h"
#include <QMouseEvent>

NameWidget::NameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NameWidget)
{
    ui->setupUi(this);
}

NameWidget::~NameWidget()
{
    delete ui;
}

void NameWidget::setName(const QString &name)
{
    ui->label_name->setText(name);
}

void NameWidget::mousePressEvent(QMouseEvent *ev)
{
    m_pos = ev->pos();
}

void NameWidget::mouseReleaseEvent(QMouseEvent *ev)
{
    if(ev->pos() == m_pos)
    {
        emit clicked();
    }
}


void mouseclick_test()
{
	NameWidget* nw = new NameWidget;
	nw->show();
}
