/*Author: Brian Kamau 15-1659
 * Group One:Inventory System.
 * We have all through the Program used User defined Header files
 * Header files generally contain functions that can be used all through .cpp files throughout the Program.
 *
 *
*/


#include "mainview.h"
#include "ui_mainview.h"
#include "ui_edititems.h"
#include "adminpage.h" //
#include "ui_availableinventory.h"
#include "edititems.h"
#include "availableinventory.h"
#include <QAction>
#include <QMessageBox>
#include <iostream>
#include <ctime>
#include<string>
#include<cstring>
#include <QTime>
#include <QDateTime>

using namespace std;
void populateComboBox();
QDateTime *currenttime=new QDateTime();
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

void mainView::on_availableIventory_clicked()
{
    hide();
    available = new availableInventory(this);
    available->show();
}

void mainView::on_editTeams_clicked()
{
    hide();
    editteams = new editTeams(this);
    editteams->show();
}

void mainView::on_editTeams_2_clicked()
{
    hide();
    returnitem = new returnItems(this);
    returnitem->show();
}

void mainView::on_editItems_clicked()
{
    hide();
    edititems = new editItems(this);
    edititems->show();

}


void mainView::on_previewTable_clicked()
{
    adminPage conn;
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQueryModel * combo = new QSqlQueryModel();
    QSqlQueryModel * teams = new QSqlQueryModel();
    conn.connectDatabase();

    QSqlQuery *query = new QSqlQuery(conn.db);
    QSqlQuery *combom = new QSqlQuery(conn.db);
    QSqlQuery *getTeam = new QSqlQuery(conn.db);

    query->prepare("SELECT *FROM Log_Information");
    combom->prepare("SELECT ItemName FROM Inventory_Information");
    getTeam->prepare("SELECT TeamName FROM Team_Information");

    query->exec();
    combom->exec();
    getTeam->exec();
    model->setQuery(*query);
    combo->setQuery(*combom);
    teams->setQuery(*getTeam);

    ui->tableView->setModel(model);
    ui->itemType->setModel(combo);
    ui->teamName->setModel(teams);
    conn.disconnectDatabase();

}
void mainView::on_submitDb_clicked()
{

    adminPage conn;
    QString studentId,name,itemType,teamName;
    int items;
    teamName=ui->teamName->currentText();
    name=ui->stuName->text();
    itemType=ui->itemType->currentText();
    studentId=ui->stuId->text();
    items=ui->getItemCount->value();


    if(studentId.isEmpty()){
        QMessageBox::warning(this,"Error","Enter Student ID");
        return;
    }if(name.isEmpty()){
        QMessageBox::warning(this,"Error","Enter Student Name");
        return;
    }if(items<=0){
        QMessageBox::warning(this,"Error","Items Borrowed Cannot be Zero");
        return;
    }

    conn.connectDatabase();
    QSqlQuery sql;
    sql.prepare("INSERT INTO Log_Information (DATE,Team Name,Student ID,Student Name,"
                 "Item Type,Amount) VALUES('"+QDateTime::currentDateTime().toString()+"','"+teamName+"','"+studentId+"','"+name+"','"+itemType+"','"+items+"')");

        if(sql.exec()){
        QMessageBox::information(this,"Saved","Log Saved");
        conn.disconnectDatabase();
    }else{
        cout<<"Database Error"<<endl;

    }




}

