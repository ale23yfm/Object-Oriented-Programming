#pragma once
#include <string>

class Driver
{
private:
	std::string name;
	double latitude;
	double longitude;
	int score;

public:
	Driver(std::string name, double latitude, double longitude, int score) : name(name), latitude(latitude), longitude(longitude), score(score) {};

	std::string getName() { return this->name; };
	double getLatitude() { return this->latitude; };
	double getLongitude() { return this->longitude; };
	int getScore() { return this->score; };
};