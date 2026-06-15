#pragma once
#include <string>
#include "county.h"

class Independent : public County
{
protected:
	std::string names;
	int votes;

public:
	Independent(std::string name, std::string names, int votes) :County(name), names(names), votes(votes) {};
	bool eligible() const override;
	int mandates() const override;
	std::string toString() const override;
};