#include "adminpage.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QStyle>
#include <QSize>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    adminPage w;
    w.setFixedSize(QSize(390,250));
    w.setGeometry(
                   QStyle::alignedRect(
                       Qt::LeftToRight,
                       Qt::AlignCenter,
                       w.size(),
                       qApp->desktop()->availableGeometry()
                       )
                   );

    w.setWindowTitle("Inventory System");
    w.show();

    return a.exec();
}
