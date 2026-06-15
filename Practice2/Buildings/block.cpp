#include "block.h"

bool Block::mustBeRestored() const
{
	return this->constructionYear < 2026-40 && this->occupiedApartments >= 80/100*this->totalApartments;
}

bool Block::canBeDemolished() const
{
	return this->occupiedApartments < 0.05 * this->totalApartments;
}

std::string Block::toString() const
{
	std::string res;
	res += "Address: " + this->address + " | constructionYear: " + std::to_string(this->constructionYear) + " | totalApartments: " + std::to_string(this->totalApartments) + " | occupiedApartments: " + std::to_string(this->occupiedApartments);

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