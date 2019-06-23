#include "editpcardialog.h"
#include "ui_editpcardialog.h"

editPCarDialog::editPCarDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editPCarDialog)
{
    ui->setupUi(this);
}

editPCarDialog::~editPCarDialog()
{
    delete ui;
}

QString editPCarDialog::getMod()
{
    return this->ui->modl4->text();
}

QString editPCarDialog::getOwName()
{
    return this->ui->owNa4->text();

}
QString editPCarDialog::getOwSur()
{
    return this->ui->owSu4->text();

}
QString editPCarDialog::getOwID()
{
    return this->ui->owID4->text();

}
QString editPCarDialog::getEnsur()
{
    return this->ui->ensu4->text();
}
