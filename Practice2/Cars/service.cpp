#include "service.h"
#include <fstream>

void Service::servAdd(Vehicle* v)
{
	this->repo.repoAdd(v);
}

void Service::servRemove(std::string licensePlate)
{
	this->repo.repoDelete(licensePlate);
}

std::vector<Vehicle*> Service::servShow()
{
	return this->repo.repoShow();
}

std::vector<Vehicle*> Service::servShowExpensive()
{
	std::vector<Vehicle*> res, all = this->servShow();
	for (auto a : all)
		if (a->maintenanceCost() > 3000)
			res.push_back(a);
	return res;
}

void Service::servSaveToFile(std::string filename, int year1, int year2)
{
	std::ofstream fout(filename);
	std::vector<Vehicle*> all = this->servShow();
	for (auto a : all)
		if (a->getYearOfManufacture() > year1 && a->getYearOfManufacture() < year2)
			fout << a->toString() << '\n';
	fout.close();
}