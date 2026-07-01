#pragma once
#include "repo.h"
#include "observer.h"

class Serv
{
private:
	Repo& repo;
	std::vector<Observer*>observers;

public:
	Serv(Repo& repo) :repo(repo){};

	std::vector<Volunteer*> getAssignedVolunteers(std::string dep);
	std::vector<Volunteer*> getUnassignedVolunteers();
	std::vector<Department*> getDepartments() { return this->repo.getDepartments(); };
	std::vector<Department*> getDepartmentsSorted();

	int getNrVolunteers(std::string dep);

	void addVolunteer(std::string name, std::string email, std::string interests);

	void assignVolunteers(std::string name, std::string d);

	void addObserver(Observer* o) { this->observers.push_back(o); };
	void notify()
	{
		for (auto o : observers)
			o->update();
		this->repo.saveVolunteers();
	}
};