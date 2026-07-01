#pragma once
#include <string>

class Volunteer
{
private:
	std::string name, email, interests, depart;

public:
	Volunteer(std::string name, std::string email, std::string interests, std::string depart) :name(name), email(email), interests(interests), depart(depart) {};

	std::string getName() { return this->name; };
	std::string getEmail() { return this->email; };
	std::string getInterests() { return this->interests; };
	std::string getDepart() { return this->depart; };
	void setDepart(std::string d) { this->depart = d; };
};