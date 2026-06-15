#include "car.h"

double Car::maintenanceCost() const
{
	if (this->hasAC == true)
		return 500 * this->numberOfSeats + 300;
	else return 500 * this->numberOfSeats;
}

std::string Car::toString() const
{
	std::string res;
	res += "car | licensePlate: " + this->licensePlate + " | yearOfManufacture" + std::to_string(this->yearOfManufacture) + " | numberOfSeats: " + std::to_string(this->numberOfSeats) + " | hasAC: ";
	if (this->hasAC == true) 
		res += "YES";
	else res += "NO";
	return res;
}
