#pragma once
#include "repo.h"

class Service
{
private:
	Repo& repo;

public:
	Service(Repo& repo) :repo(repo) {};
	void Add(County* c);
	std::vector<County*> getAll();
	std::vector<County*> servShowAllParliament();
	void writeToFile();
};