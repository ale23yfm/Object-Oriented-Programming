#include "adminRepo.h"
#include <stdexcept>

void RepoAdmin::repoAddAdmin(const Event& e)
{
	if (repoFindAdmin(e) != -1)
		throw std::runtime_error("Event already exists!");
	this->da.daAdd(e);
}

void RepoAdmin::repoRemoveAdmin(int index)
{
	this->da.daRemove(index);
}

void RepoAdmin::repoUpdateAdmin(int index, const Event& newEvent)
{
	this->da[index] = newEvent;
}

Event& RepoAdmin::repoGetAdmin(int index)
{
	return this->da[index];
}

int RepoAdmin::repoFindAdmin(const Event& e)
{
	for (int i = 0; i < this->repoGetSizeAdmin(); i++)
	{
		Event& current = da[i];
		if (e == current)
			return i;
	}
	return -1;
}

int RepoAdmin::repoGetSizeAdmin() const
{
	return this->da.daGetSize(); 
}

