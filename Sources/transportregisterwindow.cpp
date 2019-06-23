#include "transportregisterwindow.h"
#include "ui_transportregisterwindow.h"

TransportRegisterWindow::TransportRegisterWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::TransportRegisterWindow)
{

    ui->setupUi(this);
    this->hide(); //Window is hidden before login is successful.
    pCarModel = new QStandardItemModel(this);
    QStringList PCarHorizontalHeader;
    PCarHorizontalHeader.append("Model");
    PCarHorizontalHeader.append("License Number");
    PCarHorizontalHeader.append("Owner Name");
    PCarHorizontalHeader.append("Owner Surname");
    PCarHorizontalHeader.append("Owner ID");
    PCarHorizontalHeader.append("Ensured by");
    pCarModel->setHorizontalHeaderLabels(PCarHorizontalHeader);

    pVanModel = new QStandardItemModel(this);
    QStringList PVanHorizontalHeader;
    PVanHorizontalHeader.append("Model");
    PVanHorizontalHeader.append("License Number");
    PVanHorizontalHeader.append("Owner Name");
    PVanHorizontalHeader.append("Owner Surname");
    PVanHorizontalHeader.append("Owner ID");
    PVanHorizontalHeader.append("Load capacity");
    pVanModel->setHorizontalHeaderLabels(PVanHorizontalHeader);

    mBikeModel = new QStandardItemModel(this);
    QStringList MBikeHorizontalHeader;
    MBikeHorizontalHeader.append("Model");
    MBikeHorizontalHeader.append("License Number");
    MBikeHorizontalHeader.append("Owner Name");
    MBikeHorizontalHeader.append("Owner Surname");
    MBikeHorizontalHeader.append("Owner ID");
    MBikeHorizontalHeader.append("Max Speed");
    MBikeHorizontalHeader.append("Swept Volume");
    mBikeModel->setHorizontalHeaderLabels(MBikeHorizontalHeader);

    cCarModel = new QStandardItemModel(this);
    QStringList CCarHorizontalHeader;
    CCarHorizontalHeader.append("Model");
    CCarHorizontalHeader.append("License Number");
    CCarHorizontalHeader.append("Company Name");
    CCarHorizontalHeader.append("Org Nr");
    CCarHorizontalHeader.append("Ensured by");
    cCarModel->setHorizontalHeaderLabels(CCarHorizontalHeader);

    cVanModel = new QStandardItemModel(this);
    QStringList CVanHorizontalHeader;
    CVanHorizontalHeader.append("Model");
    CVanHorizontalHeader.append("License Number");
    CVanHorizontalHeader.append("Company Name");
    CVanHorizontalHeader.append("Org Nr");
    CVanHorizontalHeader.append("Load capacity");
    cVanModel->setHorizontalHeaderLabels(CVanHorizontalHeader);

    busModel = new QStandardItemModel(this);
    QStringList BusHorizontalHeader;
    BusHorizontalHeader.append("Model");
    BusHorizontalHeader.append("License Number");
    BusHorizontalHeader.append("Company Name");
    BusHorizontalHeader.append("Org Nr");
    BusHorizontalHeader.append("Bus Type");
    BusHorizontalHeader.append("Bus Number");
    BusHorizontalHeader.append("Seats");
    busModel->setHorizontalHeaderLabels(BusHorizontalHeader);

    searchModel = new QStandardItemModel(this);
    QStringList SearchHorizontalHeader;
    SearchHorizontalHeader.append("Model");
    SearchHorizontalHeader.append("License Number");
    searchModel->setHorizontalHeaderLabels(SearchHorizontalHeader);

}
TransportRegisterWindow::~TransportRegisterWindow()
{
    delete ui;
}
void TransportRegisterWindow::restrictUi(QString userGroup)
{
    if (userGroup == "USER")
    {
        this->ui->tabsy->removeTab(3);
        this->ui->tabsy->removeTab(3);
        this->ui->tabsy->removeTab(3);
        this->ui->addPCarButton->setDisabled(true);
        this->ui->addPVanButton->setDisabled(true);
        this->ui->addMBikeButton->setDisabled(true);
        this->ui->removeButton->setDisabled(true);
        this->ui->importButton->setDisabled(true);
        this->ui->clearButton->setDisabled(true);
    }
    else if (userGroup == "COMPANY")
    {
        this->ui->tabsy->removeTab(0);
        this->ui->tabsy->removeTab(0);
        this->ui->tabsy->removeTab(0);
    }
}

void TransportRegisterWindow::on_addPCarButton_clicked()
{
    addPCarDialog apcd(this);
    if (apcd.exec())
    {

        bool added;
        added = Regstr.addPCar(apcd.getMod(), apcd.getLicNr(), apcd.getOwName(), apcd.getOwSur(), apcd.getOwID(), apcd.getEnsur());
        if (added == true)
        {
            TransportRegister temp(Regstr);
            temp.filterPCars();
            QStandardItem *item;
            for (int i = 0; i < temp.nrOfVeh(); i++)
            {
                item = new QStandardItem(QString(temp.vehicles[i]->getModel()));
                this->pCarModel->setItem(i, 0, item);

                item = new QStandardItem(QString(temp.vehicles[i]->getLicenseNumber()));
                this->pCarModel->setItem(i, 1, item);

                item = new QStandardItem(QString(dynamic_cast<PrivateCar*>(temp.vehicles[i])->getOwnerName()));
                this->pCarModel->setItem(i, 2, item);

                item = new QStandardItem(QString(dynamic_cast<PrivateCar*>(temp.vehicles[i])->getOwnerSurname()));
                this->pCarModel->setItem(i, 3, item);

                item = new QStandardItem(QString(dynamic_cast<PrivateCar*>(temp.vehicles[i])->getOwnerID()));
                this->pCarModel->setItem(i, 4, item);

                item = new QStandardItem(QString(dynamic_cast<PrivateCar*>(temp.vehicles[i])->getEnsurance()));
                this->pCarModel->setItem(i, 5, item);
            }
            ui->PCarView->setModel(this->pCarModel);
        }
        else
        {
            QMessageBox notAdded(this);
            notAdded.critical(this, "Error", "Vehicle with such license number already exists!");
        }
    }
}


void TransportRegisterWindow::on_addPVanButton_clicked()
{
    addPVanDialog apcd(this);
    if (apcd.exec())
    {

        bool added;
        added = this->Regstr.addPVan(apcd.getMod(), apcd.getLicNr(), apcd.getOwName(), apcd.getOwSur(), apcd.getOwID(), apcd.getLoad());
        if (added == true)
        {
            TransportRegister temp(Regstr);
            temp.filterPVans();
            QStandardItem *item;
            for (int i = 0; i < temp.nrOfVeh(); i++)
            {
                item = new QStandardItem(QString(temp.vehicles[i]->getModel()));
                this->pVanModel->setItem(i, 0, item);

                item = new QStandardItem(QString(temp.vehicles[i]->getLicenseNumber()));
                this->pVanModel->setItem(i, 1, item);

                item = new QStandardItem(QString(dynamic_cast<PrivateVan*>(temp.vehicles[i])->getOwnerName()));
                this->pVanModel->setItem(i, 2, item);

                item = new QStandardItem(QString(dynamic_cast<PrivateVan*>(temp.vehicles[i])->getOwnerSurname()));
                this->pVanModel->setItem(i, 3, item);

                item = new QStandardItem(QString(dynamic_cast<PrivateVan*>(temp.vehicles[i])->getOwnerID()));
                this->pVanModel->setItem(i, 4, item);

                item = new QStandardItem(QString::number(dynamic_cast<PrivateVan*>(temp.vehicles[i])->getLoadCapacity()));
                this->pVanModel->setItem(i, 5, item);
            }
            ui->PVanView->setModel(this->pVanModel);
        }
        else
        {
            QMessageBox notAdded(this);
            notAdded.critical(this, "Error", "Vehicle with such license number already exists!");
        }
    }
}

