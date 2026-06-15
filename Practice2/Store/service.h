#pragma once
#include "repo.h"
#include <vector>

class Service
{
private:
	Repo& repo;
public:
	Service(Repo& repo) : repo(repo) {};
	void servAdd(Appliance* a);
	std::vector<Appliance*> servShowAll();
	std::vector<Appliance*> servShowIneff();
	void servWriteToFile(std::string filename, double value);
	
};
