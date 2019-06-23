/* Dialog for adding company cars */

#ifndef ADDCCARDIALOG_H
#define ADDCCARDIALOG_H

#include <QDialog>

namespace Ui {
class addCCarDialog;
}

class addCCarDialog : public QDialog
{
Q_OBJECT

public:
explicit addCCarDialog(QWidget *parent = 0);
~addCCarDialog();

//Get-functions used to return data from fields to other window
//for adding vehicles to register
QString getMod();
QString getLicNr();
QString getCompName();
QString getOrgNr();
QString getEnsur();

private:
Ui::addCCarDialog *ui;
};

#endif // ADDCCARDIALOG_H
