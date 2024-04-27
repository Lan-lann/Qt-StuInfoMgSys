#include "CCountDlg.h"
CCountDlg::CCountDlg(QWidget* parent)
	:QDialog(parent)
{
	resize(300, 400);
	QHBoxLayout* pHLayCourse = new QHBoxLayout();
	QLabel* pLabelCourse = new QLabel();
	pLabelCourse->setText("Course");
	pLECourse = new QLineEdit();
	pLECourse->setPlaceholderText("Please enter the course in English");

	pHLayCourse->addWidget(pLabelCourse);
	pHLayCourse->addWidget(pLECourse);

	QHBoxLayout* pHLayScope = new QHBoxLayout();
	QLabel* pLabelScopeHint = new QLabel();
	QLabel* pLabelScope = new QLabel();
	pLEScope1 = new QLineEdit();
	pLEScope2 = new QLineEdit();
	pLabelScopeHint->setText("Scope");
	pLabelScope->setText("~");
	pHLayScope->addWidget(pLabelScopeHint);
	pHLayScope->addWidget(pLEScope1);
	pHLayScope->addWidget(pLabelScope);
	pHLayScope->addWidget(pLEScope2);

	QPushButton* pbtnSelect = new QPushButton();
	pbtnSelect->setText("Count");
	QVBoxLayout* pVLayMain = new QVBoxLayout(this);


	pVLayMain->addLayout(pHLayCourse);
	pVLayMain->addLayout(pHLayScope);
	pVLayMain->addWidget(pbtnSelect);
	
	connect(pbtnSelect, &QPushButton::clicked, this, &CCountDlg::countStudent);
}

CCountDlg::~CCountDlg()
{

}

void CCountDlg::countStudent()
{
	CMainWidget* mainWidget = (CMainWidget*)parentWidget();

	QVector<CStudentInfo> query;

	mainWidget->loadStudentInfo(query);

	QString course = pLECourse->text().trimmed();
	QString gradeLeft = pLEScope1->text().trimmed();
	QString gradeRight = pLEScope2->text().trimmed();

	//����������ʽ�����û�����
	QRegularExpression re("^[A-Za-z]+$");
	QRegularExpressionMatch match = re.match(course);

	//��ʾ�û�����γ���
	//if (course.isEmpty())
	//{
	//	QMessageBox::information(nullptr, "Hint", "Please enter the couse");
	//	return;
	//}

	//�����û�����������Ϣ
	if (course.isEmpty() || gradeLeft.isEmpty() || gradeRight.isEmpty())
	{
		QMessageBox::information(nullptr, "Hint", "Please enter complete information");
		return;
	}

	//�����û�������ȷ�ĸ�ʽ
	if (!match.hasMatch())
	{
		QMessageBox::information(nullptr, "Hint", "Please enter the course name in the correct format");
		pLECourse->clear();
		return;
	}


	QVector<CStudentInfo> targetQuery;
	if (course.toLower() == "chinese")
	{
		std::sort(query.begin(), query.end(), CCountDlg::cmpChinese);
		for (int i = 0; i < query.size(); i++)
		{
			if (query[i].getChinese() <= gradeRight.toInt() && query[i].getChinese() >= gradeLeft.toInt())
			{
				targetQuery.push_back(query[i]);
			}
		}
	}
	else if (course.toLower() == "english")
	{
		std::sort(query.begin(), query.end(), CCountDlg::cmpEnglish);
		for (int i = 0; i < query.size(); i++)
		{
			if (query[i].getEnglish() <= gradeRight.toInt() && query[i].getEnglish() >= gradeLeft.toInt())
			{
				targetQuery.push_back(query[i]);
			}
		}
	}
	else if (course.toLower() == "math")
	{
		std::sort(query.begin(), query.end(), CCountDlg::cmpMath);
		for (int i = 0; i < query.size(); i++)
		{
			if (query[i].getMath() <= gradeRight.toInt() && query[i].getMath() >= gradeLeft.toInt())
			{
				targetQuery.push_back(query[i]);
			}
		}
	}
	
	QMessageBox::information(nullptr, "Success", "Successfully Count");

	mainWidget->tableReflash(targetQuery);

	this->close();
}

bool CCountDlg::cmpChinese(CStudentInfo& a, CStudentInfo& b)
{
	return (a.getChinese() > b.getChinese());
}

bool CCountDlg::cmpMath(CStudentInfo& a, CStudentInfo& b)
{
	return (a.getMath() > b.getMath());
}

bool CCountDlg::cmpEnglish(CStudentInfo& a, CStudentInfo& b)
{
	return (a.getEnglish() > b.getEnglish());
}