#include "CAddDlg.h"

CAddDlg::CAddDlg(QWidget* p)
    :QDialog(p)
{
	resize(500, 500);
	setWindowTitle("AddStudentInfo");
	QLabel* plabelName = new QLabel(this);
	plabelName->setText("Name");
	QLabel* plabelSex = new QLabel(this);
	plabelSex->setText("Sex");
	QLabel* plabelAge = new QLabel(this);
	plabelAge->setText("Age");
	QLabel* plabelNumber = new QLabel(this);
	plabelNumber->setText("Number");
	QLabel* plabelChinese = new QLabel(this);
	plabelChinese->setText("Chinese");
	QLabel* plabelEnglish = new QLabel(this);
	plabelEnglish->setText("English");
	QLabel* plabelMath = new QLabel(this);
	plabelMath->setText("Math");

	lineEditName = new QLineEdit(this);
	lineEditSex = new QLineEdit(this);
	lineEditAge = new QLineEdit(this);
	lineEditNumber = new QLineEdit(this);
	lineEditChinese = new QLineEdit(this);
	lineEditEnglish = new QLineEdit(this);
	lineEditMath = new QLineEdit(this);
	btnAdd = new QPushButton(this);
	btnAdd->setText("Add");

	lineEditName->setFixedWidth(100);
	lineEditSex->setFixedWidth(100);
	lineEditAge->setFixedWidth(100);
	lineEditNumber->setFixedWidth(100);
	lineEditChinese->setFixedWidth(100);
	lineEditEnglish->setFixedWidth(100);
	lineEditMath->setFixedWidth(100);
	btnAdd->setFixedWidth(150);

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

	QHBoxLayout* pHLayAdd = new QHBoxLayout();
	pHLayAdd->addStretch();
	pHLayAdd->addWidget(btnAdd);
	pHLayAdd->addStretch();

	QVBoxLayout* pVLayMain = new QVBoxLayout(this);
	pVLayMain->setContentsMargins(100, 5, 100, 5);
	pVLayMain->addLayout(pHLayName);
	pVLayMain->addLayout(pHLaySex);
	pVLayMain->addLayout(pHLayAge);
	pVLayMain->addLayout(pHLayNumber);
	pVLayMain->addLayout(pHLayChinese);
	pVLayMain->addLayout(pHLayEnglish);
	pVLayMain->addLayout(pHLayMath);
	pVLayMain->addLayout(pHLayAdd);

	connect(btnAdd, &QPushButton::clicked, this, &CAddDlg::addStudent);
	

}
CAddDlg::~CAddDlg()
{

}

void CAddDlg::addStudent()
{
	QString studentName = lineEditName->text().trimmed();
	QString studentSex = lineEditSex->text().trimmed();
	QString studentAge = lineEditAge->text().trimmed();
	QString studentNumber = lineEditNumber->text().trimmed();
	QString studentChinese = lineEditChinese->text().trimmed();
	QString studentEnglish = lineEditEnglish->text().trimmed();
	QString studentMath = lineEditMath->text().trimmed();
	if (studentName.isEmpty() || studentSex.isEmpty() ||
		studentAge.isEmpty() || studentNumber.isEmpty() ||
		studentChinese.isEmpty() || studentEnglish.isEmpty() ||
		studentMath.isEmpty())
	{
		QMessageBox::information(this, "Hint", "Please enter complete information");
		return;
	}

	QFile file("student.txt");
	file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
	//open()可以用来打开文件这里QIODevice::WriteOnly代表将文件以只写的方式打开
	//QIODevice::Text代表我们打开的是文本文件，QIODevice::Text会对end-of-line结束符进行转译
	//QIODevice::Append以追加的方式打开，新增加的内容将被追加到文件末尾

	//if (!file.isOpen()) 
	//{ //如果数据文件没有打开，弹出对话框提示用户
	//	QMessageBox::information(this, "反馈", "数据文件打开失败");
	//	return ;
	//}
	QTextStream out(&file);
	//QTextStream可以进行一些基本的文本读写，比如QString int char之类的数据QDataStream可以进行一个如QMap QPoint之类数据的读写。
	out << studentName << " " << studentSex << " " << studentAge << " " << studentNumber << " " << studentChinese << " " << studentEnglish << " " << studentMath << '\n';
	//将我们刚刚获取的数据写入文件
	file.close();
	QMessageBox::information(this, "Success", "Successfully Added");
	lineEditName->clear();
	lineEditSex->clear();
	lineEditAge->clear();
	lineEditNumber->clear();
	lineEditChinese->clear();
	lineEditEnglish->clear();
	lineEditMath->clear();

	//将用户输入的数据清空

	/*if(ui->idLineEdit->text() == "") {
		QMessageBox::about(NULL, "反馈", "id不能为空");
		return;
	}*/
	QFile file2("student.txt");
	file2.open(QIODevice::ReadOnly | QIODevice::Text);
	//以只读的方式打开文本文件
	//if (!file.isOpen()) { //文件打开失败
	//	QMessageBox::about(NULL, "反馈", "文件打开失败");
	//	return;
	//}
	QTextStream inp(&file2);
	//以file作为Qt文本流
	QVector<CStudentInfo> allStudentInfo;
	//数据类型为StudentInfo的QVector容器
	while (!inp.atEnd()) { //读到文件结尾
		QString Name, Number, Sex;
		int Chinese, Math, English, Age;
		inp >> Name >> Sex >> Age >> Number >> Chinese >> Math >> English;
		allStudentInfo.push_back(CStudentInfo(Name, Number, Sex, Age, Chinese, Math, English));
		//调用之前建立的构造函数实例化一个StudentInfo对象并将其加入allStudentInfo
	}
	allStudentInfo.pop_back();
	//扔掉最后的无用数据
	file2.close();

	CMainWidget* mainWidget = (CMainWidget*)parentWidget();

	mainWidget->tableReflash(allStudentInfo);

	this->close();
	
}

