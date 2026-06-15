#pragma once
#include "repo.h"

class Service
{
private:
	Repo& repo;

public:
	Service(Repo& repo) : repo(repo) {};
	std::vector<Cars*> getAll();
	std::vector<Cars*> getByManufacturer(std::string man);
	int getNumberByManufacturer(std::string man);
};