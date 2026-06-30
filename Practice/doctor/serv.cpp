#include "serv.h"

std::vector<Patient*> Service::getPatients(std::string spec)
{
	std::vector<Patient*> res;

	for (auto i : this->getAllPatients())
		if (i->getSpecialization() == spec || i->getDiagnosis() == "undiagnosed")
			res.push_back(i);
	sort(res.begin(), res.end(), [](Patient*a, Patient*b) 
		{
			return a->getDate() < b->getDate();
		});

	return res;
}

std::vector<Patient*> Service::getPforM(std::string name)
{
	std::vector<Patient*> res;
	for (auto i : this->getAllPatients())
		if (name == i->getMedic())
			res.push_back(i);
	sort(res.begin(), res.end(), [](Patient* a, Patient* b)
		{
			return a->getDate() < b->getDate();
		});
	return res;
}

void Service::updatePatient(std::string name, std::string newSpec, std::string newDiag, std::string medic)
{
	for (auto i : this->getAllPatients())
		if (i->getName() == name)
		{
			if (i->getDiagnosis() != "undiagnosed" && i->getMedic() != medic)
				throw std::runtime_error("The patient should be yours or undiagnosed! Try another one!");
			if (newSpec !="")
				i->setSpecialization(newSpec);
			if (newDiag !="")
				i->setDiagnosis(newDiag);
			notify();
			return;
		}
	throw std::runtime_error("Patient not found!");
}