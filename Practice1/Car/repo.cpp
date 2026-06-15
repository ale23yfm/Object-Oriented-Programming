#include "repo.h"
#include <stdexcept>

int Repo::repoGetSize() const
{
	return this->da.daGetSize();
}

int Repo::repoFindIndex(const Cars& car)
{
	for (int i = 0; i < this->repoGetSize(); i++)
	{
		Cars& current = da[i];
		if (current == car)
			return i;
	}
	return -1;
}

Cars Repo::repoFindByIndex(int index)
{
	return this->da[index];
}

void Repo::repoAdd(const Cars& car)
{
	if (repoFindIndex(car) != -1)
		throw std::runtime_error("This car already exists!");
	this->da.daAdd(car);
}

void Repo::repoDelete(const Cars& car)
{
	int index = repoFindIndex(car);
	if (index == -1)
		throw std::runtime_error("This car does not exist!");
	this->da.daDelete(index);
}

DynamicArray Repo::repoGetAll() const
{
	return this->da;
}
