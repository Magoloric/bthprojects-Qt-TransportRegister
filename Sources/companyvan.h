/* Vehicle type declaration */
#ifndef COMPANYVAN_H
#define COMPANYVAN_H
#include "companyvehicle.h"

class CompanyVan : public CompanyVehicle
{
public:
CompanyVan(QString model,
           QString licenseNumber,
           QString companyName,
           QString orgNr,
           int loadCapacity);
~CompanyVan();

//Set- and get-functions
void setLoadCapacity(int loadCapacity);
int getLoadCapacity();

//Output functions
QString toString() const; // Used for information display
QString toStringSimple() const; // Used for database exports: only values are printed out


private:
int loadCapacity;
};
#endif
