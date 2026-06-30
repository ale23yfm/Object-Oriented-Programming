#include "repo.h"
#include <QMessageBox>

void Repo::loadMedics()
{
	std::ifstream fin(this->medFile);
	std::string line;

	while (getline(fin, line))
	{
		if (line.empty()) continue;
		std::string name="", specialization = "";
		std::stringstream ss(line);

		getline(ss, name, '|');
		getline(ss, specialization);

		auto trim = [](std::string& s)
			{
				s.erase(0, s.find_first_not_of(" \t\r\n"));
				if (!s.empty())
					s.erase(s.find_last_not_of(" \t\r\n")+1);
			};

		trim(name);
		trim(specialization);

		if (!name.empty())
			this->medics.push_back(new Medic(name, specialization));
	}
}

void Repo::loadPatients()
{
	std::ifstream fin(this->patFile);
	std::string line;

	while (getline(fin, line))
	{
		if (line.empty()) continue;    

		std::string name="", specialization = "", diagnosis = "", medic = "", date = "";
		std::stringstream ss(line);

		getline(ss, name, '|');
		getline(ss, specialization, '|');
		getline(ss, diagnosis, '|');
		getline(ss, medic, '|');
		getline(ss, date);

		auto trim = [](std::string& s)
			{
				s.erase(0, s.find_first_not_of(" \t\r\n"));
				if (!s.empty())
					s.erase(s.find_last_not_of(" \t\r\n")+1);
			};

		trim(name);
		trim(specialization);
		trim(diagnosis);
		trim(medic);
		trim(date);

		if (!name.empty())

			this->patients.push_back(new Patient(name, specialization, diagnosis, medic, date));
		}
}

void Repo::saveToFile()
{
	std::ofstream fout(this->patFile);
	for (auto i : this->getPatients())
		fout << i->getName() << "|" << i->getSpecialization() << "|" << i->getDiagnosis() << "|" << i->getMedic() << "|" << i->getDate() << "\n";
}
