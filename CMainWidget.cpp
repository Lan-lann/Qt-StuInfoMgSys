#include "CMainWidget.h"


CMainWidget::CMainWidget(QWidget* p)
	:QWidget(p)
{
    this->setFixedSize(973, 574);
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint);

    //关闭按钮设置
    QPushButton* btnCloseMain = new QPushButton(this);
    btnCloseMain->setObjectName(QString("btnCloseMain"));
    btnCloseMain->setText("");
    btnCloseMain->setFixedSize(32, 32);
    btnCloseMain->setStyleSheet("QPushButton{background-image:url(:/CLoginDlg/resources/Login/close.svg);border:none}" \
        "QPushButton:hover{" \
        "background-color:rgb(99, 99, 99);" \
        "background-image:url(:/CLoginDlg/resources/Login/close_hover.svg);border:none;}");

    QPushButton* btnMinMain = new QPushButton(this);
    btnMinMain->setObjectName("btnMinMain");
    btnMinMain->setText("");
    btnMinMain->setFixedSize(32, 32);
    btnMinMain->setStyleSheet("QPushButton{background-image:url(:/CLoginDlg/resources/Login/min.svg);border:none}" \
        "QPushButton:hover{" \
        "background-color:rgb(99, 99, 99);" \
        "background-image:url(:/CLoginDlg/resources/Login/min_hover.svg);border:none;}");

    QHBoxLayout* pHLay1 = new QHBoxLayout();
    pHLay1->addWidget(btnMinMain);
    pHLay1->addWidget(btnCloseMain);

    pTableMain = new QTableWidget(this);
    //pTableMain->setGeometry(100, 100, 1000, 1000);
    pTableMain->verticalHeader()->setHidden(true);
    pTableMain->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    pTableMain->setColumnCount(9);

    pTableMain->setHorizontalHeaderItem(0, new QTableWidgetItem("*选择栏"));
    pTableMain->setHorizontalHeaderItem(1, new QTableWidgetItem("ID"));
    pTableMain->setHorizontalHeaderItem(2, new QTableWidgetItem("学生姓名"));
    pTableMain->setHorizontalHeaderItem(3, new QTableWidgetItem("学生性别"));
    pTableMain->setHorizontalHeaderItem(4, new QTableWidgetItem("学生年龄"));
    pTableMain->setHorizontalHeaderItem(5, new QTableWidgetItem("学生学号"));
    pTableMain->setHorizontalHeaderItem(6, new QTableWidgetItem("语文成绩"));
    pTableMain->setHorizontalHeaderItem(7, new QTableWidgetItem("数学成绩"));
    pTableMain->setHorizontalHeaderItem(8, new QTableWidgetItem("英语成绩"));


    QPushButton* btnAdd = new QPushButton(this);
    QPushButton* btnModify = new QPushButton(this);
    QPushButton* btnSelect = new QPushButton(this);
    QPushButton* btnSort = new QPushButton(this);
    QPushButton* btnCount = new QPushButton(this);
    QPushButton* btnDel = new QPushButton(this);
    QHBoxLayout* pHLay2 = new QHBoxLayout();
    btnAdd->setText("增加学生信息");
    btnModify->setText("修改学生信息");
    btnDel->setText("删除学生信息");
    btnSelect->setText("信息查询");
    btnSort->setText("成绩排序");
    btnCount->setText("成绩统计");
    pHLay2->addWidget(btnAdd);
    pHLay2->addWidget(btnDel);
    pHLay2->addWidget(btnModify);
    pHLay2->addWidget(btnSelect);
    pHLay2->addWidget(btnSort);
    pHLay2->addWidget(btnCount);

    QHBoxLayout* pHLayMain = new QHBoxLayout();
    pHLayMain->addLayout(pHLay2);
    pHLayMain->addLayout(pHLay1);
    QVBoxLayout* pVLayMain = new QVBoxLayout(this);
    pVLayMain->addLayout(pHLayMain);
    pVLayMain->addWidget(pTableMain);

    connect(btnCloseMain, &QPushButton::clicked, this, &QWidget::close);
    connect(btnMinMain, &QPushButton::clicked, this, &QWidget::showMinimized);
    connect(btnAdd, &QPushButton::clicked, [=] {
        CAddDlg* addStudent = new CAddDlg(this);
        addStudent->setAttribute(Qt::WA_DeleteOnClose); // 关闭时销毁对象
        addStudent->setModal(true); // 设置为模态窗口，即窗口打开后只能该修改界面操作，不能在其他窗口进行操作，保证操作时的唯一性
        addStudent->show();
        });
    
    QVector<CStudentInfo> query;
    this->loadStudentInfo(query);
    this->tableReflash(query);
   
}
CMainWidget::~CMainWidget()
{
    
}

