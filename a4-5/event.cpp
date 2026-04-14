#include "event.h"

DataTime::DataTime(int day, int month, int year, int hour, int minute)
    : day(day), month(month), year(year), hour(hour), minute(minute)
{}

Event::Event(const std::string& title, const std::string& description, int day, int month, int year, int hour, int minute, int nrPeople, const std::string& link) 
    : title(title), description(description), dataTime(day, month, year, hour, minute), nrPeople(nrPeople), link(link)
{}
