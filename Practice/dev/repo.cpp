#include "repo.h"
#include <fstream>
#include <sstream>

void Repo::loadUsers()
{
	std::ifstream fin(this->userFile);

	std::string line, name, type;

	while (getline(fin, line))
	{

		if (line.empty()) continue;

		std::stringstream ss(line);

		getline(ss, name, ','); 
		getline(ss, type);

		auto trim = [](std::string s)
			{
				s.erase(0, s.find_first_not_of(" \t\r\n"));
				if (!s.empty())
					s.erase(s.find_last_not_of(" \t\r\n"));
			};

		trim(name);
		trim(type);
		this->users.push_back(new User(name, type));
	}
}

void Repo::loadIssues()
{
	std::ifstream fin(this->issueFile);

	std::string line, desc, status, reporter, solver;

	while (std::getline(fin, line))
	{
		if (line.empty()) continue;

		std::stringstream ss(line);

		getline(ss, desc, ',');
		getline(ss, status, ',');
		getline(ss, reporter, ',');
		getline(ss, solver);

		auto trim = [](std::string& s)
			{
				s.erase(0, s.find_first_not_of(" \t\r\n"));
				if (!s.empty())
					s.erase(s.find_last_not_of(" \t\r\n") + 1);
			};

		trim(desc);
		trim(status);
		trim(reporter);
		trim(solver);

		if (!desc.empty())
			this->issues.push_back(new Issue(desc, status, reporter, solver));
	}
}

void Repo::saveIssues()
{
	std::ofstream fout(this->issueFile);
	for (auto i : this->getIssues())
		fout << "\n" << i->getDesc() << "," << i->getStatus() << "," << i->getReporter() << "," << i->getSolver();
}
