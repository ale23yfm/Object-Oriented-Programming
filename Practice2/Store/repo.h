#pragma once
#include "appliance.h"
#include <vector>

class Repo
{
private:
	std::vector<Appliance*> appl;

public:
	void repoAdd(Appliance* a);
	std::vector<Appliance*> repoShowAll();
};