void TransportRegisterWindow::on_addMBikeButton_clicked()
{
    addMBikeDialog apcd(this);
    if (apcd.exec())
    {

        bool added;
        added = this->Regstr.addMBike(apcd.getMod(), apcd.getLicNr(), apcd.getOwName(), apcd.getOwSur(), apcd.getOwID(), apcd.getMaxSpeed(), apcd.getSVolume());
        if (added == true)
        {
            TransportRegister temp(Regstr);
            temp.filterBikes();
            QStandardItem *item;
            for (int i = 0; i < temp.nrOfVeh(); i++)
            {
                item = new QStandardItem(QString(temp.vehicles[i]->getModel()));
                this->mBikeModel->setItem(i, 0, item);

                item = new QStandardItem(QString(temp.vehicles[i]->getLicenseNumber()));
                this->mBikeModel->setItem(i, 1, item);

                item = new QStandardItem(QString(dynamic_cast<Motorbike*>(temp.vehicles[i])->getOwnerName()));
                this->mBikeModel->setItem(i, 2, item);

                item = new QStandardItem(QString(dynamic_cast<Motorbike*>(temp.vehicles[i])->getOwnerSurname()));
                this->mBikeModel->setItem(i, 3, item);

                item = new QStandardItem(QString(dynamic_cast<Motorbike*>(temp.vehicles[i])->getOwnerID()));
                this->mBikeModel->setItem(i, 4, item);

                item = new QStandardItem(QString::number(dynamic_cast<Motorbike*>(temp.vehicles[i])->getMaxSpeed()));
                this->mBikeModel->setItem(i, 5, item);

                item = new QStandardItem(QString::number(dynamic_cast<Motorbike*>(temp.vehicles[i])->getSVolume()));
                this->mBikeModel->setItem(i, 6, item);
            }
            ui->MBikeView->setModel(this->mBikeModel);
        }
        else
        {
            QMessageBox notAdded(this);
            notAdded.critical(this, "Error", "Vehicle with such license number already exists!");
        }
    }
}

void TransportRegisterWindow::on_addCCarButton_clicked()
{
    addCCarDialog apcd(this);
    if (apcd.exec())
    {

        bool added;
        added = this->Regstr.addCCar(apcd.getMod(), apcd.getLicNr(), apcd.getCompName(), apcd.getOrgNr(), apcd.getEnsur());
        if (added == true)
        {
            TransportRegister temp(Regstr);
            temp.filterCCars();
            QStandardItem *item;
            for (int i = 0; i < temp.nrOfVeh(); i++)
            {
                item = new QStandardItem(QString(temp.vehicles[i]->getModel()));
                this->cCarModel->setItem(i, 0, item);

                item = new QStandardItem(QString(temp.vehicles[i]->getLicenseNumber()));
                this->cCarModel->setItem(i, 1, item);

                item = new QStandardItem(QString(dynamic_cast<CompanyCar*>(temp.vehicles[i])->getCompanyName()));
                this->cCarModel->setItem(i, 2, item);

                item = new QStandardItem(QString(dynamic_cast<CompanyCar*>(temp.vehicles[i])->getOrgNr()));
                this->cCarModel->setItem(i, 3, item);

                item = new QStandardItem(QString(dynamic_cast<CompanyCar*>(temp.vehicles[i])->getEnsurance()));
                this->cCarModel->setItem(i, 4, item);
            }
            ui->CCarView->setModel(this->cCarModel);
        }
        else
        {
            QMessageBox notAdded(this);
            notAdded.critical(this, "Error", "Vehicle with such license number already exists!");
        }
    }
}

void TransportRegisterWindow::on_addCVanButton_clicked()
{
    addCVanDialog apcd(this);
    if (apcd.exec())
    {

        bool added;
        added = this->Regstr.addCVan(apcd.getMod(), apcd.getLicNr(), apcd.getCompName(), apcd.getOrgNr(), apcd.getCap());
        if (added == true)
        {
            TransportRegister temp(Regstr);
            temp.filterCVans();
            QStandardItem *item;
            for (int i = 0; i < temp.nrOfVeh(); i++)
            {
                item = new QStandardItem(QString(temp.vehicles[i]->getModel()));
                this->cVanModel->setItem(i, 0, item);

                item = new QStandardItem(QString(temp.vehicles[i]->getLicenseNumber()));
                this->cVanModel->setItem(i, 1, item);

                item = new QStandardItem(QString(dynamic_cast<CompanyVan*>(temp.vehicles[i])->getCompanyName()));
                this->cVanModel->setItem(i, 2, item);

                item = new QStandardItem(QString(dynamic_cast<CompanyVan*>(temp.vehicles[i])->getOrgNr()));
                this->cVanModel->setItem(i, 3, item);

                item = new QStandardItem(QString::number(dynamic_cast<CompanyVan*>(temp.vehicles[i])->getLoadCapacity()));
                this->cVanModel->setItem(i, 4, item);
            }
            ui->CVanView->setModel(this->cVanModel);
        }
        else
        {
            QMessageBox notAdded(this);
            notAdded.critical(this, "Error", "Vehicle with such license number already exists!");
        }
    }
}

void TransportRegisterWindow::on_addBusButton_clicked()
{
    addBusDialog apcd(this);
    if (apcd.exec())
    {

        bool added;
        added = this->Regstr.addBus(apcd.getMod(), apcd.getLicNr(), apcd.getCompName(), apcd.getOrgNr(), apcd.getType(), apcd.getBusNr(), apcd.getSeats());
        if (added == true)
        {
            TransportRegister temp(Regstr);
            temp.filterBuses();
            QStandardItem *item;
            for (int i = 0; i < temp.nrOfVeh(); i++)
            {
                item = new QStandardItem(QString(temp.vehicles[i]->getModel()));
                this->busModel->setItem(i, 0, item);

                item = new QStandardItem(QString(temp.vehicles[i]->getLicenseNumber()));
                this->busModel->setItem(i, 1, item);

                item = new QStandardItem(QString(dynamic_cast<Bus*>(temp.vehicles[i])->getCompanyName()));
                this->busModel->setItem(i, 2, item);

                item = new QStandardItem(QString(dynamic_cast<Bus*>(temp.vehicles[i])->getOrgNr()));
                this->busModel->setItem(i, 3, item);

                item = new QStandardItem(QString(dynamic_cast<Bus*>(temp.vehicles[i])->getBusType()));
                this->busModel->setItem(i, 4, item);

                item = new QStandardItem(QString(dynamic_cast<Bus*>(temp.vehicles[i])->getBusNr()));
                this->busModel->setItem(i, 5, item);

                item = new QStandardItem(QString::number(dynamic_cast<Bus*>(temp.vehicles[i])->getNrOfSeats()));
                this->busModel->setItem(i, 6, item);
            }
            ui->BusView->setModel(this->busModel);
        }
        else
        {
            QMessageBox notAdded(this);
            notAdded.critical(this, "Error", "Vehicle with such license number already exists!");
        }
    }
}

