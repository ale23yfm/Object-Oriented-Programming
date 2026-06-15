#include "serv.h"
#include <algorithm>
#include <stdexcept>

std::vector<Labor*> Serv::getAll()
{
	std::vector<Labor*> res = this->repo.getAll();
	std::sort(res.begin(), res.end(), [](Labor* a, Labor* b) {return a->getStart() < b->getStart(); });
	return res;
}

std::vector<Labor*> Serv::getAllbyWage(int w)
{
	std::vector<Labor*> res;
	for (auto i : this->getAll())
		if (i->getWage() > w)
			res.push_back(i);
	return res;
}

std::vector<Labor*> Serv::getAllFilter(int start, std::string coun)
{
	std::vector<Labor*> res;
	bool found = false;
	for (auto i : this->getAll())
		if (i->getCountry() == coun && i->getStart())
		{
			found = true;
			res.push_back(i);
		}
	if (found == false)
		throw std::runtime_error("Not found");
	return res;
}

int Serv::getTotal(int start, std::string coun)
{
	int total = 0;
	bool found = false;

	for (auto i : this->getAll())
		if (i->getCountry() == coun && i->getStart() == start)
		{
			found = true;
			total+=i->getPos();
}
if (found == false)
throw std::runtime_error("Not found");
	return total;
}
