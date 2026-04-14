#include <iostream>
#include "ui.h"
#include "tests.h"
using namespace std;

int main()
{
	{
		RepoAdmin repoAdmin;
		RepoUser repoUser;
		ServiceAdmin servAdmin(repoAdmin);
		ServiceUser servUser(repoAdmin, repoUser);
		UI ui(servAdmin, servUser);

		testsAllAdmin();
		
		//simulate memory leak
		//int* ptr = new int[10];

		servAdmin.servAddAdmin("Party", "Party for students", 12, 3, 2026, 19, 30, 352, "https://party.ro/");
		servAdmin.servAddAdmin("Meeting", "Job meeting", 2, 4, 2026, 10, 40, 124, "https://meet.ro/");
		servAdmin.servAddAdmin("TSM", "Newspaper release", 21, 5, 2026, 14, 10, 24, "https://tsm.ro/");
		servAdmin.servAddAdmin("Careers", "Careers for teens", 14, 6, 2026, 11, 20, 70, "https://careers.ro/");
		servAdmin.servAddAdmin("Green Party", "Party for students", 10, 3, 2026, 15, 30, 300, "https://greenparty.ro/");
		servAdmin.servAddAdmin("Music Festival", "Cluj", 1, 3, 2026, 19, 30, 20, "https://music.ro/");
		servAdmin.servAddAdmin("Cooking show", "Competition", 29, 5, 2026, 8, 40, 5, "https://cookingshow.ro/");
		servAdmin.servAddAdmin("IT", "IT speakers", 20, 3, 2026, 10, 10, 240, "https://it.ro/");
		servAdmin.servAddAdmin("Girls' night", "Party with friends", 22, 5, 2026, 22, 30, 10, "https://gnight.ro/");
		servAdmin.servAddAdmin("Boys' night", "Party with friends", 12, 4, 2026, 22, 30, 15, "https://bnight.ro/");

		ui.run();
	}
	_CrtDumpMemoryLeaks();
	return 0;
}