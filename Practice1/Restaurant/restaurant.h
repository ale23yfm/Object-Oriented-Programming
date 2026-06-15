#pragma once
#include <string>
#include <vector>

class Recipe
{
private:
	std::string menu;
	std::string name;
	std::vector<std::string> ingredients;
public:
	Recipe(const std::string& menu = "", const std::string& name = "", const std::vector<std::string> ingredients = {}) : menu{ menu },  name{name}, ingredients{ingredients} {}
	std::string getMenu() { return menu; }
	std::string getName() { return name; }
	std::vector<std::string> getIngredients() { return ingredients; }

	bool operator==(const Recipe& other) const
	{
		return this->menu == other.menu && this->name == other.name;
	}
};