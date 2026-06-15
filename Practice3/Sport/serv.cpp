#include "serv.h"
#include <algorithm>
#include <stdexcept>

std::vector<Sport*> Service::getAll()
{
	std::vector<Sport*> res = this->repo.getAll();
	std::sort(res.begin(), res.end(), [](Sport* a, Sport* b) {return a->getStart() < b->getStart(); });
	return res;
}

std::vector<Sport*> Service::filterByIntensity(int intLevel)
{
	std::vector<Sport*> res;
	for (auto i : this->getAll())
		if (i->getIntensity() >= intLevel)
			res.push_back(i);
	return res;
}

std::vector<Sport*> Service::filterByDesc(std::string desc, int s)
{
	std::vector<Sport*> res;
	for (auto i : this->getAll())
		if (i->getDescription() == desc && i->getStart() >= s)
			res.push_back(i);
	return res;
}

int Service::totalHours(std::string desc, int s)
{
	int total = 0;
	bool found = false;
	for (auto i : this->getAll())
		if (i->getDescription() == desc && i->getStart() >= s)
		{
			int h = i->getEnd() - i->getStart();
			total += h;
			found = true;
		}
	if (found == false)
		throw std::runtime_error("Description not found");
	else
	return total;
}
