#pragma once
#include "county.h"
#include <vector>

class Repo
{
private:
	std::vector<County*> counties;
public:
	Repo() = default;
	Repo(std::vector<County*> counties) :counties(counties) {};
	void repoAdd(County* c);
	std::vector<County*> repoShowAll();
};