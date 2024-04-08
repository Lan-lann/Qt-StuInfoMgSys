#include "CLoginDlg.h"
#include <QtWidgets/QApplication>
#include "CMainWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CLoginDlg w;
    w.show();
    return a.exec();
}
