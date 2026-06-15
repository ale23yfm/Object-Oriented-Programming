#pragma once
#include "vehicle.h"
#include <string>

class Car: public Vehicle
{
protected:
	int numberOfSeats; 
	bool hasAC;
public:
	Car(std::string licensePlate, int yearOfManufacture, int numberOfSeats, bool hasAC) : Vehicle(licensePlate, yearOfManufacture), numberOfSeats(numberOfSeats), hasAC(hasAC){};
	double maintenanceCost() const;
	int getYearOfManufacture() const { return this->yearOfManufacture; }
	std::string getLicensePlate() const { return this->licensePlate; }
	std::string toString() const;
};