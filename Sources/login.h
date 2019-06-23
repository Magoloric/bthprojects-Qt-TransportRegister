/* Login dialog */
#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "fileexport.h"

namespace Ui {
class Login;

}

class Login : public QDialog
{
Q_OBJECT

public:
explicit Login(QWidget *parent = 0);
~Login();

//Functions used to return values;
QString getUserName();
QString getPassword();//Gets encrypted password
QString getGroup();

//Checks if login was successful
bool loggedIn();

private slots:
void on_loginButton_clicked();
void on_closeButton_clicked();

private:
Ui::Login *ui;
};
#endif // LOGIN_H
