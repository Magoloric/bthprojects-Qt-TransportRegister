/* Dialog for adding private vans */

#ifndef ADDPVANDIALOG_H
#define ADDPVANDIALOG_H

#include <QDialog>

namespace Ui {
class addPVanDialog;
}

class addPVanDialog : public QDialog
{
Q_OBJECT

public:
explicit addPVanDialog(QWidget *parent = 0);
~addPVanDialog();

//Get-functions used to return data from fields to other window
//for adding vehicles to register.
QString getMod();
QString getLicNr();
QString getOwName();
QString getOwSur();
QString getOwID();
int getLoad();


private:
Ui::addPVanDialog *ui;
};

#endif // ADDPVANDIALOG_H