void TransportRegisterWindow::on_PCarView_doubleClicked(const QModelIndex &index)
{
    editPCarDialog edit(this);
    if (edit.exec())
    {
        TransportRegister temp(Regstr);
        temp.filterPCars();
        bool edited;

        edited = temp.editPCar(edit.getMod(), temp.vehicles[index.row()]->getLicenseNumber(), edit.getOwName(), edit.getOwSur(), edit.getOwID(), edit.getEnsur());
        Regstr.editPCar(edit.getMod(), temp.vehicles[index.row()]->getLicenseNumber(), edit.getOwName(), edit.getOwSur(), edit.getOwID(), edit.getEnsur());
        if(edited == true)
        {

            QStandardItem *item;
            if(index.column() != 0)
            {
                item = new QStandardItem(QString(temp.vehicles[index.row()]->getModel()));


                this->pCarModel->setItem(index.row(), 0, item);
            }
            if(index.column() != 2)
            {
                item = new QStandardItem(QString(dynamic_cast<PrivateCar*>(temp.vehicles[index.row()])->getOwnerName()));


                this->pCarModel->setItem(index.row(), 2, item);
            }

            if(index.column() != 3)
            {
                item = new QStandardItem(QString(dynamic_cast<PrivateCar*>(temp.vehicles[index.row()])->getOwnerSurname()));


                this->pCarModel->setItem(index.row(), 3, item);
            }
            if(index.column() != 4)
            {
                item = new QStandardItem(QString(dynamic_cast<PrivateCar*>(temp.vehicles[index.row()])->getOwnerID()));


                this->pCarModel->setItem(index.row(), 4, item);
            }
            if(index.column() != 5)
            {
                item = new QStandardItem(QString(dynamic_cast<PrivateCar*>(temp.vehicles[index.row()])->getEnsurance()));


                this->pCarModel->setItem(index.row(), 5, item);
            }
            if(index.column() == 0)
            {
                item = new QStandardItem(QString(temp.vehicles[index.row()]->getModel()));


                this->pCarModel->setItem(index.row(), 0, item);
            }
            if(index.column() == 2)
            {
                item = new QStandardItem(QString(dynamic_cast<PrivateCar*>(temp.vehicles[index.row()])->getOwnerName()));


                this->pCarModel->setItem(index.row(), 2, item);
            }

            if(index.column() == 3)
            {
                item = new QStandardItem(QString(dynamic_cast<PrivateCar*>(temp.vehicles[index.row()])->getOwnerSurname()));


                this->pCarModel->setItem(index.row(), 3, item);
            }
            if(index.column() == 4)
            {
                item = new QStandardItem(QString(dynamic_cast<PrivateCar*>(temp.vehicles[index.row()])->getOwnerID()));


                this->pCarModel->setItem(index.row(), 4, item);
            }
            if(index.column() == 5)
            {
                item = new QStandardItem(QString(dynamic_cast<PrivateCar*>(temp.vehicles[index.row()])->getEnsurance()));


                this->pCarModel->setItem(index.row(), 5, item);
            }

        }
    }
}


void TransportRegisterWindow::on_PVanView_doubleClicked(const QModelIndex &index)
{
    editpvandialog edit(this);
    if (edit.exec())
    {
        TransportRegister temp(Regstr);
        temp.filterPVans();
        bool edited;

        edited = temp.editPVan(edit.getMod(), temp.vehicles[index.row()]->getLicenseNumber(), edit.getOwName(), edit.getOwSur(), edit.getOwID(), edit.getLoad());
        Regstr.editPVan(edit.getMod(), temp.vehicles[index.row()]->getLicenseNumber(), edit.getOwName(), edit.getOwSur(), edit.getOwID(), edit.getLoad());
        if(edited == true)
        {

            QStandardItem *item;
            if(index.column() != 0)
            {
                item = new QStandardItem(QString(temp.vehicles[index.row()]->getModel()));


                this->pVanModel->setItem(index.row(), 0, item);
            }
            if(index.column() != 2)
            {
                item = new QStandardItem(QString(dynamic_cast<PrivateVan*>(temp.vehicles[index.row()])->getOwnerName()));


                this->pVanModel->setItem(index.row(), 2, item);
            }

            if(index.column() != 3)
            {
                item = new QStandardItem(QString(dynamic_cast<PrivateVan*>(temp.vehicles[index.row()])->getOwnerSurname()));


                this->pVanModel->setItem(index.row(), 3, item);
            }
            if(index.column() != 4)
            {
                item = new QStandardItem(QString(dynamic_cast<PrivateVan*>(temp.vehicles[index.row()])->getOwnerID()));


                this->pVanModel->setItem(index.row(), 4, item);
            }
            if(index.column() != 5)
            {
                item = new QStandardItem(QString::number(dynamic_cast<PrivateVan*>(temp.vehicles[index.row()])->getLoadCapacity()));


                this->pVanModel->setItem(index.row(), 5, item);
            }
            if(index.column() == 0)
            {
                item = new QStandardItem(QString(temp.vehicles[index.row()]->getModel()));


                this->pVanModel->setItem(index.row(), 0, item);
            }
            if(index.column() == 2)
            {
                item = new QStandardItem(QString(dynamic_cast<PrivateVan*>(temp.vehicles[index.row()])->getOwnerName()));


                this->pVanModel->setItem(index.row(), 2, item);
            }

            if(index.column() == 3)
            {
                item = new QStandardItem(QString(dynamic_cast<PrivateVan*>(temp.vehicles[index.row()])->getOwnerSurname()));


                this->pVanModel->setItem(index.row(), 3, item);
            }
            if(index.column() == 4)
            {
                item = new QStandardItem(QString(dynamic_cast<PrivateVan*>(temp.vehicles[index.row()])->getOwnerID()));


                this->pVanModel->setItem(index.row(), 4, item);
            }
            if(index.column() == 5)
            {
                item = new QStandardItem(QString::number(dynamic_cast<PrivateVan*>(temp.vehicles[index.row()])->getLoadCapacity()));


                this->pVanModel->setItem(index.row(), 5, item);
            }

        }
    }
}

