#include "transportregister.h"

void TransportRegister::expand()
{
        Vehicle** temp = new Vehicle*[this->capacity + 5];

        for (int i = 0; i < nrOfVehicles; i++)
        {
                temp[i] = this->vehicles[i];
        }

        delete[] this->vehicles;
        this->vehicles = temp;

        this->capacity += 5;
}

TransportRegister::TransportRegister()
{
        this->nrOfVehicles = 0;
        this->capacity = 5;
        this->vehicles = new Vehicle*[this->capacity];
}

TransportRegister::TransportRegister(const TransportRegister & other)
{
        this->nrOfVehicles = other.nrOfVehicles;
        this->capacity = other.capacity;
        this->vehicles = new Vehicle*[other.capacity];

        for (int i = 0; i < other.nrOfVehicles; i++)
        {
                if (typeid(PrivateCar) == typeid(*other.vehicles[i]))
                {
                        this->vehicles[i] = new PrivateCar(dynamic_cast<PrivateCar*>(other.vehicles[i])->getModel(),
                                                           dynamic_cast<PrivateCar*>(other.vehicles[i])->getLicenseNumber(),
                                                           dynamic_cast<PrivateCar*>(other.vehicles[i])->getOwnerName(),
                                                           dynamic_cast<PrivateCar*>(other.vehicles[i])->getOwnerSurname(),
                                                           dynamic_cast<PrivateCar*>(other.vehicles[i])->getOwnerID(),
                                                           dynamic_cast<PrivateCar*>(other.vehicles[i])->getEnsurance()
                                                           );
                }
                else if (typeid(PrivateVan) == typeid(*other.vehicles[i]))
                {
                        this->vehicles[i] = new PrivateVan(dynamic_cast<PrivateVan*>(other.vehicles[i])->getModel(),
                                                           dynamic_cast<PrivateVan*>(other.vehicles[i])->getLicenseNumber(),
                                                           dynamic_cast<PrivateVan*>(other.vehicles[i])->getOwnerName(),
                                                           dynamic_cast<PrivateVan*>(other.vehicles[i])->getOwnerSurname(),
                                                           dynamic_cast<PrivateVan*>(other.vehicles[i])->getOwnerID(),
                                                           dynamic_cast<PrivateVan*>(other.vehicles[i])->getLoadCapacity()
                                                           );
                }
                else if (typeid(Motorbike) == typeid(*other.vehicles[i]))
                {
                        this->vehicles[i] = new Motorbike(dynamic_cast<Motorbike*>(other.vehicles[i])->getModel(),
                                                          dynamic_cast<Motorbike*>(other.vehicles[i])->getLicenseNumber(),
                                                          dynamic_cast<Motorbike*>(other.vehicles[i])->getOwnerName(),
                                                          dynamic_cast<Motorbike*>(other.vehicles[i])->getOwnerSurname(),
                                                          dynamic_cast<Motorbike*>(other.vehicles[i])->getOwnerID(),
                                                          dynamic_cast<Motorbike*>(other.vehicles[i])->getMaxSpeed(),
                                                          dynamic_cast<Motorbike*>(other.vehicles[i])->getSVolume()
                                                          );
                }
                else if (typeid(CompanyCar) == typeid(*other.vehicles[i]))
                {
                        this->vehicles[i] = new CompanyCar(dynamic_cast<CompanyCar*>(other.vehicles[i])->getModel(),
                                                           dynamic_cast<CompanyCar*>(other.vehicles[i])->getLicenseNumber(),
                                                           dynamic_cast<CompanyCar*>(other.vehicles[i])->getCompanyName(),
                                                           dynamic_cast<CompanyCar*>(other.vehicles[i])->getOrgNr(),
                                                           dynamic_cast<CompanyCar*>(other.vehicles[i])->getEnsurance()
                                                           );
                }
                else if (typeid(CompanyVan) == typeid(*other.vehicles[i]))
                {
                        this->vehicles[i] = new CompanyVan(dynamic_cast<CompanyVan*>(other.vehicles[i])->getModel(),
                                                           dynamic_cast<CompanyVan*>(other.vehicles[i])->getLicenseNumber(),
                                                           dynamic_cast<CompanyVan*>(other.vehicles[i])->getCompanyName(),
                                                           dynamic_cast<CompanyVan*>(other.vehicles[i])->getOrgNr(),
                                                           dynamic_cast<CompanyVan*>(other.vehicles[i])->getLoadCapacity()
                                                           );
                }
                else if (typeid(Bus) == typeid(*other.vehicles[i]))
                {
                        this->vehicles[i] = new Bus(dynamic_cast<Bus*>(other.vehicles[i])->getModel(),
                                                    dynamic_cast<Bus*>(other.vehicles[i])->getLicenseNumber(),
                                                    dynamic_cast<Bus*>(other.vehicles[i])->getCompanyName(),
                                                    dynamic_cast<Bus*>(other.vehicles[i])->getOrgNr(),
                                                    dynamic_cast<Bus*>(other.vehicles[i])->getBusType(),
                                                    dynamic_cast<Bus*>(other.vehicles[i])->getBusNr(),
                                                    dynamic_cast<Bus*>(other.vehicles[i])->getNrOfSeats()
                                                    );
                }
        }
}

