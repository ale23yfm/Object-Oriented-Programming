#include "repo.h"
#include <stdexcept>

int Repo::repoGetSize()
{
	return this->da.daGetSize();
}

int Repo::repoGetIndex(const Weather& w)
{
	for (int i = 0; i < repoGetSize(); i++)
	{
		Weather& current = da[i];
		if (w == current)
			return i;
	}
	return -1;
}

DynamicArray Repo::repoGetAll()
{
	DynamicArray copy;
	for (int i = 0; i < repoGetSize(); i++)
		copy.daAdd(da[i]);
	return copy;
}

void Repo::repoAdd(Weather& w)
{
	if (repoGetIndex(w) != -1)
		throw std::runtime_error("The station already exists!");
	this->da.daAdd(w);
}
