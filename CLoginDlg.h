#pragma once

#include <QtWidgets/QDialog>
#include "ui_CLoginDlg.h"
#include <QPixmap>
#include <QMouseEvent>
#include <QMessageBox>
#include "CMainWidget.h"
#include "CStudentInfo.h"

class CLoginDlg : public QDialog
{
    Q_OBJECT

public:
    CLoginDlg(QWidget *parent = nullptr);
    ~CLoginDlg();

private slots:
    void on_btnJoin_clicked();
    void on_btnClose_clicked();
    void on_btnMin_clicked();
private:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
private:
    Ui::CLoginDlgClass ui;

    QPoint diff_pos;
    QPoint window_pos;
    QPoint mouse_pos;
};
