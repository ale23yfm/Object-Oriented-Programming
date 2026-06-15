#include "service.h"

void Service::servAdd(const std::string& name, const std::string& species, int age, const std::string& color)
{
	Animals animal{ name, species, age, color };
	this->repo.repoAdd(animal);
}

void Service::servDelete(const std::string& name, const std::string& species)
{
	Animals animal{ name, species, 0, "" };
	this->repo.repoDelete(animal);
}

DynamicArray Service::servGetAllSorted()	
{
	DynamicArray da = this->repo.repoGetAll();
	for (int i = 0; i < da.daGetSize()-1; i++)
		for (int j = i+1; j < da.daGetSize(); j++)
			if (da[i].getSpecies() > da[j].getSpecies() || 
				(da[i].getSpecies() == da[j].getSpecies() && da[i].getName() > da[j].getName()))
			{
				Animals temp = da[i];
				da[i] = da[j];
				da[j] = temp;
			}
	return da;
}

DynamicArray Service::servSortByColor()
{
	DynamicArray da = this->repo.repoGetAll();
	DynamicArray copy;
	for (int i = 0; i < da.daGetSize(); i++)
			if (da[i].getAge() >= 10)
				copy.daAdd(da[i]);

	for(int i = 0; i < copy.daGetSize(); i++)
		for (int j = i + 1; j < copy.daGetSize(); j++)
			if (copy[i].getColor() > copy[j].getColor())
			{
				Animals temp = copy[i];
				copy[i] = copy[j];
				copy[j] = temp;
			}
	return copy;
}
