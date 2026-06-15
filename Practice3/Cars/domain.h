#pragma once
#include <string>

class Cars
{
private:
	std::string name;
	std::string model;
	int year;
	std::string color;

public:
	Cars(std::string name, std::string model, int year, std::string color) :name(name), model(model), year(year), color(color){};
	std::string getName() { return this->name; };
	std::string getModel() { return this->model; };
	int getYear() { return this->year; };
	std::string getColor() { return this->color;};
};