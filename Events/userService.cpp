#include "userService.h"
#include "userAddAction.h"
#include "userDeleteAction.h"
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include "adminService.h"

ServiceUser::ServiceUser(ServiceAdmin& servAdmin, RepoAdmin& adminRepo, RepoUser& userRepo) : servAdmin{ servAdmin }, adminRepo{ adminRepo }, userRepo{ userRepo }, fileList{ nullptr }
{
}

void ServiceUser::servAddUser(Event& e)
{
	int index = adminRepo.repoFindAdmin(e);
	Validation::validate(e);
	if (index == -1)
		throw RepositoryException("The event does not exist");
	Event updated = adminRepo.repoGetAdmin(index);
	updated.setNrPeople(updated.getNrPeople() + 1);

	adminRepo.repoUpdateAdmin(index, updated);

	userRepo.repoAddUser(updated);
	e = updated;

	recordAction(new AddActionUser(servAdmin, *this, updated));
}

void ServiceUser::servRemoveUser(const std::string& title, int day, int month, int year, int hour, int minute)
{
	int index = servFindEventUser(title, day, month, year, hour, minute);
	if (index == -1)
		throw RepositoryException("Event not found in user list");

	Event e = userRepo.repoGetUser(index);
	Validation::validate(e);

	int adminIndex = adminRepo.repoFindAdmin(e);
	if (adminIndex == -1)
		throw RepositoryException("Event not found in admin repo");

	Event update = adminRepo.repoGetAdmin(adminIndex);
	update.setNrPeople(update.getNrPeople() - 1);
	adminRepo.repoUpdateAdmin(adminIndex, update);

	userRepo.repoRemoveUser(index);
	recordAction(new DeleteActionUser(servAdmin, *this, e));

}

int ServiceUser::servGetSizeUser() const
{
	return userRepo.repoGetSizeUser();
}

Event& ServiceUser::servGetEventByIndexUser(int index)
{
	return userRepo.repoGetUser(index);
}

int ServiceUser::servFindEventUser(const std::string& title, int day, int month, int year, int hour, int minute)
{
	const auto& all = userRepo.repoGetAllUser();

	auto it = std::find_if(all.begin(), all.end(), [&](const Event& e)
		{
			return e.getTitle() == title &&
				e.getDay() == day &&
				e.getMonth() == month &&
				e.getYear() == year &&
				e.getHour() == hour &&
				e.getMinute() == minute;
		});
	
	if (it == all.end())
		return -1;
	return it - all.begin();
}

std::vector<Event> ServiceUser::servFindEventbyMonthUser(int month)
{
	std::vector<Event> result;
	
	const auto& all = adminRepo.repoGetAllAdmin();

	std::copy_if(all.begin(), all.end(), std::back_inserter(result), [month](const Event& e) {
		return e.getMonth() == month || month == 0;
		});
	std::sort(result.begin(), result.end(), [](const Event& a, const Event& b) {
		if (a.getYear() != b.getYear()) return a.getYear() < b.getYear();
		if (a.getMonth() != b.getMonth()) return a.getMonth() < b.getMonth();
		if (a.getDay() != b.getDay()) return a.getDay() < b.getDay();
		if (a.getHour() != b.getHour()) return a.getHour() < b.getHour();
		return a.getMinute() < b.getMinute();
		});	

	return result;
}

int ServiceUser::servFindUser(const Event& e)
{
	return userRepo.repoFindUser(e);
}

void ServiceUser::setFile(FileEventList* f)
{
	this->fileList = f;
}

void ServiceUser::addToFileList(const Event& e)
{
	if (this->fileList == nullptr)
		return;
	this->fileList->add(e);
	this->fileList->writeToFile();
}

void ServiceUser::display()
{
	if (this->fileList == nullptr)
		return;
	this->fileList->display();	
}

const std::vector<Event>& ServiceUser::servGetAllUser() const
{
	return this->userRepo.repoGetAllUser();
}

void ServiceUser::undo()
{
	if (undoStack.empty()) return;
	Action* action = undoStack.back();
	undoStack.pop_back();
	action->executeUndo();
	redoStack.push_back(action);
}

void ServiceUser::redo()
{
	if (redoStack.empty()) return;
	Action* action = redoStack.back();
	redoStack.pop_back();
	action->executeRedo();
	undoStack.push_back(action);
}

void ServiceUser::recordAction(Action* action)
{
	undoStack.push_back(action);
	redoStack.clear();
}

void ServiceUser::addNoRecord(const Event& e)
{
	userRepo.repoAddUser(e);
	Event newEvent = Event{e.getTitle(), e.getDescription(), e.getDay(), e.getMonth(), e.getYear(), e.getHour(), e.getMinute(), e.getNrPeople()+1, e.getLink()};
	servAdmin.servUpdateAdmin(e.getTitle(),e.getDay(), e.getMonth(), e.getYear(), e.getHour(), e.getMinute(), newEvent);
}

void ServiceUser::removeNoRecord(const std::string& title, int day, int month, int year, int hour, int minute)
{
	int index = servFindEventUser(title, day, month, year, hour, minute);

	Event e = userRepo.repoGetUser(index);
	Validation::validate(e);

	int adminIndex = adminRepo.repoFindAdmin(e);
	if (adminIndex == -1)
		throw RepositoryException("Event not found in admin repo");

	Event newEvent = Event{ e.getTitle(), e.getDescription(), e.getDay(), e.getMonth(), e.getYear(), e.getHour(), e.getMinute(), e.getNrPeople() - 1, e.getLink() };
	servAdmin.servUpdateAdmin(e.getTitle(), e.getDay(), e.getMonth(), e.getYear(), e.getHour(), e.getMinute(), newEvent);

	if (index == -1)
		throw RepositoryException("Event not found!");
	userRepo.repoRemoveUser(index);
}