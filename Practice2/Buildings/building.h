#pragma once
#include <string>

class Building
{
protected:
	std::string address;
	int constructionYear;

public:
	Building(std::string address, int constructionYear) : address(address), constructionYear(constructionYear) {};
	virtual bool mustBeRestored() const = 0;
	virtual bool canBeDemolished() const = 0;
	virtual std::string toString() const = 0;

	int getConstructionYear() { return this->constructionYear; };
	std::string getAddress() { return this->address; };

	virtual ~Building() = default;
};