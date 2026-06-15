#include "service.h"

DynamicArray Service::servGetAll()
{
	return this->repo.repoGetAll();
}

std::map<std::string, int> Service::servGetAllBySenzor(const std::string& senzor)
{
	std::map<std::string, int> result;
	DynamicArray da = this->repo.repoGetAll();

	for (int i = 0; i < da.daGetSize(); i++)
	{
		Weather& w = da[i];
		if (w.hasSenzor(senzor))
			result[w.getLocation()]++;
	}
	return result;
}

void Service::servAdd(const std::string &location, const std::string &name, const std::vector<std::string>& senzors)
{
	Weather weather{ location, name, senzors };
	this->repo.repoAdd(weather);
}
