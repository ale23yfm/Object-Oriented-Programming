#pragma once
#include "domain.h"
#include <vector>

class Repo
{
private:
	std::vector<Sport*> sports;

public:
	Repo() = default;
	Repo(std::vector<Sport*> sports) :sports(sports) {};
	std::vector<Sport*> getAll() { return this->sports; };
	void loadFromFile();
};