TransportRegister::~TransportRegister()
{
        for (int i = 0; i < this->nrOfVehicles; i++)
                delete this->vehicles[i];
        delete[] this->vehicles;
}

int TransportRegister::dupSearch(QString licenseNumber) const
{
        return this->dupSearch(Vehicle(licenseNumber));
}
int TransportRegister::dupSearch(const Vehicle & other) const
{
        int toFind = -1;

        for (int i = 0; i < this->nrOfVehicles && toFind == -1; i++)
        {
                if (other == *this->vehicles[i])
                {
                        toFind = i;
                }
        }

        return toFind;
}

//ADDING

bool TransportRegister::addPCar(QString model,
                                QString licenseNumber,
                                QString ownerName,
                                QString ownerSurname,
                                QString ownerID,
                                QString ensuredBy)
{
        bool added = false;

        int pos = -1;
        pos = this->dupSearch(licenseNumber);
        if (pos == -1)
        {
                if (this->nrOfVehicles == this->capacity)
                        this->expand();

                this->vehicles[this->nrOfVehicles++] = new PrivateCar(model,
                                                                      licenseNumber,
                                                                      ownerName,
                                                                      ownerSurname,
                                                                      ownerID,
                                                                      ensuredBy);
                added = true;
        }
        return added;
}

bool TransportRegister::addPVan(QString model,
                                QString licenseNumber,
                                QString ownerName,
                                QString ownerSurname,
                                QString ownerID,
                                int loadCapacity)
{
        bool added = false;

        int pos = -1;
        pos = this->dupSearch(licenseNumber);
        if (pos == -1)
        {
                if (this->nrOfVehicles == this->capacity)
                        this->expand();

                this->vehicles[this->nrOfVehicles++] = new PrivateVan(model,
                                                                      licenseNumber,
                                                                      ownerName,
                                                                      ownerSurname,
                                                                      ownerID,
                                                                      loadCapacity);
                added = true;
        }
        return added;
}

bool TransportRegister::addMBike(QString model,
                                 QString licenseNumber,
                                 QString ownerName,
                                 QString ownerSurname,
                                 QString ownerID,
                                 int maxSpeed,
                                 int sVolume)
{
        bool added = false;

        int pos = -1;
        pos = this->dupSearch(licenseNumber);
        if (pos == -1)
        {
                if (this->nrOfVehicles == this->capacity)
                        this->expand();

                this->vehicles[this->nrOfVehicles++] = new Motorbike(model,
                                                                     licenseNumber,
                                                                     ownerName,
                                                                     ownerSurname,
                                                                     ownerID,
                                                                     maxSpeed,
                                                                     sVolume);
                added = true;
        }
        return added;
}

bool TransportRegister::addCCar(QString model,
                                QString licenseNumber,
                                QString companyName,
                                QString orgNr,
                                QString ensuredBy)
{
        bool added = false;

        int pos = -1;
        pos = this->dupSearch(licenseNumber);
        if (pos == -1)
        {
                if (this->nrOfVehicles == this->capacity)
                        this->expand();

                this->vehicles[this->nrOfVehicles++] = new CompanyCar(model,
                                                                      licenseNumber,
                                                                      companyName,
                                                                      orgNr,
                                                                      ensuredBy);
                added = true;
        }
        return added;
}

bool TransportRegister::addCVan(QString model,
                                QString licenseNumber,
                                QString companyName,
                                QString orgNr,
                                int loadCapacity)
{
        bool added = false;

        int pos = -1;
        pos = this->dupSearch(licenseNumber);
        if (pos == -1)
        {
                if (this->nrOfVehicles == this->capacity)
                        this->expand();

                this->vehicles[this->nrOfVehicles++] = new CompanyVan(model,
                                                                      licenseNumber,
                                                                      companyName,
                                                                      orgNr,
                                                                      loadCapacity);
                added = true;
        }
        return added;
}

