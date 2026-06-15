#pragma once
#include "building.h"

class House : public Building
{
private:
	std::string type;
	bool isHistorical;

public:
	House(std::string address, int constructionYear, std::string type, bool isHistorical) : Building(address, constructionYear), type(type), isHistorical(isHistorical) {};
	bool mustBeRestored() const override; 
	bool canBeDemolished() const override;

	std::string getType() { return this->type; };
	bool getIsHistorical() { return this->isHistorical; };

	std::string toString() const override;
};