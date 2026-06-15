#pragma once
#include "building.h"
#include <vector>

class Repo
{
private:
	std::vector<Building*> buildings;
public:
	Repo() = default;
	Repo(std::vector<Building*> buildings) :buildings(buildings) {};
	void repoAdd(Building* b);
	std::vector<Building*> repoGetAll();
	int repoGetIndex(Building* b);
	~Repo();
};