#include "Repo.h"

void Repo::loadWriter()
{
	std::ifstream fin(this->writerFile);
	std::string line;
	while (getline(fin, line))
	{
		if (line.empty()) continue;
		std::string name, expertise;
		std::stringstream ss(line);

		getline(ss, name, '|');
		getline(ss, expertise);

		auto trim = [](std::string& s)
			{
				s.erase(0, s.find_first_not_of(" \t\r\n"));
				if (!s.empty())
					s.erase(s.find_last_not_of(" \t\r\n")+1);
			};
		trim(name);
		trim(expertise);

		this->writers.push_back(new Writer(name, expertise));
	}
}

void Repo::loadIdea()
{
	std::ifstream fin(this->ideaFile);
	std::string line;
	while (getline(fin, line))
	{
		if (line.empty()) continue;
		std::string desc, status, creator, acts;
		int act;
		std::stringstream ss(line);

		getline(ss, desc, '|');
		getline(ss, status, '|');
		getline(ss, creator, '|');
		getline(ss, acts);

		auto trim = [](std::string& s)
			{
				s.erase(0, s.find_first_not_of(" \t\r\n"));
				if (!s.empty())
					s.erase(s.find_last_not_of(" \t\r\n") + 1);
			};

		trim(desc);
		trim(status);
		trim(creator);
		trim(acts);

		act = stoi(acts);

		this->ideas.push_back(new Idea(desc, status, creator, act));
	}
}

void Repo::saveToFile()
{
}
