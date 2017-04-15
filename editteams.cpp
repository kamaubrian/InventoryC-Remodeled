#include "editteams.h"
#include "ui_editteams.h"
#include <QSize>

editTeams::editTeams(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editTeams)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(330,190));
}

editTeams::~editTeams()
{
    delete ui;
}
