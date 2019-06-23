/* Dialog for editing company cars */
#ifndef EDITCCARDIALOG_H
#define EDITCCARDIALOG_H

#include <QDialog>

namespace Ui {
class editCCarDialog;
}

class editCCarDialog : public QDialog
{
Q_OBJECT

public:
explicit editCCarDialog(QWidget *parent = 0);
~editCCarDialog();
//Get-functions used to return data from fields to other window
//for editing vehicles in register.
QString getMod();
QString getCompName();
QString getOrgNr();
QString getEnsur();
private:
Ui::editCCarDialog *ui;
};

#endif // EDITCCARDIALOG_H
