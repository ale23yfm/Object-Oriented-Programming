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
	Cars(const std::string& name = "", const std::string& model = "", int year = 0, const std::string& color = "") : name{ name }, model{ model }, year{ year }, color{ color } {}

	std::string getName() const { return name; }
	std::string getModel() const { return model; }
	std::string getColor() const { return color; }
	int getYear() const { return year; }

	bool operator==(const Cars& other) const
	{
		return this->model == other.model &&
			this->year == other.year;
	}
};