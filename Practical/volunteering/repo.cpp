#include "repo.h"

void Repo::loadDepartments()
{
	std::ifstream fin(this->depFile);
	std::string line, name, desc;
	while(getline(fin, line))
	{
		if (line.empty()) continue;

		std::stringstream ss(line);

		getline(ss,name, '|');
		getline(ss,desc);

		auto trim = [](std::string& s)
			{
				s.erase(0, s.find_first_not_of(" \t\r\n"));
				if (!s.empty())
					s.erase(s.find_last_not_of(" \t\r\n")+1);
			};

		trim(name);
		trim(desc);

		if (!name.empty() && !desc.empty())
			this->departments.push_back(new Department(name, desc));
	}
}

void Repo::loadVolunteers()
{
	std::ifstream fin(this->volFile);
	std::string line, name, email, interests, dep;

	while (getline(fin, line))
	{
		if (line.empty()) continue;
		std::stringstream ss(line);

		getline(ss, name, '|');
		getline(ss, email, '|');
		getline(ss, interests, '|');
		getline(ss, dep);

		auto trim = [](std::string& s)
			{
				s.erase(0, s.find_first_not_of(" \t\r\n"));
				if (!s.empty())
					s.erase(s.find_last_not_of(" \t\r\n")+1);
			};
		
		trim(name);
		trim(email);
		trim(interests);
		trim(dep);

		if (!name.empty() && !email.empty())
			this->volunteers.push_back(new Volunteer(name, email, interests, dep));
	}
}

void Repo::assignVolunteer(std::string name, std::string d)
{
	for (auto i : this->getVolunteers())
		if (name == i->getName())
			i->setDepart(d);
}

void Repo::saveVolunteers()
{
	std::ofstream fout(this->volFile);
	for (auto i : this->getVolunteers())
		fout << i->getName() << "|" << i->getEmail() << "|" << i->getInterests() << "|" << i->getDepart() << "\n";
}
