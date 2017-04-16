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

private slots:
    void on_exitTeam_clicked();

    void on_submitEditTeam_clicked();
    void clearTextBoxes();

private:
    Ui::editTeams *ui;
};

#endif // EDITTEAMS_H
