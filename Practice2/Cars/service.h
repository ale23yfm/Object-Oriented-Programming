#pragma once
#include "repo.h"

class Service
{
private:
	Repo& repo;

public:
	Service(Repo& repo) :repo(repo){};
	void servAdd(Vehicle* v);
	void servRemove(std::string licensePlate);
	std::vector<Vehicle*> servShow();
	std::vector<Vehicle*> servShowExpensive();
	void servSaveToFile(std::string filename, int year1, int year2);
};