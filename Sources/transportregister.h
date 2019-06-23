/* Container class declaration */
#ifndef TRANSPORTREGISTER_H
#define TRANSPORTREGISTER_H

#include "privatecar.h"
#include "privatevan.h"
#include "motorbike.h"
#include "companycar.h"
#include "companyvan.h"
#include "bus.h"
#include "privatevehicle.h"
#include "companyvehicle.h"
#include <typeinfo>
class TransportRegister
{
friend class TransportRegisterWindow;
friend class fileexport;

public:
TransportRegister();
TransportRegister(const TransportRegister & other);
~TransportRegister();

//Functions for adding vehicles
bool addPCar(QString model,
             QString licenseNumber,
             QString ownerName,
             QString ownerSurname,
             QString ownerID,
             QString ensuredBy);     //PrivateCar
bool addPVan(QString model,
             QString licenseNumber,
             QString ownerName,
             QString ownerSurname,
             QString ownerID,
             int loadCapacity);     //PrivateVan
bool addMBike(QString model,
              QString licenseNumber,
              QString ownerName,
              QString ownerSurname,
              QString ownerID,
              int maxSpeed,
              int sVolume);     //Motorbike
bool addCCar(QString model,
             QString licenseNumber,
             QString companyName,
             QString orgNr,
             QString ensuredBy);     //CompanyCar
bool addCVan(QString model,
             QString licenseNumber,
             QString companyName,
             QString orgNr,
             int loadCapacity);     //CompanyVan
bool addBus(QString model,
            QString licenseNumber,
            QString companyName,
            QString orgNr,
            QString busType,
            QString busNr,
            int numberOfSeats);     //Bus

//Functions for editing vehicles
bool editPCar(QString model,
              QString licenseNumber,
              QString ownerName,
              QString ownerSurname,
              QString ownerID,
              QString ensuredBy);     //PrivateCar
bool editPVan(QString model,
              QString licenseNumber,
              QString ownerName,
              QString ownerSurname,
              QString ownerID,
              int loadCapacity);     //PrivateVan
bool editMBike(QString model,
               QString licenseNumber,
               QString ownerName,
               QString ownerSurname,
               QString ownerID,
               int maxSpeed,
               int sVolume);     //Motorbike
bool editCCar(QString model,
              QString licenseNumber,
              QString companyName,
              QString orgNr,
              QString ensuredBy);     //CompanyCar
bool editCVan(QString model,
              QString licenseNumber,
              QString companyName,
              QString orgNr,
              int loadCapacity);     //CompanyVan
bool editBus(QString model,
             QString licenseNumber,
             QString companyName,
             QString orgNr,
             QString busType,
             QString busNr,
             int numberOfSeats);     //Bus

//Functions for sorting - Selection sort is used
void sortByModel();
void sortByLicenseNumber();
void sortByOwnerName();
void sortByOwnerSurname();
void sortByOwnerID();
void sortByEnsurance();
void sortByLoadCapacity();
void sortByMaxSpeed();
void sortBySVolume();
void sortByCompanyName();
void sortByOrgNr();
void sortByBusType();
void sortByBusNr();
void sortByNrOfSeats();

//Functions for getting number of vehicles
int nrOfPCars();
int nrOfPVans();
int nrOfMBikes();
int nrOfCCars();
int nrOfCVans();
int nrOfBuses();
int nrOfVeh();

//Functions for register filtering
//NOTE: Contains no temporary container class!
//Create temporary copy of main register before using.
void filterPCars();
void filterPVans();
void filterBikes();
void filterCCars();
void filterCVans();
void filterBuses();

//Other functions
bool removeVehicle(QString licenseNumber); // Removes vehicle by license number if finds it.
void expand(); // Expands the register if number of vehicles is larger than capacity.
int dupSearch(QString licenseNumber) const; //Search function overrider
int dupSearch(const Vehicle & other) const; //Searches for vehicle with matching license number.


//Operator overrider
TransportRegister& operator = (const TransportRegister & other);

private:
Vehicle** vehicles;
int capacity; //Register capacity
int nrOfVehicles; //Number of vehicles currently in register
};

#endif // TRANSPORTREGISTER_H
