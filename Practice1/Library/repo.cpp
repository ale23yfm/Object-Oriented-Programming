#include "repo.h"
#include <stdexcept>

int Repo::repoGetSize() const
{
	return this->da.daGetSize();
}

int Repo::repoGetIndex(const Books& book)
{
	for (int i = 0; i < repoGetSize(); i++)
	{
		Books& current = da[i];
		if (book == current)
			return i;
	}
	return -1;
}

DynamicArray Repo::repoGetAll() const
{
	DynamicArray da;
	for (int i = 0; i < da.daGetSize(); i++)
		da.daAdd(da[i]);
	return da;
}

void Repo::repoAdd(const Books& book)
{
	if (repoGetIndex(book) != -1)
		throw std::runtime_error("Book already exists!");
	this->da.daAdd(book);
}

void Repo::repoDelete(const Books& book)
{
	if (repoGetIndex(book) == -1)
		throw std::runtime_error("Book does not exist");
	this->da.daDelete(repoGetIndex(book));
}
