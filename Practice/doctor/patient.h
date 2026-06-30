#pragma once
#include <string>

class Patient
{
private:
	std::string name, specialization, diagnosis, medic, date;

public:
	Patient(std::string name, std::string specialization = "", std::string diagnosis = "undiagnosed", std::string medic = "", std::string date = "") :name(name), specialization(specialization), diagnosis(diagnosis), medic(medic), date(date) {};

	std::string getName() { return this->name; };
	std::string getDiagnosis() { return this->diagnosis; };
	std::string getSpecialization() { return this->specialization; };
	std::string getDate() { return this->date; };
	std::string getMedic() { return this->medic; };

	void setSpecialization(std::string s) { this->specialization=s; };
	void setDiagnosis(std::string d) { this->diagnosis = d; };
};
