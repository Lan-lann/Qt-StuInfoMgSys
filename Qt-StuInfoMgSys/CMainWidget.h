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
#include <QMessageBox>
#include <QList>
#include <QPainter>
#include <QPaintEvent>
#include <QStackedWidget>

#include "CAddDlg.h"
#include "CModifyDlg.h"
#include "CAddDlg.h"
#include "CStudentInfo.h"
#include "CSelectDlg.h"
#include "CSortDlg.h"
#include "CCountDlg.h"

class CMainWidget : public QWidget
{
	Q_OBJECT


public:
	CMainWidget(QWidget* p = nullptr);
	~CMainWidget();
	void tableReflash(QVector<CStudentInfo>& query);
	void cellSetting(int row, int column, QString text);
	void loadStudentInfo(QVector<CStudentInfo>& query);

	QTableWidget* pTableMain;
private slots:
	void onLoadClicked_slot();
	void onDelClicked_slot();
private:
	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	//void paintEvent(QPaintEvent* event) override;
	QPoint diff_pos;
	QPoint window_pos;
	QPoint mouse_pos;

	
};