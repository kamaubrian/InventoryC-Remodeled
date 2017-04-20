
#include "returnitems.h"
#include "ui_returnitems.h"
#include "adminpage.h"
#include<QSize>
bool returnItem(QString stuName);
returnItems::returnItems(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::returnItems)
{
    ui->setupUi(this);

    this->setFixedSize(QSize(330,210));
}

returnItems::~returnItems()
{
    delete ui;
}

void returnItems::on_refresh_clicked()
{
    adminPage conn;
    conn.connectDatabase();
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery(conn.db);

    query->prepare("SELECT `Student Name` FROM Log_Information");
    query->exec();
    model->setQuery(*query);
    ui->comboBox->setModel(model);
    conn.disconnectDatabase();

}

void returnItems::on_returnSubmit_2_clicked()
{
    hide();
}

void returnItems::on_returnSubmit_clicked()
{
    QString stuName;
    stuName=ui->comboBox->currentText();
    returnItem(stuName);

}
bool returnItem(QString stuName ){
    bool success;
    adminPage conn;
    conn.connectDatabase();
    QSqlQuery query;
    QString sql;
    sql="DELETE FROM Log_Information WHERE `Student Name` ='"+stuName+"'";
    query.prepare(sql);
    if(query.exec(sql)){
        success=true;
    }else{
        success = false;
    }
    conn.disconnectDatabase();
    return success;

}
/*void returnItems::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QString name = ui->comboBox->currentText();
    adminPage conn;

    conn.connectDatabase();
    QSqlQuery query;
    QString sql;

    sql = "SELECT *FROM Log_Information WHERE `Student Name` ='"+name+"'";
    query.prepare(sql);

    if(query.exec()){
        while(query.next()){
          ui->itemNa->setText(query.value(3).toString());
        }
    }
    conn.disconnectDatabase();

}
*/
