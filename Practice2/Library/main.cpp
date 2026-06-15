#include <iostream>
#include "ui.h"
#include "book.h"
#include "fiction.h"

using namespace std;

int main()
{
	Repo repo;
	Service serv(repo);
	UI ui(serv);
	serv.servAdd(new Book("isbn1", 2000));
	serv.servAdd(new Fiction("licensePlate2", 1982, 3000, "cargoType1"));
	ui.run();
	return 0;
}