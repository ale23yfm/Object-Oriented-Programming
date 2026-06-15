#pragma once
#include "building.h"

class Block : public Building
{
private:
	int totalApartments;
	int occupiedApartments;

public:
	Block(std::string address, int constructionYear, int totalApartments, int occupiedApartments) : Building(address, constructionYear), totalApartments(totalApartments), occupiedApartments(occupiedApartments) {};
	bool mustBeRestored() const override;
	bool canBeDemolished() const override;

	int getTotalApartments() { return this->totalApartments;};
	int getOccupiedApartments() { return this->occupiedApartments;};

	std::string toString() const override;
};