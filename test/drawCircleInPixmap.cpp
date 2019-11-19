#include "common.h"
#include <qpainterpath.h>
#include <qpixmap.h>
#include <qpainter>

void drawCircleInPixmap()
{
    int x = 0;
    int y = 0;
    int w = 10;
    int h = 10;

    //////给笔记item加上绿点
    QPixmap pixmap(10, 10);
    QPainter painter(&pixmap);
    // 反走样
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QColor(48.190, 142, 1));
    painter.setBrush(QColor(48.190, 142, 1));
    painter.setBackgroundMode(Qt::TransparentMode);
    //painter.drawEllipse(0, 0, 10, 10);
    painter.drawRect(0, 0, 10, 10);
    painter.drawEllipse(QPointF(5, 5), 5, 5);
    ////noteItem->setIcon(0, pixmap);

    //QPainterPath path;
    //path.addEllipse(x, y, w, h);
    //painter.setClipPath(path);
    //painter.drawPixmap(x, y, w, h, pixmap);

    //QLinearGradient myGradient;
    //QPen myPen(QColor(48.190, 142, 1));
    //QRectF boundingRectangle(0,0,10,10);

    //QPainterPath myPath;
    //myPath.addEllipse(boundingRectangle);

    //QPainter painter(&pixmap);
    //painter.setBrush(myGradient);
    //painter.setPen(myPen);
    //painter.drawPath(myPath);

    pixmap.save("C:/Users/ET/Desktop/circle.png");
}