void TransportRegisterWindow::on_MBikeView_doubleClicked(const QModelIndex &index)
{
    editmbikedialog edit(this);
    if (edit.exec())
    {
        TransportRegister temp(Regstr);
        temp.filterBikes();
        bool edited;

        edited = temp.editMBike(edit.getMod(), temp.vehicles[index.row()]->getLicenseNumber(), edit.getOwName(), edit.getOwSur(), edit.getOwID(), edit.getMaxSpeed(), edit.getSVolume());
        Regstr.editMBike(edit.getMod(), temp.vehicles[index.row()]->getLicenseNumber(), edit.getOwName(), edit.getOwSur(), edit.getOwID(), edit.getMaxSpeed(), edit.getSVolume());
        if(edited == true)
        {

            QStandardItem *item;
            if(index.column() != 0)
            {
                item = new QStandardItem(QString(temp.vehicles[index.row()]->getModel()));


                this->mBikeModel->setItem(index.row(), 0, item);
            }
            if(index.column() != 2)
            {
                item = new QStandardItem(QString(dynamic_cast<Motorbike*>(temp.vehicles[index.row()])->getOwnerName()));


                this->mBikeModel->setItem(index.row(), 2, item);
            }

            if(index.column() != 3)
            {
                item = new QStandardItem(QString(dynamic_cast<Motorbike*>(temp.vehicles[index.row()])->getOwnerSurname()));


                this->mBikeModel->setItem(index.row(), 3, item);
            }
            if(index.column() != 4)
            {
                item = new QStandardItem(QString(dynamic_cast<Motorbike*>(temp.vehicles[index.row()])->getOwnerID()));


                this->mBikeModel->setItem(index.row(), 4, item);
            }
            if(index.column() != 5)
            {
                item = new QStandardItem(QString::number(dynamic_cast<Motorbike*>(temp.vehicles[index.row()])->getMaxSpeed()));


                this->mBikeModel->setItem(index.row(), 5, item);
            }
            if(index.column() != 6)
            {
                item = new QStandardItem(QString::number(dynamic_cast<Motorbike*>(temp.vehicles[index.row()])->getSVolume()));


                this->mBikeModel->setItem(index.row(), 6, item);
            }
            if(index.column() == 0)
            {
                item = new QStandardItem(QString(temp.vehicles[index.row()]->getModel()));


                this->mBikeModel->setItem(index.row(), 0, item);
            }
            if(index.column() == 2)
            {
                item = new QStandardItem(QString(dynamic_cast<Motorbike*>(temp.vehicles[index.row()])->getOwnerName()));


                this->mBikeModel->setItem(index.row(), 2, item);
            }

            if(index.column() == 3)
            {
                item = new QStandardItem(QString(dynamic_cast<Motorbike*>(temp.vehicles[index.row()])->getOwnerSurname()));


                this->mBikeModel->setItem(index.row(), 3, item);
            }
            if(index.column() == 4)
            {
                item = new QStandardItem(QString(dynamic_cast<Motorbike*>(temp.vehicles[index.row()])->getOwnerID()));

                this->mBikeModel->setItem(index.row(), 4, item);
            }
            if(index.column() == 5)
            {
                item = new QStandardItem(QString::number(dynamic_cast<Motorbike*>(temp.vehicles[index.row()])->getMaxSpeed()));

                this->mBikeModel->setItem(index.row(), 5, item);
            }
            if(index.column() == 6)
            {
                item = new QStandardItem(QString::number(dynamic_cast<Motorbike*>(temp.vehicles[index.row()])->getSVolume()));

                this->mBikeModel->setItem(index.row(), 6, item);
            }

        }
    }
}

void TransportRegisterWindow::on_CCarView_doubleClicked(const QModelIndex &index)
{
    editCCarDialog edit(this);
    if (edit.exec())
    {
        TransportRegister temp(Regstr);
        temp.filterCCars();
        bool edited;

        edited = temp.editCCar(edit.getMod(), temp.vehicles[index.row()]->getLicenseNumber(), edit.getCompName(), edit.getOrgNr(), edit.getEnsur());
        Regstr.editCCar(edit.getMod(), temp.vehicles[index.row()]->getLicenseNumber(), edit.getCompName(), edit.getOrgNr(), edit.getEnsur());
        if(edited == true)
        {

            QStandardItem *item;
            if(index.column() != 0)
            {
                item = new QStandardItem(QString(temp.vehicles[index.row()]->getModel()));

                this->cCarModel->setItem(index.row(), 0, item);
            }
            if(index.column() != 2)
            {
                item = new QStandardItem(QString(dynamic_cast<CompanyCar*>(temp.vehicles[index.row()])->getCompanyName()));

                this->cCarModel->setItem(index.row(), 2, item);
            }

            if(index.column() != 3)
            {
                item = new QStandardItem(QString(dynamic_cast<CompanyCar*>(temp.vehicles[index.row()])->getOrgNr()));
                this->cCarModel->setItem(index.row(), 3, item);
            }
            if(index.column() != 4)
            {
                item = new QStandardItem(QString(dynamic_cast<CompanyCar*>(temp.vehicles[index.row()])->getEnsurance()));

                this->cCarModel->setItem(index.row(), 4, item);
            }
            if(index.column() == 0)
            {
                item = new QStandardItem(QString(temp.vehicles[index.row()]->getModel()));

                this->cCarModel->setItem(index.row(), 0, item);
            }
            if(index.column() == 2)
            {
                item = new QStandardItem(QString(dynamic_cast<CompanyCar*>(temp.vehicles[index.row()])->getCompanyName()));

                this->cCarModel->setItem(index.row(), 2, item);
            }

            if(index.column() == 3)
            {
                item = new QStandardItem(QString(dynamic_cast<CompanyCar*>(temp.vehicles[index.row()])->getOrgNr()));

                this->cCarModel->setItem(index.row(), 3, item);
            }
            if(index.column() == 4)
            {
                item = new QStandardItem(QString(dynamic_cast<CompanyCar*>(temp.vehicles[index.row()])->getEnsurance()));

                this->cCarModel->setItem(index.row(), 4, item);
            }

        }
    }
}

void TransportRegisterWindow::on_CVanView_doubleClicked(const QModelIndex &index)
{
    editCVanDialog edit(this);
    if (edit.exec())
    {
        TransportRegister temp(Regstr);
        temp.filterCVans();
        bool edited;

        edited = temp.editCVan(edit.getMod(), temp.vehicles[index.row()]->getLicenseNumber(), edit.getCompName(), edit.getOrgNr(), edit.getCap());
        Regstr.editCVan(edit.getMod(), temp.vehicles[index.row()]->getLicenseNumber(), edit.getCompName(), edit.getOrgNr(), edit.getCap());
        if(edited == true)
        {

            QStandardItem *item;
            if(index.column() != 0)
            {
                item = new QStandardItem(QString(temp.vehicles[index.row()]->getModel()));

                this->cVanModel->setItem(index.row(), 0, item);
            }
            if(index.column() != 2)
            {
                item = new QStandardItem(QString(dynamic_cast<CompanyVan*>(temp.vehicles[index.row()])->getCompanyName()));

                this->cVanModel->setItem(index.row(), 2, item);
            }

            if(index.column() != 3)
            {
                item = new QStandardItem(QString(dynamic_cast<CompanyVan*>(temp.vehicles[index.row()])->getOrgNr()));

                this->cVanModel->setItem(index.row(), 3, item);
            }
            if(index.column() != 4)
            {
                item = new QStandardItem(QString::number(dynamic_cast<CompanyVan*>(temp.vehicles[index.row()])->getLoadCapacity()));

                this->cVanModel->setItem(index.row(), 4, item);
            }
            if(index.column() == 0)
            {
                item = new QStandardItem(QString(temp.vehicles[index.row()]->getModel()));

                this->cVanModel->setItem(index.row(), 0, item);
            }
            if(index.column() == 2)
            {
                item = new QStandardItem(QString(dynamic_cast<CompanyVan*>(temp.vehicles[index.row()])->getCompanyName()));

                this->cVanModel->setItem(index.row(), 2, item);
            }

            if(index.column() == 3)
            {
                item = new QStandardItem(QString(dynamic_cast<CompanyVan*>(temp.vehicles[index.row()])->getOrgNr()));

                this->cVanModel->setItem(index.row(), 3, item);
            }
            if(index.column() == 4)
            {
                item = new QStandardItem(QString::number(dynamic_cast<CompanyVan*>(temp.vehicles[index.row()])->getLoadCapacity()));

                this->cVanModel->setItem(index.row(), 4, item);
            }

        }
    }
}

