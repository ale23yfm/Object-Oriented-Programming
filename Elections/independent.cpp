#include "independent.h"

bool Independent::eligible() const
{
	return this->mandates() >0;
}

int Independent::mandates() const
{
	return 0;
}

std::string Independent::toString() const
{
	std::string res;
	res += "Independent | County: " + this->name + " | name: " + this->names + " | votes: " + std::to_string(this->votes);
	return res;
}
