#pragma once
#include <string>

class User
{
private:
	std::string name;
	std::string type;

public:
	User(std::string name, std::string type) : name(name), type(type){};

	std::string getName() const { return this->name; };
	std::string getType() const { return this->type; };
};