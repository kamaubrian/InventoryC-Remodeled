#include "availableinventory.h"
#include "ui_availableinventory.h"
#include <QMessageBox>
#include "adminpage.h"


availableInventory::availableInventory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::availableInventory)
{
    ui->setupUi(this);
    this->setWindowTitle("Check Available Inventory");

}

availableInventory::~availableInventory()
{
    delete ui;
}

void availableInventory::on_pushButton_clicked()
{
    QMessageBox::information(this,"Help Information","Please Contact Database Manager");

}

void availableInventory::on_availableInventory_2_clicked()
{
    adminPage conn;
    QSqlQueryModel * model = new QSqlQueryModel();
    conn.connectDatabase();
    QSqlQuery * query = new QSqlQuery(conn.db);

    query->prepare("SELECT *FROM Inventory_Information");
    query->exec();
    model->setQuery(*query);
    ui->tableView->setModel(model);
    conn.disconnectDatabase();


}

void availableInventory::on_pushButton_2_clicked()
{
    hide();
    mainView conn;
    conn.show();

}
