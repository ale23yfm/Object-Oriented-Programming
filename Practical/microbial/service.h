#pragma once
#include "repo.h"

class Service
{
private:
	Repo& repo;

public:
	Service(Repo& repo) :repo(repo) {};

	std::vector<Bacterium*> getBacterias() { return this->repo.getBacterias(); };
	std::vector<Bacterium*> getBacteriaBySpecies(std::string spec) { 
		std::vector<Bacterium*> res;
		for (auto i : this->getBacterias())
			if (i->getSpecies() == spec)
				res.push_back(i);
		return res; };
	std::vector<Biologist*> getBiologists() { return this->repo.getBiologists(); };
};