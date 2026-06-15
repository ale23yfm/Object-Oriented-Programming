#pragma once
#include "vehicle.h"
#include <string>
#include <vector>

class Repo
{
private:
	std::vector<Vehicle* > vehicles;

public:
	void repoAdd(Vehicle* v);
	void repoDelete(std::string licensePlate);
	std::vector<Vehicle* > repoShow();
	int repoFindIndex(std::string licensePlate);
};