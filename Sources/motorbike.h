/* Vehicle type declaration */
#ifndef MOTORBIKE_H
#define MOTORBIKE_H
#include "privatevehicle.h"

class Motorbike : public PrivateVehicle
{
public:
Motorbike(QString model,
          QString licenseNumber,
          QString ownerName,
          QString ownerSurname,
          QString ownerID,
          int maxSpeed,
          int sVolume);
~Motorbike();

//Set-functions
void setMaxSpeed(int maxSpeed);
void setSVolume(int sVolume);


//Get-functions
int getMaxSpeed();
int getSVolume();

//Output options
QString toString() const; // Used for information display
QString toStringSimple() const; // Used for database exports: only values are printed out

private:
int maxSpeed;
int sVolume; //Swept volume, used to determine if a mc is heavy or light.
};
#endif
