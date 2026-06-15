#include "neonatal.h"

bool NeonatalUnit::isEfficient() const
{
	return this->averageGrade > 8.5 && this->numberOfNewBorns >= this->numberOfMothers;
}

std::string NeonatalUnit::toString() const
{
	std::string res;
	res += "Neonatal at : " + this->hospitalName + " | numberOfDoctors: " + std::to_string(this->numberOfDoctors) + " | numberOfNewBorns: " + std::to_string(this->numberOfNewBorns) + " | numberOfMothers: " + std::to_string(this->numberOfMothers) + " | averageGrade: " + std::to_string(this->averageGrade) + " | efficiency: ";
	if (this->isEfficient() == true)
		res += "YES";
	else
		res += "NO";
	return res;
}
