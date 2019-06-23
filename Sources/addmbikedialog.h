/* Dialog for adding motorbikes */

#ifndef ADDMBIKEDIALOG_H
#define ADDMBIKEDIALOG_H

#include <QDialog>

namespace Ui {
class addMBikeDialog;
}

class addMBikeDialog : public QDialog
{
Q_OBJECT

public:
explicit addMBikeDialog(QWidget *parent = 0);
~addMBikeDialog();

//Get-functions used to return data from fields to other window
//for adding vehicles to register.
QString getMod();
QString getLicNr();
QString getOwName();
QString getOwSur();
QString getOwID();
int getMaxSpeed();
int getSVolume();
private:
Ui::addMBikeDialog *ui;
};

#endif // ADDMBIKEDIALOG_H
