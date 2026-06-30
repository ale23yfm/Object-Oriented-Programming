#pragma once
#include <string>
#include <vector>
#include "driver.h"

class Report
{
private:
	std::string desc;
	Driver* reporter;
	double latitude;
	double longitude;
	bool status;
	std::vector<Driver*> validatedBy;

public:
	Report(Driver* reporter, std::string desc, double latitude, double longitude, bool status) : desc(desc), latitude(latitude), longitude(longitude), status(status) {};

	std::string getDesc() { return this->desc; };
	double getLatitude() { return this->latitude; };
	double getLongitude() { return this->longitude; };
	bool getStatus() { return this->status; };
};