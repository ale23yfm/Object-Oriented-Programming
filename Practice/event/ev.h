#pragma once
#include <string>

class Event
{
private:
	std::string organiser, name, desc, date;
	float latit, longit;

public:
	Event(std::string organiser, std::string name, std::string desc, std::string date, float latit, float longit) :
		organiser(organiser), name(name), desc(desc), date(date), latit(latit), longit(longit){};

	std::string getOrganiser() { return this->organiser; };
	std::string getName() { return this->name; };
	std::string getDesc() { return this->desc; };
	std::string getDate() { return this->date; };

	void setDesc(std::string n) { this->desc=n; };
	void setDate(std::string n) { this->date=n; };

	float getLatit() { return this->latit; };
	float getLongit() { return this->longit; };
};