#pragma once
#include <string>
#include <vector>

class Vegetables
{
private:
	std::string family;
	std::string name;
	std::string parts;

public:
	Vegetables(std::string family, std::string name, std::string parts) : family(family), name(name), parts(parts){};
	std::string getFamily() { return this->family; };
	std::string getName() { return this->name; };
	std::string getParts() { return this->parts; };
};