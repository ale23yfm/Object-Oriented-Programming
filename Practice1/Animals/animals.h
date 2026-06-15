#pragma once
#include <string>

class Animals
{
private:
	std::string name;
	std::string species;
	int age;
	std::string color;

public: 
	Animals(const std::string name = "", const std::string species = "", int age= 0, const std::string color = "") : name{name}, species{species}, age{age}, color{color} {};
	std::string getName() { return name; };
	std::string getSpecies() { return species; };
	int getAge() { return age; };
	std::string getColor() { return color; };

	bool operator==(Animals other)
	{
		return this->name == other.name && this->species == other.species;
	}
};