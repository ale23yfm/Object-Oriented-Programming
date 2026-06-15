#include "repo.h"
#include <fstream>

void Repo::loadFromFile()
{
	std::ifstream fin("cars.txt");
	std::string name, model, yearS, color;
	int year;
	while (std::getline(fin, name, '|') && std::getline(fin, model, '|') && std::getline(fin, yearS, '|') && std::getline(fin, color))
	{
		name = name.substr(name.find_first_not_of(" \t"));
		model = model.substr(model.find_first_not_of(" \t"));
		yearS = yearS.substr(yearS.find_first_not_of(" \t"));
		color = color.substr(color.find_first_not_of(" \t"));

		year = std::stoi(yearS);

		this->cars.push_back(new Cars(name, model, year, color));
	}
}
