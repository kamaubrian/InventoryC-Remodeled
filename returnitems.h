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

private slots:
    void on_refresh_clicked();

    void on_returnSubmit_2_clicked();

    void on_returnSubmit_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::returnItems *ui;
};

#endif // RETURNITEMS_H
