/********************************************************************************
** Form generated from reading UI file 'CLoginDlg.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOGINDLG_H
#define UI_CLOGINDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CLoginDlgClass
{
public:
    QLabel *label_login;
    QWidget *widget_base;
    QPushButton *btnJoin;
    QLabel *label_2;
    QWidget *widget_up;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_username;
    QFrame *line;
    QLineEdit *lineEdit_password;
    QFrame *line_2;
    QLineEdit *lineEdit_3;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QLabel *label_logo;
    QLabel *label_3;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnMin;
    QPushButton *btnClose;

    void setupUi(QDialog *CLoginDlgClass)
    {
        if (CLoginDlgClass->objectName().isEmpty())
            CLoginDlgClass->setObjectName("CLoginDlgClass");
        CLoginDlgClass->resize(913, 574);
        CLoginDlgClass->setMinimumSize(QSize(913, 574));
        CLoginDlgClass->setMaximumSize(QSize(913, 774));
        label_login = new QLabel(CLoginDlgClass);
        label_login->setObjectName("label_login");
        label_login->setGeometry(QRect(500, 110, 379, 75));
        label_login->setMaximumSize(QSize(379, 75));
        label_login->setAlignment(Qt::AlignCenter);
        widget_base = new QWidget(CLoginDlgClass);
        widget_base->setObjectName("widget_base");
        widget_base->setGeometry(QRect(520, 180, 351, 341));
        widget_base->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        btnJoin = new QPushButton(widget_base);
        btnJoin->setObjectName("btnJoin");
        btnJoin->setGeometry(QRect(40, 230, 281, 31));
        btnJoin->setStyleSheet(QString::fromUtf8(""));
        label_2 = new QLabel(widget_base);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(250, 280, 48, 16));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        widget_up = new QWidget(widget_base);
        widget_up->setObjectName("widget_up");
        widget_up->setGeometry(QRect(40, 50, 281, 161));
        layoutWidget = new QWidget(widget_up);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 11, 281, 141));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_username = new QLineEdit(layoutWidget);
        lineEdit_username->setObjectName("lineEdit_username");

        verticalLayout->addWidget(lineEdit_username);

        line = new QFrame(layoutWidget);
        line->setObjectName("line");
        line->setFrameShadow(QFrame::Sunken);
        line->setFrameShape(QFrame::Shape::HLine);

        verticalLayout->addWidget(line);

        lineEdit_password = new QLineEdit(layoutWidget);
        lineEdit_password->setObjectName("lineEdit_password");

        verticalLayout->addWidget(lineEdit_password);

        line_2 = new QFrame(layoutWidget);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout->addWidget(line_2);

        lineEdit_3 = new QLineEdit(layoutWidget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(lineEdit_3);

        line_3 = new QFrame(layoutWidget);
        line_3->setObjectName("line_3");
        line_3->setFrameShape(QFrame::Shape::HLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout->addWidget(line_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        radioButton_2 = new QRadioButton(layoutWidget);
        radioButton_2->setObjectName("radioButton_2");

        horizontalLayout->addWidget(radioButton_2);

        radioButton = new QRadioButton(layoutWidget);
        radioButton->setObjectName("radioButton");

        horizontalLayout->addWidget(radioButton);


        verticalLayout->addLayout(horizontalLayout);

        label_logo = new QLabel(CLoginDlgClass);
        label_logo->setObjectName("label_logo");
        label_logo->setGeometry(QRect(30, 10, 161, 141));
        label_3 = new QLabel(CLoginDlgClass);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(200, 60, 141, 41));
        layoutWidget1 = new QWidget(CLoginDlgClass);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(734, 13, 168, 31));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnMin = new QPushButton(layoutWidget1);
        btnMin->setObjectName("btnMin");

        horizontalLayout_2->addWidget(btnMin);

        btnClose = new QPushButton(layoutWidget1);
        btnClose->setObjectName("btnClose");

        horizontalLayout_2->addWidget(btnClose);


        retranslateUi(CLoginDlgClass);

        QMetaObject::connectSlotsByName(CLoginDlgClass);
    } // setupUi

    void retranslateUi(QDialog *CLoginDlgClass)
    {
        CLoginDlgClass->setWindowTitle(QCoreApplication::translate("CLoginDlgClass", "CLoginDlg", nullptr));
        label_login->setText(QCoreApplication::translate("CLoginDlgClass", "\347\224\250\346\210\267\347\231\273\345\275\225", nullptr));
        btnJoin->setText(QCoreApplication::translate("CLoginDlgClass", "\347\231\273\345\275\225", nullptr));
        label_2->setText(QCoreApplication::translate("CLoginDlgClass", "\345\277\230\350\256\260\345\257\206\347\240\201", nullptr));
        lineEdit_username->setPlaceholderText(QCoreApplication::translate("CLoginDlgClass", "\347\224\250\346\210\267\345\220\215", nullptr));
        lineEdit_password->setPlaceholderText(QCoreApplication::translate("CLoginDlgClass", "\345\257\206\347\240\201", nullptr));
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("CLoginDlgClass", "\351\252\214\350\257\201\347\240\201", nullptr));
        radioButton_2->setText(QCoreApplication::translate("CLoginDlgClass", "\347\256\241\347\220\206\345\221\230", nullptr));
        radioButton->setText(QCoreApplication::translate("CLoginDlgClass", "\346\225\231\345\270\210", nullptr));
        label_logo->setText(QCoreApplication::translate("CLoginDlgClass", "Logo", nullptr));
        label_3->setText(QCoreApplication::translate("CLoginDlgClass", "\346\225\231\345\212\241\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        btnMin->setText(QCoreApplication::translate("CLoginDlgClass", "PushButton", nullptr));
        btnClose->setText(QCoreApplication::translate("CLoginDlgClass", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CLoginDlgClass: public Ui_CLoginDlgClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOGINDLG_H
