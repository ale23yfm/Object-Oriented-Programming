#include <iostream>
#include "ui.h"

using namespace std;

int main()
{
	Repo repo;
	Service serv(repo);
	UI ui(serv);

	serv.Add(new Party("name1", "names2", 5000));
	serv.Add(new Party("name4", "names2", 1));
	serv.Add(new Alliance("name2", "name1", 10, 2));
	serv.Add(new Independent("name3", "names1", 10));

	ui.run();
	return 0;
}