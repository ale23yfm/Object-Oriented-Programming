#include "serv.h"
#include <fstream>
#include <algorithm>

void Serv::servAdd(Building* b)
{
	if(servFindIndex(b) != -1)
		throw std::runtime_error("The building already exists");
	this->repo.repoAdd(b);
}

int Serv::servFindIndex(Building* b)
{
	return this->repo.repoGetIndex(b);
}

std::vector<Building*> Serv::servGetAll()
{
	return this->repo.repoGetAll();
}

std::vector<Building*> Serv::servGetAllSorted()
{
	std::vector<Building*> all = this->servGetAll();
	std::sort(all.begin(), all.end(), [](Building* a, Building* b) {return a->getConstructionYear() < b->getConstructionYear(); });
	return all;
}

void Serv::writeToFileDemolished(std::string filename)
{
	std::ofstream fout(filename);
	std::vector<Building*> all = this->servGetAll();
	for (auto b : all)
		if (b->canBeDemolished() == true)
			fout << b->toString() << '\n';
	fout.close();
}

void Serv::writeToFileRestore(std::string filename)
{
	std::ofstream fout(filename);
	std::vector<Building*> all = this->servGetAll();
	for (auto b : all)
		if (b->mustBeRestored() == true)
			fout << b->toString() << '\n';
	fout.close();
}
