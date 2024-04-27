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

#include "CStudentInfo.h"
#include "CMainWidget.h"

class CAddDlg : public QDialog
{
	 Q_OBJECT


public:
	CAddDlg(QWidget* p = nullptr);
	~CAddDlg();

private slots:
	void addStudent();

private:
	QLineEdit* lineEditName;
	QLineEdit* lineEditSex;
	QLineEdit* lineEditAge;
	QLineEdit* lineEditNumber;
	QLineEdit* lineEditChinese;
	QLineEdit* lineEditEnglish;
	QLineEdit* lineEditMath;
	QPushButton* btnAdd;
	
};
