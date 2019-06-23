/* Dialog for adding company vans */

#ifndef ADDCVANDIALOG_H
#define ADDCVANDIALOG_H

#include <QDialog>

namespace Ui {
class addCVanDialog;
}

class addCVanDialog : public QDialog
{
Q_OBJECT

public:
explicit addCVanDialog(QWidget *parent = 0);
~addCVanDialog();

//Get-functions used to return data from fields to other window
//for adding vehicles to register.
QString getMod();
QString getLicNr();
QString getCompName();
QString getOrgNr();
int getCap();

private:
Ui::addCVanDialog *ui;
};

#endif // ADDCVANDIALOG_H
