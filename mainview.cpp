#include "mainview.h"
#include "ui_mainview.h"

mainView::mainView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainView)
{
    ui->setupUi(this);
    this->setWindowTitle("Main View");
}

mainView::~mainView()
{
    delete ui;
}
