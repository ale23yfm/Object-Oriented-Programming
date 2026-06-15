#include "repo.h"
#include <fstream>

void Repo::loadFromFile()
{
	std::ifstream fin("vegetables.txt");
	std::vector<Vegetables*> all;
	std::string nameStr, familyStr, partsStr;
	//std::vector<std::string> parts;
	while (std::getline(fin, familyStr, '|') && std::getline(fin, nameStr, '|') && std::getline(fin, partsStr))
	{
		familyStr = familyStr.substr(familyStr.find_first_not_of(" \t"));
		nameStr = nameStr.substr(nameStr.find_first_not_of(" \t"));
		partsStr = partsStr.substr(partsStr.find_first_not_of(" \t"));
		//parts.clear();

		this->vegetables.push_back(new Vegetables(familyStr, nameStr, partsStr));
	}
}
