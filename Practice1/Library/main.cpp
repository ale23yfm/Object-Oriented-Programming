#include <iostream>
#include "ui.h"

using namespace std;

int main()
{
	Repo repo;
	Service serv(repo);
	UI ui(serv);

	serv.servAdd("1984", "George Orwell", 1949, "dystopian");
	serv.servAdd("Dune", "Frank Herbert", 1965, "sci-fi");
	serv.servAdd("Hamlet", "William Shakespeare", 1603, "drama");
	serv.servAdd("The Hobbit", "J.R.R.Tolkien", 1937, "fantasy");
	serv.servAdd("Foundation", "Isaac Asimov", 1951, "sci");
				
	ui.uiRun();
	return 0;
}