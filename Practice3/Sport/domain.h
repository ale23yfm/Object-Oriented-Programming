#pragma once
#include <string>

class Sport
{
private:
	int start;
	int end;
	std::string type;
	int intensity;
	std::string description;

public:
	Sport(int start, int end, std::string type, int intensity, std::string description) :start(start), end(end), type(type), intensity(intensity), description(description) {};
	int getStart() { return this->start; };
	int getEnd() { return this->end; };
	std::string getType() { return this->type; };
	int getIntensity() { return this->intensity; };
	std::string getDescription() { return this->description; };
};