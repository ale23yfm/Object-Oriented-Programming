#pragma once
#include <string>
#include "appliance.h"

class Refrigerator : public Appliance
{
protected:
	std::string electricityUsageClass;
	bool hasFreezer;

public:
	Refrigerator(std::string id, std::string electricityUsageClass, bool hasFreezer) :Appliance(id), electricityUsageClass(electricityUsageClass), hasFreezer(hasFreezer){};
	std::string toString() const;
	double consumedElectricity() const;
};