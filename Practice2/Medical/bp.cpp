#include "bp.h"

bool BP::isResultOK() const
{
	return this->systolicValue >= 90 && this->systolicValue <= 119 && this->diastolicValue >= 60 && this->diastolicValue <= 79;
}

std::string BP::toString() const
{
	std::string res;
	res += "BP | data: " + this->data + " | systolicValue: " + std::to_string(this->systolicValue) + " | diastolicValue: " + std::to_string(this->diastolicValue);
	if (this->isResultOK() == true) 
		res += " | IS OK";
	else res += " | IS NOT OK";
	return res;
}
