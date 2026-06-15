#include "house.h"

bool House::mustBeRestored() const
{
	return this->constructionYear < 1926;
}

bool House::canBeDemolished() const
{
	return this->isHistorical == false;
}

std::string House::toString() const
{
	std::string res;
	res += "Address: " + this->address + " | constructionYear: " + std::to_string(this->constructionYear) + " | Type:" + this->type + " | isHistorical: ";
	if (this->isHistorical == true)
		res += "YES";
	else res += "NO";
	res += +" | mustBeRestored: ";
	if (this->mustBeRestored() == true)
		res += "YES";
	else res += "NO";
	res += +" | canBeDemolished: ";
	if (this->canBeDemolished() == true)
		res += "YES";
	else res += "NO";
	return res;
}
