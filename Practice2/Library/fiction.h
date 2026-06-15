#pragma once
#include <string>
#include "book.h"

class Fiction : public Book
{
protected:
	std::string genre;
	int numberOfPages;
public:
	Fiction(std::string isbn, int publicationYear, std::string genre, int numberOfPages) : Book(isbn, publicationYear), genre(genre), numberOfPages(numberOfPages) {};
	double rentalPricePerDay() const;
	std::string toString() const;
};