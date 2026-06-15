#pragma once
#include "repo.h"

class Service
{
private:
	Repo& repo;
public:
	Service(Repo& repo) : repo(repo) {};
	void servAdd(HospitalDepartment* d);
	std::vector<HospitalDepartment*> servGetAll();
	std::vector<HospitalDepartment*> servGetAllEfficient();
	void writeToFile(std::string filename);
};