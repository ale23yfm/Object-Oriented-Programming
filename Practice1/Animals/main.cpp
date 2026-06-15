#include <iostream>
#include "ui.h"

using namespace std;

int main()
{
	Repo repo;
	Service serv(repo);
	UI ui(serv);

	serv.servAdd("Bella", "dog", 12, "brown");
	serv.servAdd("Max", "dog", 4, "black");
	serv.servAdd("Luna", "cat", 11, "white");
	serv.servAdd("Coco", "parrot", 2, "green");
	serv.servAdd("Rex", "dog", 15, "grey");

	ui.uiRun();
	return 0;
}