#pragma once
#include "repo.h"

class Service
{
private:
	Repo& repo;

public:
	Service (Repo& repo) : repo{repo}{}
	
	/// <summary>
	/// The function adds a new recipe by repo
	/// </summary>
	/// <param name="menu">the menu of the recipe</param>
	/// <param name="name">the name of the recipe</param>
	/// <param name="ingredients">the list of recipe's ingredients</param>
	void servAdd(const std::string& menu, const std::string& name, const std::vector<std::string>& ingredients);
	int servGetSize();
	DynamicArray servGetAll();
	DynamicArray& servGetByName(const std::string& name);
};