#include "fiction.h"

double Fiction::rentalPricePerDay() const
{
	if (this->genre == "thriller")
		return 0.05* this->numberOfPages + 0.5;
	return 0.05* this->numberOfPages;
}

std::string Fiction::toString() const
{
	std::string res;
	res += "Fiction | publicationYear: " + std::to_string(this->publicationYear) + " | isbn: " + this->isbn + " | genre: " + this->genre + " | numberOfPages: " + std::to_string(this->numberOfPages) + " | rentalPricePerDay: " + std::to_string(this->rentalPricePerDay());
	return res;
}
