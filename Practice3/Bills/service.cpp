#include "service.h"
#include <algorithm>
#include <stdexcept>

std::vector<Bill*> Service::getAllSorted()
{
	std::vector<Bill*> res = this->repo.getAll();
	std::sort(res.begin(), res.end(), [](Bill* a, Bill* b) {return a->getCompanyName() < b->getCompanyName(); });
		
	return res; 
}

double Service::UnpaidBills(std::string& name)
{
	double total = 0.0;
	bool found = false;
	for (auto i : this->repo.getAll())
		if (name == i->getCompanyName())
		{
			found = true;
			if (i->getIsPaid() == false)
				total += i->getSum();
		}
	if (found == false)
		throw std::runtime_error("Company not found");
	else
		return total;
}