bool TransportRegister::addBus(QString model,
                               QString licenseNumber,
                               QString companyName,
                               QString orgNr,
                               QString busType,
                               QString busNr,
                               int numberOfSeats)
{
        bool added = false;

        int pos = -1;
        pos = this->dupSearch(licenseNumber);
        if (pos == -1)
        {
                if (this->nrOfVehicles == this->capacity)
                        this->expand();

                this->vehicles[this->nrOfVehicles++] = new Bus(model,
                                                               licenseNumber,
                                                               companyName,
                                                               orgNr,
                                                               busType,
                                                               busNr,
                                                               numberOfSeats);
                added = true;
        }
        return added;
}

//EDITING

bool TransportRegister::editPCar(QString model,
                                 QString licenseNumber,
                                 QString ownerName,
                                 QString ownerSurname,
                                 QString ownerID,
                                 QString ensuredBy)
{
        bool changed = false;
        for (int i = 0; i < this->nrOfVehicles; i++)
        {
                if (this->vehicles[i]->getLicenseNumber() == licenseNumber && typeid(PrivateCar) == typeid(*vehicles[i]))
                {
                        if (model != "")
                                this->vehicles[i]->setModel(model);
                        if (ownerName != "")
                                dynamic_cast<PrivateCar*>(this->vehicles[i])->setOwnerName(ownerName);
                        if (ownerSurname != "")
                                dynamic_cast<PrivateCar*>(this->vehicles[i])->setOwnerSurname(ownerSurname);
                        if (ownerID != "")
                                dynamic_cast<PrivateCar*>(this->vehicles[i])->setOwnerID(ownerID);
                        if (ensuredBy != "")
                                dynamic_cast<PrivateCar*>(this->vehicles[i])->setEnsurance(ensuredBy);

                        changed = true;
                }
        }
        return changed;
}

bool TransportRegister::editPVan(QString model,
                                 QString licenseNumber,
                                 QString ownerName,
                                 QString ownerSurname,
                                 QString ownerID,
                                 int loadCapacity)
{

        bool changed = false;
        for (int i = 0; i < this->nrOfVehicles; i++)
        {
                if (this->vehicles[i]->getLicenseNumber() == licenseNumber && typeid(PrivateVan) == typeid(*vehicles[i]))
                {
                        if (model != "")
                                this->vehicles[i]->setModel(model);
                        if (ownerName != "")
                                dynamic_cast<PrivateVan*>(this->vehicles[i])->setOwnerName(ownerName);
                        if (ownerSurname != "")
                                dynamic_cast<PrivateVan*>(this->vehicles[i])->setOwnerSurname(ownerSurname);
                        if (ownerID != "")
                                dynamic_cast<PrivateVan*>(this->vehicles[i])->setOwnerID(ownerID);
                        if (loadCapacity != 0)
                                dynamic_cast<PrivateVan*>(this->vehicles[i])->setLoadCapacity(loadCapacity);

                        changed = true;
                }
        }
        return changed;
}

bool TransportRegister::editMBike(QString model,
                                  QString licenseNumber,
                                  QString ownerName,
                                  QString ownerSurname,
                                  QString ownerID,
                                  int maxSpeed,
                                  int sVolume)
{

        bool changed = false;
        for (int i = 0; i < this->nrOfVehicles; i++)
        {
                if (this->vehicles[i]->getLicenseNumber() == licenseNumber && typeid(Motorbike) == typeid(*vehicles[i]))
                {
                        if (model != "")
                                this->vehicles[i]->setModel(model);
                        if (ownerName != "")
                                dynamic_cast<Motorbike*>(this->vehicles[i])->setOwnerName(ownerName);
                        if (ownerSurname != "")
                                dynamic_cast<Motorbike*>(this->vehicles[i])->setOwnerSurname(ownerSurname);
                        if (ownerID != "")
                                dynamic_cast<Motorbike*>(this->vehicles[i])->setOwnerID(ownerID);
                        if (maxSpeed != 0)
                                dynamic_cast<Motorbike*>(this->vehicles[i])->setMaxSpeed(maxSpeed);
                        if (sVolume != 0)
                                dynamic_cast<Motorbike*>(this->vehicles[i])->setSVolume(sVolume);

                        changed = true;
                }
        }
        return changed;
}

bool TransportRegister::editCCar(QString model,
                                 QString licenseNumber,
                                 QString companyName,
                                 QString orgNr,
                                 QString ensuredBy)
{
        bool changed = false;
        for (int i = 0; i < this->nrOfVehicles; i++)
        {
                if (this->vehicles[i]->getLicenseNumber() == licenseNumber && typeid(CompanyCar) == typeid(*vehicles[i]))
                {
                        if (model != "")
                                this->vehicles[i]->setModel(model);
                        if (companyName != "")
                                dynamic_cast<CompanyCar*>(this->vehicles[i])->setCompanyName(companyName);
                        if (orgNr != "")
                                dynamic_cast<CompanyCar*>(this->vehicles[i])->setOrgNr(orgNr);
                        if (ensuredBy != "")
                                dynamic_cast<CompanyCar*>(this->vehicles[i])->setEnsurance(ensuredBy);

                        changed = true;
                }
        }
        return changed;
}

