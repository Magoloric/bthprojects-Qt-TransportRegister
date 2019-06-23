#include "privatevan.h"

PrivateVan::PrivateVan(QString model,
                       QString licenseNumber,
                       QString ownerName,
                       QString ownerSurname,
                       QString ownerID,
                       int loadCapacity) :
    PrivateVehicle(model,
                   licenseNumber,
                   ownerName,
                   ownerSurname,
                   ownerID)
{
    this->loadCapacity = loadCapacity;

}
PrivateVan::~PrivateVan()
{

}

void PrivateVan::setLoadCapacity(int loadCapacity)
{
    this->loadCapacity = loadCapacity;
}

int PrivateVan::getLoadCapacity()
{
    return this->loadCapacity;
}

//ToString
QString PrivateVan::toString() const
{
    QString output;

    output += PrivateVehicle::toString()
              + QString::fromStdString("Load Capacity: ") + QString::fromStdString(std::to_string(loadCapacity)) + QString::fromStdString("\n");

    return output;
}

QString PrivateVan::toStringSimple() const
{
    QString output;

    output += PrivateVehicle::toStringSimple()
              + QString::fromStdString(std::to_string(loadCapacity)) + QString::fromStdString("| \n");

    return output;
}
