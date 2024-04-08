#pragma once
#include <QObject>
#include <QWidget>
class CountWidget : public QWidget
{
	Q_OBJECT


public:
	CountWidget(QWidget* p = nullptr);
	~CountWidget();

};