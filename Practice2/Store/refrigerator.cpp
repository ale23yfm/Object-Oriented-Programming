#include "refrigerator.h"

std::string Refrigerator::toString() const
{
	std::string res;
	res += "Refrigerator | id: " + this->id + " | electricityUsageClass: " + this->electricityUsageClass + " | hasFreezer:";
	if (this->hasFreezer == true) 
		res += "YES";
	else res += "NO";
	res += " | consumedElectricity: " + std::to_string(this->consumedElectricity()) + " KW";
	return res;
}

double Refrigerator::consumedElectricity() const
{
	int x;
	if (this->electricityUsageClass == "A")
		x = 3;
	else 
		x = 2;
	if (this->hasFreezer == true)
			return 30 * x + 20;
	else return 30 * x;
}
