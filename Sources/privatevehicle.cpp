#include "privatevehicle.h"

PrivateVehicle::PrivateVehicle(QString model,
                               QString licenseNumber,
                               QString ownerName,
                               QString ownerSurname,
                               QString ownerID) :
    Vehicle (model, licenseNumber)
{
    this->ownerName = ownerName;
    this->ownerSurname = ownerSurname;
    this->ownerID = ownerID;
}

PrivateVehicle::~PrivateVehicle()
{

}

void PrivateVehicle::setOwnerName(QString ownerName)
{
    this->ownerName = ownerName;

}

void PrivateVehicle::setOwnerSurname(QString ownerSurname)
{
    this->ownerSurname = ownerSurname;

}
void PrivateVehicle::setOwnerID(QString ownerID)
{
    this->ownerID = ownerID;

}

QString PrivateVehicle::getOwnerName()
{
    return this->ownerName;
}
QString PrivateVehicle::getOwnerSurname()
{
    return this->ownerSurname;
}

QString PrivateVehicle::getOwnerID()
{
    return this->ownerID;
}

QString PrivateVehicle::toString() const
{
    QString output;

    output += Vehicle::toString()
              + "Owner's Name: " + ownerName + "\n"
              + "Owner's Surname: " + ownerSurname + "\n"
              + "Owner's ID Number: " + ownerID + "\n";

    return output;
}
QString PrivateVehicle::toStringSimple() const
{
    QString output;

    output += Vehicle::toStringSimple()
              + ownerName + "|" + ownerSurname + "|" + ownerID + "|";

    return output;
}
