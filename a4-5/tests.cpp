#include "tests.h"
#include <iostream>
#include <cassert>

void testDynamicArray()
{
	// AddAndAccess
	{
		DynamicArray<Event> da;

		da.daAdd(Event("A", "B", 1, 2, 3, 4, 5, 10, "L"));
		da.daAdd(Event("C", "D", 1, 2, 3, 4, 5, 10, "L"));
		da.daAdd(Event("E", "F", 1, 2, 3, 4, 5, 10, "L"));
		da.daAdd(Event("G", "H", 1, 2, 3, 4, 5, 10, "L"));

		da[0].setDuration(60);
		assert(da[0].getDuration() == 60);

		assert(da.daGetSize() == 4);
		assert(da[0].getTitle() == "A");
		assert(da[0].getDescription() == "B");
		assert(da[0].getDay() == 1);
		assert(da[0].getMonth() == 2);
		assert(da[0].getYear() == 3);
		assert(da[0].getHour() == 4);
		assert(da[0].getMinute() == 5);
		assert(da[0].getNrPeople() == 10);
		da[0].setNrPeople(20);
		assert(da[0].getNrPeople() == 20);
		assert(da[0].getLink() == "L");
	}

	// RemoveAndResize
	{
		DynamicArray<Event> da;

		for (int i = 0; i < 20; i++)
			da.daAdd(Event("X", "Y", 1, 1, 1, 1, 1, 1, "L"));

		assert(da.daGetSize() == 20);

		da.daRemove(0);
		assert(da.daGetSize() == 19);

		da.daRemove(-1);
		da.daRemove(999);
		assert(da.daGetSize() == 19);
	}

	// Operators
	{
		DynamicArray<Event> da;

		da.daAdd(Event("A", "B", 1, 2, 3, 4, 5, 10, "L"));

		da = da; 
		assert(da.daGetSize() == 1);
		assert(da[0].getTitle() == "A");

		da.daAdd(Event("C", "D", 1, 2, 3, 4, 5, 10, "L"));
		da.daAdd(Event("E", "F", 1, 2, 3, 4, 5, 10, "L"));

		Event e2 = da[1];
		da -= e2;
		assert(da.daGetSize() == 2);

		Event e3 = da[1];
		da = da - e3;
		assert(da.daGetSize() == 1);

		bool thrown = false;
		try
		{
			Event& e = da[11];
		}
		catch(std::out_of_range&)
		{
			thrown = true;
		}
		assert(thrown == true);
	}

	{
		//Sorting
		DynamicArray<Event> da;

		da.daAdd(Event("A", "B", 3, 2, 3, 4, 5, 10, "L"));
		da.daAdd(Event("C", "D", 2, 2, 3, 4, 5, 10, "L"));
		da.daAdd(Event("E", "F", 1, 2, 3, 4, 5, 10, "L"));

		da.sort([](const Event& a, const Event& b) {
			return a.getDay() < b.getDay();
			});
		assert(da[0].getTitle() == "E");
		assert(da[1].getTitle() == "C");
		assert(da[2].getTitle() == "A");
	}

	std::cout << "testDynamicArray: all tests passed\n";
}

void testAdminRepo()
{ 
	RepoAdmin repo;
	repo.repoAddAdmin(Event("A", "B", 1, 2, 3, 4, 5, 10, "L"));
	repo.repoAddAdmin(Event("C", "D", 1, 2, 3, 4, 5, 10, "L"));
	assert(repo.repoGetSizeAdmin() == 2);
	bool thrown = false;
	try
	{
		repo.repoAddAdmin(Event("A", "B", 1, 2, 3, 4, 5, 10, "L"));
	}
	catch (std::runtime_error&)
	{
		thrown = true;
	}
	assert(thrown = true);

	Event event = repo.repoGetAdmin(0);
	assert(event.getTitle() == "A");

	repo.repoRemoveAdmin(1);
	assert(repo.repoGetSizeAdmin() == 1);

	Event updated = Event("X", "Y", 1, 2, 3, 4, 5, 10, "L");
	repo.repoUpdateAdmin(0, updated);
	assert(repo.repoGetAdmin(0).getTitle() == "X");

	std::cout << "testAdminRepo: all tests passed\n";
}

void testUserRepo()
{
	RepoUser repo;
	repo.repoAddUser(Event("A", "B", 1, 2, 3, 4, 5, 10, "L"));
	assert(repo.repoGetSizeUser() == 1);
	repo.repoAddUser(Event("C", "D", 1, 2, 3, 4, 5, 10, "L"));

	bool thrown = false;
	try
	{
		repo.repoAddUser(Event("A", "B", 1, 2, 3, 4, 5, 10, "L"));
	}
	catch (std::runtime_error)
	{
		thrown = true;
	}
	assert(thrown == true);

	repo.repoRemoveUser(0);
	assert(repo.repoGetUser(0).getTitle() == "C");

	std::cout << "testUserRepo: all tests passed\n";
}

