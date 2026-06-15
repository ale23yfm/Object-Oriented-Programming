#pragma once
#include <string>
#include "book.h"

class Academic : public Book
{
protected:
	std::string subject;
	bool isUniversityLevel;
public:
	Academic(std::string isbn, int publicationYear, std::string subject, bool isUniversityLevel) : Book(isbn, publicationYear), subject(subject), isUniversityLevel(isUniversityLevel){};
	double rentalPricePerDay() const;
	std::string toString() const;
};