bool TransportRegister::editCVan(QString model,
                                 QString licenseNumber,
                                 QString companyName,
                                 QString orgNr,
                                 int loadCapacity)
{
        bool changed = false;
        for (int i = 0; i < this->nrOfVehicles; i++)
        {
                if (this->vehicles[i]->getLicenseNumber() == licenseNumber && typeid(CompanyVan) == typeid(*vehicles[i]))
                {
                        if (model != "")
                                this->vehicles[i]->setModel(model);
                        if (companyName != "")
                                dynamic_cast<CompanyVan*>(this->vehicles[i])->setCompanyName(companyName);
                        if (orgNr != "")
                                dynamic_cast<CompanyVan*>(this->vehicles[i])->setOrgNr(orgNr);
                        if (loadCapacity != 0)
                                dynamic_cast<CompanyVan*>(this->vehicles[i])->setLoadCapacity(loadCapacity);

                        changed = true;
                }
        }
        return changed;
}

bool TransportRegister::editBus(QString model,
                                QString licenseNumber,
                                QString companyName,
                                QString orgNr,
                                QString busType,
                                QString busNr,
                                int numberOfSeats)
{
        bool changed = false;
        for (int i = 0; i < this->nrOfVehicles; i++)
        {
                if (this->vehicles[i]->getLicenseNumber() == licenseNumber && typeid(Bus) == typeid(*vehicles[i]))
                {
                        if (model != "")
                                this->vehicles[i]->setModel(model);
                        if (companyName != "")
                                dynamic_cast<Bus*>(this->vehicles[i])->setCompanyName(companyName);
                        if (orgNr != "")
                                dynamic_cast<Bus*>(this->vehicles[i])->setOrgNr(orgNr);
                        if (busType != "")
                                dynamic_cast<Bus*>(this->vehicles[i])->setBusType(busType);
                        if (busNr != "")
                                dynamic_cast<Bus*>(this->vehicles[i])->setBusNr(busNr);
                        if (numberOfSeats != 0)
                                dynamic_cast<Bus*>(this->vehicles[i])->setNrOfSeats(numberOfSeats);


                        changed = true;
                }
        }
        return changed;
}

bool TransportRegister::removeVehicle(QString licenseNumber)
{
        bool removed = false;
        int toDel = this->dupSearch(licenseNumber);
        if (toDel != -1)
        {
                delete this->vehicles[toDel];
                for (int i = toDel; i < this->nrOfVehicles; i++)
                {
                        this->vehicles[i] = this->vehicles[i + 1];
                }
                this->nrOfVehicles--;
                removed = true;
        }
        return removed;
}
void TransportRegister::sortByModel()
{
        {
                int minIndex = 0;
                for (int i = 0; i < this->nrOfVehicles - 1; i++)
                {
                        minIndex = i;
                        for (int j = (i + 1); j < this->nrOfVehicles; j++)
                        {
                                if (this->vehicles[j]->getModel() < this->vehicles[minIndex]->getModel())
                                {
                                        minIndex = j;
                                }
                        }

                        Vehicle* temp = this->vehicles[minIndex];
                        this->vehicles[minIndex] = this->vehicles[i];
                        this->vehicles[i] = temp;

                }
        }
}


void TransportRegister::sortByLicenseNumber()
{
        {
                int minIndex = 0;
                for (int i = 0; i < this->nrOfVehicles - 1; i++)
                {
                        minIndex = i;
                        for (int j = (i + 1); j < this->nrOfVehicles; j++)
                        {
                                if (this->vehicles[j]->getLicenseNumber() < this->vehicles[minIndex]->getLicenseNumber())
                                {
                                        minIndex = j;
                                }
                        }
                        Vehicle* temp = this->vehicles[minIndex];
                        this->vehicles[minIndex] = this->vehicles[i];
                        this->vehicles[i] = temp;
                }
        }
}

