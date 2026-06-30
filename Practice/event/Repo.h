#pragma once
#include "pers.h"
#include "ev.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

class Repo
{
private:
	std::vector<Event*> evs;
	std::vector<Person*> pers;
	std::string evFile;
	std::string persFile;

	void loadEvents();
	void loadPers();

public:
	Repo() = default;
	Repo(std::string evFile, std::string persFile) :evFile(evFile), persFile(persFile){
		loadEvents();
		loadPers(); };

	void saveFile();

	void addEvent(std::string organiser, std::string name, std::string desc, std::string date, float latit, float longit)
		{
		this->evs.push_back(new Event(organiser, name, desc, date, latit, longit));
		};

	std::vector<Event*> getEvs() { return this->evs; };
	std::vector<Person*> getPers() { return this->pers; };
};

