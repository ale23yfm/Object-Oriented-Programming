#include "service.h"

DynamicArray Service::servGetAllSorted()
{
	DynamicArray da = this->repo.repoGetAll();
	for (int i = 0; i < da.daGetSize()-1; i++)
		for (int j = i + 1; j < da.daGetSize(); j++)
			if (da[i].getAuthor() > da[j].getAuthor() || (da[i].getAuthor() == da[j].getAuthor() && da[i].getTitle() > da[j].getTitle()))
			{
				Books temp = da[i];
				da[i] = da[j];
				da[j] = temp;
			}
	return da;
}

DynamicArray Service::servGetClassic()
{
	DynamicArray da = this->repo.repoGetAll();
	DynamicArray classic;
	for (int i = 0; i < da.daGetSize(); i++)
		if (2026 - da[i].getYear() > 45)
			classic.daAdd(da[i]);
	for (int i  = 0; i < classic.daGetSize()-1; i++)
		for (int j  = i + 1; j < classic.daGetSize(); j++)
			if (classic[i].getGenre() > classic[i].getGenre())
			{
				Books temp = classic[i];
				classic[i] = classic[j];
				classic[j] = temp;
			}
	return classic;
}

void Service::servAdd(const std::string& title, const std::string& author, int year, const std::string& genre)
{
	Books book{title, author, year, genre};
	this->repo.repoAdd(book);
}

void Service::servDelete(const std::string& title, const std::string& author)
{
	Books book{ title, author, 0, "" };
	this->repo.repoDelete(book);
}

