/* Dialog for editing company vans */
#ifndef EDITCVANDIALOG_H
#define EDITCVANDIALOG_H

#include <QDialog>

namespace Ui {
class editCVanDialog;
}

class editCVanDialog : public QDialog
{
Q_OBJECT

public:
explicit editCVanDialog(QWidget *parent = 0);
~editCVanDialog();
//Get-functions used to return data from fields to other window
//for editing vehicles in register.
QString getMod();
QString getCompName();
QString getOrgNr();
int getCap();
private:
Ui::editCVanDialog *ui;
};

#endif // EDITCVANDIALOG_H
