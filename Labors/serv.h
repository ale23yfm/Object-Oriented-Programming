#pragma once
#include "repo.h"

class Serv
{
private:
	Repo& repo;

public:
	Serv(Repo& repo) :repo(repo) {};
	std::vector<Labor*> getAll();
	std::vector<Labor*> getAllbyWage(int w);
	std::vector<Labor*> getAllFilter(int start, std::string coun);
	int getTotal(int start, std::string coun);
};