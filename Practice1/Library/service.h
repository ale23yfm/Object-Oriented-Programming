#pragma once
#include "repo.h"

class Service
{
private:
	Repo& repo;

public:
	Service (Repo& repo) : repo{repo} {}
	DynamicArray servGetAllSorted();
	DynamicArray servGetClassic();
	void servAdd(const std::string &title, const std::string& author, int year, const std::string& genre);
	void servDelete(const std::string &title, const std::string& author);
};