void TransportRegister::sortByOwnerName()
{
        {
                int minIndex = 0;
                for (int i = 0; i < this->nrOfVehicles - 1; i++)
                {
                        minIndex = i;
                        for (int j = (i + 1); j < this->nrOfVehicles; j++)
                        {

                                if (dynamic_cast<PrivateVehicle*>(this->vehicles[j])->getOwnerName() < dynamic_cast<PrivateVehicle*>(this->vehicles[minIndex])->getOwnerName())
                                {
                                        minIndex = j;
                                }
                        }
                        Vehicle* temp = this->vehicles[minIndex];
                        this->vehicles[minIndex] = this->vehicles[i];
                        this->vehicles[i] = temp;
                }
        }
}
void TransportRegister::sortByOwnerSurname()
{
        {
                int minIndex = 0;
                for (int i = 0; i < this->nrOfVehicles - 1; i++)
                {
                        minIndex = i;
                        for (int j = (i + 1); j < this->nrOfVehicles; j++)
                        {

                                if (dynamic_cast<PrivateVehicle*>(this->vehicles[j])->getOwnerSurname() < dynamic_cast<PrivateVehicle*>(this->vehicles[minIndex])->getOwnerSurname())
                                {
                                        minIndex = j;
                                }
                        }
                        Vehicle* temp = this->vehicles[minIndex];
                        this->vehicles[minIndex] = this->vehicles[i];
                        this->vehicles[i] = temp;
                }
        }
}
void TransportRegister::sortByOwnerID()
{
        {
                int minIndex = 0;
                for (int i = 0; i < this->nrOfVehicles - 1; i++)
                {
                        minIndex = i;
                        for (int j = (i + 1); j < this->nrOfVehicles; j++)
                        {

                                if (dynamic_cast<PrivateVehicle*>(this->vehicles[j])->getOwnerID() < dynamic_cast<PrivateVehicle*>(this->vehicles[minIndex])->getOwnerID())
                                {
                                        minIndex = j;
                                }
                        }
                        Vehicle* temp = this->vehicles[minIndex];
                        this->vehicles[minIndex] = this->vehicles[i];
                        this->vehicles[i] = temp;
                }
        }
}
void TransportRegister::sortByEnsurance()
{
        {
                int minIndex = 0;
                for (int i = 0; i < this->nrOfVehicles - 1; i++)
                {
                        minIndex = i;
                        if (typeid(PrivateCar) == typeid(*vehicles[i]))
                        {
                                for (int j = (i + 1); j < this->nrOfVehicles; j++)
                                {
                                        if (dynamic_cast<PrivateCar*>(this->vehicles[j])->getEnsurance() < dynamic_cast<PrivateCar*>(this->vehicles[minIndex])->getEnsurance())
                                        {
                                                minIndex = j;
                                        }
                                }
                        }
                        else
                        {
                                for (int j = (i + 1); j < this->nrOfVehicles; j++)
                                {
                                        if (dynamic_cast<CompanyCar*>(this->vehicles[j])->getEnsurance() < dynamic_cast<CompanyCar*>(this->vehicles[minIndex])->getEnsurance())
                                        {
                                                minIndex = j;
                                        }
                                }
                        }
                        Vehicle* temp = this->vehicles[minIndex];
                        this->vehicles[minIndex] = this->vehicles[i];
                        this->vehicles[i] = temp;
                }
        }
}
void TransportRegister::sortByLoadCapacity()
{
        {
                int minIndex = 0;
                for (int i = 0; i < this->nrOfVehicles - 1; i++)
                {
                        minIndex = i;
                        if (typeid(PrivateCar) == typeid(*vehicles[i]))
                        {
                                for (int j = (i + 1); j < this->nrOfVehicles; j++)
                                {
                                        if (dynamic_cast<PrivateVan*>(this->vehicles[j])->getLoadCapacity() < dynamic_cast<PrivateVan*>(this->vehicles[minIndex])->getLoadCapacity())
                                        {
                                                minIndex = j;
                                        }
                                }
                        }
                        else
                        {
                                for (int j = (i + 1); j < this->nrOfVehicles; j++)
                                {
                                        if (dynamic_cast<CompanyVan*>(this->vehicles[j])->getLoadCapacity() < dynamic_cast<CompanyVan*>(this->vehicles[minIndex])->getLoadCapacity())
                                        {
                                                minIndex = j;
                                        }
                                }
                        }
                        Vehicle* temp = this->vehicles[minIndex];
                        this->vehicles[minIndex] = this->vehicles[i];
                        this->vehicles[i] = temp;
                }
        }
}
void TransportRegister::sortByMaxSpeed()
{
        {
                int minIndex = 0;
                for (int i = 0; i < this->nrOfVehicles - 1; i++)
                {
                        minIndex = i;
                        for (int j = (i + 1); j < this->nrOfVehicles; j++)
                        {

                                if (dynamic_cast<Motorbike*>(this->vehicles[j])->getMaxSpeed() < dynamic_cast<Motorbike*>(this->vehicles[minIndex])->getMaxSpeed())
                                {
                                        minIndex = j;
                                }
                        }
                        Vehicle* temp = this->vehicles[minIndex];
                        this->vehicles[minIndex] = this->vehicles[i];
                        this->vehicles[i] = temp;
                }
        }
}
void TransportRegister::sortBySVolume()
{
        {
                int minIndex = 0;
                for (int i = 0; i < this->nrOfVehicles - 1; i++)
                {
                        minIndex = i;
                        for (int j = (i + 1); j < this->nrOfVehicles; j++)
                        {

                                if (dynamic_cast<Motorbike*>(this->vehicles[j])->getSVolume() < dynamic_cast<Motorbike*>(this->vehicles[minIndex])->getSVolume())
                                {
                                        minIndex = j;
                                }
                        }
                        Vehicle* temp = this->vehicles[minIndex];
                        this->vehicles[minIndex] = this->vehicles[i];
                        this->vehicles[i] = temp;
                }
        }
}
void TransportRegister::sortByCompanyName()
{
        {
                int minIndex = 0;
                for (int i = 0; i < this->nrOfVehicles - 1; i++)
                {
                        minIndex = i;
                        for (int j = (i + 1); j < this->nrOfVehicles; j++)
                        {

                                if (dynamic_cast<CompanyVehicle*>(this->vehicles[j])->getCompanyName() < dynamic_cast<CompanyVehicle*>(this->vehicles[minIndex])->getCompanyName())
                                {
                                        minIndex = j;
                                }
                        }
                        Vehicle* temp = this->vehicles[minIndex];
                        this->vehicles[minIndex] = this->vehicles[i];
                        this->vehicles[i] = temp;
                }
        }
}
void TransportRegister::sortByOrgNr()
{
        {
                int minIndex = 0;
                for (int i = 0; i < this->nrOfVehicles - 1; i++)
                {
                        minIndex = i;
                        for (int j = (i + 1); j < this->nrOfVehicles; j++)
                        {

                                if (dynamic_cast<CompanyVehicle*>(this->vehicles[j])->getOrgNr() < dynamic_cast<CompanyVehicle*>(this->vehicles[minIndex])->getOrgNr())
                                {
                                        minIndex = j;
                                }
                        }
                        Vehicle* temp = this->vehicles[minIndex];
                        this->vehicles[minIndex] = this->vehicles[i];
                        this->vehicles[i] = temp;
                }
        }
}
void TransportRegister::sortByBusType()
{
        {
                int minIndex = 0;
                for (int i = 0; i < this->nrOfVehicles - 1; i++)
                {
                        minIndex = i;
                        for (int j = (i + 1); j < this->nrOfVehicles; j++)
                        {

                                if (dynamic_cast<Bus*>(this->vehicles[j])->getBusType() < dynamic_cast<Bus*>(this->vehicles[minIndex])->getBusType())
                                {
                                        minIndex = j;
                                }
                        }
                        Vehicle* temp = this->vehicles[minIndex];
                        this->vehicles[minIndex] = this->vehicles[i];
                        this->vehicles[i] = temp;
                }
        }
}
void TransportRegister::sortByBusNr()
{
        {
                int minIndex = 0;
                for (int i = 0; i < this->nrOfVehicles - 1; i++)
                {
                        minIndex = i;
                        for (int j = (i + 1); j < this->nrOfVehicles; j++)
                        {

                                if (dynamic_cast<Bus*>(this->vehicles[j])->getBusNr() < dynamic_cast<Bus*>(this->vehicles[minIndex])->getBusNr())
                                {
                                        minIndex = j;
                                }
                        }
                        Vehicle* temp = this->vehicles[minIndex];
                        this->vehicles[minIndex] = this->vehicles[i];
                        this->vehicles[i] = temp;
                }
        }
}
void TransportRegister::sortByNrOfSeats()
{
        {
                int minIndex = 0;
                for (int i = 0; i < this->nrOfVehicles - 1; i++)
                {
                        minIndex = i;
                        for (int j = (i + 1); j < this->nrOfVehicles; j++)
                        {

                                if (dynamic_cast<Bus*>(this->vehicles[j])->getNrOfSeats() < dynamic_cast<Bus*>(this->vehicles[minIndex])->getNrOfSeats())
                                {
                                        minIndex = j;
                                }
                        }
                        Vehicle* temp = this->vehicles[minIndex];
                        this->vehicles[minIndex] = this->vehicles[i];
                        this->vehicles[i] = temp;
                }
        }
}
//Get quantity
int TransportRegister::nrOfPCars()
{
        int privCars = 0;

        for (int i = 0; i < this->nrOfVehicles; i++)
        {
                if (typeid(PrivateCar) == typeid(*vehicles[i]))
                        privCars++;
        }

        return privCars;
}
int TransportRegister::nrOfPVans()
{
        int privVans = 0;

        for (int i = 0; i < this->nrOfVehicles; i++)
        {
                if (typeid(PrivateVan) == typeid(*vehicles[i]))
                        privVans++;
        }

        return privVans;
}
int TransportRegister::nrOfMBikes()
{
        int motorbikes = 0;

        for (int i = 0; i < this->nrOfVehicles; i++)
        {
                if (typeid(Motorbike) == typeid(*vehicles[i]))
                        motorbikes++;
        }

        return motorbikes;
}
int TransportRegister::nrOfCCars()
{
        int compCars = 0;

        for (int i = 0; i < this->nrOfVehicles; i++)
        {
                if (typeid(CompanyCar) == typeid(*vehicles[i]))
                        compCars++;
        }

        return compCars;
}
int TransportRegister::nrOfCVans()
{
        int compVans = 0;

        for (int i = 0; i < this->nrOfVehicles; i++)
        {
                if (typeid(CompanyVan) == typeid(*vehicles[i]))
                        compVans++;
        }

        return compVans;
}
int TransportRegister::nrOfBuses()
{
        int buses = 0;

        for (int i = 0; i < this->nrOfVehicles; i++)
        {
                if (typeid(Bus) == typeid(*vehicles[i]))
                        buses++;
        }

        return buses;
}
int TransportRegister::nrOfVeh()
{
        return this->nrOfVehicles;
}
void TransportRegister::filterPCars()
{
        Vehicle** temp = new Vehicle*[this->nrOfPCars()];
        int j = 0;
        for (int i = 0; i < nrOfVehicles; i++)
        {
                if (typeid(PrivateCar) == typeid(*this->vehicles[i]))
                {
                        temp[j] = this->vehicles[i];
                        j++;
                }
        }

        delete[] this->vehicles;
        this->vehicles = temp;
        this->nrOfVehicles = j;
}

