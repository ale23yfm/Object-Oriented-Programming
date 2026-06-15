#include "UserRepo.h"
#include <stdexcept>
#include <fstream>

void RepoUser::loadFromFile()
{
	std::ifstream fin(this->filename);
	if (!fin.is_open()) return;
	Event e;
	while (fin >> e)
		events.push_back(e);
	fin.close();
}

void RepoUser::writeToFile()
{
	std::ofstream fout(this->filename);
	if (!fout.is_open()) return;
	for (const auto& e : events)
		fout << e;
	fout.close();
}

RepoUser::RepoUser(const std::string& filename) : filename(filename)
{
	loadFromFile();
}

void RepoUser::repoAddUser(const Event& e)
{
	if (repoFindUser(e) != -1)
		throw RepositoryException("Event already exists!");
	this->events.push_back(e); 
	writeToFile();
}

void RepoUser::repoRemoveUser(int index)
{
	if (index < 0 || index > this->events.size())
		throw RepositoryException("Event does not exist");
	this->events.erase(events.begin() + index);
	writeToFile();
}

Event& RepoUser::repoGetUser(int index)
{
	return this->events.at(index);
}

int RepoUser::repoFindUser(const Event& e)
{
	auto it = std::find(events.begin(), events.end(), e);
	if (it == events.end())
			return -1;
	return it - events.begin();
}

const std::vector<Event>& RepoUser::repoGetAllUser() const
{
	return events;
}

int RepoUser::repoGetSizeUser() const
{
	return this->events.size();
}

