#include "service.h"

void Service::servAdd(const std::string& menu, const std::string& name, const std::vector<std::string>& ingredients)
{
	Recipe r = { menu, name, ingredients };
	this->repo.repoAdd(r);
}

int Service::servGetSize()
{
	return this->repo.repoGetSize();
}

DynamicArray Service::servGetAll()
{
	return this->repo.repoGetAll();
}

//DynamicArray& Service::servGetByName(const std::string& name)
//{
//	Recipe r = ("", name, {""});
//	return this->repo.repoGetByName(r);
//}

