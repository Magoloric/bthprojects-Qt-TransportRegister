#include "motorbike.h"

Motorbike::Motorbike(QString model,
                     QString licenseNumber,
                     QString ownerName,
                     QString ownerSurname,
                     QString ownerID,
                     int maxSpeed,
                     int sVolume) :
    PrivateVehicle(model,
                   licenseNumber,
                   ownerName,
                   ownerSurname,
                   ownerID)
{
    this->maxSpeed = maxSpeed;
    this->sVolume = sVolume;
}

Motorbike::~Motorbike()
{

}

void Motorbike::setMaxSpeed(int maxSpeed)
{
    this->maxSpeed = maxSpeed;
}
void Motorbike::setSVolume(int sVolume)
{
    this->sVolume = sVolume;
}
int Motorbike::getMaxSpeed()
{
    return this->maxSpeed;
}

int Motorbike::getSVolume()
{
    return this->sVolume;
}

QString Motorbike::toString() const
{
    QString output;

    output += PrivateVehicle::toString()
              + QString::fromStdString("Maximal Speed: ") + QString::fromStdString(std::to_string(maxSpeed)) + QString::fromStdString("\n")
              + QString::fromStdString("Swept Volume: ") + QString::fromStdString(std::to_string(sVolume)) + QString::fromStdString("\n");

    return output;
}
QString Motorbike::toStringSimple() const
{
    QString output;

    output += PrivateVehicle::toStringSimple()
              + QString::fromStdString(std::to_string(maxSpeed)) + QString::fromStdString("|")
              + QString::fromStdString(std::to_string(sVolume)) + QString::fromStdString("| \n");

    return output;
}
