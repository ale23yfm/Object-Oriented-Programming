#pragma once
#include "repo.h"

class Service
{
private:
	Repo& repo;

public:
	Service(Repo& repo) : repo(repo) {};
	std::vector<Bill*> getAllSorted();
	double UnpaidBills(std::string& name);
};