#include <iostream>
#include "ui.h"

using namespace std;

int main()
{
	Repo repo;
	Serv serv(repo);
	UI ui(serv);
	serv.servAdd(new House("address", 1987, "type", true));
	serv.servAdd(new House("address", 2000, "type", false));
	serv.servAdd(new Block("address", 1723, 45, 12));
	serv.servAdd(new Block("address", 1986, 1000, 0));
	ui.run();
	return 0;
}