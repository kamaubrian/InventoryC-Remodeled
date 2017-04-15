#ifndef EDITTEAMS_H
#define EDITTEAMS_H

#include <QDialog>

namespace Ui {
class editTeams;
}

class editTeams : public QDialog
{
    Q_OBJECT

public:
    explicit editTeams(QWidget *parent = 0);
    ~editTeams();

private:
    Ui::editTeams *ui;
};

#endif // EDITTEAMS_H
