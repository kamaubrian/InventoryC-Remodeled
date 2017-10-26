#ifndef EDITITEMS_H
#define EDITITEMS_H
#include <QDialog>
//#include "mainview.h"

namespace Ui {
class editItems;
}

class editItems : public QDialog
{
    Q_OBJECT

public:
    explicit editItems(QWidget *parent = 0);
    ~editItems();

private slots:
    void on_exit_clicked();

    void on_submitEdit_clicked();
private:
    Ui::editItems *ui;
    //mainView * mainview;



};

#endif // EDITITEMS_H
