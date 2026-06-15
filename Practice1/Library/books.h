#pragma once
#include <string>

class Books
{
private:
	std::string title;
	std::string author;
	int year;
	std::string genre;
public:
	Books(const std::string title = "", const std::string author = "", int year = 0, const std::string genre = ""): title{title}, author{author}, year{year}, genre{genre} {}
	std::string getTitle() const { return this->title; }
	std::string getAuthor() const { return this->author; }
	int getYear() const { return this->year; }
	std::string getGenre() const { return this->genre; }

	bool operator==(const Books &other) const
	{
		return this->author == other.author && this->title == other.title;
	}
};