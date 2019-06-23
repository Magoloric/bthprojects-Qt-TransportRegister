/* Vehicle type declaration */
#ifndef PRIVATEVAN_H
#define PRIVATEVAN_H
#include "privatevehicle.h"

class PrivateVan : public PrivateVehicle
{
public:
PrivateVan(QString model,
           QString licenseNumber,
           QString ownerName,
           QString ownerSurname,
           QString ownerID,
           int loadCapacity);
~PrivateVan();

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
