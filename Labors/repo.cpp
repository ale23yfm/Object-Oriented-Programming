#include "repo.h"
#include <fstream>

std::vector<Labor*> Repo::getAll()
{
	return this->labors;
}

void Repo::loadFromFile()
{
	std::ifstream fin("labors.txt");
	std::string startS, endS, type, country, posS, wageS;
	int start, end, pos, wage;
	while (std::getline(fin, startS, ';') && std::getline(fin, endS, ';') && std::getline(fin, type, ';') && std::getline(fin, country, ';') && std::getline(fin, posS, ';') && std::getline(fin, wageS))
	{
		startS = startS.substr(startS.find_first_not_of(" \t"));
		endS = endS.substr(endS.find_first_not_of(" \t"));
		type = type.substr(type.find_first_not_of(" \t"));
		country = country.substr(country.find_first_not_of(" \t"));
		posS = posS.substr(posS.find_first_not_of(" \t"));
		wageS = wageS.substr(wageS.find_first_not_of(" \t"));

		start = std::stoi(startS);
		end = std::stoi(endS);
		pos = std::stoi(posS);
		wage = std::stoi(wageS);

		this->labors.push_back(new Labor(start, end, type, country, pos, wage));
	}
}
