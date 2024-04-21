#include "CSelectDlg.h"
CSelectDlg::CSelectDlg(QWidget* parent)
	:QDialog(parent)
{
	
	setWindowTitle("SelectStudentInfo");

	QVBoxLayout* pVLayBtn = new QVBoxLayout();

	QPushButton* btnNumber = new QPushButton();
	btnNumber->setText("Number");
	QPushButton* btnName = new QPushButton();
	btnName->setText("Name");
	pVLayBtn->addWidget(btnNumber);
	pVLayBtn->addWidget(btnName);



	QHBoxLayout* pHLayMain = new QHBoxLayout(this);
	pSW = new QStackedWidget();
	pSW->setFixedSize(400, 500);

	numberWidget = new QWidget();
	//numberWidget->setStyleSheet("background-color:#409EFF");
	initNumberWidget();
	

	nameWidget = new QWidget();
	initNameWidget();
	//nameWidget->setStyleSheet("background-color:#31655f");
	//numberWidget->setAttribute(Qt::WA_DeleteOnClose); // 关闭时销毁对象

	//nameWidget->setAttribute(Qt::WA_DeleteOnClose); // 关闭时销毁对象

	QLabel* pLabelNumber = new QLabel();
	pLabelNumber->setText("Number");
	pLENumber = new QLineEdit();
	btnSelect_number = new QPushButton();
	btnSelect_number->setText("Select");
	QHBoxLayout* pHLayNumberEdit = new QHBoxLayout();
	pHLayNumberEdit->addWidget(pLabelNumber);
	pHLayNumberEdit->addWidget(pLENumber);
	QVBoxLayout* pVLayNumber = new QVBoxLayout(numberWidget);
	pVLayNumber->addLayout(pHLayNumberEdit);
	pVLayNumber->addLayout(pVLayMainNumber);
	pVLayNumber->addWidget(btnSelect_number);

	QLabel* pLabelName = new QLabel();
	pLabelName->setText("Name");
	pLEName = new QLineEdit();
	btnSelect_name = new QPushButton();
	btnSelect_name->setText("Select");
	QHBoxLayout* pHLayNameEdit = new QHBoxLayout();
	pHLayNameEdit->addWidget(pLabelName);
	pHLayNameEdit->addWidget(pLEName);
	QVBoxLayout* pVLayName = new QVBoxLayout(nameWidget);
	pVLayName->addLayout(pHLayNameEdit);
	pVLayName->addLayout(pVLayMainName);
	pVLayName->addWidget(btnSelect_name);


	pSW->addWidget(numberWidget);
	pSW->addWidget(nameWidget);
	pHLayMain->addLayout(pVLayBtn);
	pHLayMain->addWidget(pSW);

	/*this->setStyleSheet(".QPushButton,QLineEdit{border-color:#000000;background-color:#909399;color:black;} \
		.QLabel{background-color:#909399;}");*/
	connect(btnNumber, &QPushButton::clicked,[=] {
		//initNumberWidget();
		pSW->setCurrentIndex(0);
		});

	connect(btnName, &QPushButton::clicked, [=] {
		//initNameWidget();
		pSW->setCurrentIndex(1);
		});

	connect(btnSelect_number, &QPushButton::clicked, this, &CSelectDlg::selectStudent_number);
	connect(btnSelect_name, &QPushButton::clicked, this, &CSelectDlg::selectStudent_name);
}

CSelectDlg::~CSelectDlg()
{

}

