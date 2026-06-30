#include "repo.h"
#include <fstream>
#include <sstream>

void Repo::loadDrivers()
{
	std::ifstream fin(this->driverFile);
	std::string line, name;
	double latitude;
	double longitude;
	int score;

	while (getline(fin, line))
	{
		if (line.empty()) continue;

		std::stringstream ss(line);

		getline(ss, name, ',');
		ss >> latitude;
		ss >> longitude;
		ss >> score;

		auto trim = [](std::string s) 
			{
				s.erase(0, s.find_first_not_of(" \t\r\n"));
				if (!s.empty())
					s.erase(s.find_last_not_of(" \t\r\n")+1);
			};

		trim(name);
		if (!name.empty())
			this->drivers.push_back(new Driver(name, latitude, longitude, score));
	}
}

void Repo::loadReports()
{
}
