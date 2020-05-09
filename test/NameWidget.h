#ifndef NAMEWIDGET_H
#define NAMEWIDGET_H

#include <QWidget>

namespace Ui {
class NameWidget;
}

class NameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NameWidget(QWidget *parent = nullptr);
    ~NameWidget();

    void setName(const QString &name);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

signals:
    void clicked();


private:
    Ui::NameWidget *ui;
    QPoint m_pos;
};

#endif // NAMEWIDGET_H