void CSelectDlg::selectStudent_number()
{
	
	CMainWidget* mainWidget = (CMainWidget*)parentWidget();
	QVector<CStudentInfo> query;
	mainWidget->loadStudentInfo(query);

	QString number = pLENumber->text().trimmed();
	if (number.isEmpty())
	{
		QMessageBox::information(nullptr, "Hint", "Please enter the student number");
		return;
	}

	QString studentName;
	QString studentSex;
	int studentAge;
	QString studentNumber;
	int studentChinese;
	int studentEnglish;
	int studentMath;
	
	int flag = 1;
	for (int i = 0; i < query.size(); i++)
	{
		if (query[i].getNumber() == number)
		{
			studentName = query[i].getName();
			studentSex = query[i].getSex();
			studentAge = query[i].getAge();
			studentNumber = query[i].getNumber();
			studentChinese = query[i].getChinese();
			studentEnglish = query[i].getEnglish();
			studentMath = query[i].getMath();
			flag = 0;
			break;
		}
	}

	if (flag)
	{
		QMessageBox::information(nullptr, "Hint", "The student could not be found");
		pLENumber->clear();
		lineEditName->clear();
		lineEditSex->clear();
		lineEditAge->clear();
		lineEditNumber->clear();
		lineEditChinese->clear();
		lineEditEnglish->clear();
		lineEditMath->clear();
		return;
	}

	lineEditName->clear();
	lineEditSex->clear();
	lineEditAge->clear();
	lineEditNumber->clear();
	lineEditChinese->clear();
	lineEditEnglish->clear();
	lineEditMath->clear();

	lineEditName->setText(studentName);
	lineEditSex->setText(studentSex);
	lineEditAge->setText(QString::number(studentAge));
	lineEditNumber->setText(studentNumber);
	lineEditChinese->setText(QString::number(studentChinese));
	lineEditEnglish->setText(QString::number(studentEnglish));
	lineEditMath->setText(QString::number(studentMath));


}