void TransportRegister::filterPVans()
{
        Vehicle** temp = new Vehicle*[this->nrOfPVans()];
        int j = 0;
        for (int i = 0; i < nrOfVehicles; i++)
        {
                if (typeid(PrivateVan) == typeid(*this->vehicles[i]))
                {
                        temp[j] = this->vehicles[i];
                        j++;
                }
        }

        delete[] this->vehicles;
        this->vehicles = temp;
        this->nrOfVehicles = j;

}

void TransportRegister::filterBikes()
{
        Vehicle** temp = new Vehicle*[this->nrOfMBikes()];
        int j = 0;
        for (int i = 0; i < nrOfVehicles; i++)
        {
                if (typeid(Motorbike) == typeid(*this->vehicles[i]))
                {
                        temp[j] = this->vehicles[i];
                        j++;
                }
        }

        delete[] this->vehicles;
        this->vehicles = temp;
        this->nrOfVehicles = j;

}

void TransportRegister::filterCCars()
{
        Vehicle** temp = new Vehicle*[this->nrOfCCars()];
        int j = 0;
        for (int i = 0; i < nrOfVehicles; i++)
        {
                if (typeid(CompanyCar) == typeid(*this->vehicles[i]))
                {
                        temp[j] = this->vehicles[i];
                        j++;
                }
        }

        delete[] this->vehicles;
        this->vehicles = temp;
        this->nrOfVehicles = j;

}

