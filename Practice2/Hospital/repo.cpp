#include "repo.h"
#include <fstream>

void Repo::repoAdd(HospitalDepartment* d)
{
	this->departments.push_back(d);
}

std::vector<HospitalDepartment*> Repo::repoShowAll()
{
	return this->departments;
}

std::vector<HospitalDepartment*> Repo::repoShowAllEfficient()
{
	std::vector<HospitalDepartment*> res;
	std::vector<HospitalDepartment*> all = this->repoShowAll();
	for (auto d : all)
		if (d->isEfficient())
			res.push_back(d);
	return res;
}

Repo::~Repo()
{
	for (auto d : this->departments)
		delete d;
}
