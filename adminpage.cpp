#include "adminpage.h"
#include "ui_adminpage.h"
#include "mainview.h"

#include <QCoreApplication>
#include <QMessageBox>
#include <QException>
#include <iostream>
#include <QDebug>
#include <vector>


using namespace std;\
QString getUsername(QString user);
QString getPassword(QString pass);
adminPage::adminPage(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::adminPage)
{
    ui->setupUi(this);
    ui->username->setPlaceholderText("Enter Username");
    ui->password->setPlaceholderText("Enter Password");
}

adminPage::~adminPage()
{
    delete ui;
}

void adminPage::on_pushButton_clicked()
{
    try{


         QString username;
         QString password;

         username=ui->username->text();
         password=ui->password->text();
         if(username.isEmpty()){
             QMessageBox::warning(this,"Empty Username","Enter Username");
             return;
         }
         if(password.isEmpty()){
             QMessageBox::warning(this,"Empty Password","Enter Password");
             return;
         }

             if(username.compare(getUsername(username))==0 && password.compare(getPassword(password))==0){
                 hide();
                 disconnectDatabase();
                 mainview = new mainView(this);
                 mainview->show();
             }else{
                 QMessageBox::warning(this,"Error","Unknown User");
                 qDebug()<<username<<":::::"<<endl;
                 qDebug()<<password<<"::::::"<<endl;
                 ui->username->setText("");
                 ui->password->setText("");

              }

    }catch(QException ex){
        cout<<"Exception"<<ex.what()<<endl;
    }

}
QString getUsername(QString user){
    adminPage conn;
    QString username="";
    conn.connectDatabase();
    QSqlQuery query;
    QString sql;
    sql="SELECT *FROM Credentials WHERE Username='"+user+"'";
    if(query.exec(sql)){
        while(query.next()){
            username=query.value("Username").toString();
        }
    }
    conn.disconnectDatabase();
    return username;
}
QString getPassword(QString pass){

    adminPage conn;
    QString password="";
    conn.connectDatabase();
    QSqlQuery query;
    QString sql;

    sql="SELECT *FROM Credentials WHERE Password='"+pass+"'";
    if(query.exec(sql)){
        while(query.next()){
            password=query.value("Password").toString();
        }
    }
    conn.disconnectDatabase();
    return password;
}




