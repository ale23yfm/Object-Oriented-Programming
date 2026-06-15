#include "service.h"
#include <stdexcept>

void Service::servAdd(const std::string& name, int age, bool infected, int room)
{
	Hospital patient{ name, age, infected, room };
	this->repo.repoAdd(patient);
}

void Service::servDelete(const std::string& name)
{
	Hospital patient{ name, 0, false, 0 };
	this->repo.repoDelete(patient);
}

DynamicArray Service::servUpdate(Hospital &infected, int minAge)
{
	DynamicArray newlist;
	int index = this->repo.repoGetIndex(infected);
	if (index == -1)
		throw std::runtime_error("The patient does not exist");
	if(infected.getInfected() == false)
		throw std::runtime_error("The patient is not infected");
	int room = infected.getRoom();

	for (int i = 0; i < repo.repoGetSize(); i++)
	{
		DynamicArray& arr = repo.repoGetArray();
		Hospital& p = arr[i];

		if (p.getRoom() == infected.getRoom() && p.getAge() >= minAge && p.getInfected() == false)
		{
			p.setInfected();
			newlist.daAdd(p);
		}
	}
	return newlist;
}

DynamicArray Service::servGetAll()
{
	DynamicArray da = this->repo.repoGetAll();
	return da;
}

Hospital Service::servGetByName(const std::string& name)
{
	Hospital current{name, 0,false, 0};
	DynamicArray da = repo.repoGetArray();
	for (int i = 0; i < repo.repoGetSize(); i++)
		if(current.getName() == da[i].getName())
			return da[i];
	throw std::runtime_error("This patient does not exist");
}

int Service::servGetSize()
{
	return repo.repoGetSize();
}

