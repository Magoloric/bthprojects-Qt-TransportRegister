/* Vehicle type declaration */
#ifndef COMPANYCAR_H
#define COMPANYCAR_H
#include "companyvehicle.h"

class CompanyCar : public CompanyVehicle
{
public:
CompanyCar(QString model,
           QString licenseNumber,
           QString companyName,
           QString orgNr,
           QString ensuredBy);
~CompanyCar();

//Set- and get-functions
void setEnsurance(QString ensuredBy);
QString getEnsurance();

//Output functions
QString toString() const; // Used for information display
QString toStringSimple() const; // Used for database exports: only values are printed out

private:
QString ensuredBy;
};
#endif
