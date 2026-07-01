#pragma once
#include <string>
#include <vector>

class Bacterium
{
private:
	std::string name, species;
	int size;
	std::vector<std::string> diseases;

public:
	Bacterium(std::string name, std::string species, int size, std::vector<std::string> diseases) :name(name), species(species), size(size), diseases(diseases){};

	std::string getName() { return this->name; };
	std::string getSpecies() { return this->species; };
	int getSize() { return this->size; };
	std::vector<std::string> getDiseases() { return this->diseases; };

	void setName(std::string n) { this->name = n; };
	void setSpecies(std::string s) { this->species = s; };
	void setSize(int s) {this->size = s; };
};
