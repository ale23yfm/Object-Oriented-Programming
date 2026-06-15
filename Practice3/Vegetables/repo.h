#pragma once
#include "domain.h"

class Repo
{
private:
	std::vector<Vegetables*> vegetables;

public:
	Repo() = default;
	Repo(std::vector<Vegetables*> vegerables) :vegetables(vegerables) {};
	std::vector<Vegetables*> getAll() { return this->vegetables; };
	void loadFromFile();
};
