#pragma once
#include "repo.h"
#include "observer.h"
#include <algorithm>

class Service
{
private:
	Repo& repo;
	std::vector<Observer*> observers;

public:
	Service(Repo& repo): repo(repo) {};

	void addObserver(Observer* o) { observers.push_back(o); };
	void notify()
	{
		for (auto i : this->observers)
			i->update();
		this->repo.saveToFile();
	}

	void addPatient(std::string name, std::string spec, std::string medic, std::string date, std::string diag = "undiagnosed")
	{
		for (auto i : this->getAllPatients())
			if (name == i->getName())
				throw std::runtime_error("Patient already exists");
		this->repo.addPatient(name, spec, diag, medic, date);
		notify();
	};

	std::vector<Medic*> getAllMedics() { return this->repo.getMedics(); };
	std::vector<Patient*> getAllPatients() { return this->repo.getPatients(); };
	std::vector<Patient*> getPatients(std::string spec);
	std::vector<Patient*> getPforM(std::string name);
	void updatePatient(std::string name, std::string newSpec, std::string newDiag, std::string medic);
};