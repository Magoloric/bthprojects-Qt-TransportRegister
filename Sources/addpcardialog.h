/* Dialog for adding private cars */

#ifndef ADDPCARDIALOG_H
#define ADDPCARDIALOG_H

#include <QDialog>

namespace Ui {
class addPCarDialog;
}

class addPCarDialog : public QDialog
{
Q_OBJECT

public:
explicit addPCarDialog(QWidget *parent = 0);
~addPCarDialog();

//Get-functions used to return data from fields to other window
//for adding vehicles to register.
QString getMod();
QString getLicNr();
QString getOwName();
QString getOwSur();
QString getOwID();
QString getEnsur();
private:
Ui::addPCarDialog *ui;
};

#endif // ADDPCARDIALOG_H
