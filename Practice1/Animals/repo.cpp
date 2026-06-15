#include "repo.h"
#include <stdexcept>

int Repo::repoGetSize() const
{
	return this->da.daGetSize();
}

void Repo::repoAdd(const Animals& animal)
{
	if (repoFindIndex(animal) != -1)
		throw std::runtime_error("Animal already exists");
	this->da.daAdd(animal);
}

void Repo::repoDelete(const Animals& animal)
{
	if (repoFindIndex(animal) == -1)
		throw std::runtime_error("Animal does not exist");
	this->da.daDelete(repoFindIndex(animal));
}

int Repo::repoFindIndex(const Animals& animal)
{
	for (int i = 0; i < repoGetSize(); i++)
	{
		Animals& current = da[i];
		if (animal == current)
			return i;
	}
	return -1;
}

DynamicArray Repo::repoGetAll() const
{
	DynamicArray copy;
	for (int i = 0; i < repoGetSize(); i++)
		copy.daAdd(da[i]);
	return copy;
}
