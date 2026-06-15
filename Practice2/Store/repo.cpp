#include "repo.h"

void Repo::repoAdd(Appliance* a)
{
	this->appl.push_back(a);
}

std::vector<Appliance*> Repo::repoShowAll()
{
	return this->appl;
}
