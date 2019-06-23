#include "editcvandialog.h"
#include "ui_editcvandialog.h"

editCVanDialog::editCVanDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editCVanDialog)
{
    ui->setupUi(this);
}

editCVanDialog::~editCVanDialog()
{
    delete ui;
}
QString editCVanDialog::getMod()
{
    return this->ui->model_CV->text();
}
QString editCVanDialog::getCompName()
{
    return this->ui->comname_CV->text();

}
QString editCVanDialog::getOrgNr()
{
    return this->ui->orgnr_CV->text();

}
int editCVanDialog::getCap()
{
    QString str = this->ui->loacap_CV->text();
    int num = str.toInt();
    return num;
}
