/* Base class declaration */

#ifndef VEHICLE_H
#define VEHICLE_H
#include <QObject>
#include <string>

class Vehicle : public QObject
{

Q_OBJECT
public:
Vehicle(QString model,
        QString licenseNumber);
Vehicle(QString licenseNumber);
virtual ~Vehicle();

//Set-functions & get-functions
void setModel(QString model);
void setLicenseNumber(QString licenseNumber);
QString getModel() const;
QString getLicenseNumber() const;

//Output functions
virtual QString toString() const; // Used for information display
virtual QString toStringSimple() const; // Used for database exports: only values are printed out

//Operator overrider
bool operator== (Vehicle & other) const;
private:
QString model;
QString licenseNumber;
};

#endif
