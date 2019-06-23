#include "companyvan.h"

CompanyVan::CompanyVan(QString model,
                       QString licenseNumber,
                       QString companyName,
                       QString orgNr,
                       int loadCapacity) :
    CompanyVehicle(model,
                   licenseNumber,
                   companyName,
                   orgNr)
{
    this->loadCapacity = loadCapacity;
}

CompanyVan::~CompanyVan()
{

}
void CompanyVan::setLoadCapacity(int loadCapacity)
{
    this->loadCapacity = loadCapacity;

}
int CompanyVan::getLoadCapacity()
{
    return this->loadCapacity;

}
QString CompanyVan::toString() const
{
    QString output;

    output += CompanyVehicle::toString()
              + QString::fromStdString("Load Capacity: ") + QString::fromStdString(std::to_string(loadCapacity)) + QString::fromStdString("\n");

    return output;
}
QString CompanyVan::toStringSimple() const
{
    QString output;

    output += CompanyVehicle::toStringSimple()
              + QString::fromStdString(std::to_string(loadCapacity)) + QString::fromStdString("| \n");

    return output;
}
