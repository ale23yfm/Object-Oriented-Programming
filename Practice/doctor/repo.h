#pragma once
#include <vector>
#include <fstream>
#include <sstream>
#include "med.h"
#include "patient.h"

class Repo
{
private:
	std::vector<Medic*> medics;
	std::vector<Patient*> patients;
	std::string medFile;
	std::string patFile;

	void loadMedics();
	void loadPatients();

public:
	Repo() = default;
	Repo(std::string medFile, std::string patFile) :medFile(medFile), patFile(patFile) {
		loadMedics();
		loadPatients();
	};

	void saveToFile();

	void addPatient(std::string name, std::string spec, std::string diag, std::string medic, std::string date)
	{
		this->patients.push_back(new Patient(name, spec, diag, medic, date));
	};

	std::vector<Medic*> getMedics() { return this->medics; };
	std::vector<Patient*> getPatients() { return this->patients; };
};