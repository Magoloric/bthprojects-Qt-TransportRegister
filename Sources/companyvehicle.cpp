#include "companyvehicle.h"

CompanyVehicle::CompanyVehicle(QString model,
                               QString licenseNumber,
                               QString companyName,
                               QString orgNr) :
    Vehicle(model, licenseNumber)
{
    this->companyName = companyName;
    this->orgNr = orgNr;
}

CompanyVehicle::~CompanyVehicle()
{

}

void CompanyVehicle::setCompanyName(QString companyName)
{
    this->companyName = companyName;
}
void CompanyVehicle::setOrgNr(QString orgNr)
{
    this->orgNr = orgNr;
}
QString CompanyVehicle::getCompanyName()
{
    return this->companyName;
}

QString CompanyVehicle::getOrgNr()
{
    return this->orgNr;
}

QString CompanyVehicle::toString() const
{
    QString output;

    output += Vehicle::toString()
              + "Company Name: " + companyName + "\n"
              + "Organization Number: " + orgNr + "\n";

    return output;
}
QString CompanyVehicle::toStringSimple() const
{
    QString output;

    output += Vehicle::toStringSimple()
              + companyName + "|" + orgNr + "|";

    return output;
}
