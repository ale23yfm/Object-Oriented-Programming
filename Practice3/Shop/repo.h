#pragma once
#include <vector>
#include <fstream>
#include "domain.h"

class Repo
{
private:
	std::vector<Shop*> list;
public:
	Repo() = default;
	Repo(std::vector<Shop*> list) :list(list) {};
	std::vector<Shop*> getAll() { return this->list; };

	void add(std::string category, std::string name, int quantity)
	{
		this->list.push_back(new Shop(category, name, quantity));
	};

	void loadFromFile()
	{
		std::ifstream fin("list.txt");
		std::string category, name, q;
		int quantity;
		while (std::getline(fin, category, '|') && std::getline(fin, name, '|') && std::getline(fin, q))
		{
			category = category.substr(category.find_first_not_of(" \t"));
			name = name.substr(name.find_first_not_of(" \t"));
			q = q.substr(q.find_first_not_of(" \t"));
			
			quantity = std::stoi(q);
			this->list.push_back(new Shop(category, name, quantity));
		}
	};
};