void TransportRegisterWindow::on_BusView_doubleClicked(const QModelIndex &index)
{
    editBusDialog edit(this);
    if (edit.exec())
    {
        TransportRegister temp(Regstr);
        temp.filterBuses();
        bool edited;

        edited = temp.editBus(edit.getMod(), temp.vehicles[index.row()]->getLicenseNumber(), edit.getCompName(), edit.getOrgNr(), edit.getType(), edit.getBusNr(), edit.getSeats());
        Regstr.editBus(edit.getMod(), temp.vehicles[index.row()]->getLicenseNumber(), edit.getCompName(), edit.getOrgNr(), edit.getType(), edit.getBusNr(), edit.getSeats());
        if(edited == true)
        {

            QStandardItem *item;
            if(index.column() != 0)
            {
                item = new QStandardItem(QString(temp.vehicles[index.row()]->getModel()));

                this->busModel->setItem(index.row(), 0, item);
            }
            if(index.column() != 2)
            {
                item = new QStandardItem(QString(dynamic_cast<Bus*>(temp.vehicles[index.row()])->getCompanyName()));

                this->busModel->setItem(index.row(), 2, item);
            }

            if(index.column() != 3)
            {
                item = new QStandardItem(QString(dynamic_cast<Bus*>(temp.vehicles[index.row()])->getOrgNr()));

                this->busModel->setItem(index.row(), 3, item);
            }
            if(index.column() != 4)
            {
                item = new QStandardItem(QString(dynamic_cast<Bus*>(temp.vehicles[index.row()])->getBusType()));

                this->busModel->setItem(index.row(), 4, item);
            }
            if(index.column() != 5)
            {
                item = new QStandardItem(QString(dynamic_cast<Bus*>(temp.vehicles[index.row()])->getBusNr()));

                this->busModel->setItem(index.row(), 5, item);
            }
            if(index.column() != 6)
            {
                item = new QStandardItem(QString::number(dynamic_cast<Bus*>(temp.vehicles[index.row()])->getNrOfSeats()));

                this->busModel->setItem(index.row(), 6, item);
            }
            if(index.column() == 0)
            {
                item = new QStandardItem(QString(temp.vehicles[index.row()]->getModel()));

                this->busModel->setItem(index.row(), 0, item);
            }
            if(index.column() == 2)
            {
                item = new QStandardItem(QString(dynamic_cast<Bus*>(temp.vehicles[index.row()])->getCompanyName()));

                this->busModel->setItem(index.row(), 2, item);
            }

            if(index.column() == 3)
            {
                item = new QStandardItem(QString(dynamic_cast<Bus*>(temp.vehicles[index.row()])->getOrgNr()));

                this->busModel->setItem(index.row(), 3, item);
            }
            if(index.column() == 4)
            {
                item = new QStandardItem(QString(dynamic_cast<Bus*>(temp.vehicles[index.row()])->getBusType()));

                this->busModel->setItem(index.row(), 4, item);
            }
            if(index.column() == 5)
            {
                item = new QStandardItem(QString(dynamic_cast<Bus*>(temp.vehicles[index.row()])->getBusNr()));


                this->busModel->setItem(index.row(), 5, item);
            }
            if(index.column() == 6)
            {
                item = new QStandardItem(QString::number(dynamic_cast<Bus*>(temp.vehicles[index.row()])->getNrOfSeats()));


                this->busModel->setItem(index.row(), 6, item);
            }

        }
    }
}

void TransportRegisterWindow::on_PCarView_clicked(const QModelIndex &index)
{
    TransportRegister temp(Regstr);
    temp.filterPCars();
    ui->infoView->setText(temp.vehicles[index.row()]->toString());
}
void TransportRegisterWindow::on_PVanView_clicked(const QModelIndex &index)
{
    TransportRegister temp(Regstr);
    temp.filterPVans();
    ui->infoView->setText(temp.vehicles[index.row()]->toString());
}
void TransportRegisterWindow::on_MBikeView_clicked(const QModelIndex &index)
{
    TransportRegister temp(Regstr);
    temp.filterBikes();
    ui->infoView->setText(temp.vehicles[index.row()]->toString());
}

void TransportRegisterWindow::on_CCarView_clicked(const QModelIndex &index)
{
    TransportRegister temp(Regstr);
    temp.filterCCars();
    ui->infoView->setText(temp.vehicles[index.row()]->toString());
}

void TransportRegisterWindow::on_CVanView_clicked(const QModelIndex &index)
{
    TransportRegister temp(Regstr);
    temp.filterCVans();
    ui->infoView->setText(temp.vehicles[index.row()]->toString());
}

void TransportRegisterWindow::on_BusView_clicked(const QModelIndex &index)
{
    TransportRegister temp(Regstr);
    temp.filterBuses();
    ui->infoView->setText(temp.vehicles[index.row()]->toString());
}

void TransportRegisterWindow::on_removeButton_clicked()
{
    deldialog remd(this);
    if (remd.exec())
    {
        int foundSpec = 0;
        int found = Regstr.dupSearch(remd.getLicNr());
        if (found != -1)
        {
            if (typeid(PrivateCar) == typeid(*Regstr.vehicles[found]))
            {
                TransportRegister temp(Regstr);
                temp.filterPCars();
                foundSpec = temp.dupSearch(remd.getLicNr());
                this->pCarModel->removeRow(foundSpec);
            }
            else if (typeid(PrivateVan) == typeid(*Regstr.vehicles[found]))
            {
                TransportRegister temp(Regstr);
                temp.filterPVans();
                foundSpec = temp.dupSearch(remd.getLicNr());
                this->pVanModel->removeRow(foundSpec);
            }
            else if (typeid(Motorbike) == typeid(*Regstr.vehicles[found]))
            {
                TransportRegister temp(Regstr);
                temp.filterBikes();
                foundSpec = temp.dupSearch(remd.getLicNr());
                this->mBikeModel->removeRow(foundSpec);
            }

            else if (typeid(CompanyCar) == typeid(*Regstr.vehicles[found]))
            {
                TransportRegister temp(Regstr);
                temp.filterCCars();
                foundSpec = temp.dupSearch(remd.getLicNr());
                this->cCarModel->removeRow(foundSpec);
            }
            else if (typeid(CompanyVan) == typeid(*Regstr.vehicles[found]))
            {
                TransportRegister temp(Regstr);
                temp.filterCVans();
                foundSpec = temp.dupSearch(remd.getLicNr());
                this->cVanModel->removeRow(foundSpec);
            }
            else if (typeid(Bus) == typeid(*Regstr.vehicles[found]))
            {
                TransportRegister temp(Regstr);
                temp.filterBuses();
                foundSpec = temp.dupSearch(remd.getLicNr());
                this->busModel->removeRow(foundSpec);
            }
            Regstr.removeVehicle(remd.getLicNr());
        }
        else
        {
            QMessageBox notDeleted(this);
            notDeleted.critical(this, "Error", "No vehicle with such license number exists!");
        }
    }
}

