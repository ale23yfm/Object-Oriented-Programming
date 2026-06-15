#include "event.h"
#include <iostream>
#include <Windows.h>
#include <shellapi.h>

DataTime::DataTime(int day, int month, int year, int hour, int minute)
    : day(day), month(month), year(year), hour(hour), minute(minute)
{}

Event::Event(const std::string& title, const std::string& description, int day, int month, int year, int hour, int minute, int nrPeople, const std::string& link) 
    : title(title), description(description), dataTime(day, month, year, hour, minute), nrPeople(nrPeople), link(link), duration(0)
{}

void Event::play()
{
    ShellExecuteA(NULL, "open", this->getLink().c_str(), NULL, NULL, SW_SHOWMAXIMIZED);
}

std::string Event::toHTML() const
{
    std::string res = "\n<tr>";
    res += "<td>" + this->title + "</td> \n";
    res += "<td>" + this->description + "</td> \n";
    res += "<td>" + std::to_string(this->getDay()) + "/" + std::to_string(this->getMonth()) + "/" + std::to_string(this->getYear()) + "</td> \n";
    res += "<td>" + std::to_string(this->getHour()) + ":" + std::to_string(this->getMinute()) + "</td> \n";
    res += "<td>" + std::to_string(this->nrPeople) + "</td> \n";
    res += "<td><a href=\"" + this->link + "\">Link</a></td>\n"; 
    res += "</tr>\n";

    return res;
}

std::string Event::toCSV() const
{
    std::string res = this->title;
    res += "," + this->description + ",";
    res += std::to_string(this->getDay()) + "/" + std::to_string(this->getMonth()) + "/" + std::to_string(this->getYear())+ ",";
    res += std::to_string(this->getHour()) + ":" + std::to_string(this->getMinute()) + ",";
    res += std::to_string(this->nrPeople) + ",";
    res += this->link + "\n";
    return res;
}

std::string Event::toString() const
{
    std::string res;
    res += this->title + "\n" + this->description + "\n";
    res += std::to_string(this->getDay()) + " " + std::to_string(this->getMonth()) + " " + std::to_string(this->getYear()) + "\n";
    res += std::to_string(this->getHour()) + " " + std::to_string(this->getMinute()) + "\n";
    res += std::to_string(this->nrPeople) + "\n";
    res += this->link + "\n";
    res += this->duration + "\n";
    return res;
}

std::ostream& operator<<(std::ostream& stream, const Event& e)
{
    stream << e.title << "\n";
    stream << e.description << "\n";
    stream << e.getDay() << " " << e.getMonth() << " " << e.getYear() << "\n";
    stream << e.getHour() << " " << e.getMinute() << "\n";
    stream << e.nrPeople << "\n";
    stream << e.link << "\n";
    stream << e.duration << "\n";
    return stream;
}

std::istream& operator>>(std::istream& stream, Event& e)
{
    std::string title, description, link;
    int day, month, year, hour, minute, nrPeople, duration;

    std::getline(stream, title);

    if (title.empty())
        return stream;

    std::getline(stream, description);
    stream >> day >> month >> year;
    stream >> hour >> minute;
    stream >> nrPeople;
    stream.ignore();
    std::getline(stream, link);
    stream >> duration;
    stream.ignore();

    e = Event(title, description, day, month, year, hour, minute, nrPeople, link);
    e.setDuration(duration);

    return stream;
}
