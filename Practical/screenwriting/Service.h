#pragma once
#include "Repo.h"
#include "Observer.h"
#include <vector>

class Service
{
private:
	Repo& repo;
	std::vector<Observer*> obs;

public:
	Service(Repo& repo) :repo(repo) {};

	void addObserver(Observer* o)
	{
		this->obs.push_back(o);
	}
	void notify()
	{
		for (auto i : this->obs)
			i->update();
		this->repo.saveToFile();
	}

	void acceptIdea(Idea* idea)
	{
		this->repo.acceptIdea(idea);
		notify();
	}

	void addIdea(std::string desc, std::string creator, int act)
	{
		for (auto i : this->getIdeas())
			if (i->getDesc() == desc && i->getAct() == act)
				throw std::runtime_error("Idea already exists");
		this->repo.addIdea(desc, creator, act);
		notify();
	}

	std::vector<Idea*> getIdeas();
	std::vector<Writer*> getWriters() { return this->repo.getWriters(); };
};

