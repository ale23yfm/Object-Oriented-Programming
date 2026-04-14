#pragma once
#include "adminRepo.h"

class ServiceAdmin
{
private:
	RepoAdmin& repo;

public:
	/// <summary>
	/// Service constructor
	/// </summary>
	/// <param name="repo">the repo base</param>
	ServiceAdmin(RepoAdmin& repo);

	/// <summary>
	/// Adds an event into service
	/// </summary>
	/// <param name="title">title of the event</param>
	/// <param name="description">description of the event</param>
	/// <param name="day">day of the event</param>
	/// <param name="month">month of the event</param>
	/// <param name="year">year of the event</param>
	/// <param name="hour">hour of the event</param>
	/// <param name="minute">minute of the event</param>
	/// <param name="nrPeople">no of people at the event</param>
	/// <param name="link">link of the event</param>
	void servAddAdmin(const std::string& title, const std::string& description, int day, int month, int year, int hour, int minute, int nrPeople, const std::string& link);
	
	/// <summary>
	/// Removes an event in the service
	/// </summary>
	/// <param name="title">title of the event</param>
	/// <param name="day">day of the event</param>
	/// <param name="month">month of the event</param>
	/// <param name="year">year of the event</param>
	/// <param name="hour">hour of the event</param>
	/// <param name="minute">minute of the event</param>
	void servRemoveAdmin(const std::string& title, int day, int month, int year, int hour, int minute);

	/// <summary>
	/// Updates an event
	/// </summary>
	/// <param name="title">title of the event</param>
	/// <param name="day">day of the event</param>
	/// <param name="month">month of the event</param>
	/// <param name="year">year of the event</param>
	/// <param name="hour">hour of the event</param>
	/// <param name="minute">minute of the event</param>
	/// <param name="newEvent">the event with the new information</param>
	void servUpdateAdmin(const std::string& title, int day, int month, int year, int hour, int minute, const Event& newEvent);

	/// <summary>
	/// Gets the size of the array in service
	/// </summary>
	/// <returns>the size</returns>
	int servGetSizeAdmin() const;

	/// <summary>
	/// Gets the event by index
	/// </summary>
	/// <param name="index">the index of the wanted element</param>
	/// <returns>the element</returns>
	Event& servGetEventByIndexAdmin(int index);

	/// <summary>
	/// Returns the event
	/// </summary>
	/// <param name="title">title of the event</param>
	/// <param name="day">day of the event</param>
	/// <param name="month">month of the event</param>
	/// <param name="year">year of the event</param>
	/// <param name="hour">hour of the event</param>
	/// <param name="minute">minute of the event</param>
	/// <returns>the event</returns>
	int servFindEventAdmin(const std::string& title, int day, int month, int year, int hour, int minute);
	int servFindAdmin(const Event& e);
	DynamicArray<Event> filterByDuration(int time);
};