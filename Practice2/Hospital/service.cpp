#include "service.h"
#include "surgery.h"
#include <fstream>

void Service::servAdd(HospitalDepartment* d)
{
	this->repo.repoAdd(d);
}

std::vector<HospitalDepartment*> Service::servGetAll()
{
	return this->repo.repoShowAll();
}

std::vector<HospitalDepartment*> Service::servGetAllEfficient()
{
	return this->repo.repoShowAllEfficient();
}

void Service::writeToFile(std::string filename)
{
	std::ofstream fout(filename);
	std::vector<HospitalDepartment*> all = this->servGetAll();
	for (auto d : all)
		fout << d->toString() << '\n';
	fout.close();
}
