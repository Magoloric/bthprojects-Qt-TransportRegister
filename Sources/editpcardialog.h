/* Dialog for editing private cars */
#ifndef EDITPCARDIALOG_H
#define EDITPCARDIALOG_H

#include <QDialog>

namespace Ui {
class editPCarDialog;
}

class editPCarDialog : public QDialog
{
Q_OBJECT

public:
explicit editPCarDialog(QWidget *parent = 0);
~editPCarDialog();

//Get-functions used to return data from fields to other window
//for editing vehicles in register.
QString getMod();
QString getOwName();
QString getOwSur();
QString getOwID();
QString getEnsur();
private:
Ui::editPCarDialog *ui;
};

#endif // EDITPCARDIALOG_H
