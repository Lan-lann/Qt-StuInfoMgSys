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
class CSortDlg : public QDialog
{
	Q_OBJECT


public:
	CSortDlg(QWidget* p = nullptr);
	~CSortDlg();
	static bool cmpChinese(CStudentInfo& a, CStudentInfo& b);
	static bool cmpEnglish(CStudentInfo& a, CStudentInfo& b);
	static bool cmpMath(CStudentInfo& a, CStudentInfo& b);
	
private slots:
	void sortStudent();
private:
	QPushButton* pbtnSortA;
	QPushButton* pbtnSortD;
	QLineEdit* pLECourse;

};

