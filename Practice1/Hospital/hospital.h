#pragma once
#include <string>
class Hospital
{
private:
	std::string name;
	int age;
	bool infected;
	int room;

public:
	Hospital(const std::string& name = "", int age = 0, bool infected = false, int room = 0): name{name}, age{age}, infected{infected}, room{room}{}
	std::string getName() { return name; }
	int getAge() { return age; }
	bool getInfected() { return infected; }
	void setInfected() { infected = true; }
	int getRoom() { return room; }

	bool operator==(Hospital &other) const
	{
		return this->name == other.name;
	}
};