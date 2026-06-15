#include "adminService.h"
#include "adminAddAction.h"
#include "adminDeleteAction.h"
#include "adminUpdateAction.h"
#include <stdexcept>
#include <algorithm>
#include <iterator>

ServiceAdmin::ServiceAdmin(RepoAdmin& repo): repo(repo)
{
}

void ServiceAdmin::servAddAdmin(const std::string& title, const std::string& description, int day, int month, int year, int hour, int minute, int nrPeople, const std::string& link)
{
	Event e{ title, description, day, month, year, hour, minute, nrPeople, link };
	Validation::validate(e);
	this->repo.repoAddAdmin(e);
	recordAction(new AddAction(*this, e));
}

void ServiceAdmin::servRemoveAdmin(const std::string& title, int day, int month, int year, int hour, int minute)
{
	int index = servFindEventAdmin(title, day, month, year, hour, minute);
	if (index == -1)
		throw RepositoryException("Event not found!");
	Event e = servGetEventByIndexAdmin(index);
	repo.repoRemoveAdmin(index);
	recordAction(new DeleteAction(*this, e));
}

void ServiceAdmin::servUpdateAdmin(const std::string& title, int day, int month, int year, int hour, int minute, const Event &newEvent)
{
	int index = servFindEventAdmin(title, day, month, year, hour, minute);
	Validation::validate(newEvent);
	if (index == -1)
		throw RepositoryException("Event not found!");
	Event e = servGetEventByIndexAdmin(index);
	repo.repoUpdateAdmin(index, newEvent);
	recordAction(new UpdateAction(*this, e,newEvent));
}

int ServiceAdmin::servGetSizeAdmin() const
{
	return repo.repoGetSizeAdmin();
}

Event& ServiceAdmin::servGetEventByIndexAdmin(int index)
{
	return repo.repoGetAdmin(index);
}

int ServiceAdmin::servFindEventAdmin(const std::string& title, int day, int month, int year, int hour, int minute)
{
	Event current{ title, "", day, month, year, hour, minute, 0, "" };
	return repo.repoFindAdmin(current);
}

int ServiceAdmin::servFindAdmin(const Event& e)
{
	return repo.repoFindAdmin(e);
}

const std::vector<Event>& ServiceAdmin::servGetAllAdmin() const
{
	return this->repo.repoGetAllAdmin();
}

std::vector<Event> ServiceAdmin::filterByDuration(int time)
{
	std::vector<Event> filtered;
	const auto& all = repo.repoGetAllAdmin();

	std::copy_if(all.begin(), all.end(), std::back_inserter(filtered), [time](const Event& e) {return e.getDuration() < time; });
	
	return filtered;
}

void ServiceAdmin::undo()
{
	if (undoStack.empty()) return;
	Action* action = undoStack.back();
	undoStack.pop_back();
	action->executeUndo();
	redoStack.push_back(action);
}

void ServiceAdmin::redo()
{
	if (redoStack.empty()) return;
	Action* action = redoStack.back();
	redoStack.pop_back();
	action->executeRedo();
	undoStack.push_back(action);
}

void ServiceAdmin::recordAction(Action* action)
{
	undoStack.push_back(action);
	redoStack.clear();
}

void ServiceAdmin::addNoRecord(const Event& e)
{
	repo.repoAddAdmin(e);
}

void ServiceAdmin::removeNoRecord(const std::string& title, int day, int month, int year, int hour, int minute)
{
	int index = servFindEventAdmin(title, day, month, year, hour, minute);
	if (index == -1)
		throw RepositoryException("Event not found!");
	repo.repoRemoveAdmin(index);
}

void ServiceAdmin::updateNoRecord(const std::string& title, int day, int month, int year, int hour, int minute, const Event& newEvent)
{
	int index = servFindEventAdmin(title, day, month, year, hour, minute);
	if (index == -1)
		throw RepositoryException("Event not found!");
	repo.repoUpdateAdmin(index, newEvent);
}
