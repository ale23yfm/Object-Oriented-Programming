#pragma once
#include "dynamicArray.h"

class Repo
{
private:
	DynamicArray da;

public:
	int repoGetSize();
	DynamicArray repoGetAll();
	int repoGetIndex(Recipe& r);

	/// <summary>
	/// The function adds a new recipe or trows an exception if the recipe already exists
	/// </summary>
	/// <param name="r">The recipe to be added</param>
	void repoAdd(Recipe& r);

	/// <summary>
	/// The functions gives an array of the recipes having a given name
	/// </summary>
	/// <param name="r">the recipe that matches only the name</param>
	/// <returns>the new dynamic array with the corresponding recipes</returns>
	DynamicArray& repoGetByName(Recipe& r);
};