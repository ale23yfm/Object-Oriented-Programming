#pragma once
#include "action.h"
#include "userRepo.h"
#include "adminRepo.h"
#include "exceptions.h"
#include "validation.h"
#include "fileEventList.h"

enum class FileType { CSV, HTML };
class ServiceAdmin;

class ServiceUser
{
private:
	RepoAdmin& adminRepo;
	RepoUser& userRepo;
	ServiceAdmin& servAdmin;
	FileEventList* fileList;
	std::vector<Action*> undoStack;
	std::vector<Action*> redoStack;

public:
	/// <summary>
	/// Service constructor
	/// </summary>
	/// <param name="repo">the repo base</param>
	ServiceUser(ServiceAdmin& servAdmin, RepoAdmin& adminRepo, RepoUser& userRepo);
	
	/// <summary>
	/// Adds an event into service
	/// </summary>
	/// <param name="e">the event to be added</param>
	void servAddUser(Event& e);

	/// <summary>
	/// Removes an event in the service
	/// </summary>
	/// <param name="title">title of the event</param>
	/// <param name="day">day of the event</param>
	/// <param name="month">month of the event</param>
	/// <param name="year">year of the event</param>
	/// <param name="hour">hour of the event</param>
	/// <param name="minute">minute of the event</param>
	void servRemoveUser(const std::string& title, int day, int month, int year, int hour, int minute);

	/// <summary>
	/// Gets the size of the array in service
	/// </summary>
	/// <returns>the size</returns>
	int servGetSizeUser() const;

	/// <summary>
	/// Gets the event by index
	/// </summary>
	/// <param name="index">the index of the wanted element</param>
	/// <returns>the element</returns>
	Event& servGetEventByIndexUser(int index);

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
	int servFindEventUser(const std::string& title, int day, int month, int year, int hour, int minute);

	std::vector<Event> servFindEventbyMonthUser(int month);

	int servFindUser(const Event& e);

	bool cmpEventChrono(const Event& a, const Event& b)
	{
		if (a.getYear() != b.getYear()) return a.getYear() < b.getYear();
		if (a.getMonth() != b.getMonth()) return a.getMonth() < b.getMonth();
		if (a.getDay() != b.getDay()) return a.getDay() < b.getDay();
		if (a.getHour() != b.getHour()) return a.getHour() < b.getHour();
		return a.getMinute() < b.getMinute();
	};

	void setFile(FileEventList* f);

	void addToFileList(const Event& e);
	void display();
	const std::vector<Event>& servGetAllUser() const;
	void undo();
	void redo();
	void recordAction(Action* action);
	void addNoRecord(const Event& e);
	void removeNoRecord(const std::string& title, int day, int month, int year, int hour, int minute);
	void updateNoRecord(const std::string& title, int day, int month, int year, int hour, int minute, const Event& newEvent);
};