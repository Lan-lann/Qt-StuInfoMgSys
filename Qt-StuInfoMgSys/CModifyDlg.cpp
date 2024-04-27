#include "CModifyDlg.h"
CModifyDlg::CModifyDlg(QWidget* parent)
	:QDialog(parent)
{
	resize(250, 500);
	setWindowTitle("ModifyStudentInfo");
	/*this->setStyleSheet(".QPushButton,QLineEdit{border-color:#000000;background-color:#909399;color:black;} \
		.QLabel{background-color:#909399;}");*/
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
	lineEditName->setFixedHeight(25);
	lineEditSex = new QLineEdit(this);
	lineEditSex->setFixedHeight(25);
	lineEditAge = new QLineEdit(this);
	lineEditAge->setFixedHeight(25);
	lineEditNumber = new QLineEdit(this);
	lineEditNumber->setFixedHeight(25);
	lineEditChinese = new QLineEdit(this);
	lineEditChinese->setFixedHeight(25);
	lineEditEnglish = new QLineEdit(this);
	lineEditEnglish->setFixedHeight(25);
	lineEditMath = new QLineEdit(this);
	lineEditMath->setFixedHeight(25);
	btnAdd = new QPushButton(this);
	btnAdd->setFixedHeight(25);
	btnAdd->setText("Modify");

	lineEditName->setFixedWidth(100);
	lineEditSex->setFixedWidth(100);
	lineEditAge->setFixedWidth(100);
	lineEditNumber->setFixedWidth(100);
	lineEditChinese->setFixedWidth(100);
	lineEditEnglish->setFixedWidth(100);
	lineEditMath->setFixedWidth(100);
	btnAdd->setFixedWidth(150);

	CMainWidget* mainWidget = (CMainWidget*)parentWidget();
	int rowCount = mainWidget->pTableMain->rowCount();
	for (int row = 0; row < rowCount; row++) {
		QTableWidgetItem* item = mainWidget->pTableMain->item(row, 0);
		Qt::CheckState status = item->checkState();
		if (status == Qt::CheckState::Checked) {
			QLineEdit* numberItem = (QLineEdit*)mainWidget->pTableMain->cellWidget(row, 5);
			QLineEdit* nameItem = (QLineEdit*)mainWidget->pTableMain->cellWidget(row, 2);
			QLineEdit* sexItem = (QLineEdit*)mainWidget->pTableMain->cellWidget(row, 3);
			QLineEdit* ageItem = (QLineEdit*)mainWidget->pTableMain->cellWidget(row, 4);
			QLineEdit* chineseItem = (QLineEdit*)mainWidget->pTableMain->cellWidget(row, 6);
			QLineEdit* mathItem = (QLineEdit*)mainWidget->pTableMain->cellWidget(row, 7);
			QLineEdit* englishItem = (QLineEdit*)mainWidget->pTableMain->cellWidget(row, 8);
			lineEditNumber->setText(numberItem->text());
			lineEditName->setText(nameItem->text());
			lineEditSex->setText(sexItem->text());
			lineEditAge->setText(ageItem->text());
			lineEditChinese->setText(chineseItem->text());
			lineEditEnglish->setText(englishItem->text());
			lineEditMath->setText(mathItem->text());
		}
	}
	

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
	pVLayMain->addLayout(pHLayMath);
	pVLayMain->addLayout(pHLayEnglish);
	pVLayMain->addLayout(pHLayAdd);

	connect(btnAdd, &QPushButton::clicked, this, &CModifyDlg::modifyStudent);
}

CModifyDlg::~CModifyDlg()
{

}

void CModifyDlg::modifyStudent()
{
	CMainWidget* mainWidget = (CMainWidget*)parentWidget();
	QVector<CStudentInfo> query;
	mainWidget->loadStudentInfo(query);



	int rowCount = mainWidget->pTableMain->rowCount();
	QString number;
	for (int row = 0; row < rowCount; row++) {
		QTableWidgetItem* item = mainWidget->pTableMain->item(row, 0);
		Qt::CheckState status = item->checkState();
		if (status == Qt::CheckState::Checked) {
			QLineEdit* numberItem = (QLineEdit*)mainWidget->pTableMain->cellWidget(row, 5);
			number = numberItem->text();

		}
	}

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
		QMessageBox::information(nullptr, "Hint", "Please enter complete information");
		return;
	}

	for (int i = 0; i < query.size(); i++)
	{
		if (query[i].getNumber() == number)
		{
			query[i] = CStudentInfo(studentName, studentNumber, studentSex, studentAge.toInt(), studentChinese.toInt(), studentMath.toInt(), studentEnglish.toInt());
			break;
		}
	}

	QMessageBox::information(this, "Success", "Successfully Modify");

	QFile file("student.txt");
	file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate);
	QTextStream out(&file);
	for (int i = 0; i < query.size(); i++)
	{
		out << query[i].getName() << " " << query[i].getSex() << " " << query[i].getAge() << " " << query[i].getNumber() << " " << query[i].getChinese() << " " << query[i].getMath() << " " << query[i].getEnglish() << '\n';
	}

	file.close();
	mainWidget->tableReflash(query);

	this->close();
}