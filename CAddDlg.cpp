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
	//open()�����������ļ�����QIODevice::WriteOnly�����ļ���ֻд�ķ�ʽ��
	//QIODevice::Text�������Ǵ򿪵����ı��ļ���QIODevice::Text���end-of-line����������ת��
	//QIODevice::Append��׷�ӵķ�ʽ�򿪣������ӵ����ݽ���׷�ӵ��ļ�ĩβ

	//if (!file.isOpen()) 
	//{ //��������ļ�û�д򿪣������Ի�����ʾ�û�
	//	QMessageBox::information(this, "����", "�����ļ���ʧ��");
	//	return ;
	//}
	QTextStream out(&file);
	//QTextStream���Խ���һЩ�������ı���д������QString int char֮�������QDataStream���Խ���һ����QMap QPoint֮�����ݵĶ�д��
	out << studentName << " " << studentSex << " " << studentAge << " " << studentNumber << " " << studentChinese << " " << studentEnglish << " " << studentMath << '\n';
	//�����Ǹոջ�ȡ������д���ļ�
	file.close();
	QMessageBox::information(this, "Success", "Successfully Added");
	lineEditName->clear();
	lineEditSex->clear();
	lineEditAge->clear();
	lineEditNumber->clear();
	lineEditChinese->clear();
	lineEditEnglish->clear();
	lineEditMath->clear();

	//���û�������������

	/*if(ui->idLineEdit->text() == "") {
		QMessageBox::about(NULL, "����", "id����Ϊ��");
		return;
	}*/
	QFile file2("student.txt");
	file2.open(QIODevice::ReadOnly | QIODevice::Text);
	//��ֻ���ķ�ʽ���ı��ļ�
	//if (!file.isOpen()) { //�ļ���ʧ��
	//	QMessageBox::about(NULL, "����", "�ļ���ʧ��");
	//	return;
	//}
	QTextStream inp(&file2);
	//��file��ΪQt�ı���
	QVector<CStudentInfo> allStudentInfo;
	//��������ΪStudentInfo��QVector����
	while (!inp.atEnd()) { //�����ļ���β
		QString Name, Number, Sex;
		int Chinese, Math, English, Age;
		inp >> Name >> Sex >> Age >> Number >> Chinese >> Math >> English;
		allStudentInfo.push_back(CStudentInfo(Name, Number, Sex, Age, Chinese, Math, English));
		//����֮ǰ�����Ĺ��캯��ʵ����һ��StudentInfo���󲢽������allStudentInfo
	}
	allStudentInfo.pop_back();
	//�ӵ�������������
	file2.close();

	CMainWidget* mainWidget = (CMainWidget*)parentWidget();

	mainWidget->tableReflash(allStudentInfo);

	this->close();
	
}

