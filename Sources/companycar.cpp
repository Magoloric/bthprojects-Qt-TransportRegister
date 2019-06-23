#include "companycar.h"

CompanyCar::CompanyCar(QString model,
                       QString licenseNumber,
                       QString companyName,
                       QString orgNr,
                       QString ensuredBy) :
    CompanyVehicle(model,
                   licenseNumber,
                   companyName,
                   orgNr)
{
    this->ensuredBy = ensuredBy;
}

CompanyCar::~CompanyCar()
{

}
void CompanyCar::setEnsurance(QString ensuredBy)
{
    this->ensuredBy = ensuredBy;

}
QString CompanyCar::getEnsurance()
{
    return this->ensuredBy;

}
QString CompanyCar::toString() const
{
    QString output;

    output += CompanyVehicle::toString()
              + "Ensured by: " + ensuredBy + "\n";
    return output;
}
QString CompanyCar::toStringSimple() const
{
    QString output;

    output += CompanyVehicle::toStringSimple()
              + ensuredBy + "| \n";
    return output;
}
