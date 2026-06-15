#include "repo.h"
#include <stdexcept>

void Repo::repoAdd(Vehicle* v)
{
	this->vehicles.push_back(v);
}

void Repo::repoDelete(std::string licensePlate)
{
	int index = this->repoFindIndex(licensePlate);
	if (index == -1)
		throw std::runtime_error("The vehicle does not exist");
	this->vehicles.erase(this->vehicles.begin() + index);
}

std::vector<Vehicle* > Repo::repoShow()
{
	return this->vehicles;
}

int Repo::repoFindIndex(std::string licensePlate)
{
	std::vector<Vehicle* > all = this->repoShow();
	int i = 0;
	for (auto a : all)
	{
		if (licensePlate == a->getLicensePlate())
			return i;
		i++;
	}
	return -1;
}