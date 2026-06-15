#include <iostream>
#include <assert.h>
#include "ui.h"

using namespace std;

void testRepo()
{
	Repo repo;
	std::string menu = "menu";
	std::string name = "name";
	std::vector<std::string> ingredients = { "a, b" };
	Recipe r(menu, name, ingredients);
	repo.repoAdd(r);
	assert(repo.repoGetSize() == 1);
	cout << "All s good in repo.\n";
}

void testService()
{
	Repo repo;
	Service serv(repo); 
	serv.servAdd("breakfast", "oat boal", { "oat", "milk", "honey" });
	assert(serv.servGetSize() == 1);
	cout << "All s good in service.\n";
}

int main()
{
	Repo repo;
	Service serv(repo);
	UI ui(serv);

	testRepo();
	testService();

	serv.servAdd("breakfast", "oat boal", { "oat", "milk", "honey" });
	serv.servAdd("lunch", "appetizer", { "cheese", "parsley" });
	serv.servAdd("lunch", "soup", { "meat", "carrot", "parsley", "onion" });
	serv.servAdd("dinner", "stake", { "meat", "salt", "pepper" });
	serv.servAdd("dinner", "boiled rice", { "rice", "salt", "water" });
	serv.servAdd("dinner", "appetizer", { "cheese", "bacon", "eggs" });

	ui.uiRun();
	return 0;
}