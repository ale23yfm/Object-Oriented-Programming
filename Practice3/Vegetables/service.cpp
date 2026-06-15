#include "service.h"
#include <algorithm>

std::vector<Vegetables*> Service::getAll()
{
	std::vector<Vegetables*> res= this->repo.getAll(); 
	std::sort(res.begin(), res.end(), [](Vegetables* a, Vegetables* b) {return a->getFamily() < b->getFamily(); });
	return res;
}

std::vector<std::string> Service::getUniqueFamilies()
{
	std::vector<std::string> res;
	for (auto i : getAll())
	{
		std::string fname = i->getFamily();
		if (std::find(res.begin(), res.end(), fname) == res.end())
			res.push_back(fname);
	}
	std::sort(res.begin(), res.end(), [](std::string a, std::string b) {return a < b; });
	return res;
}

std::vector<Vegetables*> Service::getVegByFamily(std::string fam)
{
	std::vector<Vegetables*> res;
	for (auto i : this->getAll())
	{
		if (fam == i->getFamily())
			res.push_back(i);
	}
	return res;	
}


