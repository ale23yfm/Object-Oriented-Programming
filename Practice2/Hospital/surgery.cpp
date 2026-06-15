#include "surgery.h"

bool Surgery::isEfficient() const
{
	if (this->numberOfDoctors == 0) return false;
	return this->numberOfPatients/this->numberOfDoctors >= 2;
}

std::string Surgery::toString() const
{
	std::string res;
	res += "Surgery at : " + this->hospitalName + " | numberOfDoctors: " + std::to_string(this->numberOfDoctors) + " | numberOfPatients: " + std::to_string(this->numberOfPatients) + " | efficiency: ";
	if (this->isEfficient() == true)
		res += "YES";
	else
		res += "NO";
	return res;
}
