#pragma once
#include "repo.h"

class Service
{
private:
	Repo& repo;

public:
	Service(Repo& repo) :repo(repo){};
	std::vector<std::string> getAllOnce();
	std::vector<Shop*> getFiltered(const std::string& cat);
	std::vector<Shop*> getFilteredByMin(const int mini);
	int getFilteredQuantity(const std::string& cat);
};