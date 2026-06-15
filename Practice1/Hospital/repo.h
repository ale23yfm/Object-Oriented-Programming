#pragma once
#include "dynamicArray.h"

class Repo
{
private:
	DynamicArray da;

public:
	int repoGetSize();
	DynamicArray repoGetAll();
	int repoGetIndex(const Hospital& patient);
	void repoAdd(const Hospital& patient);
	void repoDelete(const Hospital& patient);
	DynamicArray& repoGetArray() { return da; }
	const DynamicArray& repoGetArray() const { return da; }
};