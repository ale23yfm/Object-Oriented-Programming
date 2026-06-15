#include "repo.h"

void Repo::repoAdd(Building* b)
{
	this->buildings.push_back(b);
}

std::vector<Building*> Repo::repoGetAll()
{
	return this->buildings;
}

int Repo::repoGetIndex(Building* b)
{
	int i = 0;
	for (auto r : this->repoGetAll())
	{
		if (r->getAddress() == b->getAddress() && r->getConstructionYear() == b->getConstructionYear())
			return i;
		i++;
	}
	return -1;
}

Repo::~Repo()
{
	for (auto b : this->buildings)
		delete b;
}
