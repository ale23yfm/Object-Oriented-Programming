#pragma once
#include "repo.h"
#include <string>
#include <map>
class Service
{
private:
	Repo& repo;
public:
	Service(Repo &repo) : repo {repo} {}
	DynamicArray servGetAll();
	std::map<std::string, int> servGetAllBySenzor(const std::string& senzor);
	void servAdd(const std::string &location, const std::string& name, const std::vector<std::string>& senzors);
};