#pragma once
#include "repo.h"

class Service
{
private:
	Repo& repo;
public:
	Service(Repo& repo) :repo(repo) {};
	std::vector<Vegetables*> getAll();
	std::vector<std::string> getUniqueFamilies();

	std::vector<Vegetables*> getVegByFamily(std::string fam);

};