#include "addcvandialog.h"
#include "ui_addcvandialog.h"

addCVanDialog::addCVanDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addCVanDialog)
{
    ui->setupUi(this);
}

addCVanDialog::~addCVanDialog()
{
    delete ui;
}
QString addCVanDialog::getMod()
{
    return this->ui->model_CV->text();
}
QString addCVanDialog::getLicNr()
{
    return this->ui->licnr_CV->text();

}
QString addCVanDialog::getCompName()
{
    return this->ui->comname_CV->text();

}
QString addCVanDialog::getOrgNr()
{
    return this->ui->orgnr_CV->text();

}
int addCVanDialog::getCap() //Gets capacity as text and converts it to int
{
    QString str = this->ui->loacap_CV->text();
    int num = str.toInt();
    return num;
}
