#include "fileexport.h"
#include "ui_fileexport.h"

fileexport::fileexport(QWidget *parent, TransportRegister *regPtr) :
    QDialog(parent),
    ui(new Ui::fileexport)
{
    ui->setupUi(this);

    ui->sortByBusNumber->setDisabled(true);
    ui->sortByBusType->setDisabled(true);
    ui->sortByCompName->setDisabled(true);
    ui->sortByEnsur->setDisabled(true);
    ui->sortByID->setDisabled(true);
    ui->sortByLoadCap->setDisabled(true);
    ui->sortByMaxSpeed->setDisabled(true);
    ui->sortByNrOfSeats->setDisabled(true);
    ui->sortByOrgNr->setDisabled(true);
    ui->sortByOwName->setDisabled(true);
    ui->sortBySurname->setDisabled(true);
    ui->sortBySVol->setDisabled(true);

    this->reg = *regPtr;
}

fileexport::~fileexport()
{
    delete ui;
}

void fileexport::on_whatToExport_activated(int index)
{
    ui->sortByBusNumber->setChecked(false);
    ui->sortByBusType->setChecked(false);
    ui->sortByCompName->setChecked(false);
    ui->sortByEnsur->setChecked(false);
    ui->sortByID->setChecked(false);
    ui->sortByLoadCap->setChecked(false);
    ui->sortByMaxSpeed->setChecked(false);
    ui->sortByNrOfSeats->setChecked(false);
    ui->sortByOrgNr->setChecked(false);
    ui->sortByOwName->setChecked(false);
    ui->sortBySurname->setChecked(false);
    ui->sortBySVol->setChecked(false);
    if (index == 0)
    {
        ui->sortByBusNumber->setDisabled(true);
        ui->sortByBusType->setDisabled(true);
        ui->sortByCompName->setDisabled(true);
        ui->sortByEnsur->setDisabled(true);
        ui->sortByID->setDisabled(true);
        ui->sortByLoadCap->setDisabled(true);
        ui->sortByMaxSpeed->setDisabled(true);
        ui->sortByNrOfSeats->setDisabled(true);
        ui->sortByOrgNr->setDisabled(true);
        ui->sortByOwName->setDisabled(true);
        ui->sortBySurname->setDisabled(true);
        ui->sortBySVol->setDisabled(true);

    }
    else if (index == 1)
    {
        ui->sortByBusNumber->setDisabled(true);
        ui->sortByBusType->setDisabled(true);
        ui->sortByCompName->setDisabled(true);
        ui->sortByEnsur->setDisabled(false);
        ui->sortByID->setDisabled(false);
        ui->sortByLoadCap->setDisabled(true);
        ui->sortByMaxSpeed->setDisabled(true);
        ui->sortByNrOfSeats->setDisabled(true);
        ui->sortByOrgNr->setDisabled(true);
        ui->sortByOwName->setDisabled(false);
        ui->sortBySurname->setDisabled(false);
        ui->sortBySVol->setDisabled(true);
    }
    else if (index == 2)
    {
        ui->sortByBusNumber->setDisabled(true);
        ui->sortByBusType->setDisabled(true);
        ui->sortByCompName->setDisabled(true);
        ui->sortByEnsur->setDisabled(true);
        ui->sortByID->setDisabled(false);
        ui->sortByLoadCap->setDisabled(false);
        ui->sortByMaxSpeed->setDisabled(true);
        ui->sortByNrOfSeats->setDisabled(true);
        ui->sortByOrgNr->setDisabled(true);
        ui->sortByOwName->setDisabled(false);
        ui->sortBySurname->setDisabled(false);
        ui->sortBySVol->setDisabled(true);
    }
    else if (index == 3)
    {
        ui->sortByBusNumber->setDisabled(true);
        ui->sortByBusType->setDisabled(true);
        ui->sortByCompName->setDisabled(true);
        ui->sortByEnsur->setDisabled(true);
        ui->sortByID->setDisabled(false);
        ui->sortByLoadCap->setDisabled(true);
        ui->sortByMaxSpeed->setDisabled(false);
        ui->sortByNrOfSeats->setDisabled(true);
        ui->sortByOrgNr->setDisabled(true);
        ui->sortByOwName->setDisabled(false);
        ui->sortBySurname->setDisabled(false);
        ui->sortBySVol->setDisabled(false);
    }
    else if (index == 4)
    {
        ui->sortByBusNumber->setDisabled(true);
        ui->sortByBusType->setDisabled(true);
        ui->sortByCompName->setDisabled(false);
        ui->sortByEnsur->setDisabled(false);
        ui->sortByID->setDisabled(true);
        ui->sortByLoadCap->setDisabled(true);
        ui->sortByMaxSpeed->setDisabled(true);
        ui->sortByNrOfSeats->setDisabled(true);
        ui->sortByOrgNr->setDisabled(false);
        ui->sortByOwName->setDisabled(true);
        ui->sortBySurname->setDisabled(true);
        ui->sortBySVol->setDisabled(true);
    }
    else if (index == 5)
    {
        ui->sortByBusNumber->setDisabled(true);
        ui->sortByBusType->setDisabled(true);
        ui->sortByCompName->setDisabled(false);
        ui->sortByEnsur->setDisabled(true);
        ui->sortByID->setDisabled(true);
        ui->sortByLoadCap->setDisabled(false);
        ui->sortByMaxSpeed->setDisabled(true);
        ui->sortByNrOfSeats->setDisabled(true);
        ui->sortByOrgNr->setDisabled(false);
        ui->sortByOwName->setDisabled(true);
        ui->sortBySurname->setDisabled(true);
        ui->sortBySVol->setDisabled(true);
    }
    else if (index == 6)
    {
        ui->sortByBusNumber->setDisabled(false);
        ui->sortByBusType->setDisabled(false);
        ui->sortByCompName->setDisabled(false);
        ui->sortByEnsur->setDisabled(true);
        ui->sortByID->setDisabled(true);
        ui->sortByLoadCap->setDisabled(true);
        ui->sortByMaxSpeed->setDisabled(true);
        ui->sortByNrOfSeats->setDisabled(false);
        ui->sortByOrgNr->setDisabled(false);
        ui->sortByOwName->setDisabled(true);
        ui->sortBySurname->setDisabled(true);
        ui->sortBySVol->setDisabled(true);
    }
}

