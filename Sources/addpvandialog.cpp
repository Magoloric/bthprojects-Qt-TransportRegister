#include "addpvandialog.h"
#include "ui_addpvandialog.h"

addPVanDialog::addPVanDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addPVanDialog)
{
    ui->setupUi(this);
}

addPVanDialog::~addPVanDialog()
{
    delete ui;
}
QString addPVanDialog::getMod()
{
    return this->ui->model_PV->text();
}
QString addPVanDialog::getLicNr()
{
    return this->ui->licnr_PV->text();

}
QString addPVanDialog::getOwName()
{
    return this->ui->owname_PV->text();

}
QString addPVanDialog::getOwSur()
{
    return this->ui->ownsur_PV->text();

}
QString addPVanDialog::getOwID()
{
    return this->ui->ownid_PV->text();

}
int addPVanDialog::getLoad() //Gets capacity as text and converts it to int
{
    QString str = this->ui->locap_PV->text();
    int num = str.toInt();
    return num;
}
