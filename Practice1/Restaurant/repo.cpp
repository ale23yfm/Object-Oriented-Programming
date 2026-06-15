#include "repo.h"
#include <stdexcept>

int Repo::repoGetSize()
{
	return this->da.daGetSize();
}

DynamicArray Repo::repoGetAll()
{
	DynamicArray copy;
	for (int i = 0; i < da.daGetSize(); i++)
	{
		Recipe& r = da[i];
		copy.daAdd(r);
	}
	return copy;
}

int Repo::repoGetIndex(Recipe& r)
{
	for (int i = 0; i < repoGetSize(); i++)
	{
		Recipe& current = da[i];
		if (current == r)
			return i;
	}
	return -1;
}

void Repo::repoAdd(Recipe& r)
{
	if (repoGetIndex(r) != -1)
		throw std::runtime_error("The recipe already exists");
	this->da.daAdd(r);
}

DynamicArray& Repo::repoGetByName(Recipe& r)
{
	int index = repoGetIndex(r);
	DynamicArray copy;
	for (int i = 0; i< da.daGetSize(); i++)
 {
		Recipe& current = da[i];
 if (r.getName() == current.getName())
 copy.daAdd(current);
 }

	return copy;
}
