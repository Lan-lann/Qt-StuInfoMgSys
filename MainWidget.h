#pragma once

#include <QtWidgets/QWidget>


class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = Q_NULLPTR);

private:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

private:
    QPoint diff_pos;  // ���ʹ��ڵ����λ��
    QPoint window_pos;
    QPoint mouse_pos;
};
