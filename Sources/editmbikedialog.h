/* Dialog for editing motorbikes */
#ifndef EDITMBIKEDIALOG_H
#define EDITMBIKEDIALOG_H

#include <QDialog>

namespace Ui {
class editmbikedialog;
}

class editmbikedialog : public QDialog
{
Q_OBJECT

public:
explicit editmbikedialog(QWidget *parent = 0);
~editmbikedialog();
//Get-functions used to return data from fields to other window
//for editing vehicles in register.
QString getMod();
QString getOwName();
QString getOwSur();
QString getOwID();
int getMaxSpeed();
int getSVolume();

private:
Ui::editmbikedialog *ui;
};

#endif // EDITMBIKEDIALOG_H
