#include "CSortDlg.h"
CSortDlg::CSortDlg(QWidget* parent)
	:QDialog(parent)
{
	resize(300, 400);
	/*this->setStyleSheet(".QPushButton,QLineEdit{border-color:#000000;background-color:#909399;color:black;} \
		.QLabel{background-color:#909399;}");*/
	QLabel* pLabelCourse = new QLabel();
	pLabelCourse->setText("Course");
	pLECourse = new QLineEdit();
	pLECourse->setPlaceholderText("Please enter the course in English");
	QHBoxLayout* pHLayCourse = new QHBoxLayout();
	pHLayCourse->addWidget(pLabelCourse);
	pHLayCourse->addWidget(pLECourse);

	pbtnSortA = new QPushButton();
	pbtnSortA->setText("Ascending sort");
	pbtnSortD = new QPushButton();
	pbtnSortD->setText("Descending sort");

	QHBoxLayout* pHLaySort = new QHBoxLayout();
	pHLaySort->addWidget(pbtnSortA);
	pHLaySort->addWidget(pbtnSortD);

	QVBoxLayout* pVLayMain = new QVBoxLayout(this);
	pVLayMain->addLayout(pHLayCourse);
	pVLayMain->addLayout(pHLaySort);

	connect(pbtnSortA, &QPushButton::clicked, this, &CSortDlg::sortStudent);
	connect(pbtnSortD, &QPushButton::clicked, this, &CSortDlg::sortStudent);
}

CSortDlg::~CSortDlg()
{

}

void CSortDlg::sortStudent()
{
	CMainWidget* mainWidget = (CMainWidget*)parentWidget();
	QVector<CStudentInfo> query;
	mainWidget->loadStudentInfo(query);

	QString course = pLECourse->text().trimmed();
	if (course.isEmpty())
	{
		QMessageBox::information(nullptr, "Hint", "Please enter the couse name");
		return;
	}

	QPushButton* pbtnSort = qobject_cast<QPushButton*>(sender());

	if(course.toLower() == "chinese" && pbtnSort == pbtnSortA) std::sort(query.begin(), query.end(), CSortDlg::cmpChinese);
	else if(course.toLower() == "chinese" && pbtnSort == pbtnSortD)
	{
		std::sort(query.begin(), query.end(), CSortDlg::cmpChinese);
		std::reverse(query.begin(), query.end());
	}
	else if(course.toLower() == "english" && pbtnSort == pbtnSortA) std::sort(query.begin(), query.end(), CSortDlg::cmpEnglish);
	else if (course.toLower() == "english" && pbtnSort == pbtnSortD)
	{
		std::sort(query.begin(), query.end(), CSortDlg::cmpEnglish);
		std::reverse(query.begin(), query.end());
	}
	else if(course.toLower() == "math" && pbtnSort == pbtnSortA) std::sort(query.begin(), query.end(), CSortDlg::cmpMath);
	else if (course.toLower() == "math" && pbtnSort == pbtnSortD)
	{
		std::sort(query.begin(), query.end(), CSortDlg::cmpMath);
		std::reverse(query.begin(), query.end());
	}
	else
	{
		QMessageBox::information(this, "Warning", "No such course");
		pLECourse->clear();
		return;

	}
	QMessageBox::information(this, "Success", "Successfully Sort");

	mainWidget->tableReflash(query);

	this->close();


}

bool CSortDlg::cmpChinese(CStudentInfo& a, CStudentInfo& b)
{
	return (a.getChinese() < b.getChinese());
}

bool CSortDlg::cmpMath(CStudentInfo& a, CStudentInfo& b)
{
	return (a.getMath() < b.getMath());
}

bool CSortDlg::cmpEnglish(CStudentInfo& a, CStudentInfo& b)
{
	return (a.getEnglish() < b.getEnglish());
}