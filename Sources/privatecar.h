/* Vehicle type declaration */
#ifndef PRIVATECAR_H
#define PRIVATECAR_H
#include "privatevehicle.h"

class PrivateCar : public PrivateVehicle
{
public:
PrivateCar(QString model,
           QString licenseNumber,
           QString ownerName,
           QString ownerSurname,
           QString ownerID,
           QString ensuredBy);
~PrivateCar();

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
