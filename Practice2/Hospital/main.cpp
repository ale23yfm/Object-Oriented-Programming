#include <iostream>
#include "ui.h"

using namespace std;

int main()
{
	Repo repo;
	Service serv(repo);
	UI ui(serv);

	serv.servAdd(new Surgery(12, "hospitalName", 2));
	serv.servAdd(new NeonatalUnit(12, 3, 6, "hospitalName", 2));
	serv.servAdd(new NeonatalUnit(12, 13, 6, "hospitalName", 2));
	serv.servAdd(new NeonatalUnit(12, 13, 9, "hospitalName", 9));
	ui.run();
	return 0;
}