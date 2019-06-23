#include "addmbikedialog.h"
#include "ui_addmbikedialog.h"

addMBikeDialog::addMBikeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addMBikeDialog)
{
    ui->setupUi(this);
}

addMBikeDialog::~addMBikeDialog()
{
    delete ui;
}

QString addMBikeDialog::getMod()
{
    return this->ui->model_MB->text();
}
QString addMBikeDialog::getLicNr()
{
    return this->ui->licnr_MB->text();
}
QString addMBikeDialog::getOwName()
{
    return this->ui->owname_MB->text();
}
QString addMBikeDialog::getOwSur()
{
    return this->ui->ownsur_MB->text();
}
QString addMBikeDialog::getOwID()
{
    return this->ui->ownid_MB->text();
}
int addMBikeDialog::getMaxSpeed() //Gets speed as text and converts it to int
{
    QString str = this->ui->maxspe->text();
    int num = str.toInt();
    return num;
}
int addMBikeDialog::getSVolume()//Gets swept volume as text and converts it to int
{
    QString str = this->ui->swepvo->text();
    int num = str.toInt();
    return num;
}
