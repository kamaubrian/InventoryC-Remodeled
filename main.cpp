/*
 * PROJECT :: INVENTORY SYSTEM V.1.1
 * AUTHORS :: BRIAN KAMAU 15-1659,MBONDA TSHITOKO 15-0674
 *
 *
 *
 *
 *
*/
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
