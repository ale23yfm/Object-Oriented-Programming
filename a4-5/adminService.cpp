#include "adminService.h"
#include <stdexcept>

ServiceAdmin::ServiceAdmin(RepoAdmin& repo): repo{repo}
{
}

void ServiceAdmin::servAddAdmin(const std::string& title, const std::string& description, int day, int month, int year, int hour, int minute, int nrPeople, const std::string& link)
{
	Event e{ title, description, day, month, year, hour, minute, nrPeople, link };
	this->repo.repoAddAdmin(e);
}

void ServiceAdmin::servRemoveAdmin(const std::string& title, int day, int month, int year, int hour, int minute)
{
	int index = servFindEventAdmin(title, day, month, year, hour, minute);
	if (index == -1)
		throw std::runtime_error("Event not found!");
	repo.repoRemoveAdmin(index);
}

void ServiceAdmin::servUpdateAdmin(const std::string& title, int day, int month, int year, int hour, int minute, const Event &newEvent)
{
	int index = servFindEventAdmin(title, day, month, year, hour, minute);
	if (index == -1)
		throw std::runtime_error("Event not found!");
	repo.repoUpdateAdmin(index, newEvent);
}

int ServiceAdmin::servGetSizeAdmin() const
{
	return repo.repoGetSizeAdmin();
}

Event& ServiceAdmin::servGetEventByIndexAdmin(int index)
{
	return repo.repoGetAdmin(index);
}

int ServiceAdmin::servFindEventAdmin(const std::string& title, int day, int month, int year, int hour, int minute)
{
	Event current{ title, "", day, month, year, hour, minute, 0, "" };
	return repo.repoFindAdmin(current);
}

int ServiceAdmin::servFindAdmin(const Event& e)
{
	return repo.repoFindAdmin(e);
}

DynamicArray<Event> ServiceAdmin::filterByDuration(int time)
{
	DynamicArray<Event> filtered;
	for (int i = 0; i < this->repo.repoGetSizeAdmin(); i++)
	{
		if (repo.repoGetAdmin(i) < time)
			filtered.daAdd(repo.repoGetAdmin(i));
	}
	return filtered;
}