void testAdminService()
{
	RepoAdmin repo;
	ServiceAdmin serv(repo);
	Event e = Event("E", "F", 1, 2, 3, 4, 5, 10, "L");
	serv.servAddAdmin("A", "B", 1, 2, 3, 4, 5, 10, "L");
	serv.servAddAdmin("C", "D", 2, 2, 3, 4, 5, 10, "L");
	serv.servAddAdmin("E", "F", 1, 2, 3, 4, 5, 10, "L");
	assert(serv.servGetSizeAdmin() == 3);

	serv.servRemoveAdmin("A", 1, 2, 3, 4, 5);
	assert(serv.servGetEventByIndexAdmin(0).getTitle() == "E");

	assert(serv.servFindEventAdmin("E", 1, 2, 3, 4, 5) == 0);
	assert(serv.servFindAdmin(e) == 0);

	bool thrown = false;
	try
	{
		serv.servRemoveAdmin("C", 1, 2, 3, 4, 5);
	}
	catch (std::runtime_error)
	{
		thrown = true;
	}
	assert(thrown == true);

	serv.servUpdateAdmin("E", 1, 2, 3, 4, 5, Event("X", "Y", 1, 2, 3, 4, 5, 10, "L"));
	
	assert(serv.servGetEventByIndexAdmin(0).getTitle() == "X");

	thrown = false;
	try
	{
		serv.servUpdateAdmin("A", 1, 2, 3, 4, 5, Event("X", "Y", 1, 2, 3, 4, 5, 10, "L"));
	}
	catch (std::runtime_error)
	{
		thrown = true;
	}
	assert(thrown == true);


	Event e1 = Event("E", "F", 1, 2, 3, 4, 5, 10, "L");
	Event e2 = Event("y", "b", 1, 2, 3, 4, 5, 10, "L");
	Event e3 = Event("g", "w", 1, 2, 3, 4, 5, 10, "L");

	e1.setDuration(30);
	e2.setDuration(10);
	e3.setDuration(20);

	DynamicArray<Event> result = serv.filterByDuration(25);
	assert(result.daGetSize() == 2);

	std::cout << "testAdminService: all tests passed\n";
}

void testUserService()
{
	RepoAdmin repoAdmin;
	RepoUser repoUser;
	ServiceUser serv(repoAdmin, repoUser);

	Event e1 = Event("E", "F", 2, 2, 3, 4, 5, 10, "L");
	Event e2 = Event("C", "D", 3, 2, 3, 3, 7, 12, "L");
	Event e3 = Event("A", "B", 2, 2, 3, 4, 6, 9, "L");
	Event e4 = Event("X", "Y", 1, 1, 1, 1, 1, 1, "L");

	repoAdmin.repoAddAdmin(e1);
	repoAdmin.repoAddAdmin(e2);
	repoAdmin.repoAddAdmin(e3);

	serv.servAddUser(e1);

	assert(serv.servGetSizeUser() == 1);

	bool thrown = false;
	try
	{
		serv.servAddUser(e4);
	}
	catch (std::runtime_error)
	{
		thrown = true;
	}
	assert(thrown == true);

	assert(serv.servGetEventByIndexUser(0).getTitle() == "E");
	assert(serv.servFindUser(e1) == 0);

	assert(serv.servFindEventUser("E", 2, 2, 3, 4, 5) == 0);
	assert(serv.servFindEventUser("X", 2, 2, 3, 4, 5) == -1);

	serv.servAddUser(e2);
	serv.servRemoveUser("E", 2, 2, 3, 4, 5);
	assert(serv.servGetSizeUser() == 1);

	thrown = false;
	try
	{
		serv.servRemoveUser("X", 2, 2, 3, 4, 5);
	}
	catch (std::runtime_error)
	{
		thrown = true;
	}
	assert(thrown == true);

	DynamicArray<Event> da = serv.servFindEventbyMonthUser(2);
	assert(da.daGetSize() == 3);

	assert(da[0].getTitle() == "E");
	assert(da[1].getTitle() == "A");
	assert(da[2].getTitle() == "C");


	std::cout << "testUserService: all tests passed\n\n";
}

void testsAllAdmin()
{
	testDynamicArray();
	testAdminRepo();
	testUserRepo();
	testAdminService();
	testUserService();
}