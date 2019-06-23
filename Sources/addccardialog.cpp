#include "addccardialog.h"
#include "ui_addccardialog.h"

addCCarDialog::addCCarDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addCCarDialog)
{
    ui->setupUi(this);
}

addCCarDialog::~addCCarDialog()
{
    delete ui;
}
QString addCCarDialog::getMod()
{
    return this->ui->model_CC_2->text();
}
QString addCCarDialog::getLicNr()
{
    return this->ui->licnr_CC_2->text();

}
QString addCCarDialog::getCompName()
{
    return this->ui->comname_CC_2->text();

}
QString addCCarDialog::getOrgNr()
{
    return this->ui->orgnr_CC_2->text();

}
QString addCCarDialog::getEnsur()
{
    return this->ui->ensur_CC_2->text();
}
