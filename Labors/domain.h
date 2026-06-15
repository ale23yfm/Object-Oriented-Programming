#pragma once
#include <string>

class Labor
{
private:
	int start;
	int end;
	std::string type;
	std::string country;
	int pos;
	int wage;

public:
	Labor(int start, int end, std::string type, std::string country, int pos, int wage) :start(start), end(end), type(type), country(country), pos(pos), wage(wage) {};
	int getStart() { return this->start; };
	int getEnd() { return this->end; };
	std::string getType() { return this->type; };
	std::string getCountry() { return this->country; };
	int getPos() { return this->pos; };
	int getWage() { return this->wage; };
};