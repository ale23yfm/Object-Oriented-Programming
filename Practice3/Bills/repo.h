#pragma once
#include "domain.h"
#include <vector>

class Repo
{
private:
	std::vector<Bill*> bills;

public:
	Repo() = default;
	Repo(std::vector<Bill*> bills): bills(bills){};
	void loadFromFile();
	std::vector<Bill*> getAll();
	
};