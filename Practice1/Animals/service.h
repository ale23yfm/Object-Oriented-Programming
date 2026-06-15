#pragma once
#include "repo.h"

class Service
{
private:
	Repo& repo;

public:
	Service(Repo& repo) : repo{ repo } {};
	void servAdd(const std::string& name, const std::string& species, int age, const std::string& color);
	void servDelete(const std::string& name, const std::string& species);
	DynamicArray servGetAllSorted();
	DynamicArray servSortByColor();
};