#pragma once
#include <string>

class Medic
{
private:
	std::string name, specialization;

public:
	Medic(std::string name, std::string specialization = "") :name(name), specialization(specialization) {};

	std::string getName() { return this->name; };
	std::string getSpecialization() { return this->specialization; };
	
};