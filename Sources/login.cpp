#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

QString Login::getUserName()
{
    return ui->userLine->text();
}
QString Login::getPassword()
{
    QString pass = ui->passLine->text(); //Gets value from field
    QByteArray toHash = pass.toUtf8(); //Converts it to byte array
    int strLength = pass.length();
    for (int i = 0; i < strLength; i++) //XOR-encrypts password
    {
        toHash[i] = toHash[i] ^ 0x21;
    }
    std::string conv = toHash.toStdString(); //Converts bytes into standard stirng
    QString result = QString::fromStdString(conv); //Converts it to QString
    return result; //Returns result
}

QString Login::getGroup()
{
    return ui->groupBox->currentText();
}

bool Login::loggedIn()
{
    {
        bool found = false;
        QStringList arr;
        QFile file(":/new/user/userDB.txt");
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(this, tr("Error"), tr("There is a problem with user database!"));
        }
        int linecounter = 0;
        QTextStream in(&file);
        QString line = in.readLine();
        while(!in.atEnd()) //Reads data from user database to list of strings, one line per string.
        {
            line = in.readLine();
            arr.append(line);
            linecounter++;
        }
        file.close();
        for (int j = 0; j < linecounter; j++)
        {
            QString usersString = arr.at(j);
            QStringList uList = usersString.split('|'); //Splits each string into list of values, those are separated by "|"
            if (uList.at(0) == this->getGroup() && uList.at(1) == this->getUserName() && uList.at(2) == this->getPassword())
            {
                found = true;
            }
        }
        return found;
    }
}


void Login::on_loginButton_clicked()
{
    bool li = this->loggedIn();
    if (li == true)
    {
        ((TransportRegisterWindow*)parentWidget())->restrictUi(this->getGroup()); //Deletes parts of UI that should not be available.
        ((TransportRegisterWindow*)parentWidget())->show(); //Shows the main window
        this->hide();

    }
    else //If username, password or group didn't match, shows error
    {
        QMessageBox::critical(this, tr("Error"), tr("Wrong username, password or no such user in this group!"));
        this->exec();
    }
}
void Login::on_closeButton_clicked()
{
    this->close();
}
