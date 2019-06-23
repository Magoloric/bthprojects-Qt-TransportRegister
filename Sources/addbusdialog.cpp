#include "addbusdialog.h"
#include "ui_addbusdialog.h"

addBusDialog::addBusDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addBusDialog)
{
    ui->setupUi(this);
}

addBusDialog::~addBusDialog()
{
    delete ui;
}
QString addBusDialog::getMod()
{
    return this->ui->model_B->text();
}
QString addBusDialog::getLicNr()
{
    return this->ui->licnr_B->text();

}
QString addBusDialog::getCompName()
{
    return this->ui->comname_B->text();

}
QString addBusDialog::getOrgNr()
{
    return this->ui->orgnr_B->text();

}
QString addBusDialog::getType()
{
    return this->ui->bustyp->text();

}
int addBusDialog::getSeats() //Gets number of seats as text and converts it to int
{
    QString str = this->ui->nrofsea->text();
    int num = str.toInt();
    return num;
}
QString addBusDialog::getBusNr()
{
    return this->ui->insnr->text();

}
