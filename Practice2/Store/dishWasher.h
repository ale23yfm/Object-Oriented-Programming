#pragma once
#include <string>
#include "appliance.h"

class DishWasher : public Appliance
{
protected:
	double consumedElectricityForOneHour;

public:
	DishWasher(std::string id, double consumedElectricityForOneHour) :Appliance(id), consumedElectricityForOneHour(consumedElectricityForOneHour) {};
	std::string toString() const;
	double consumedElectricity() const;
};