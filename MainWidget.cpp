#include "MainWidget.h"
#include <QMouseEvent>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint);
}

void MainWidget::mousePressEvent(QMouseEvent* event)
{
    mouse_pos = event->globalPos();
    window_pos = this->pos();
    diff_pos = mouse_pos - window_pos;
}

void MainWidget::mouseMoveEvent(QMouseEvent* event)
{
    QPoint pos = event->globalPos();
    //this->move(pos);
    this->move(pos - diff_pos);
}
