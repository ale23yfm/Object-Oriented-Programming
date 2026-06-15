#include "party.h"

bool Party::eligible() const
{
	return this->votes > 250 * 5 / 100;
}

int Party::mandates() const
{
	return 0;
}

std::string Party::toString() const
{
	std::string res;
	res += "Party | County: " + this->name + " | name: " + this->names + " | votes: " + std::to_string(this->votes);
	return res;
}
