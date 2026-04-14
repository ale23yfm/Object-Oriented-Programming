#include "UserService.h"
#include <stdexcept>

ServiceUser::ServiceUser(RepoAdmin& adminRepo, RepoUser& userRepo) : adminRepo{ adminRepo }, userRepo{ userRepo }
{
}

void ServiceUser::servAddUser(Event& e)
{
	int index = adminRepo.repoFindAdmin(e);
	if (index == -1)
		throw std::runtime_error("The event does not exist");
	Event updated = adminRepo.repoGetAdmin(index);
	updated.setNrPeople(updated.getNrPeople() + 1);

	adminRepo.repoUpdateAdmin(index, updated);

	userRepo.repoAddUser(updated);
	e = updated;
}

void ServiceUser::servRemoveUser(const std::string& title, int day, int month, int year, int hour, int minute)
{
	int index = servFindEventUser(title, day, month, year, hour, minute);
	if (index == -1)
		throw std::runtime_error("Event not found in user list");

	Event e = userRepo.repoGetUser(index);

	int adminIndex = adminRepo.repoFindAdmin(e);
	if (adminIndex == -1)
		throw std::runtime_error("Event not found in admin repo");

	Event update = adminRepo.repoGetAdmin(adminIndex);
	update.setNrPeople(update.getNrPeople() - 1);
	adminRepo.repoUpdateAdmin(adminIndex, update);

	userRepo.repoRemoveUser(index);
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
	for (int i = 0; i < userRepo.repoGetSizeUser(); i++)
	{
		Event e = userRepo.repoGetUser(i);
		if (e.getTitle() == title && e.getDay() == day && e.getMonth() == month && e.getYear() == year && e.getHour() == hour && e.getMinute() == minute)
			return i;
	}
	return -1;
}

DynamicArray<Event> ServiceUser::servFindEventbyMonthUser(int month)
{
	DynamicArray<Event> result;
	for (int i = 0; i < this->adminRepo.repoGetSizeAdmin(); i++)
	{
		Event current = this->adminRepo.repoGetAdmin(i);
		if (current.getMonth() == month || month == 0)
			result.daAdd(current);
	}
	result.sort([](const Event& a, const Event& b) {
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
