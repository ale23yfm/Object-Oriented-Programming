#include "service.h"
#include <fstream>

void Service::servAdd(Appliance* a)
{
	this->repo.repoAdd(a);
}

std::vector<Appliance*> Service::servShowAll()
{
	return this->repo.repoShowAll();
}

std::vector<Appliance*> Service::servShowIneff()
{
	std::vector<Appliance*> res, all = this->servShowAll();
	for (auto a : all)
		if (a->consumedElectricity() > 100)
			res.push_back(a);
	return res;
}

void Service::servWriteToFile(std::string filename, double value)
{
	std::ofstream fout(filename);
	std::vector<Appliance*> all = this->servShowAll();
	for (auto a : all)
		if (a->consumedElectricity() < value)
			fout << a->toString() << '\n';
	fout.close();
}
