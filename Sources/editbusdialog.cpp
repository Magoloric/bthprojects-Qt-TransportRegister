#include "editbusdialog.h"
#include "ui_editbusdialog.h"

editBusDialog::editBusDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editBusDialog)
{
    ui->setupUi(this);
}

editBusDialog::~editBusDialog()
{
    delete ui;
}
QString editBusDialog::getMod()
{
    return this->ui->model_B->text();
}
QString editBusDialog::getCompName()
{
    return this->ui->comname_B->text();

}
QString editBusDialog::getOrgNr()
{
    return this->ui->orgnr_B->text();

}
QString editBusDialog::getType()
{
    return this->ui->bustyp->text();

}
int editBusDialog::getSeats()
{
    QString str = this->ui->nrofsea->text();
    int num = str.toInt();
    return num;
}
QString editBusDialog::getBusNr()
{
    return this->ui->insnr->text();

}