void CMainWidget::tableReflash(QVector<CStudentInfo>& query)
{
    for (int row = pTableMain->rowCount() - 1; row >= 0; row--)
    {
        pTableMain->removeRow(row);
    }

    int row = 0;

    while (row < query.size())
    {
        int index_row = pTableMain->rowCount();
        pTableMain->setRowCount(index_row + 1);
        //第一列插入复选框
        QTableWidgetItem* check = new QTableWidgetItem();
        check->setCheckState(Qt::Unchecked);
        check->setFlags(check->flags() ^ Qt::ItemIsEditable);
        pTableMain->setItem(row, 0, check); //插入复选框
        cellSetting(row, 1, QString("%1").arg(row + 1));
        cellSetting(row, 2, query[row].getName());
        cellSetting(row, 3, query[row].getSex());
        cellSetting(row, 4, query[row].toString(query[row].getAge()));
        cellSetting(row, 5, query[row].getNumber());
        cellSetting(row, 6, query[row].toString(query[row].getChinese()));
        cellSetting(row, 7, query[row].toString(query[row].getEnglish()));
        cellSetting(row, 8, query[row].toString(query[row].getMath()));
        row++;
    }

}


void CMainWidget::cellSetting(int row, int column, QString text)
{
    QLineEdit* lineEdit = new QLineEdit(text);
    lineEdit->setStyleSheet("border: 0px;color:black"); // 设置该输入框无边框，黑色字体
    // 设置只读
    lineEdit->setReadOnly(true);
    pTableMain->setCellWidget(row, column, lineEdit);
}

void CMainWidget::loadStudentInfo(QVector<CStudentInfo>& query)
{
    QFile file2("student.txt");
    file2.open(QIODevice::ReadOnly | QIODevice::Text);
    //以只读的方式打开文本文件
    //if (!file.isOpen()) { //文件打开失败
    //	QMessageBox::about(NULL, "反馈", "文件打开失败");
    //	return;
    //}
    QTextStream inp(&file2);
    //以file作为Qt文本流
    //数据类型为StudentInfo的QVector容器
    while (!inp.atEnd()) { //读到文件结尾
        QString Name, Number, Sex;
        int Chinese, Math, English, Age;
        inp >> Name >> Sex >> Age >> Number >> Chinese >> Math >> English;
        query.push_back(CStudentInfo(Name, Number, Sex, Age, Chinese, Math, English));
        //调用之前建立的构造函数实例化一个StudentInfo对象并将其加入allStudentInfo
    }
    query.pop_back();
    //扔掉最后的无用数据
    file2.close();
}
//void CMainWidget::on_btnCloseMain_clicked()
//{
//    this->close();
//}
//
//void CMainWidget::on_btnMinMain_clicked()
//{
//    this->showMinimized();
//}

//void CMainWidget::on_btnAdd_clicked()
//{
//    CAddDlg* addStudent = new CAddDlg(this);
//    addStudent->setAttribute(Qt::WA_DeleteOnClose); // 关闭时销毁对象
//    addStudent->setModal(true); // 设置为模态窗口，即窗口打开后只能该修改界面操作，不能在其他窗口进行操作，保证操作时的唯一性
//    addStudent->show();
//}

void CMainWidget::mousePressEvent(QMouseEvent* event)
{
    mouse_pos = event->globalPos();
    window_pos = this->pos();
    diff_pos = mouse_pos - window_pos;
}

void CMainWidget::mouseMoveEvent(QMouseEvent* event)
{
    QPoint pos = event->globalPos();
    //this->move(pos);
    this->move(pos - diff_pos);
}
