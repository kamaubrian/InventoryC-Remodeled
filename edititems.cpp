#include "edititems.h"
#include"adminpage.h"
#include "ui_edititems.h"
#include "mainview.h"
#include <QSize>
#include <QMessageBox>
#include <vector>
#include<iostream>

using namespace std;
bool checkItemExist(QString itemName);
editItems::editItems(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editItems)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(330,230));
}

editItems::~editItems()
{
    delete ui;
}

void editItems::on_exit_clicked()
{
    hide();
}

void editItems::on_submitEdit_clicked()
{
    adminPage conn;
    QString itemName;
    int quantity;
    itemName = ui->editItemName->text();
    quantity = ui->itemamount->value();
    if(itemName.isEmpty()){
        QMessageBox::warning(this,"Error","Enter Item Name");
        return;
    }
    if(quantity<=0){
        QMessageBox::warning(this,"Error","Item Quantity Not Zero");
        return;
    }
    if(ui->editItemsCombo->currentText()=="ADD"){
            try{
                if(checkItemExist(itemName)){
                    QMessageBox::warning(this,"Already Exists","Item Alreasy Exists");
                }
                else{
                    conn.connectDatabase();
                    QSqlQuery sql;
                    sql.prepare("INSERT *INTO `Inventory_Info`(ItemName,Amount) values ('"+itemName+"','"+quantity+"')");

                    if(sql.exec()){
                        conn.disconnectDatabase();
                        QMessageBox::warning(this,"Correct","Correct");
                    }else{
                        QMessageBox::warning(this,"Database Error","Database Error");
                    }

                }

        }catch(QException ex){
            cout<<ex.what()<<endl;
        }

    }
}
vector<QString> getItem(QString itemName){
    adminPage conn;
    conn.connectDatabase();
    vector<QString> itemlist;
    QString sql;

    try{
        QSqlQuery query;
        sql= "SELECT *FROM Inventory_Info WHERE ItemName ='"+itemName+"'";
        query.exec(sql);
        while(query.next()){
            itemlist.push_back("ItemName");
        }

    }catch(QException ex){
        cout<<"Error"<<ex.what()<<endl;
    }
    conn.disconnectDatabase();

    return itemlist;
}
bool checkItemExist(QString itemName){
    return !getItem(itemName).empty();
}
