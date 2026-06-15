#include <iostream>
#include "ui.h"

using namespace std;

int main()
{
	Repo repo;
	Service serv(repo);
	serv.servAdd(new Refrigerator("1", "A", true));
	serv.servAdd(new Refrigerator("2", "A++", false));
	serv.servAdd(new Refrigerator("3", "A++", true));
	serv.servAdd(new Refrigerator("4", "A", false));
	serv.servAdd(new DishWasher("5", 20));
	UI ui(serv);
	ui.run();
}