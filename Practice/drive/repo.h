#pragma once
#include <vector>
#include "driver.h"
#include "report.h"

class Repo
{
private:
	std::vector<Driver*> drivers;
	std::vector<Report*> reports;
	std::string driverFile;
	std::string reportFile;

	void loadDrivers();
	void loadReports();

public:
	Repo() = default;
	Repo(std::string driverFile, std::string reportFile) :driverFile(driverFile), reportFile(reportFile){};


};