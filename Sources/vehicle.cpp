#include "vehicle.h"

Vehicle::Vehicle(QString model,
                 QString licenseNumber)
{
    this->model = model;
    this->licenseNumber = licenseNumber;
}
Vehicle::Vehicle(QString licenseNumber)
{
    this->licenseNumber = licenseNumber;
}
Vehicle::~Vehicle()
{

}
void Vehicle::setModel(QString model)
{
    this->model = model;
}

void Vehicle::setLicenseNumber(QString licenseNumber)
{
    this->licenseNumber = licenseNumber;
}
QString Vehicle::getModel() const
{
    return this->model;
}
QString Vehicle::getLicenseNumber() const
{
    return this->licenseNumber;
}
QString Vehicle::toString() const
{
    QString output;

    output += "Model: " + model + "\n" + "License Number: " + licenseNumber + "\n";

    return output;
}
QString Vehicle::toStringSimple() const
{
    QString output;

    output += model + "|" + licenseNumber + "|";

    return output;
}
bool Vehicle::operator== (Vehicle & other) const
{
    return this->licenseNumber == other.licenseNumber;
}

