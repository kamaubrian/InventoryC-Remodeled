#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include <QMainWindow>
#include "mainview.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QtSql>
#include <iostream>

using namespace std;
namespace Ui {
class adminPage;
}

class adminPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminPage(QWidget *parent = 0);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    //***This function defines the MYSQL Database Connection on the Localhost.**/
    bool connectDatabase(){


        bool success = true;
        try{
        db.setHostName("localhost");
        db.setUserName("root");
        db.setPassword("wamatu");
        db.setDatabaseName("Inventory");
        db.setPort(3306);
        db.open();
        cout<<"running"<<endl;
        }catch(QException ex){
            cout<<"Error"<<ex.what()<<endl;
        }

    return success;
    }

    bool disconnectDatabase(){



        bool success = true;
            db.close();

            success = true;
        return success;
    }
    ~adminPage(); //The Destructor for the Class adminPage.

private slots:
    void on_pushButton_clicked();

private:

    Ui::adminPage *ui;
   // QSqlDatabase db;

    mainView *mainview;   //Pointer pointing to mainview ui form.


};


#endif // ADMINPAGE_H
