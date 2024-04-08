#pragma once
#include <QObject>
#include <QWidget>
#include <QVector>
#include <typeinfo>
#include <QTableWidget>
#include <QFile>
#include <QPushButton>
#include <QHBoxLayout>
#include <QString>
#include <QTableWidget>
#include <QHeaderView>
#include <QMouseEvent>
#include <QPoint>
#include "menuwidget.h"
#include "addstudentwidget.h"
#include "selectwidget.h"
#include "modifywidget.h"
#include "sortwidget.h"
#include "countWidget.h"
#include "CAddDlg.h"
#include "CStudentInfo.h"


class CMainWidget : public QWidget
{
	Q_OBJECT


public:
	CMainWidget(QWidget* p = nullptr);
	~CMainWidget();
	void tableReflash(QVector<CStudentInfo>& query);
	void cellSetting(int row, int column, QString text);
	void loadStudentInfo(QVector<CStudentInfo>& query);
private slots:
	
private:
	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	QPoint diff_pos;
	QPoint window_pos;
	QPoint mouse_pos;

	QTableWidget* pTableMain;
};