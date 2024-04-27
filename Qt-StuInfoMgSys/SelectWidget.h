#pragma once
#include <QObject>
#include <QWidget>
class SelectWidget : public QWidget
{
	Q_OBJECT


public:
	SelectWidget(QWidget* p = nullptr);
	~SelectWidget();

};