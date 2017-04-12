#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include <QMainWindow>
#include "mainview.h"

namespace Ui {
class adminPage;
}

class adminPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminPage(QWidget *parent = 0);

    ~adminPage();

private slots:


    void on_pushButton_clicked();

private:
    Ui::adminPage *ui;
    mainView *mainview;

};

#endif // ADMINPAGE_H
