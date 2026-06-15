#include <iostream>
#include "ui.h"
#include "tests.h"

using namespace std;

int main()
{
	Repo repo;
	Service serv(repo);
	UI ui(serv);

	testRepo();
	testService();

	serv.servAdd("Jessica_Thompson", 42, false, 3);
	serv.servAdd("Lidia_Aspen", 30, true, 3);
	serv.servAdd("Scott_Smith", 86, false, 2);
	serv.servAdd("Zene_Hardy", 37, true, 2);
	serv.servAdd("Andrew_Scott", 62, false, 2);

	ui.uiRun();
	return 0;
}