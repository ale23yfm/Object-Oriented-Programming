#pragma once
#include "Repo.h"
#include "Observer.h"
#include <vector>
#include <algorithm>

class Service
{
private:
	Repo& repo;
	std::vector<Observer*> obs;

public:
	Service(Repo& repo) : repo(repo) {};

	void addObserver(Observer* o)
	{
		this->obs.push_back(o);
	}

	void notify()
	{
		for (auto i : this->obs)
			i->update();
		this->repo.saveFile();
	}
	
	std::vector<Event*> getEvs() { 
		std::vector<Event*> res = this->repo.getEvs();

		sort(res.begin(), res.end(), [](Event* a, Event* b)
			{
				return a->getDate() < b->getDate();
			});
		return res; };

	std::vector<Person*> getPers() { return this->repo.getPers(); };

	void addEvent(std::string organiser, std::string name, std::string desc, std::string date, float latit, float longit);
	void updateEvent(std::string organiser, std::string name, float latit, float longit, std::string newDesc = "", std::string newDate = "");
};

