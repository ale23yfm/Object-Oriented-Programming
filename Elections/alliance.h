#pragma once
#include <string>
#include "county.h"

class Alliance : public County
{
protected:
	std::string names;
	int votes;
	int number;

public:
	Alliance(std::string name, std::string names, int votes, int number) :County(name), names(names), votes(votes), number(number) {};
	bool eligible() const override;
	int mandates() const override;
	std::string toString() const override;
};