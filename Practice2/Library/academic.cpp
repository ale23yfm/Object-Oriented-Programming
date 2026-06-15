#include "academic.h"

double Academic::rentalPricePerDay() const
{
	if (this->isUniversityLevel == true)
		return 3.0 + 2.0;
	return 3.0;
}

std::string Academic::toString() const
{
	std::string res;
	res += "Academic | publicationYear: " + std::to_string(this->publicationYear) + " | isbn: " + this->isbn + " | isUniversityLevel: ";
	if (this->isUniversityLevel == true)
		res += "YES";
	else res += "NO";
	res += " | subject: " + this->subject + " | rentalPricePerDay: " + std::to_string(this->rentalPricePerDay());
	return res;
}
