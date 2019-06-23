#include "addpcardialog.h"
#include "ui_addpcardialog.h"

addPCarDialog::addPCarDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addPCarDialog)
{
    ui->setupUi(this);
}

addPCarDialog::~addPCarDialog()
{
    delete ui;
}

QString addPCarDialog::getMod()
{
    return this->ui->modl->text();
}
QString addPCarDialog::getLicNr()
{
    return this->ui->lcnr->text();

}
QString addPCarDialog::getOwName()
{
    return this->ui->owNa->text();

}
QString addPCarDialog::getOwSur()
{
    return this->ui->owSu->text();

}
QString addPCarDialog::getOwID()
{
    return this->ui->owID->text();

}
QString addPCarDialog::getEnsur()
{
    return this->ui->ensu->text();
}

