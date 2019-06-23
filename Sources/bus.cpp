#include "bus.h"

Bus::Bus(QString model,
         QString licenseNumber,
         QString companyName,
         QString orgNr,
         QString busType,
         QString busNr,
         int numberOfSeats) :
    CompanyVehicle(model,
                   licenseNumber,
                   companyName,
                   orgNr)
{
    this->busType = busType;
    this->busNr = busNr;
    this->numberOfSeats = numberOfSeats;
}

Bus::~Bus()
{

}

void Bus::setBusType(QString busType)
{
    this->busType = busType;
}

void Bus::setBusNr(QString busNr)
{
    this->busNr = busNr;
}

void Bus::setNrOfSeats(int numberOfSeats)
{
    this->numberOfSeats = numberOfSeats;
}

QString Bus::getBusType()
{
    return this->busType;
}

QString Bus::getBusNr()
{
    return this->busNr;
}

int Bus::getNrOfSeats()
{
    return this->numberOfSeats;
}

QString Bus::toString() const
{
    QString output;

    output += CompanyVehicle::toString()
              + QString::fromStdString("Bus type: ") + busType + QString::fromStdString("\n")
              + QString::fromStdString("Bus Insider Number: ") + busNr + "\n"
              + QString::fromStdString("Number of seats: ") + QString::fromStdString(std::to_string(numberOfSeats)) + QString::fromStdString("\n");

    return output;
}
QString Bus::toStringSimple() const
{
    QString output;

    output += CompanyVehicle::toStringSimple()
              + busType + "|"
              + busNr + "|"
              + QString::fromStdString(std::to_string(numberOfSeats)) + QString::fromStdString("| \n");

    return output;
}
