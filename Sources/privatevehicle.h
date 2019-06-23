/* Abstract vehicle group declaration */
#ifndef PRIVATEVEHICLE_H
#define PRIVATEVEHICLE_H
#include "vehicle.h"

class PrivateVehicle : public Vehicle
{
public:
PrivateVehicle(QString model,
               QString licenseNumber,
               QString ownerName,
               QString ownerSurname,
               QString ownerID);
virtual ~PrivateVehicle();

//Set-functions
void setOwnerName(QString ownerName);
void setOwnerSurname(QString ownerSurname);
void setOwnerID(QString ownerID);

//Get-functions
QString getOwnerName();
QString getOwnerSurname();
QString getOwnerID();

//Output functions
virtual QString toString() const; // Used for information display
virtual QString toStringSimple() const; // Used for database exports: only values are printed out

private:
QString ownerName;
QString ownerSurname;
QString ownerID;
};

#endif // PRIVATEVEHICLE_H
