#include "service.h"
#include <fstream>

void Service::Add(County* c)
{
	this->repo.repoAdd(c);
}

std::vector<County*> Service::getAll()
{
	return this->repo.repoShowAll();
}

std::vector<County*> Service::servShowAllParliament()
{
	std::vector<County*> res, all = this->getAll();
	for (auto a : all)
		if (a->eligible() == true)
			res.push_back(a);
	return res;
}

void Service::writeToFile()
{
	std::ofstream fout("election.txt");
	std::vector<County*> all = this->getAll();
	for (auto a : all)
		fout << a->toString() << '\n';
	fout.close();
}

