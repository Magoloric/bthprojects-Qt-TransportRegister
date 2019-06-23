/* Abstract vehicle group declaration */
#ifndef COMPANYVEHICLE_H
#define COMPANYVEHICLE_H
#include "vehicle.h"

class CompanyVehicle : public Vehicle
{
public:
CompanyVehicle(QString model,
               QString licenseNumber,
               QString companyName,
               QString orgNr);
virtual ~CompanyVehicle();

//Set-functions
void setCompanyName(QString companyName);
void setOrgNr(QString orgNr);

//Get-functions
QString getCompanyName();
QString getOrgNr();


//Output functions
virtual QString toString() const; // Used for information display
virtual QString toStringSimple() const; // Used for database exports: only values are printed out


private:
QString companyName;
QString orgNr; //Company ID number
};

#endif // COMPANYVEHICLE_H
