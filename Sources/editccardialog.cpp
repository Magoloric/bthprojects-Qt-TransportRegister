#include "editccardialog.h"
#include "ui_editccardialog.h"

editCCarDialog::editCCarDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editCCarDialog)
{
    ui->setupUi(this);
}

editCCarDialog::~editCCarDialog()
{
    delete ui;
}
QString editCCarDialog::getMod()
{
    return this->ui->model_CC_2->text();
}
QString editCCarDialog::getCompName()
{
    return this->ui->comname_CC_2->text();

}
QString editCCarDialog::getOrgNr()
{
    return this->ui->orgnr_CC_2->text();

}
QString editCCarDialog::getEnsur()
{
    return this->ui->ensur_CC_2->text();
}
