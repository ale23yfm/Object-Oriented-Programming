#pragma once
#include <string>

class DataTime
{
private:
	int day;
	int month;
	int year;
	int hour;
	int minute;

public:
	DataTime(int day=1, int month=1, int year=2026, int hour = 0, int minute = 0);
	int getDay() const { return day; }
	int getMonth() const { return month; }
	int getYear() const { return year; }
	int getHour() const { return hour; }
	int getMinute() const { return minute; }
};

class Event
{
private:
	std::string title;
	std::string description;
	DataTime dataTime;
	int nrPeople;
	std::string link;

	int duration;

public:
	Event(const std::string& title = "", const std::string& description = "", int day = 1, int month = 1, int year = 2026, int hour = 0, int minute = 0, int nrPeople = 0, const std::string& link = "");

	std::string getTitle() const { return title; }
	std::string getDescription() const { return description; }
	int getDay() const { return dataTime.getDay(); }
	int getMonth() const { return dataTime.getMonth(); }
	int getYear() const { return dataTime.getYear(); }
	int getHour() const { return dataTime.getHour(); }
	int getMinute() const { return dataTime.getMinute(); }
	int getNrPeople() const { return nrPeople; }
	void setDuration(int newDuration) { this->duration = newDuration; }
	void setNrPeople(int newNrPeople) { this->nrPeople = newNrPeople; }
	int getDuration() const { return duration; }
	std::string getLink() const { return link; }

	inline bool operator==(const Event& other) const
	{
		return this->title == other.title &&
			this->dataTime.getDay() == other.dataTime.getDay() &&
			this->dataTime.getMonth() == other.dataTime.getMonth() &&
			this->dataTime.getYear() == other.dataTime.getYear() &&
			this->dataTime.getHour() == other.dataTime.getHour() &&
			this->dataTime.getMinute() == other.dataTime.getMinute();
	}

	bool operator<(int time) const
	{
		return this->duration < time;
	}
};