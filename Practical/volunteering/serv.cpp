#include "serv.h"
#include <algorithm>
#include <QMessageBox>

std::vector<Volunteer*> Serv::getAssignedVolunteers(std::string dep)
{ 
	std::vector<Volunteer*> res;
	for (auto i : this->repo.getVolunteers())
		if (i->getDepart() == dep)
			res.push_back(i);
	sort(res.begin(), res.end(), [](Volunteer* a, Volunteer* b)
		{
			return a->getName() < b->getName();
		});

	return res; 
}

std::vector<Volunteer*> Serv::getUnassignedVolunteers()
{
	std::vector<Volunteer*> res;
	for (auto i : this->repo.getVolunteers())
		if (i->getDepart() == "")
			res.push_back(i);

	sort(res.begin(), res.end(), [](Volunteer* a, Volunteer* b)
		{
			return a->getName() < b->getName();
		});
	return res;
}

std::vector<Department*> Serv::getDepartmentsSorted()
{
	std::vector<Department*> res = this->getDepartments();

	sort(res.begin(), res.end(), [this](Department*a, Department*b)
		{
			return getNrVolunteers(a->getName()) < getNrVolunteers(b->getName());
		});

	return res;
}

int Serv::getNrVolunteers(std::string dep)
{
	int total = 0;

	for (auto i : this->getAssignedVolunteers(dep))
			total += 1;
	return total;
}

void Serv::addVolunteer(std::string name, std::string email, std::string interests)
{
	for (auto i : this->repo.getVolunteers())
		if (i->getEmail() == email)
			throw std::runtime_error("Volunteer already exists");
	this->repo.addVolunteer(new Volunteer(name, email, interests, ""));
	notify();
}

void Serv::assignVolunteers(std::string name, std::string d)
{
	if (name.empty())
		throw std::runtime_error("Name cannot be empty");
	for (auto i : this->getUnassignedVolunteers())
		if (i->getName() == name)
		{
			this->repo.assignVolunteer(name, d);
			notify();
			return;
		}
}