void fileexport::on_exportButtons_accepted()
{
    TransportRegister temp(reg);
    QString *arr = new QString[temp.nrOfVeh()];

    if (ui->dontSortButton->isChecked() == true)
    {
    }
    else if (ui->sortByModel->isChecked() == true)
    {
        temp.sortByModel();
    }
    else if (ui->sortByLicNr->isChecked() == true)
    {
        temp.sortByLicenseNumber();
    }
    else if (ui->sortByOwName->isChecked() == true)
    {
        temp.sortByOwnerName();
    }
    else if (ui->sortBySurname->isChecked() == true)
    {
        temp.sortByOwnerSurname();
    }
    else if (ui->sortByID->isChecked() == true)
    {
        temp.sortByOwnerID();
    }
    else if (ui->sortByEnsur->isChecked() == true)
    {
        temp.sortByEnsurance();
    }
    else if (ui->sortByLoadCap->isChecked() == true)
    {
        temp.sortByLoadCapacity();
    }
    else if (ui->sortByMaxSpeed->isChecked() == true)
    {
        temp.sortByMaxSpeed();
    }
    else if (ui->sortBySVol->isChecked() == true)
    {
        temp.sortBySVolume();
    }
    else if (ui->sortByCompName->isChecked() == true)
    {
        temp.sortByCompanyName();
    }
    else if (ui->sortByOrgNr->isChecked() == true)
    {
        temp.sortByOrgNr();
    }
    else if (ui->sortByBusType->isChecked() == true)
    {
        temp.sortByBusType();
    }
    else if (ui->sortByBusNumber->isChecked() == true)
    {
        temp.sortByBusNr();
    }
    else if (ui->sortByNrOfSeats->isChecked() == true)
    {
        temp.sortByNrOfSeats();
    }
    if (ui->whatToExport->currentIndex() == 0)
    {
        for (int i = 0; i < temp.nrOfVeh(); i++)
        {
            if (typeid(PrivateCar) == typeid(*temp.vehicles[i]))
            {
                arr[i] = "PrivateCar|" + temp.vehicles[i]->toStringSimple();
            }
            else if (typeid(PrivateVan) == typeid(*temp.vehicles[i]))
            {
                arr[i] = "PrivateVan|" + temp.vehicles[i]->toStringSimple();
            }
            else if (typeid(Motorbike) == typeid(*temp.vehicles[i]))
            {
                arr[i] = "Motorbike|" + temp.vehicles[i]->toStringSimple();
            }
            else if (typeid(CompanyCar) == typeid(*temp.vehicles[i]))
            {
                arr[i] = "CompanyCar|" + temp.vehicles[i]->toStringSimple();
            }
            else if (typeid(CompanyVan) == typeid(*temp.vehicles[i]))
            {
                arr[i] = "CompanyVan|" + temp.vehicles[i]->toStringSimple();
            }
            else if (typeid(Bus) == typeid(*temp.vehicles[i]))
            {
                arr[i] = "Bus|" + temp.vehicles[i]->toStringSimple();
            }
        }
    }
    else if (ui->whatToExport->currentIndex() == 1)
    {
        temp.filterPCars();
        for (int i = 0; i < temp.nrOfVeh(); i++)
        {
            arr[i] = "PrivateCar|" + temp.vehicles[i]->toStringSimple();
        }
    }
    else if (ui->whatToExport->currentIndex() == 2)
    {
        temp.filterPVans();
        for (int i = 0; i < temp.nrOfVeh(); i++)
        {
            arr[i] = "PrivateVan|" + temp.vehicles[i]->toStringSimple();
        }
    }
    else if (ui->whatToExport->currentIndex() == 3)
    {
        temp.filterBikes();
        for (int i = 0; i < temp.nrOfVeh(); i++)
        {
            arr[i] = "Motorbike|" + temp.vehicles[i]->toStringSimple();
        }
    }
    else if (ui->whatToExport->currentIndex() == 4)
    {
        temp.filterCCars();
        for (int i = 0; i < temp.nrOfVeh(); i++)
        {
            arr[i] = "CompanyCar|" + temp.vehicles[i]->toStringSimple();
        }
    }
    else if (ui->whatToExport->currentIndex() == 5)
    {
        temp.filterCVans();
        for (int i = 0; i < temp.nrOfVeh(); i++)
        {
            arr[i] = "CompanyVan|" + temp.vehicles[i]->toStringSimple();
        }
    }
    else if (ui->whatToExport->currentIndex() == 6)
    {
        temp.filterBuses();
        for (int i = 0; i < temp.nrOfVeh(); i++)
        {
            arr[i] = "Bus|" + temp.vehicles[i]->toStringSimple();
        }
    }

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), QString(),
                                                    tr("Text Files (*.txt)"));

    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox notExported(this);
            notExported.critical(this, "Error", "Error writing to file!");
        }
        else
        {
            QTextStream stream(&file);
            stream << "\r\n"; //Blank first line for proper work
            for (int i = 0; i < temp.nrOfVeh(); i++)
            {
                stream << arr[i] <<  "\r\n";
            }
            stream.flush();
            file.close();
        }
    }
}

