#include "editpvandialog.h"
#include "ui_editpvandialog.h"

editpvandialog::editpvandialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editpvandialog)
{
    ui->setupUi(this);
}

editpvandialog::~editpvandialog()
{
    delete ui;
}
QString editpvandialog::getMod()
{
    return this->ui->model_PV->text();
}

QString editpvandialog::getOwName()
{
    return this->ui->owname_PV->text();

}
QString editpvandialog::getOwSur()
{
    return this->ui->ownsur_PV->text();

}
QString editpvandialog::getOwID()
{
    return this->ui->ownid_PV->text();

}
int editpvandialog::getLoad()
{
    QString str = this->ui->locap_PV->text();
    int num = str.toInt();
    return num;
}
