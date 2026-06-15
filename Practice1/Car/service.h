#pragma once
#include "repo.h"

class Service
{
private:
	Repo& repo;

public:
	Service(Repo& repo): repo{repo} {}
	void servAdd(const std::string& name, const std::string& model, int year, const std::string& color);
	void servDelete(const std::string& model, int year);
	int servGetSize() const;
	Cars servFindByIndex(int index);
	DynamicArray servGetAllSorted();
	DynamicArray servGetVintage();
};