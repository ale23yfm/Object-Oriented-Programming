#include "Service.h"

void Service::addEvent(std::string organiser, std::string name, std::string desc, std::string date, float latit, float longit)
{
	for (auto i : this->getEvs())
		if (i->getName() == name && i->getLongit() == longit && i->getLatit() == latit)
			throw std::runtime_error("Event already exists!");
	this->repo.addEvent(organiser, name, desc, date, latit, longit);
	notify();
}

void Service::updateEvent(std::string organiser, std::string name, float latit, float longit, std::string newDesc = "", std::string newDate = "")
{
	for (auto i : this->getEvs())
	{
		if (i->getName() != name && i->getLongit() != longit && i->getLatit() != latit)
			throw std::runtime_error("Event does not exist!");
		if (newDate != "")
			i->setDate(newDate);
		if (newDesc != "")
			i->setDate(newDesc);
	}
	notify();
}