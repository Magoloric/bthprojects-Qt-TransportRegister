#include "deldialog.h"
#include "ui_deldialog.h"

deldialog::deldialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deldialog)
{
    ui->setupUi(this);
}

deldialog::~deldialog()
{
    delete ui;
}

QString deldialog::getLicNr()
{
    return this->ui->remLicNr->text();

}
