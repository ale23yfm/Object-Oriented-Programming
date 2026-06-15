#pragma once
#include <string>
#include <vector>

class Weather
{
private:
	std::string location;
	std::string name;
	std::vector<std::string> senzors;
	
public:
	Weather(const std::string location = "", const std::string name = "", const std::vector<std::string> senzors = {}) : location{location}, name{name}, senzors{senzors} {}
	std::string getLocation() const { return location; }
	std::string getName() const { return name; }
	std::vector<std::string> getSenzors() const { return senzors; }
	std::string getSenzorsAsString();

	bool operator==(Weather& other) const
	{
		return this->name == other.name && this->location == other.location;
	}

	bool hasSenzor(const std::string& s) const
	{
		for (auto& x : senzors)
			if (x == s)
				return true;
		return false;
	}
};