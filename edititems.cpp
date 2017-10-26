#include "edititems.h"
#include"adminpage.h"
#include "ui_edititems.h"
#include "mainview.h"
#include <QSize>
#include <QMessageBox>
#include <vector>
#include<iostream>

using namespace std;

bool addItems(QString itemName, QString quantity);
bool removeItems(QString itemName);
bool checkItemExist(QString itemName);

editItems::editItems(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editItems)
{
    ui->setupUi(this);
    this->setWindowTitle("Make Changes to Items");
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
    QString itemName,quantity;
    itemName = ui->editItemName->text();
    quantity = ui->itemamount->text();
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
                      addItems(itemName,quantity);
                      QMessageBox::information(this,"Success","Items Added Successfully");
                    }

        }catch(QException ex){
            cout<<ex.what()<<endl;
        }

    }else if(ui->editItemsCombo->currentText()=="REMOVE"){
        try{
            if(!checkItemExist(itemName)){
                QMessageBox::warning(this,"Does not Exist","Item Does Not Exist");
            }else{
                ui->itemamount->setEnabled(false);
                removeItems(itemName);
                QMessageBox::information(this,"Success","Items Removed Successfully");
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

        QSqlQuery query;
        sql= "SELECT *FROM Inventory_Info WHERE ItemName ='"+itemName+"'";
       if(query.exec(sql)){
        while(query.next()){
            itemlist.push_back("ItemName");
           }
       }
        conn.disconnectDatabase();
        return itemlist;
}
bool checkItemExist(QString itemName){
    return !getItem(itemName).empty();
}
bool addItems(QString itemName,QString quantity){
    adminPage conn;
    bool success;
    conn.connectDatabase();
    QSqlQuery query;
    QString sql;
    sql="INSERT INTO Inventory_Info(ItemName,Amount) VALUES('"+itemName+"','"+quantity+"')";
    query.prepare(sql);
    query.bindValue(":ItemName",itemName);
    query.bindValue(":Amount",quantity);
    if(query.exec(sql)){
        success = true;
    }else{
        success=false;
    }
    conn.disconnectDatabase();
    return success;
}
bool removeItems(QString itemName){
    adminPage conn;
    bool success;
    conn.connectDatabase();
    QSqlQuery query;
    QString sql;

    sql= "DELETE FROM Inventory_Info WHERE ItemName ='"+itemName+"'";
    query.prepare(sql);
    if(query.exec(sql)){
        success= true;
    }else{
        success=false;
    }

    return success;

}


