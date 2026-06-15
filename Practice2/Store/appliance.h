#pragma once
#include <string>

class Appliance
{
protected:
	std::string id;

public:
	Appliance(std::string id) :id(id) {};
	virtual std::string toString() const = 0;
	virtual double consumedElectricity() const = 0;
	virtual ~Appliance() = default;
};