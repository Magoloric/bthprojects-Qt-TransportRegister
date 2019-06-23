/* Dialog for adding buses */
#ifndef ADDBUSDIALOG_H
#define ADDBUSDIALOG_H

#include <QDialog>

namespace Ui {
class addBusDialog;
}

class addBusDialog : public QDialog
{
Q_OBJECT

public:
explicit addBusDialog(QWidget *parent = 0);
~addBusDialog();


//Get-functions used to return data from fields to other window
//for adding vehicles to register.
QString getMod();
QString getLicNr();
QString getCompName();
QString getOrgNr();
QString getType();
QString getBusNr();
int getSeats();


private:
Ui::addBusDialog *ui;
};

#endif // ADDBUSDIALOG_H
