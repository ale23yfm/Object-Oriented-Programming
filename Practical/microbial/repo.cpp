#include "repo.h"

void Repo::loadBiologists()
{
	std::ifstream fin(this->bioFile);
	std::string line;
	while (getline(fin, line))
	{
		if (line.empty()) continue;

		std::string name="", spec = "", token="";
		std::vector<std::string> species;

		std::stringstream ss(line);

		getline(ss, name, '|');
		getline(ss, spec);

		std::stringstream sss(spec);
		while (getline(sss, token, ','))
		{
			token.erase(0, token.find_first_not_of(" \t\r\n"));
			if (!token.empty())
				token.erase(token.find_last_not_of(" \t\r\n")+1);
			if (!token.empty())
				species.push_back(token);
		}

		name.erase(0, name.find_first_not_of(" \t\r\n"));
		if (!name.empty())
			name.erase(name.find_last_not_of(" \t\r\n") + 1);

		if (!name.empty())
			this->biologists.push_back(new Biologist(name, species));
	}
}

void Repo::loadBacteria()
{
	std::ifstream fin(this->bacFile);
	std::string line;
	
	while (getline(fin, line))
	{
		if (line.empty()) continue;

		std::stringstream ss(line);
		std::string name = "", species = "", s = "", d = "", token="";
		int size = 0;
		std::vector<std::string> diseases;

		getline(ss, name, '|');
		getline(ss, species, '|');
		getline(ss, s, '|');
		getline(ss, d);
		
		auto trim = [](std::string s)
			{
				s.erase(0, s.find_first_not_of(" \t\r\n"));
				if (!s.empty())
					s.erase(s.find_last_not_of(" \t\r\n")+1);
			};

		trim(name);
		trim(species);
		trim(s);

		size = stoi(s);

		std::stringstream ssd(d);

		while (getline(ssd, token, ','))
		{
			trim(token);
			if (!token.empty())
				diseases.push_back(token);
		}

		if (!name.empty())
			this->bacterias.push_back(new Bacterium(name, species, size, diseases));
	}
}

void Repo::saveBacteria()
{
}
