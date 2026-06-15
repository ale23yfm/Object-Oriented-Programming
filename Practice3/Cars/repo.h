#pragma once
#include "domain.h"
#include <vector>

class Repo
{
private:
	std::vector<Cars*> cars;

public:
	Repo() = default;
	Repo(std::vector<Cars*> cars) :cars(cars) {};
	std::vector<Cars*> getAll() {
		return this->cars;
	};
	void add(std::string name, std::string model, int year, std::string color)
	{
		this->cars.push_back(new Cars(name, model, year, color));
	};
	void loadFromFile();
};
