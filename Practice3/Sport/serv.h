#pragma once
#include "repo.h"

class Service
{
private:
	Repo& repo;

public:
	Service(Repo& repo) :repo(repo) {};
	std::vector<Sport*> getAll();
	std::vector<Sport*> filterByIntensity(int intLevel);
	std::vector<Sport*> filterByDesc(std::string desc, int s);
	int totalHours(std::string desc, int s);
};