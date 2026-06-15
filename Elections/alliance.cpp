#include "alliance.h"

bool Alliance::eligible() const
{
	return this->votes > 250*8/100 || this->votes > 250 * 9 / 100 || this->votes > 250 / 10;
}

int Alliance::mandates() const
{
	return 0;
}

std::string Alliance::toString() const
{
	std::string res;
	res += "Alliance | County: " + this->name + " | name: " + this->names + " | votes: " + std::to_string(this->votes) + " | number:" + std::to_string(this->number);
	return res;
}
