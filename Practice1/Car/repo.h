#pragma once
#include "dynamicArray.h"

class Repo
{
private:
	DynamicArray da;
public:
	int repoGetSize() const;
	int repoFindIndex(const Cars& car);
	Cars repoFindByIndex(int index);
	void repoAdd(const Cars& car);
	void repoDelete(const Cars& car);
	DynamicArray repoGetAll() const;
};