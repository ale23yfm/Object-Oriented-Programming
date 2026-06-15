#include "truck.h"

double Truck::maintenanceCost() const
{
	if (this->cargoType == "perishable")
		return 200 * this->loadCapacity + 1000;
	else return 200 * this->loadCapacity;
}

std::string Truck::toString() const
{
	std::string res;
	res += "truck | licensePlate: " + this->licensePlate + " | yearOfManufacture" + std::to_string(this->yearOfManufacture) + " | loadCapacity: " + std::to_string(this->loadCapacity) + " | cargoType: " + this->cargoType;
	return res;
}
