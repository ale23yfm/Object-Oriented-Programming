#include "UserRepo.h"
#include <stdexcept>

void RepoUser::repoAddUser(const Event& e)
{
	if (repoFindUser(e) != -1)
		throw std::runtime_error("Event already exists!");
	this->da.daAdd(e);
}

void RepoUser::repoRemoveUser(int index)
{
	this->da.daRemove(index);
}

Event& RepoUser::repoGetUser(int index)
{
	return this->da[index];
}

int RepoUser::repoFindUser(const Event& e)
{
	for (int i = 0; i < this->repoGetSizeUser(); i++)
	{
		Event& current = da[i];
		if (e == current)
			return i;
	}
	return -1;
}

int RepoUser::repoGetSizeUser() const
{
	return this->da.daGetSize();
}

