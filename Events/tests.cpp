//#include "tests.h"
//#include <iostream>
//#include <cassert>
//
//void testAdminRepo()
//{ 
//	RepoAdmin repo;
//	repo.repoAddAdmin(Event("A", "B", 1, 2, 3, 4, 5, 10, "L"));
//	repo.repoAddAdmin(Event("C", "D", 1, 2, 3, 4, 5, 10, "L"));
//	assert(repo.repoGetSizeAdmin() == 2);
//	bool thrown = false;
//	try
//	{
//		repo.repoAddAdmin(Event("A", "B", 1, 2, 3, 4, 5, 10, "L"));
//	}
//	catch (std::runtime_error&)
//	{
//		thrown = true;
//	}
//	assert(thrown = true);
//
//	Event event = repo.repoGetAdmin(0);
//	assert(event.getLink() == "L");
//
//	repo.repoRemoveAdmin(1);
//	assert(repo.repoGetSizeAdmin() == 1);
//
//	Event updated = Event("X", "Y", 1, 2, 3, 4, 5, 10, "L");
//	repo.repoUpdateAdmin(0, updated);
//	assert(repo.repoGetAdmin(0).getTitle() == "X");
//
//	std::cout << "testAdminRepo: all tests passed\n";
//}
//
//void testUserRepo()
//{
//	RepoUser repo;
//	repo.repoAddUser(Event("A", "B", 1, 2, 3, 4, 5, 10, "L"));
//	assert(repo.repoGetSizeUser() == 1);
//	repo.repoAddUser(Event("C", "D", 1, 2, 3, 4, 5, 10, "L"));
//
//	bool thrown = false;
//	try
//	{
//		repo.repoAddUser(Event("A", "B", 1, 2, 3, 4, 5, 10, "L"));
//	}
//	catch (std::runtime_error)
//	{
//		thrown = true;
//	}
//	assert(thrown == true);
//
//	repo.repoRemoveUser(0);
//	assert(repo.repoGetUser(0).getDescription() == "D");
//
//	std::cout << "testUserRepo: all tests passed\n";
//}
//
//void testAdminService()
//{
//	RepoAdmin repo;
//	ServiceAdmin serv(repo);
//	Event e = Event("E", "F", 1, 2, 3, 4, 5, 10, "L");
//	serv.servAddAdmin("A", "B", 1, 2, 3, 4, 5, 10, "L");
//	serv.servAddAdmin("C", "D", 2, 2, 3, 4, 5, 10, "L");
//	serv.servAddAdmin("E", "F", 1, 2, 3, 4, 5, 10, "L");
//	assert(serv.servGetSizeAdmin() == 3);
//
//	serv.servRemoveAdmin("A", 1, 2, 3, 4, 5);
//	assert(serv.servGetEventByIndexAdmin(0).getTitle() == "C");
//
//	assert(serv.servFindEventAdmin("C", 2, 2, 3, 4, 5) == 0);
//	assert(serv.servFindAdmin(e) == 1);
//
//	bool thrown = false;
//	try
//	{
//		serv.servRemoveAdmin("C", 1, 2, 3, 4, 5);
//	}
//	catch (std::runtime_error)
//	{
//		thrown = true;
//	}
//	assert(thrown == true);
//
//	serv.servUpdateAdmin("C", 2, 2, 3, 4, 5, Event("X", "Y", 1, 2, 3, 4, 5, 10, "L"));
//	
//	assert(serv.servGetEventByIndexAdmin(0).getTitle() == "X");
//
//	thrown = false;
//	try
//	{
//		serv.servUpdateAdmin("A", 1, 2, 3, 4, 5, Event("X", "Y", 1, 2, 3, 4, 5, 10, "L"));
//	}
//	catch (std::runtime_error)
//	{
//		thrown = true;
//	}
//	assert(thrown == true);
//
//	repo.repoGetAdmin(0).setDuration(30);
//	repo.repoGetAdmin(1).setDuration(10);
//
//	std::vector<Event> result = serv.filterByDuration(25);
//	assert(result.size() == 1);
//
//	std::cout << "testAdminService: all tests passed\n";
//}
//
//void testUserService()
//{
//	RepoAdmin repoAdmin;
//	RepoUser repoUser;
//	ServiceUser serv(repoAdmin, repoUser);
//
//	Event e1 = Event("E", "F", 2, 2, 3, 4, 5, 10, "L");
//	Event e2 = Event("C", "D", 3, 2, 3, 3, 7, 12, "L");
//	Event e3 = Event("A", "B", 2, 2, 3, 4, 6, 9, "L");
//	Event e4 = Event("X", "Y", 1, 1, 1, 1, 1, 1, "L");
//
//	repoAdmin.repoAddAdmin(e1);
//	repoAdmin.repoAddAdmin(e2);
//	repoAdmin.repoAddAdmin(e3);
//
//	serv.servAddUser(e1);
//
//	assert(serv.servGetSizeUser() == 1);
//
//	bool thrown = false;
//	try
//	{
//		serv.servAddUser(e4);
//	}
//	catch (std::runtime_error)
//	{
//		thrown = true;
//	}
//	assert(thrown == true);
//
//	assert(serv.servGetEventByIndexUser(0).getTitle() == "E");
//	assert(serv.servFindUser(e1) == 0);
//
//	assert(serv.servFindEventUser("E", 2, 2, 3, 4, 5) == 0);
//	assert(serv.servFindEventUser("X", 2, 2, 3, 4, 5) == -1);
//
//	serv.servAddUser(e2);
//	serv.servRemoveUser("E", 2, 2, 3, 4, 5);
//	assert(serv.servGetSizeUser() == 1);
//
//	thrown = false;
//	try
//	{
//		serv.servRemoveUser("X", 2, 2, 3, 4, 5);
//	}
//	catch (std::runtime_error)
//	{
//		thrown = true;
//	}
//	assert(thrown == true);
//
//	std::vector<Event> event = serv.servFindEventbyMonthUser(2);
//	assert(event.size() == 3);
//
//	std::cout << "testUserService: all tests passed\n\n";
//}
//
//void testsAllAdmin()
//{
//	testAdminRepo();
//	testUserRepo();
//	testAdminService();
//	testUserService();
//}