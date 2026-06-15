#include "repo.h"
#include <stdexcept>

int Repo::repoGetSize()
{
	return this->da.daGetSize();
}

DynamicArray Repo::repoGetAll()
{
	DynamicArray copy;
	for (int i = 0; i < repoGetSize(); i++)
		copy.daAdd(da[i]);
	return copy;
}

int Repo::repoGetIndex(const Hospital& patient)
{
	for (int i = 0; i < repoGetSize(); i++)
	{
		Hospital& current = da[i];
		if (current == patient)
			return i;
	}
	return -1;
}

void Repo::repoAdd(const Hospital& patient)
{
	if (repoGetIndex(patient) != -1)
		throw std::runtime_error("The patient already exists");
	this->da.daAdd(patient);
}

void Repo::repoDelete(const Hospital& patient)
{
	if (repoGetIndex(patient) == -1)
		throw std::runtime_error("The patient does not exist");
	this->da.daDelete(repoGetIndex(patient));
}