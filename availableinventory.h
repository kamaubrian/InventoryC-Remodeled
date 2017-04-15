#ifndef AVAILABLEINVENTORY_H
#define AVAILABLEINVENTORY_H

#include <QDialog>

namespace Ui {
class availableInventory;
}

class availableInventory : public QDialog
{
    Q_OBJECT

public:
    explicit availableInventory(QWidget *parent = 0);
    ~availableInventory();
private slots:

   void on_pushButton_clicked();
    void on_availableInventory_2_clicked();
   void on_pushButton_2_clicked();

private:
    Ui::availableInventory *ui;
};

#endif // AVAILABLEINVENTORY_H
