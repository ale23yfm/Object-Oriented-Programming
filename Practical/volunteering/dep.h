#pragma once
#include <string>

class Department
{
private:
	std::string name, desc;

public:
	Department(std::string name, std::string desc) :name(name), desc(desc){};

	std::string getName() { return this->name; };
	std::string getDesc() { return this->desc; };
};