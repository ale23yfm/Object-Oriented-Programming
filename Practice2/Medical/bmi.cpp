#include "bmi.h"

bool BMI::isResultOK() const
{
	return this->value >= 18.5 && this->value <= 25;
}

std::string BMI::toString() const
{
	std::string res;
	res += "BMI | data: " + this->data + " | value: " + std::to_string(this->value);
	if (this->isResultOK() == true)
		res += " | IS OK";
	else res += " | IS NOT OK";
	return res;
}