void TransportRegisterWindow::on_aboutButton_clicked()
{
    About about(this);
    about.exec();
}
void TransportRegisterWindow::on_exportButton_clicked()
{
    fileexport fEWindow(this, &Regstr);
    fEWindow.exec();
}
void TransportRegisterWindow::on_importButton_clicked()
{
    QStringList arr;
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QString(),
                                                    tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));
    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        int linecounter = 0;
        QTextStream in(&file);
        QString line = in.readLine();
        while(!in.atEnd())
        {
            line = in.readLine();
            arr.append(line);
            linecounter++;
        }
        file.close();
        for (int j = 0; j < linecounter; j++)
        {
            QStringList inData = arr.at(j).split('|');

            if (inData.contains("PrivateCar"))
            {
                this->Regstr.addPCar(inData.at(1), inData.at(2), inData.at(3), inData.at(4), inData.at(5), inData.at(6));
            }
            else if (inData.contains("PrivateVan"))
            {
                this->Regstr.addPVan(inData.at(1), inData.at(2), inData.at(3), inData.at(4), inData.at(5), (inData.at(6)).toInt());
            }
            else if (inData.contains("Motorbike"))
            {
                this->Regstr.addMBike(inData.at(1), inData.at(2), inData.at(3), inData.at(4), inData.at(5), (inData.at(6)).toInt(), (inData.at(7)).toInt());
            }
            else if (inData.contains("CompanyCar"))
            {
                this->Regstr.addCCar(inData.at(1), inData.at(2), inData.at(3), inData.at(4), inData.at(5));
            }
            else if (inData.contains("CompanyVan"))
            {
                this->Regstr.addCVan(inData.at(1), inData.at(2), inData.at(3), inData.at(4), (inData.at(5)).toInt());
            }
            else if (inData.contains("Bus"))
            {
                this->Regstr.addBus(inData.at(1), inData.at(2), inData.at(3), inData.at(4), inData.at(5), inData.at(6), (inData.at(7)).toInt());
            }
        }
        {
            QStandardItem *item;
            TransportRegister temp(Regstr);
            temp.filterPCars();
            for (int i = 0; i < temp.nrOfVeh(); i++)
            {
                item = new QStandardItem(QString(temp.vehicles[i]->getModel()));
                this->pCarModel->setItem(i, 0, item);

                item = new QStandardItem(QString(temp.vehicles[i]->getLicenseNumber()));
                this->pCarModel->setItem(i, 1, item);

                item = new QStandardItem(QString(dynamic_cast<PrivateCar*>(temp.vehicles[i])->getOwnerName()));
                this->pCarModel->setItem(i, 2, item);

                item = new QStandardItem(QString(dynamic_cast<PrivateCar*>(temp.vehicles[i])->getOwnerSurname()));
                this->pCarModel->setItem(i, 3, item);

                item = new QStandardItem(QString(dynamic_cast<PrivateCar*>(temp.vehicles[i])->getOwnerID()));
                this->pCarModel->setItem(i, 4, item);

                item = new QStandardItem(QString(dynamic_cast<PrivateCar*>(temp.vehicles[i])->getEnsurance()));
                this->pCarModel->setItem(i, 5, item);
            }
            ui->PCarView->setModel(this->pCarModel);

            TransportRegister temp2(Regstr);
            temp2.filterPVans();
            for (int i = 0; i < temp2.nrOfVeh(); i++)
            {
                item = new QStandardItem(QString(temp2.vehicles[i]->getModel()));
                this->pVanModel->setItem(i, 0, item);

                item = new QStandardItem(QString(temp2.vehicles[i]->getLicenseNumber()));
                this->pVanModel->setItem(i, 1, item);

                item = new QStandardItem(QString(dynamic_cast<PrivateVan*>(temp2.vehicles[i])->getOwnerName()));
                this->pVanModel->setItem(i, 2, item);

                item = new QStandardItem(QString(dynamic_cast<PrivateVan*>(temp2.vehicles[i])->getOwnerSurname()));
                this->pVanModel->setItem(i, 3, item);

                item = new QStandardItem(QString(dynamic_cast<PrivateVan*>(temp2.vehicles[i])->getOwnerID()));
                this->pVanModel->setItem(i, 4, item);

                item = new QStandardItem(QString::number(dynamic_cast<PrivateVan*>(temp2.vehicles[i])->getLoadCapacity()));
                this->pVanModel->setItem(i, 5, item);
            }
            ui->PVanView->setModel(this->pVanModel);

            TransportRegister temp3(Regstr);
            temp3.filterBikes();
            for (int i = 0; i < temp3.nrOfVeh(); i++)
            {
                item = new QStandardItem(QString(temp3.vehicles[i]->getModel()));
                this->mBikeModel->setItem(i, 0, item);

                item = new QStandardItem(QString(temp3.vehicles[i]->getLicenseNumber()));
                this->mBikeModel->setItem(i, 1, item);

                item = new QStandardItem(QString(dynamic_cast<Motorbike*>(temp3.vehicles[i])->getOwnerName()));
                this->mBikeModel->setItem(i, 2, item);

                item = new QStandardItem(QString(dynamic_cast<Motorbike*>(temp3.vehicles[i])->getOwnerSurname()));
                this->mBikeModel->setItem(i, 3, item);

                item = new QStandardItem(QString(dynamic_cast<Motorbike*>(temp3.vehicles[i])->getOwnerID()));
                this->mBikeModel->setItem(i, 4, item);

                item = new QStandardItem(QString::number(dynamic_cast<Motorbike*>(temp3.vehicles[i])->getMaxSpeed()));
                this->mBikeModel->setItem(i, 5, item);

                item = new QStandardItem(QString::number(dynamic_cast<Motorbike*>(temp3.vehicles[i])->getSVolume()));
                this->mBikeModel->setItem(i, 6, item);
            }
            ui->MBikeView->setModel(this->mBikeModel);

            TransportRegister temp4(Regstr);
            temp4.filterCCars();
            for (int i = 0; i < temp4.nrOfVeh(); i++)
            {
                item = new QStandardItem(QString(temp4.vehicles[i]->getModel()));
                this->cCarModel->setItem(i, 0, item);

                item = new QStandardItem(QString(temp4.vehicles[i]->getLicenseNumber()));
                this->cCarModel->setItem(i, 1, item);

                item = new QStandardItem(QString(dynamic_cast<CompanyCar*>(temp4.vehicles[i])->getCompanyName()));
                this->cCarModel->setItem(i, 2, item);

                item = new QStandardItem(QString(dynamic_cast<CompanyCar*>(temp4.vehicles[i])->getOrgNr()));
                this->cCarModel->setItem(i, 3, item);

                item = new QStandardItem(QString(dynamic_cast<CompanyCar*>(temp4.vehicles[i])->getEnsurance()));
                this->cCarModel->setItem(i, 4, item);
            }
            ui->CCarView->setModel(this->cCarModel);

            TransportRegister temp5(Regstr);
            temp5.filterCVans();
            for (int i = 0; i < temp5.nrOfVeh(); i++)
            {
                item = new QStandardItem(QString(temp5.vehicles[i]->getModel()));
                this->cVanModel->setItem(i, 0, item);

                item = new QStandardItem(QString(temp5.vehicles[i]->getLicenseNumber()));
                this->cVanModel->setItem(i, 1, item);

                item = new QStandardItem(QString(dynamic_cast<CompanyVan*>(temp5.vehicles[i])->getCompanyName()));
                this->cVanModel->setItem(i, 2, item);

                item = new QStandardItem(QString(dynamic_cast<CompanyVan*>(temp5.vehicles[i])->getOrgNr()));
                this->cVanModel->setItem(i, 3, item);

                item = new QStandardItem(QString::number(dynamic_cast<CompanyVan*>(temp5.vehicles[i])->getLoadCapacity()));
                this->cVanModel->setItem(i, 4, item);
            }
            ui->CVanView->setModel(this->cVanModel);

            TransportRegister temp6(Regstr);
            temp6.filterBuses();
            for (int i = 0; i < temp6.nrOfVeh(); i++)
            {
                item = new QStandardItem(QString(temp6.vehicles[i]->getModel()));
                this->busModel->setItem(i, 0, item);

                item = new QStandardItem(QString(temp6.vehicles[i]->getLicenseNumber()));
                this->busModel->setItem(i, 1, item);

                item = new QStandardItem(QString(dynamic_cast<Bus*>(temp6.vehicles[i])->getCompanyName()));
                this->busModel->setItem(i, 2, item);

                item = new QStandardItem(QString(dynamic_cast<Bus*>(temp6.vehicles[i])->getOrgNr()));
                this->busModel->setItem(i, 3, item);

                item = new QStandardItem(QString(dynamic_cast<Bus*>(temp6.vehicles[i])->getBusType()));
                this->busModel->setItem(i, 4, item);

                item = new QStandardItem(QString(dynamic_cast<Bus*>(temp6.vehicles[i])->getBusNr()));
                this->busModel->setItem(i, 5, item);

                item = new QStandardItem(QString::number(dynamic_cast<Bus*>(temp6.vehicles[i])->getNrOfSeats()));
                this->busModel->setItem(i, 6, item);
            }
            ui->BusView->setModel(this->busModel);
        }
    }
}
void TransportRegisterWindow::on_openButton_clicked()
{
    QMessageBox warn(this);
    warn.warning(this, "Warning!", "Warning, this  will replace your current register with one from file!");
    QStringList arr;
    TransportRegister temp;
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QString(),
                                                    tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));
    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        int linecounter = 0;
        QTextStream in(&file);
        QString line = in.readLine();
        while(!in.atEnd())
        {
            line = in.readLine();
            arr.append(line);
            linecounter++;
        }
        file.close();
        for (int j = 0; j < linecounter; j++)
        {
            QStringList inData = arr.at(j).split('|');

            if (inData.contains("PrivateCar"))
            {
                temp.addPCar(inData.at(1), inData.at(2), inData.at(3), inData.at(4), inData.at(5), inData.at(6));
            }
            else if (inData.contains("PrivateVan"))
            {
                temp.addPVan(inData.at(1), inData.at(2), inData.at(3), inData.at(4), inData.at(5), (inData.at(6)).toInt());
            }
            else if (inData.contains("Motorbike"))
            {
                temp.addMBike(inData.at(1), inData.at(2), inData.at(3), inData.at(4), inData.at(5), (inData.at(6)).toInt(), (inData.at(7)).toInt());
            }
            else if (inData.contains("CompanyCar"))
            {
                temp.addCCar(inData.at(1), inData.at(2), inData.at(3), inData.at(4), inData.at(5));
            }
            else if (inData.contains("CompanyVan"))
            {
                temp.addCVan(inData.at(1), inData.at(2), inData.at(3), inData.at(4), (inData.at(5)).toInt());
            }
            else if (inData.contains("Bus"))
            {
                temp.addBus(inData.at(1), inData.at(2), inData.at(3), inData.at(4), inData.at(5), inData.at(6), (inData.at(7)).toInt());
            }
        }
        for (int i = 0; i < this->Regstr.nrOfVeh(); i++)
        {
            this->pCarModel->removeRow(i);
            this->pVanModel->removeRow(i);
            this->mBikeModel->removeRow(i);
            this->cCarModel->removeRow(i);
            this->cVanModel->removeRow(i);
            this->busModel->removeRow(i);
        }
        this->Regstr = temp;


        QStandardItem *item;
        TransportRegister temp7(Regstr);
        temp7.filterPCars();
        for (int i = 0; i < temp7.nrOfVeh(); i++)
        {
            item = new QStandardItem(QString(temp7.vehicles[i]->getModel()));
            this->pCarModel->setItem(i, 0, item);

            item = new QStandardItem(QString(temp7.vehicles[i]->getLicenseNumber()));
            this->pCarModel->setItem(i, 1, item);

            item = new QStandardItem(QString(dynamic_cast<PrivateCar*>(temp7.vehicles[i])->getOwnerName()));
            this->pCarModel->setItem(i, 2, item);

            item = new QStandardItem(QString(dynamic_cast<PrivateCar*>(temp7.vehicles[i])->getOwnerSurname()));
            this->pCarModel->setItem(i, 3, item);

            item = new QStandardItem(QString(dynamic_cast<PrivateCar*>(temp7.vehicles[i])->getOwnerID()));
            this->pCarModel->setItem(i, 4, item);

            item = new QStandardItem(QString(dynamic_cast<PrivateCar*>(temp7.vehicles[i])->getEnsurance()));
            this->pCarModel->setItem(i, 5, item);
        }
        ui->PCarView->setModel(this->pCarModel);

        TransportRegister temp2(Regstr);
        temp2.filterPVans();
        for (int i = 0; i < temp2.nrOfVeh(); i++)
        {
            item = new QStandardItem(QString(temp2.vehicles[i]->getModel()));
            this->pVanModel->setItem(i, 0, item);

            item = new QStandardItem(QString(temp2.vehicles[i]->getLicenseNumber()));
            this->pVanModel->setItem(i, 1, item);

            item = new QStandardItem(QString(dynamic_cast<PrivateVan*>(temp2.vehicles[i])->getOwnerName()));
            this->pVanModel->setItem(i, 2, item);

            item = new QStandardItem(QString(dynamic_cast<PrivateVan*>(temp2.vehicles[i])->getOwnerSurname()));
            this->pVanModel->setItem(i, 3, item);

            item = new QStandardItem(QString(dynamic_cast<PrivateVan*>(temp2.vehicles[i])->getOwnerID()));
            this->pVanModel->setItem(i, 4, item);

            item = new QStandardItem(QString::number(dynamic_cast<PrivateVan*>(temp2.vehicles[i])->getLoadCapacity()));
            this->pVanModel->setItem(i, 5, item);
        }
        ui->PVanView->setModel(this->pVanModel);

        TransportRegister temp3(Regstr);
        temp3.filterBikes();

        for (int i = 0; i < temp3.nrOfVeh(); i++)
        {
            item = new QStandardItem(QString(temp3.vehicles[i]->getModel()));
            this->mBikeModel->setItem(i, 0, item);

            item = new QStandardItem(QString(temp3.vehicles[i]->getLicenseNumber()));
            this->mBikeModel->setItem(i, 1, item);

            item = new QStandardItem(QString(dynamic_cast<Motorbike*>(temp3.vehicles[i])->getOwnerName()));
            this->mBikeModel->setItem(i, 2, item);

            item = new QStandardItem(QString(dynamic_cast<Motorbike*>(temp3.vehicles[i])->getOwnerSurname()));
            this->mBikeModel->setItem(i, 3, item);

            item = new QStandardItem(QString(dynamic_cast<Motorbike*>(temp3.vehicles[i])->getOwnerID()));
            this->mBikeModel->setItem(i, 4, item);

            item = new QStandardItem(QString::number(dynamic_cast<Motorbike*>(temp3.vehicles[i])->getMaxSpeed()));
            this->mBikeModel->setItem(i, 5, item);

            item = new QStandardItem(QString::number(dynamic_cast<Motorbike*>(temp3.vehicles[i])->getSVolume()));
            this->mBikeModel->setItem(i, 6, item);
        }
        ui->MBikeView->setModel(this->mBikeModel);

        TransportRegister temp4(Regstr);
        temp4.filterCCars();
        for (int i = 0; i < temp4.nrOfVeh(); i++)
        {
            item = new QStandardItem(QString(temp4.vehicles[i]->getModel()));
            this->cCarModel->setItem(i, 0, item);

            item = new QStandardItem(QString(temp4.vehicles[i]->getLicenseNumber()));
            this->cCarModel->setItem(i, 1, item);

            item = new QStandardItem(QString(dynamic_cast<CompanyCar*>(temp4.vehicles[i])->getCompanyName()));
            this->cCarModel->setItem(i, 2, item);

            item = new QStandardItem(QString(dynamic_cast<CompanyCar*>(temp4.vehicles[i])->getOrgNr()));
            this->cCarModel->setItem(i, 3, item);

            item = new QStandardItem(QString(dynamic_cast<CompanyCar*>(temp4.vehicles[i])->getEnsurance()));
            this->cCarModel->setItem(i, 4, item);
        }
        ui->CCarView->setModel(this->cCarModel);

        TransportRegister temp5(Regstr);
        temp5.filterCVans();
        for (int i = 0; i < temp5.nrOfVeh(); i++)
        {
            item = new QStandardItem(QString(temp5.vehicles[i]->getModel()));
            this->cVanModel->setItem(i, 0, item);

            item = new QStandardItem(QString(temp5.vehicles[i]->getLicenseNumber()));
            this->cVanModel->setItem(i, 1, item);

            item = new QStandardItem(QString(dynamic_cast<CompanyVan*>(temp5.vehicles[i])->getCompanyName()));
            this->cVanModel->setItem(i, 2, item);

            item = new QStandardItem(QString(dynamic_cast<CompanyVan*>(temp5.vehicles[i])->getOrgNr()));
            this->cVanModel->setItem(i, 3, item);

            item = new QStandardItem(QString::number(dynamic_cast<CompanyVan*>(temp5.vehicles[i])->getLoadCapacity()));
            this->cVanModel->setItem(i, 4, item);
        }
        ui->CVanView->setModel(this->cVanModel);

        TransportRegister temp6(Regstr);
        temp6.filterBuses();
        for (int i = 0; i < temp6.nrOfVeh(); i++)
        {
            item = new QStandardItem(QString(temp6.vehicles[i]->getModel()));
            this->busModel->setItem(i, 0, item);

            item = new QStandardItem(QString(temp6.vehicles[i]->getLicenseNumber()));
            this->busModel->setItem(i, 1, item);

            item = new QStandardItem(QString(dynamic_cast<Bus*>(temp6.vehicles[i])->getCompanyName()));
            this->busModel->setItem(i, 2, item);

            item = new QStandardItem(QString(dynamic_cast<Bus*>(temp6.vehicles[i])->getOrgNr()));
            this->busModel->setItem(i, 3, item);

            item = new QStandardItem(QString(dynamic_cast<Bus*>(temp6.vehicles[i])->getBusType()));
            this->busModel->setItem(i, 4, item);

            item = new QStandardItem(QString(dynamic_cast<Bus*>(temp6.vehicles[i])->getBusNr()));
            this->busModel->setItem(i, 5, item);

            item = new QStandardItem(QString::number(dynamic_cast<Bus*>(temp6.vehicles[i])->getNrOfSeats()));
            this->busModel->setItem(i, 6, item);
        }
        ui->BusView->setModel(this->busModel);
    }
}

