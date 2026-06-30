#pragma once
#include "repo.h"
#include "observer.h"
class Service
{
private:
	Repo& repo;
	std::vector<Observer*> observers;

public:
	Service(Repo& repo) :repo(repo) {};

	std::vector<Issue*>& getIssues() { return this->repo.getIssues(); }
	std::vector<User*> getUsers() { return this->repo.getUsers(); }

	void addObserver(Observer* o) { observers.push_back(o); }

	void addIssue(const std::string& desc, const std::string& reporter);
	void resolveIssue(const std::string& desc, const std::string& solver);
	void removeIssue(const std::string& desc);

	void notify() {
		for (auto o : observers)
			o->update();
		this->repo.saveIssues();
	}
};