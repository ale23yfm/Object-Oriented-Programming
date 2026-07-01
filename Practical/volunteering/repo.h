#pragma once
#include "dep.h"
#include "vol.h"
#include <vector>
#include <fstream>
#include <sstream>

class Repo
{
private:
	std::vector<Volunteer*> volunteers;
	std::vector<Department*> departments;
	std::string volFile;
	std::string depFile;

	void loadDepartments();
	void loadVolunteers();


public:
	Repo() = default;
	Repo(std::string volFile, std::string depFile) :volFile(volFile), depFile(depFile){
		loadDepartments();
		loadVolunteers();
	};

	std::vector<Volunteer*> getVolunteers() { return this->volunteers; };
	std::vector<Department*> getDepartments() { return this->departments; };

	void assignVolunteer(std::string name, std::string d);
	void addVolunteer(Volunteer* v) { this->volunteers.push_back(v); };
	void saveVolunteers();
};