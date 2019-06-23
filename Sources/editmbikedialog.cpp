#include "editmbikedialog.h"
#include "ui_editmbikedialog.h"

editmbikedialog::editmbikedialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editmbikedialog)
{
    ui->setupUi(this);
}

editmbikedialog::~editmbikedialog()
{
    delete ui;
}
QString editmbikedialog::getMod()
{
    return this->ui->model_MB->text();
}
QString editmbikedialog::getOwName()
{
    return this->ui->owname_MB->text();
}
QString editmbikedialog::getOwSur()
{
    return this->ui->ownsur_MB->text();
}
QString editmbikedialog::getOwID()
{
    return this->ui->ownid_MB->text();
}
int editmbikedialog::getMaxSpeed()
{
    QString str = this->ui->maxspe->text();
    int num = str.toInt();
    return num;
}
int editmbikedialog::getSVolume()
{
    QString str = this->ui->swepvo->text();
    int num = str.toInt();
    return num;
}
