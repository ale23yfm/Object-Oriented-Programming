#include "repo.h"

void Repo::repoAdd(MedicalAnalysis* a)
{
	this->analysis.push_back(a);
}

void Repo::repoRemove(MedicalAnalysis* a)
{
	std::vector<MedicalAnalysis*> res, all = this->repoShowAll();
	for (auto b : all)
		if (b->getData() != a->getData())
			res.push_back(b);
	this->analysis.empty();
	this->analysis = res;
}

std::vector<MedicalAnalysis*> Repo::repoShowAll()
{
	return this->analysis;
}
