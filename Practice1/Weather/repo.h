#pragma once
#include "dynamicArray.h"

class Repo
{
private:
	DynamicArray da;

public:
	int repoGetSize();
	int repoGetIndex(const Weather& w);
	DynamicArray repoGetAll();
	void repoAdd(Weather& w);
};