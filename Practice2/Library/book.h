#pragma once
#include <string>

class Book
{
protected:
	std::string isbn;
	int publicationYear;
public:
	Book(std::string isbn, int publicationYear) : isbn(isbn), publicationYear(publicationYear) {};
	virtual double rentalPricePerDay() const = 0;
	virtual std::string toString() const = 0;
	virtual ~Book() = default;
};