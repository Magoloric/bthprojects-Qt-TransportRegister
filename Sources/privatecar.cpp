#include "privatecar.h"

PrivateCar::PrivateCar(QString model,
                       QString licenseNumber,
                       QString ownerName,
                       QString ownerSurname,
                       QString ownerID,
                       QString ensuredBy) :
    PrivateVehicle(model,
                   licenseNumber,
                   ownerName,
                   ownerSurname,
                   ownerID)
{

    this->ensuredBy = ensuredBy;

}
PrivateCar::~PrivateCar()
{

}

//Sets & Gets
void PrivateCar::setEnsurance(QString ensuredBy)
{
    this->ensuredBy = ensuredBy;
}

QString PrivateCar::getEnsurance()
{
    return this->ensuredBy;
}

//ToString
QString PrivateCar::toString() const
{
    QString output;

    output += PrivateVehicle::toString()
              + "Ensured by: " + ensuredBy + "\n";

    return output;
}
QString PrivateCar::toStringSimple() const
{
    QString output;

    output += PrivateVehicle::toStringSimple()
              + ensuredBy + "| \n";

    return output;
}
