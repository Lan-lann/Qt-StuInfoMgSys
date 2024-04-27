#pragma once
#include <QWidget>
#include <QDialog>
#include <QVBoxLayout>
#include <QSize>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QString>
#include <QMessageBox>
#include <QFile>
#include <iostream>
#include <QTextStream>
#include <QVector>
#include "QStackedWidget"

#include "CStudentInfo.h"
#include "CMainWidget.h"
class CSelectDlg : public QDialog
{
	Q_OBJECT


public:
	CSelectDlg(QWidget* p = nullptr);
	~CSelectDlg();
	void initNumberWidget();
	void initNameWidget();
private slots:
	void selectStudent_number();
	void selectStudent_name();

private:
	QStackedWidget* pSW;
	QLineEdit* pLENumber;
	QLineEdit* pLEName;
	QPushButton* btnSelect_number;
	QPushButton* btnSelect_name;



	QLineEdit* lineEditName;
	QLineEdit* lineEditSex;
	QLineEdit* lineEditAge;
	QLineEdit* lineEditNumber;
	QLineEdit* lineEditChinese;
	QLineEdit* lineEditEnglish;
	QLineEdit* lineEditMath;

	QLineEdit* lineEditName2;
	QLineEdit* lineEditSex2;
	QLineEdit* lineEditAge2;
	QLineEdit* lineEditNumber2;
	QLineEdit* lineEditChinese2;
	QLineEdit* lineEditEnglish2;
	QLineEdit* lineEditMath2;

	QVBoxLayout* pVLayMainNumber;
	QVBoxLayout* pVLayMainName;

	QWidget* numberWidget;
	QWidget* nameWidget;

};

