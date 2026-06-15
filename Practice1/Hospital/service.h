#pragma once
#include "repo.h"

class Service
{
private:
	Repo& repo;
public:
	Service(Repo& repo) : repo{ repo } {};
	void servAdd(const std::string& name, int age, bool infected, int room);
	void servDelete(const std::string& name);
	DynamicArray servUpdate(Hospital& infected, int minAge);
	DynamicArray servGetAll();
	Hospital servGetByName(const std::string& name);
	int servGetSize();
};