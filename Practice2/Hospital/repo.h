#pragma once
#include "hospital.h"
#include <vector>

class Repo
{
private:
	std::vector<HospitalDepartment*> departments;

public:
	Repo() = default;
	Repo(const std::vector<HospitalDepartment*> departments) :departments(departments) {};
	void repoAdd(HospitalDepartment* d);
	std::vector<HospitalDepartment*> repoShowAll();
	std::vector<HospitalDepartment*> repoShowAllEfficient();
	~Repo();
};