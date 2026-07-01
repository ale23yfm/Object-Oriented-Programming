#pragma once
#include <string>
#include <vector>

class Biologist
{
private:
	std::string name;
	std::vector<std::string> species;

public:
	Biologist(std::string name, std::vector<std::string> species) :name(name), species(species) {};

	std::string getName() { return this->name; };
	std::vector<std::string> getSpecies() { return this->species; };
};
