#include "UI.h"
#include "dynamicArray.h"
#include <crtdbg.h>
#include <stdlib.h>

int main()
{
	testsDynamicArray();
	Repo* repo = repoCreate();
	Service* serv = servCreate(repo);

	servAddMed(serv, "Nurofen", 200, 50, 12);
	servAddMed(serv, "Nurofen forte", 400, 10, 40);
	servAddMed(serv, "Paracetamol", 200, 73, 12);
	servAddMed(serv, "Vitamina C", 250, 63, 40);
	servAddMed(serv, "Vitamina D", 50, 13, 45);
	servAddMed(serv, "Vitamina C", 200, 34, 40);
	servAddMed(serv, "Strepsils", 100, 24, 35);
	servAddMed(serv, "Sedatif", 75, 56, 26);
	servAddMed(serv, "Coldrex", 120, 33, 34);
	servAddMed(serv, "Nurofen", 150, 64, 30);

	UI* ui = createUI(serv);
	startUI(ui);
	destroyUI(ui);

	_CrtDumpMemoryLeaks();
	return 0;
}