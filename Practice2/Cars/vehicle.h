#pragma once
#include <string>

class Vehicle
{
protected:
	std::string licensePlate;
	int yearOfManufacture;

public:
	Vehicle(std::string licensePlate, int yearOfManufacture) : licensePlate(licensePlate), yearOfManufacture(yearOfManufacture) {};
	virtual double maintenanceCost() const = 0;
	virtual std::string toString() const = 0;
	virtual int getYearOfManufacture() const = 0;
	virtual std::string getLicensePlate() const = 0;
	virtual ~Vehicle() = default;
};