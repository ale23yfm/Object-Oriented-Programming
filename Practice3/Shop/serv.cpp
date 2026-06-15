#include "serv.h"
#include <algorithm>
#include <stdexcept>

std::vector<std::string> Service::getAllOnce()
{
	std::vector<std::string> res;
	for (auto i : this->repo.getAll())
	{
		std::string cat = i->getCategory();
		if (std::find(res.begin(), res.end(), cat) == res.end())
			res.push_back(cat);
	}
	std::sort(res.begin(), res.end(), [](std::string a, std::string b) {return a < b; });
	return res;
}

std::vector<Shop*> Service::getFiltered(const std::string& cat)
{
	std::vector<Shop*> res;
	bool found = false;
	for (auto i : this->repo.getAll())
		if (cat == i->getCategory())
		{
			res.push_back(i);
			found = true;
		}
	if (found == false)
		throw std::runtime_error("Not found");
	else
		return res;
}

std::vector<Shop*> Service::getFilteredByMin(const int mini)
{
	std::vector<Shop*> res;
	bool found = false;
	for (auto i : this->repo.getAll())
		if (mini <= i->getQuantity())
		{
			res.push_back(i);
			found = true;
		}
	if (found == false)
		throw std::runtime_error("Not found");
	else
		return res;
}

int Service::getFilteredQuantity(const std::string& cat)
{
	int total = 0;
	bool found = false;
	for (auto i : this->repo.getAll())
		if (cat == i->getCategory())
		{
			total += i->getQuantity();
			found = true;
		}
	if (found == false)
		throw std::runtime_error("Not found");
	else
	return total;
}