void TransportRegisterWindow::on_clearButton_clicked()
{
    QMessageBox warn;
    warn.setText("Warning! This will permanently delete all objects in current register! Are you sure you want to continue?");
    QPushButton *yesButton = warn.addButton(QMessageBox::Yes);
    warn.addButton(QMessageBox::No);
    warn.exec();

    if (warn.clickedButton() == yesButton)
    {
        for (int i = 0; i < this->Regstr.nrOfVeh(); i++)
        {
            this->pCarModel->removeRow(i);
            this->pVanModel->removeRow(i);
            this->mBikeModel->removeRow(i);
            this->cCarModel->removeRow(i);
            this->cVanModel->removeRow(i);
            this->busModel->removeRow(i);
        }
        TransportRegister temp;
        this->Regstr = temp;
    }
}

void TransportRegisterWindow::on_searchButton_clicked()
{
    QString query = ui->lineEdit->text();

    TransportRegister temp(Regstr);
    if(ui->pCarsButton->isChecked() == true)
    {
        temp.filterPCars();
    }
    else if(ui->pVanButton->isChecked() == true)
    {
        temp.filterPVans();
    }
    else if(ui->mBikeButton->isChecked() == true)
    {
        temp.filterBikes();
    }
    else if(ui->cCarButton->isChecked() == true)
    {
        temp.filterCCars();
    }
    else if(ui->cVanButton->isChecked() == true)
    {
        temp.filterCVans();
    }
    else if(ui->busButton->isChecked() == true)
    {
        temp.filterBuses();
    }
    QStandardItem *item;
    int j = 0;
    for (int i = 0; i < this->Regstr.nrOfVeh(); i++)
    {
        this->searchModel->removeRow(i);
    }
    ui->searchView->setModel(this->searchModel);
    for (int i = 0; i < temp.nrOfVeh(); i++)
    {
        QString output = temp.vehicles[i]->toStringSimple();
        if (output.contains(query, Qt::CaseInsensitive))
        {
            item = new QStandardItem(QString(temp.vehicles[i]->getModel()));
            this->searchModel->setItem(j, 0, item);

            item = new QStandardItem(QString(temp.vehicles[i]->getLicenseNumber()));
            this->searchModel->setItem(j, 1, item);
            j++;
        }
    }
    ui->searchView->setModel(this->searchModel);

}

void TransportRegisterWindow::on_lineEdit_returnPressed()
{
    this->on_searchButton_clicked();
}

void TransportRegisterWindow::on_logoutButton_clicked()
{
    QMessageBox warn;
    warn.setText("Warning! This will restart the application! Unexported data will be lost. Continue?");
    QPushButton *yesButton = warn.addButton(QMessageBox::Yes);
    warn.addButton(QMessageBox::No);
    warn.exec();

    if (warn.clickedButton() == yesButton)
    {
        qApp->exit( TransportRegisterWindow::EXIT_CODE_REBOOT );
    }
}



void TransportRegisterWindow::on_quitButton_clicked()
{
    QMessageBox warn;
    warn.setText("Warning! This will close the application! Unexported data will be lost. Continue?");
    QPushButton *yesButton = warn.addButton(QMessageBox::Yes);
    warn.addButton(QMessageBox::No);
    warn.exec();

    if (warn.clickedButton() == yesButton)
    {
        this->close();
    }
}
int const TransportRegisterWindow::EXIT_CODE_REBOOT = -5432;


