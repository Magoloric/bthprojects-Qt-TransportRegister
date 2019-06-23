/* Dialog for editing buses */
#ifndef EDITBUSDIALOG_H
#define EDITBUSDIALOG_H

#include <QDialog>

namespace Ui {
class editBusDialog;
}

class editBusDialog : public QDialog
{
Q_OBJECT

public:
explicit editBusDialog(QWidget *parent = 0);
~editBusDialog();
//Get-functions used to return data from fields to other window
//for editing vehicles in register.
QString getMod();
QString getCompName();
QString getOrgNr();
QString getType();
QString getBusNr();
int getSeats();
private:
Ui::editBusDialog *ui;
};

#endif // EDITBUSDIALOG_H
