#include "service.h"
#include <iostream>
void Service::servAdd(const std::string& name, const std::string& model, int year, const std::string& color)
{
	Cars car{ name, model, year, color };
	this->repo.repoAdd(car);
}

void Service::servDelete(const std::string& model, int year)
{
	Cars car{ "", model, year, "" };
	this->repo.repoDelete(car);
}

int Service::servGetSize() const
{
	return this->repo.repoGetSize();
}

Cars Service::servFindByIndex(int index)
{
	return this->repo.repoFindByIndex(index);
}

DynamicArray Service::servGetAllSorted()
{
	DynamicArray cars = this->repo.repoGetAll();

	for (int i = 0; i < cars.daGetSize()-1; i++)
		for (int j = i+1; j < cars.daGetSize(); j++)
		{
			if ((cars[i].getName() > cars[j].getName()) || 
				(cars[i].getName() == cars[j].getName() && cars[i].getModel() > cars[j].getModel()))
			{
				Cars temp = cars[i];
				cars[i] = cars[j];
				cars[j] = temp;
			}
		}

	return cars;
}

DynamicArray Service::servGetVintage()
{
	DynamicArray cars = this->repo.repoGetAll();
	DynamicArray vintage;

	for (int i = 0; i < cars.daGetSize(); i++)
		if (2026 - cars[i].getYear() > 45)
			vintage.daAdd(cars[i]);

	for (int i = 0; i < vintage.daGetSize()-1; i++)
		for (int j = 0; j < vintage.daGetSize(); j++)
			if (vintage[i].getColor() > vintage[j].getColor())
			{
				Cars temp = vintage[i];
				vintage[i] = vintage[j];
				vintage[j] = temp;
			}

	return vintage;
}