void TransportRegister::filterCVans()
{
        Vehicle** temp = new Vehicle*[this->nrOfCVans()];
        int j = 0;
        for (int i = 0; i < nrOfVehicles; i++)
        {
                if (typeid(CompanyVan) == typeid(*this->vehicles[i]))
                {
                        temp[j] = this->vehicles[i];
                        j++;
                }
        }

        delete[] this->vehicles;
        this->vehicles = temp;
        this->nrOfVehicles = j;

}

void TransportRegister::filterBuses()
{
        Vehicle** temp = new Vehicle*[this->nrOfBuses()];
        int j = 0;
        for (int i = 0; i < nrOfVehicles; i++)
        {
                if (typeid(Bus) == typeid(*this->vehicles[i]))
                {
                        temp[j] = this->vehicles[i];
                        j++;
                }
        }

        delete[] this->vehicles;
        this->vehicles = temp;
        this->nrOfVehicles = j;

}

TransportRegister& TransportRegister::operator = (const TransportRegister & other)
{
        if (this != &other)
        {
                for (int i = 0; i < this->nrOfVehicles; i++)
                        delete this->vehicles[i];
                delete[] this->vehicles;
                {
                        this->nrOfVehicles = other.nrOfVehicles;
                        this->capacity = other.capacity;
                        this->vehicles = new Vehicle*[other.capacity];

                        for (int i = 0; i < other.nrOfVehicles; i++)
                        {
                                if (typeid(PrivateCar) == typeid(*other.vehicles[i]))
                                {
                                        this->vehicles[i] = new PrivateCar(dynamic_cast<PrivateCar*>(other.vehicles[i])->getModel(),
                                                                           dynamic_cast<PrivateCar*>(other.vehicles[i])->getLicenseNumber(),
                                                                           dynamic_cast<PrivateCar*>(other.vehicles[i])->getOwnerName(),
                                                                           dynamic_cast<PrivateCar*>(other.vehicles[i])->getOwnerSurname(),
                                                                           dynamic_cast<PrivateCar*>(other.vehicles[i])->getOwnerID(),
                                                                           dynamic_cast<PrivateCar*>(other.vehicles[i])->getEnsurance()
                                                                           );
                                }
                                else if (typeid(PrivateVan) == typeid(*other.vehicles[i]))
                                {
                                        this->vehicles[i] = new PrivateVan(dynamic_cast<PrivateVan*>(other.vehicles[i])->getModel(),
                                                                           dynamic_cast<PrivateVan*>(other.vehicles[i])->getLicenseNumber(),
                                                                           dynamic_cast<PrivateVan*>(other.vehicles[i])->getOwnerName(),
                                                                           dynamic_cast<PrivateVan*>(other.vehicles[i])->getOwnerSurname(),
                                                                           dynamic_cast<PrivateVan*>(other.vehicles[i])->getOwnerID(),
                                                                           dynamic_cast<PrivateVan*>(other.vehicles[i])->getLoadCapacity()
                                                                           );
                                }
                                else if (typeid(Motorbike) == typeid(*other.vehicles[i]))
                                {
                                        this->vehicles[i] = new Motorbike(dynamic_cast<Motorbike*>(other.vehicles[i])->getModel(),
                                                                          dynamic_cast<Motorbike*>(other.vehicles[i])->getLicenseNumber(),
                                                                          dynamic_cast<Motorbike*>(other.vehicles[i])->getOwnerName(),
                                                                          dynamic_cast<Motorbike*>(other.vehicles[i])->getOwnerSurname(),
                                                                          dynamic_cast<Motorbike*>(other.vehicles[i])->getOwnerID(),
                                                                          dynamic_cast<Motorbike*>(other.vehicles[i])->getMaxSpeed(),
                                                                          dynamic_cast<Motorbike*>(other.vehicles[i])->getSVolume()
                                                                          );
                                }
                                else if (typeid(CompanyCar) == typeid(*other.vehicles[i]))
                                {
                                        this->vehicles[i] = new CompanyCar(dynamic_cast<CompanyCar*>(other.vehicles[i])->getModel(),
                                                                           dynamic_cast<CompanyCar*>(other.vehicles[i])->getLicenseNumber(),
                                                                           dynamic_cast<CompanyCar*>(other.vehicles[i])->getCompanyName(),
                                                                           dynamic_cast<CompanyCar*>(other.vehicles[i])->getOrgNr(),
                                                                           dynamic_cast<CompanyCar*>(other.vehicles[i])->getEnsurance()
                                                                           );
                                }
                                else if (typeid(CompanyVan) == typeid(*other.vehicles[i]))
                                {
                                        this->vehicles[i] = new CompanyVan(dynamic_cast<CompanyVan*>(other.vehicles[i])->getModel(),
                                                                           dynamic_cast<CompanyVan*>(other.vehicles[i])->getLicenseNumber(),
                                                                           dynamic_cast<CompanyVan*>(other.vehicles[i])->getCompanyName(),
                                                                           dynamic_cast<CompanyVan*>(other.vehicles[i])->getOrgNr(),
                                                                           dynamic_cast<CompanyVan*>(other.vehicles[i])->getLoadCapacity()
                                                                           );
                                }
                                else if (typeid(Bus) == typeid(*other.vehicles[i]))
                                {
                                        this->vehicles[i] = new Bus(dynamic_cast<Bus*>(other.vehicles[i])->getModel(),
                                                                    dynamic_cast<Bus*>(other.vehicles[i])->getLicenseNumber(),
                                                                    dynamic_cast<Bus*>(other.vehicles[i])->getCompanyName(),
                                                                    dynamic_cast<Bus*>(other.vehicles[i])->getOrgNr(),
                                                                    dynamic_cast<Bus*>(other.vehicles[i])->getBusType(),
                                                                    dynamic_cast<Bus*>(other.vehicles[i])->getBusNr(),
                                                                    dynamic_cast<Bus*>(other.vehicles[i])->getNrOfSeats()
                                                                    );
                                }
                        }
                }
        }
        return *this;
}
