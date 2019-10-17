//#pragma once

#ifndef WCFPC_LIST_WIDGET_H
#define WCFPC_LIST_WIDGET_H

#include <QListWidget>

class WCListWidget : public QListWidget
{
    Q_OBJECT

public:
    explicit WCListWidget(QWidget *parent);

protected:
    void mousePressEvent(QMouseEvent *ev) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *ev) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *ev) Q_DECL_OVERRIDE;

private:
    bool m_pressed;
    QPoint m_lastPoint;
};



#endif // !WCFPC_LIST_WIDGET_H