void CSelectDlg::selectStudent_name()
{
	CMainWidget* mainWidget = (CMainWidget*)parentWidget();
	QVector<CStudentInfo> query;
	mainWidget->loadStudentInfo(query);

	QString name = pLEName->text().trimmed();
	if (name.isEmpty())
	{
		QMessageBox::information(nullptr, "Hint", "Please enter the student name");
		return;
	}

	QString studentName;
	QString studentSex;
	int studentAge;
	QString studentNumber;
	int studentChinese;
	int studentEnglish;
	int studentMath;

	int flag = 1;
	for (int i = 0; i < query.size(); i++)
	{
		if (query[i].getName() == name)
		{
			studentName = query[i].getName();
			studentSex = query[i].getSex();
			studentAge = query[i].getAge();
			studentNumber = query[i].getNumber();
			studentChinese = query[i].getChinese();
			studentEnglish = query[i].getEnglish();
			studentMath = query[i].getMath();
			flag = 0;
			break;
		}
	}

	if (flag)
	{
		QMessageBox::information(nullptr, "Hint", "The student could not be found");
		pLEName->clear();
		lineEditName2->clear();
		lineEditSex2->clear();
		lineEditAge2->clear();
		lineEditNumber2->clear();
		lineEditChinese2->clear();
		lineEditEnglish2->clear();
		lineEditMath2->clear();
		return;
	}

	lineEditName2->clear();
	lineEditSex2->clear();
	lineEditAge2->clear();
	lineEditNumber2->clear();
	lineEditChinese2->clear();
	lineEditEnglish2->clear();
	lineEditMath2->clear();

	lineEditName2->setText(studentName);
	lineEditSex2->setText(studentSex);
	lineEditAge2->setText(QString::number(studentAge));
	lineEditNumber2->setText(studentNumber);
	lineEditChinese2->setText(QString::number(studentChinese));
	lineEditEnglish2->setText(QString::number(studentEnglish));
	lineEditMath2->setText(QString::number(studentMath));


}
void CSelectDlg::initNumberWidget()
{
	QLabel* plabelName = new QLabel(numberWidget);
	plabelName->setText("Name");
	QLabel* plabelSex = new QLabel(numberWidget);
	plabelSex->setText("Sex");
	QLabel* plabelAge = new QLabel(numberWidget);
	plabelAge->setText("Age");
	QLabel* plabelNumber = new QLabel(numberWidget);
	plabelNumber->setText("Number");
	QLabel* plabelChinese = new QLabel(numberWidget);
	plabelChinese->setText("Chinese");
	QLabel* plabelEnglish = new QLabel(numberWidget);
	plabelEnglish->setText("English");
	QLabel* plabelMath = new QLabel(numberWidget);
	plabelMath->setText("Math");

	lineEditName = new QLineEdit(numberWidget);
	lineEditName->setReadOnly(true);
	lineEditName->setFixedHeight(25);

	lineEditSex = new QLineEdit(numberWidget);
	lineEditSex->setReadOnly(true);
	lineEditSex->setFixedHeight(25);

	lineEditAge = new QLineEdit(numberWidget);
	lineEditAge->setReadOnly(true);
	lineEditAge->setFixedHeight(25);

	lineEditNumber = new QLineEdit(numberWidget);
	lineEditNumber->setReadOnly(true);
	lineEditNumber->setFixedHeight(25);

	lineEditChinese = new QLineEdit(numberWidget);
	lineEditChinese->setReadOnly(true);
	lineEditChinese->setFixedHeight(25);

	lineEditEnglish = new QLineEdit(numberWidget);
	lineEditEnglish->setReadOnly(true);
	lineEditEnglish->setFixedHeight(25);

	lineEditMath = new QLineEdit(numberWidget);
	lineEditMath->setReadOnly(true);
	lineEditMath->setFixedHeight(25);

	lineEditName->setFixedWidth(100);
	lineEditSex->setFixedWidth(100);
	lineEditAge->setFixedWidth(100);
	lineEditNumber->setFixedWidth(100);
	lineEditChinese->setFixedWidth(100);
	lineEditEnglish->setFixedWidth(100);
	lineEditMath->setFixedWidth(100);

	QHBoxLayout* pHLayName = new QHBoxLayout();
	pHLayName->addStretch();
	pHLayName->addWidget(plabelName);
	pHLayName->addWidget(lineEditName);
	pHLayName->addStretch();

	QHBoxLayout* pHLaySex = new QHBoxLayout();
	pHLaySex->addStretch();
	pHLaySex->addWidget(plabelSex);
	pHLaySex->addWidget(lineEditSex);
	pHLaySex->addStretch();
	QHBoxLayout* pHLayAge = new QHBoxLayout();
	pHLayAge->addStretch();
	pHLayAge->addWidget(plabelAge);
	pHLayAge->addWidget(lineEditAge);
	pHLayAge->addStretch();
	QHBoxLayout* pHLayNumber = new QHBoxLayout();
	pHLayNumber->addStretch();
	pHLayNumber->addWidget(plabelNumber);
	pHLayNumber->addWidget(lineEditNumber);
	pHLayNumber->addStretch();
	QHBoxLayout* pHLayChinese = new QHBoxLayout();
	pHLayChinese->addStretch();
	pHLayChinese->addWidget(plabelChinese);
	pHLayChinese->addWidget(lineEditChinese);
	pHLayChinese->addStretch();
	QHBoxLayout* pHLayEnglish = new QHBoxLayout();
	pHLayEnglish->addStretch();
	pHLayEnglish->addWidget(plabelEnglish);
	pHLayEnglish->addWidget(lineEditEnglish);
	pHLayEnglish->addStretch();
	QHBoxLayout* pHLayMath = new QHBoxLayout();
	pHLayMath->addStretch();
	pHLayMath->addWidget(plabelMath);
	pHLayMath->addWidget(lineEditMath);
	pHLayMath->addStretch();

	pVLayMainNumber = new QVBoxLayout();
	pVLayMainNumber->setContentsMargins(100, 5, 100, 5);
	pVLayMainNumber->addLayout(pHLayName);
	pVLayMainNumber->addLayout(pHLaySex);
	pVLayMainNumber->addLayout(pHLayAge);
	pVLayMainNumber->addLayout(pHLayNumber);
	pVLayMainNumber->addLayout(pHLayChinese);
	pVLayMainNumber->addLayout(pHLayEnglish);
	pVLayMainNumber->addLayout(pHLayMath);

}

