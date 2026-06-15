#pragma once
#include "domain.h"
#include <vector>

class Repo
{
private:
	std::vector<Labor*> labors;

public:
	Repo() = default;
	Repo(std::vector<Labor*> labors) :labors(labors) {};
	std::vector<Labor*> getAll();
	void loadFromFile();
};