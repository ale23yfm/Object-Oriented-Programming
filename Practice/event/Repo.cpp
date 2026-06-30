#include "Repo.h"

void Repo::loadEvents()
{
	std::ifstream fin(this->evFile);
	std::string line;
	while (getline(fin, line))
	{
		if (line.empty()) continue;

		std::string organiser, name, desc, date, lats, longs;
		float latit, longit;

		std::stringstream ss(line);

		getline(ss, organiser, '|');
		getline(ss, name, '|');
		getline(ss, desc, '|');
		getline(ss, date, '|');
		getline(ss, lats, '|');
		getline(ss, longs);

		auto trim = [](std::string& s)
			{
				s.erase(0,s.find_first_not_of(" \t\r\n"));
				if (!s.empty())
				s.erase(s.find_last_not_of(" \t\r\n")+1);
			};

		trim(organiser);
		trim(name);
		trim(desc);
		trim(date);
		trim(lats);
		trim(longs);

		latit = stof(lats);
		longit = stof(longs);

		this->evs.push_back(new Event(organiser, name, desc, date, latit, longit));
	}
}

void Repo::loadPers()
{
	std::ifstream fin(this->persFile);
	std::string line;
	while (getline(fin, line))
	{
		if (line.empty()) continue;

		std::string name, lats, longs, stat;
		float latit, longit;
		bool status;

		std::stringstream ss(line);

		getline(ss, name, '|');
		getline(ss, lats, '|');
		getline(ss, longs, '|');
		getline(ss, stat);

		auto trim = [](std::string& s)
			{
				s.erase(0, s.find_first_not_of(" \t\r\n"));
				if (!s.empty())
					s.erase(s.find_last_not_of(" \t\r\n") + 1);
			};

		trim(name);
		trim(lats);
		trim(longs);
		trim(stat);

		latit = stof(lats);
		longit = stof(longs);

		if (stat == "true") status = 1;
		else status = 0;

		this->pers.push_back(new Person(name, latit, longit, status));
	}
}

void Repo::saveFile()
{
	std::ofstream fout(this->evFile);
	for (auto i : this->getEvs())
		fout << i->getOrganiser() << "|" << i->getName() << "|" << i->getDesc() << "|" << i->getDate() << "|" << i->getLatit() << "|" << i->getLongit() << "\n";
}
