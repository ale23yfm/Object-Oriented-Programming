#include "repo.h"

void Repo::repoAdd(County* c)
{
	this->counties.push_back(c);
}

std::vector<County*> Repo::repoShowAll()
{
	return this->counties;
}
