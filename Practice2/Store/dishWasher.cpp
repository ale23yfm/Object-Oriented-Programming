#include "dishWasher.h"

std::string DishWasher::toString() const
{
	std::string res;
	res += "DishWasher | id: " + this->id + " | consumedElectricity: " + std::to_string(this->consumedElectricity()) + " KW | consumedElectricity: " + std::to_string(this->consumedElectricity()) + " KW";
	return res;
}

double DishWasher::consumedElectricity() const
{
	return this->consumedElectricityForOneHour * 20;
}
