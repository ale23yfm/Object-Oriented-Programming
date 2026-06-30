#pragma once
#include <string>

class Person
{
private:
	std::string name;
	float latit, longit;
	bool status;

public:
	Person(std::string name, float latit, float longit, bool status) :
		name(name), latit(latit), longit(longit), status(status){
	};

	std::string getName() { return this->name; };
	bool getStatus() { return this->status; };

	float getLatit() { return this->latit; };
	float getLongit() { return this->longit; };
}; 