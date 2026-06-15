#include "adminRepo.h"
#include <stdexcept>
#include <fstream>
#include <iostream>

void RepoAdmin::loadFromFile()
{
	std::ifstream fin(this->filename);
	if (!fin.is_open()) return;
	Event e;
	while (fin >> e)
		events.push_back(e);
	fin.close();
}

void RepoAdmin::writeToFile()
{
	std::ofstream fout(this->filename);
	if (!fout.is_open()) return;
	for (const auto& e : events)
		fout << e;
	fout.close();
}

RepoAdmin::RepoAdmin(const std::string& filename) : filename(filename)
{
	loadFromFile();
}

void RepoAdmin::repoAddAdmin(const Event& e)
{
	if (repoFindAdmin(e) != -1)
		throw RepositoryException("Event already exists!");
	this->events.push_back(e);
	writeToFile();
}

void RepoAdmin::repoRemoveAdmin(int index)
{
	if (index < 0 || index > this->events.size())
		throw RepositoryException("Event does not exist");
	this->events.erase(events.begin() + index); 
	writeToFile();
}

void RepoAdmin::repoUpdateAdmin(int index, const Event& newEvent)
{
	if (index < 0 || index > this->events.size())
		throw RepositoryException("Event does not exist");
	this->events.at(index) = newEvent;
	writeToFile();
}

Event& RepoAdmin::repoGetAdmin(int index)
{
	return this->events.at(index);
}

int RepoAdmin::repoFindAdmin(const Event& e)
{
	auto it = std::find(events.begin(), events.end(), e);
	if (it == events.end())
		return -1;
	return it - events.begin();
}

const std::vector<Event>& RepoAdmin::repoGetAllAdmin() const
{
	return events;
}

int RepoAdmin::repoGetSizeAdmin() const
{
	return this->events.size(); 
}