void CSelectDlg::initNameWidget()
{

	QLabel* plabelName2 = new QLabel();
	plabelName2->setText("Name");
	QLabel* plabelSex2 = new QLabel();
	plabelSex2->setText("Sex");
	QLabel* plabelAge2 = new QLabel();
	plabelAge2->setText("Age");
	QLabel* plabelNumber2 = new QLabel();
	plabelNumber2->setText("Number");
	QLabel* plabelChinese2 = new QLabel();
	plabelChinese2->setText("Chinese");
	QLabel* plabelEnglish2 = new QLabel();
	plabelEnglish2->setText("English");
	QLabel* plabelMath2 = new QLabel();
	plabelMath2->setText("Math");

	lineEditName2 = new QLineEdit();
	lineEditName2->setReadOnly(true);
	lineEditName2->setFixedHeight(25);

	lineEditSex2 = new QLineEdit();
	lineEditSex2->setReadOnly(true);
	lineEditSex2->setFixedHeight(25);

	lineEditAge2 = new QLineEdit();
	lineEditAge2->setReadOnly(true);
	lineEditAge2->setFixedHeight(25);

	lineEditNumber2 = new QLineEdit();
	lineEditNumber2->setReadOnly(true);
	lineEditNumber2->setFixedHeight(25);

	lineEditChinese2 = new QLineEdit();
	lineEditChinese2->setReadOnly(true);
	lineEditChinese2->setFixedHeight(25);

	lineEditEnglish2 = new QLineEdit();
	lineEditEnglish2->setReadOnly(true);
	lineEditEnglish2->setFixedHeight(25);

	lineEditMath2 = new QLineEdit();
	lineEditMath2->setReadOnly(true);
	lineEditMath2->setFixedHeight(25);

	lineEditName2->setFixedWidth(100);
	lineEditSex2->setFixedWidth(100);
	lineEditAge2->setFixedWidth(100);
	lineEditNumber2->setFixedWidth(100);
	lineEditChinese2->setFixedWidth(100);
	lineEditEnglish2->setFixedWidth(100);
	lineEditMath2->setFixedWidth(100);

	QHBoxLayout* pHLayName2 = new QHBoxLayout();
	pHLayName2->addStretch();
	pHLayName2->addWidget(plabelName2);
	pHLayName2->addWidget(lineEditName2);
	pHLayName2->addStretch();

	QHBoxLayout* pHLaySex2 = new QHBoxLayout();
	pHLaySex2->addStretch();
	pHLaySex2->addWidget(plabelSex2);
	pHLaySex2->addWidget(lineEditSex2);
	pHLaySex2->addStretch();
	QHBoxLayout* pHLayAge2 = new QHBoxLayout();
	pHLayAge2->addStretch();
	pHLayAge2->addWidget(plabelAge2);
	pHLayAge2->addWidget(lineEditAge2);
	pHLayAge2->addStretch();
	QHBoxLayout* pHLayNumber2 = new QHBoxLayout();
	pHLayNumber2->addStretch();
	pHLayNumber2->addWidget(plabelNumber2);
	pHLayNumber2->addWidget(lineEditNumber2);
	pHLayNumber2->addStretch();
	QHBoxLayout* pHLayChinese2 = new QHBoxLayout();
	pHLayChinese2->addStretch();
	pHLayChinese2->addWidget(plabelChinese2);
	pHLayChinese2->addWidget(lineEditChinese2);
	pHLayChinese2->addStretch();
	QHBoxLayout* pHLayEnglish2 = new QHBoxLayout();
	pHLayEnglish2->addStretch();
	pHLayEnglish2->addWidget(plabelEnglish2);
	pHLayEnglish2->addWidget(lineEditEnglish2);
	pHLayEnglish2->addStretch();
	QHBoxLayout* pHLayMath2 = new QHBoxLayout();
	pHLayMath2->addStretch();
	pHLayMath2->addWidget(plabelMath2);
	pHLayMath2->addWidget(lineEditMath2);
	pHLayMath2->addStretch();

	pVLayMainName = new QVBoxLayout();
	pVLayMainName->setContentsMargins(100, 5, 100, 5);
	pVLayMainName->addLayout(pHLayName2);
	pVLayMainName->addLayout(pHLaySex2);
	pVLayMainName->addLayout(pHLayAge2);
	pVLayMainName->addLayout(pHLayNumber2);
	pVLayMainName->addLayout(pHLayChinese2);
	pVLayMainName->addLayout(pHLayEnglish2);
	pVLayMainName->addLayout(pHLayMath2);

	
}