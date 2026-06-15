#include "serv.h"
#include <algorithm>
#include <stdexcept>

std::vector<Cars*> Service::getAll()
{
	std::vector<Cars*> res = this->repo.getAll();
	std::sort(res.begin(), res.end(), [](Cars* a, Cars* b)
		{
			return a->getName() > b->getName();
		});
	return res;
}

std::vector<Cars*> Service::getByManufacturer(std::string man)
{
	std::vector<Cars*> res;
	bool found = false;
	for (auto i : this->getAll())
		if (i->getName() == man)
		{
			res.push_back(i);
			found = true;
		}
	if (found == false)
		throw std::runtime_error("Manufacturer not found");
	else
	return res;
}

int Service::getNumberByManufacturer(std::string man)
{
	int n = 0;
	for (auto i : this->getAll())
		if (i->getName() == man)
			n++;
	if (n == 0)
		throw std::runtime_error("Manufacturer not found");
	else return n;
}
