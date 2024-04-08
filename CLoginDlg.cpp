#include "CLoginDlg.h"

CLoginDlg::CLoginDlg(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint);
    this->setStyleSheet("CLoginDlg{border-image:url(:/CLoginDlg/resources/Login/Loginbg.png)}");
    ui.widget_base->setStyleSheet(QString::fromUtf8("background-color: rgb(237,239,251);" "border-radius: 5px;"));
    ui.widget_up->setStyleSheet(QString::fromUtf8("background-color: rgb(251,251,251);" "border-radius: 5px;"));

    //关闭按钮设置
    ui.btnClose->setText("");
    ui.btnClose->setFixedSize(32, 32);
    ui.btnClose->setStyleSheet("QPushButton{background-image:url(:/CLoginDlg/resources/Login/close.svg);border:none}" \
        "QPushButton:hover{" \
        "background-color:rgb(99, 99, 99);" \
        "background-image:url(:/CLoginDlg/resources/Login/close_hover.svg);border:none;}");

    //最小化按钮设置
    ui.btnMin->setText("");
    ui.btnMin->setFixedSize(32, 32);
    ui.btnMin->setStyleSheet("QPushButton{background-image:url(:/CLoginDlg/resources/Login/min.svg);border:none}" \
        "QPushButton:hover{" \
        "background-color:rgb(99, 99, 99);" \
        "background-image:url(:/CLoginDlg/resources/Login/min_hover.svg);border:none;}");

    //登录标签设置
    ui.label_login->setFont(QFont("SimHei", 22.5, QFont::Bold, false));
    ui.label_login->setStyleSheet("color:white");

    //水平线设置
    ui.line->setStyleSheet("border-top: 1px dashed;color:grey");
    ui.line_2->setStyleSheet("border-top: 1px dashed;color:grey");
    ui.line_3->setStyleSheet("border-top: 1px dashed;color:grey");

    //登录按钮设置
    ui.btnJoin->setStyleSheet("QPushButton{color:white;background-style: solid;background-color: rgb(49,154,236);}"
        "QPushButton:hover{background-color: rgb(11,116,221);}");

    //左上角“教务管理系统设置”

    ui.label_3->setFont(QFont("Arial", 15.5, QFont::Bold, false));
    ui.label_3->setStyleSheet("color:white");

    //logo设置
    ui.label_logo->setText("");
    QPixmap* pixmap = new QPixmap(":/CLoginDlg/resources/Login/School.png");
    pixmap->scaled(ui.label_logo->size(), Qt::KeepAspectRatio);
    ui.label_logo->setScaledContents(true);
    ui.label_logo->setPixmap(*pixmap);
    ui.label_logo->setStyleSheet("background-color:white;border:none");
    
    //设置密文登录
    ui.lineEdit_password->setEchoMode(QLineEdit::Password);

    //设置标题栏状态栏图标
    this->setWindowIcon(QIcon(":/CLoginDlg/resources/Login/database.png"));
}

CLoginDlg::~CLoginDlg()
{}

void CLoginDlg::on_btnJoin_clicked()
{
    //if (ui.lineEdit_username->text() == "Admin" && ui.lineEdit_password->text() == "123456")
    {
        CMainWidget* mainw = new CMainWidget();
        this->close();
        mainw->show();
        
    }
    /*else 
    {
        QMessageBox::warning(this, QString("ERROR"), QString("Invalid Login or password."));
        ui.lineEdit_username->clear();
        ui.lineEdit_password->clear();
        ui.lineEdit_username->setFocus();
    }*/
   
}

void CLoginDlg::on_btnClose_clicked()
{
    close();
}

void CLoginDlg::on_btnMin_clicked()
{
    showMinimized();
}

void CLoginDlg::mousePressEvent(QMouseEvent* event)
{
    mouse_pos = event->globalPos();
    window_pos = this->pos();
    diff_pos = mouse_pos - window_pos;
}

void CLoginDlg::mouseMoveEvent(QMouseEvent* event)
{
    QPoint pos = event->globalPos();
    //this->move(pos);
    this->move(pos - diff_pos);
}

