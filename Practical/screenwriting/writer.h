#pragma once
#include <string>

class Writer
{
private:
	std::string name, expertise;

public:
	Writer(std::string name, std::string expertise) :name(name), expertise(expertise) {};
	
	std::string getName() { return this->name; };
	std::string getExpertise() { return this->expertise; };
};