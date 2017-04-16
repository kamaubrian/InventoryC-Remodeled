#include "editteams.h"
#include "ui_editteams.h"
#include <QSize>
#include "adminpage.h"
#include <vector>
#include <iostream>
#include <QMessageBox>

using namespace std;

vector<QString>getTeam(QString team);
bool checkTeamExist(QString teamName);
bool removeTeam(QString teamName, QString id);
bool addNewTeam(QString teamName, QString teamManager, QString id);

editTeams::editTeams(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editTeams)
{
    ui->setupUi(this);
    this->setWindowTitle("Make Changes To Teams");
    this->setFixedSize(QSize(330,250));
}

editTeams::~editTeams()
{
    delete ui;
}

void editTeams::on_exitTeam_clicked()
{
    hide();
}

void editTeams::on_submitEditTeam_clicked()
{
    QString tName,tManager,id;
    tName=ui->editTeamName->text();
    tManager=ui->teamManager->text();
    id=ui->teamID->text();
    if(tName.isEmpty()){
        QMessageBox::warning(this,"Error","Enter Team Name");
        return;
    }
    if(tManager.isEmpty()){
        QMessageBox::warning(this,"Error","Enter Team Manager Name");
        return;
    }
    if(id.isEmpty()){
        QMessageBox::warning(this,"Error","Enter Identification Number");
        return;
    }

    if(ui->editTeam->currentText()=="ADD"){
       if(checkTeamExist(tName)){
           QMessageBox::warning(this,"Exists","Item Already Exists");
           return;
       } else{
           try{
               addNewTeam(tName,tManager,id);
               QMessageBox::information(this,"Success","Team Added SuccessFully");
               clearTextBoxes();

           }catch(QException ex){
               cout<<"Error"<<ex.what()<<endl;
           }
       }
    }else if(ui->editTeam->currentText()=="REMOVE"){
        if(!checkTeamExist(tName)){
            QMessageBox::warning(this,"Not Found","Team Does Not Exist");
            return;
        }else{
            try{
                ui->teamManager->setDisabled(true);
                removeTeam(tName,id);
                QMessageBox::information(this,"Success","Team Removed Successfully");
                clearTextBoxes();

            }catch(QException ex){
                cout<<"Database Error"<<ex.what()<<endl;
            }
        }
    }



}
vector<QString>getTeam(QString team){
    adminPage conn;
    conn.connectDatabase();
    QSqlQuery query;
    vector<QString> teaml;
    QString sql;
    try{
        sql="SELECT *FROM Team_Information WHERE TeamName ='"+team+"'";
        query.exec(sql);
        if(query.exec(sql)){
            while(query.next()){
                teaml.push_back("TeamName");
            }
        }
    }catch(QException ex){
        cout<<"Database Error"<<ex.what()<<endl;
    }
    conn.disconnectDatabase();
    return teaml;
}
bool checkTeamExist(QString teamName){

   return !getTeam(teamName).empty();
}
bool addNewTeam(QString teamName,QString teamManager,QString id){
    adminPage conn;
    bool success;
    conn.connectDatabase();
    QSqlQuery query;
    QString sql;

    try{
        sql="INSERT INTO Team_Information(TeamName,TeamManager,Identification) VALUES('"+teamName+"','"+teamManager+"','"+id+"')";
        query.prepare(sql);
        query.bindValue(":TeamName",teamName);
        query.bindValue(":TeamManager",teamManager);
        query.bindValue(":Identification",id);

        if(query.exec(sql)){
            success = true;
        }else{
            success=false;
        }

    }catch(QException ex){
        cout<<"Database Error"<<ex.what()<<endl;
    }
    conn.disconnectDatabase();
    return success;
}
bool removeTeam(QString teamName,QString id){
    adminPage conn;
    conn.connectDatabase();
    bool success;
    QSqlQuery query;
    QString sql;

    try{
        sql="DELETE FROM Team_Information WHERE TeamName='"+teamName+"' and Identification ='"+id+"'";
        query.prepare(sql);
        if(query.exec(sql)){
            success= true;
            cout<<success<<endl;
        }else{
            success= false;
            cout<<success<<endl;
        }

    }catch(QException ex){
        cout<<"Database Error"<<ex.what()<<endl;
    }
    conn.disconnectDatabase();
    return success;
}
void editTeams::clearTextBoxes(){
    ui->editTeamName->setText("");
    ui->teamID->setText("");
    ui->teamManager->setText("");

}
