#include "adminpage.h"
#include "ui_adminpage.h"
#include <QtSql/QtSql>
#include "mainview.h"
#include<QtSql/QSqlQuery>
#include <QCoreApplication>
#include<QtSql/QSqlDatabase>
#include<QMessageBox>
#include <QException>
#include <iostream>



bool ConnectDatabase();
static bool disconnectDatabase();
QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

using namespace std;
adminPage::adminPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminPage)
{
    ui->setupUi(this);
}

adminPage::~adminPage()
{
    delete ui;
}

void adminPage::on_pushButton_clicked()
{
    try{

         QSqlQuery query;
         QString username;
         QString password;
         QString user;
         QString pass;
         QString sql;
         username=ui->username->text();
         password=ui->password->text();
         ConnectDatabase();
         sql="SELECT *FROM Users";
         query.exec(sql);
         if(username.isEmpty()){
             QMessageBox::warning(this,"Empty Username","Enter Username");
             return;
         }
         if(password.isEmpty()){
             QMessageBox::warning(this,"Empty Password","Enter Password");
             return;
         }
         if(sql.size()>0){
             if(query.next()){
                 user=query.value("Username").toString();
                 pass=query.value("Password").toString();
                 if(user==username && pass==password){
                     hide();
                     mainview = new mainView(this);
                     mainview->show();
                 }else{
                     QMessageBox::warning(this,"Error","Unknown User");
                     username="";
                     password="";
                  }

             }
         }

    }catch(QException ex){
        cout<<"Exception"<<ex.what()<<endl;
    }
    disconnectDatabase();

}
bool ConnectDatabase(){
    bool success = true;
    try{
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("wamatu");
    db.setDatabaseName("InventoryC++");
    db.setPort(3306);
    db.open();

    }catch(QException ex){
        cout<<"Error"<<ex.what()<<endl;
    }
return success;
}
static bool disconnectDatabase(){
    bool success = true;
    if(db.open()){
        db.close();
        success = true;
    }
    return success;

}
