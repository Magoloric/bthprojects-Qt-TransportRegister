/* Vehicle type declaration */
#ifndef BUS_H
#define BUS_H
#include "companyvehicle.h"

class Bus : public CompanyVehicle
{
public:
Bus(QString model,
    QString licenseNumber,
    QString companyName,
    QString orgNr,
    QString busType,
    QString busNr,
    int numberOfSeats);
~Bus();

//Set-functions
void setBusType(QString busType);
void setBusNr(QString busNr);
void setNrOfSeats(int numberOfSeats);

//Get-functions
QString getBusType();
QString getBusNr();
int getNrOfSeats();

//Output functions
QString toString() const; // Used for information display
QString toStringSimple() const; // Used for database exports: only values are printed out

private:
QString busType; //Type of bus: City, Regional etc.
QString busNr; //Bus number set by company, e.g. 0034
int numberOfSeats;
};
#endif
