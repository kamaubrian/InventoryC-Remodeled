#ifndef RETURNITEMS_H
#define RETURNITEMS_H

#include <QDialog>

namespace Ui {
class returnItems;
}

class returnItems : public QDialog
{
    Q_OBJECT

public:
    explicit returnItems(QWidget *parent = 0);
    ~returnItems();

private:
    Ui::returnItems *ui;
};

#endif // RETURNITEMS_H
