#include "adminpage.h"
#include "ui_adminpage.h"
#include "mainview.h"

#include <QCoreApplication>
#include <QMessageBox>
#include <QException>
#include <iostream>
#include <QDebug>
#include <vector>


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
         QString sql;

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
         connectDatabase();
         sql="SELECT *FROM Credentials WHERE Username='"+username+"'and Password ='"+password+"'";

         int count;
         query.exec(sql);
             while(query.next()){
                count++;
             }
             if(count==1){
                 hide();
                 disconnectDatabase();
                 mainview = new mainView(this);
                 mainview->show();
             }else if(count!=1){
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



