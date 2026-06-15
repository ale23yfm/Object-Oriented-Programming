#include <iostream>
#include "ui.h"
using namespace std;

int main()
{
	Repo repo;
	Service serv(repo);
	UI ui(serv);	

	serv.servAdd("Fiat", "Bravo", 2007, "red");
	serv.servAdd("Fiat", "Idea", 2003, "black");
	serv.servAdd("Audi", "A5", 2007, "blue");
	serv.servAdd("BMW", "Coupe", 1900, "pink");
	serv.servAdd("Ford", "Fiesta", 1976, "yellow");

	ui.run();
	return 0;
}