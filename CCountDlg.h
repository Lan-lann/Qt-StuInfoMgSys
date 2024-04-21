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
#include <QtAlgorithms>

#include "QStackedWidget"
#include "CStudentInfo.h"
#include "CMainWidget.h"
class CCountDlg : public QDialog
{
	Q_OBJECT


public:
	CCountDlg(QWidget* p = nullptr);
	~CCountDlg();
	static bool cmpChinese(CStudentInfo& a, CStudentInfo& b);
	static bool cmpEnglish(CStudentInfo& a, CStudentInfo& b);
	static bool cmpMath(CStudentInfo& a, CStudentInfo& b);

private slots:
	void countStudent();
private:
	QLineEdit* pLECourse;
	QLineEdit* pLEScope1;
	QLineEdit* pLEScope2;

};

