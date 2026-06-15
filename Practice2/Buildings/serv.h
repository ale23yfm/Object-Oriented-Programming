#pragma once
#include "repo.h"

class Serv
{
private:
	Repo& repo;
public:
	Serv(Repo& repo) : repo(repo) {};
	void servAdd(Building* b);
	int servFindIndex(Building* b);
	std::vector<Building*> servGetAll();
	std::vector<Building*> servGetAllSorted();
	void writeToFileDemolished(std::string filename);
	void writeToFileRestore(std::string filename);
};