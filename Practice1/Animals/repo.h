#pragma once
#include "dynamicArray.h"

class Repo
{
private:
	DynamicArray da;

public:
	int repoGetSize() const;
	void repoAdd(const Animals& animal);
	void repoDelete(const Animals& animal);
	int repoFindIndex(const Animals& animal);
	DynamicArray repoGetAll() const;
};