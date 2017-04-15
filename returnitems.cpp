#include "returnitems.h"
#include "ui_returnitems.h"
#include<QSize>

returnItems::returnItems(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::returnItems)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(330,200));
}

returnItems::~returnItems()
{
    delete ui;
}
