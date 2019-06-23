/* Dialog for editing private vans */
#ifndef EDITPVANDIALOG_H
#define EDITPVANDIALOG_H

#include <QDialog>

namespace Ui {
class editpvandialog;
}

class editpvandialog : public QDialog
{
Q_OBJECT

public:
explicit editpvandialog(QWidget *parent = 0);
~editpvandialog();
//Get-functions used to return data from fields to other window
//for editing vehicles in register.
QString getMod();
QString getLicNr();
QString getOwName();
QString getOwSur();
QString getOwID();
int getLoad();
private:
Ui::editpvandialog *ui;
};

#endif // EDITPVANDIALOG_H
