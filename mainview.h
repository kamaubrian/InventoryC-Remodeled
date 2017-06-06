#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QDialog>
#include "edititems.h"
#include "availableinventory.h"
#include "editteams.h"
#include "returnitems.h"

namespace Ui {
class mainView;
}

class mainView : public QDialog
{
    Q_OBJECT

public:
    explicit mainView(QWidget *parent = 0);
    ~mainView();

private slots:
    void on_editItems_clicked();
    void on_availableIventory_clicked();
    void on_editTeams_clicked();
    void on_editTeams_2_clicked();

    void on_previewTable_clicked();
    void clearTextBox();
    void on_submitDb_clicked();

    void on_exitSystem_clicked();

private:
    Ui::mainView *ui;
    editItems *edititems;
    availableInventory *available;
    editTeams *editteams;
    returnItems *returnitem;


};

#endif // MAINVIEW_H
