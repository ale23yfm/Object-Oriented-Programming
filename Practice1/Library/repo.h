#pragma once
#include "dynamicArray.h"

class Repo
{
private:
	DynamicArray da;

public:
	int repoGetSize() const;
	int repoGetIndex(const Books& book);
	DynamicArray repoGetAll() const;
	void repoAdd(const Books& book);
	void repoDelete(const Books& book);
};