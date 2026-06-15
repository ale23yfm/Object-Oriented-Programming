#include "repo.h"
#include <fstream>

void Repo::loadFromFile()
{
	std::ifstream fin("sports.txt");
	std::string startS, endS, type, intensityS, description;
	int start, end, intensity;
	while (std::getline(fin, startS, ';') && std::getline(fin, endS, ';')&& std::getline(fin, type, ';')&& std::getline(fin, intensityS, ';')&& std::getline(fin, description))
	{
		startS = startS.substr(startS.find_first_not_of(" \t"));
		endS = endS.substr(endS.find_first_not_of(" \t"));
		type = type.substr(type.find_first_not_of(" \t"));
		intensityS = intensityS.substr(intensityS.find_first_not_of(" \t"));
		description = description.substr(description.find_first_not_of(" \t"));
		start = std::stoi(startS);
		end = std::stoi(endS);
		intensity = std::stoi(intensityS);
		this->sports.push_back(new Sport(start, end, type, intensity, description));
	}
}
