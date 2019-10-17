#include "WCListWidget.h"
#include <QMouseEvent>
#include <QScrollBar>
#include <QPainter>

WCListWidget::WCListWidget(QWidget *parent)
    : QListWidget(parent)
    , m_pressed(false)
{
    setAttribute(Qt::WA_TranslucentBackground);
    setFrameShape(QFrame::NoFrame);
    setViewMode(QListView::IconMode);
    setResizeMode(QListView::Adjust);
    setDragDropMode(QAbstractItemView::NoDragDrop);
    setDefaultDropAction(Qt::IgnoreAction);
    setDragEnabled(false);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    verticalScrollBar()->setSingleStep(30);
    horizontalScrollBar()->setSingleStep(30);
}

void WCListWidget::mousePressEvent(QMouseEvent *ev)
{
    m_pressed = true;
    m_lastPoint = ev->pos();
    QListWidget::mousePressEvent(ev);
}

void WCListWidget::mouseMoveEvent(QMouseEvent *ev)
{
    if (m_pressed)
    {
        int horiDelta = ev->pos().x() - m_lastPoint.x();
        int vertDelta = ev->pos().y() - m_lastPoint.y();
        horizontalScrollBar()->setValue(horizontalScrollBar()->value() - horiDelta);
        verticalScrollBar()->setValue(verticalScrollBar()->value() - vertDelta);

        m_lastPoint = ev->pos();
    }
    QListWidget::mouseMoveEvent(ev);
}

void WCListWidget::mouseReleaseEvent(QMouseEvent *ev)
{
    m_pressed = false;
    QListWidget::mouseReleaseEvent(ev);
}