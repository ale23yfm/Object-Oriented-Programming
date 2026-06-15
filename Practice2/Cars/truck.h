#pragma once
#include "vehicle.h"
#include <string>

class Truck : public Vehicle
{
protected:
	double loadCapacity;
	std::string cargoType;
public:
	Truck(std::string licensePlate, int yearOfManufacture, double loadCapacity, std::string cargoType) : Vehicle(licensePlate, yearOfManufacture), loadCapacity(loadCapacity), cargoType(cargoType) {};
	double maintenanceCost() const;
	int getYearOfManufacture() const { return this->yearOfManufacture; };
	std::string getLicensePlate() const { return this->licensePlate; }
	std::string toString() const;
}; 
