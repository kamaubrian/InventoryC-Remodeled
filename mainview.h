#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QDialog>

namespace Ui {
class mainView;
}

class mainView : public QDialog
{
    Q_OBJECT

public:
    explicit mainView(QWidget *parent = 0);
    ~mainView();

private:
    Ui::mainView *ui;
};

#endif // MAINVIEW_H
