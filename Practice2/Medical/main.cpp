#include <iostream>
#include "ui.h"
#include "bmi.h"
#include "bp.h"

using namespace std;

int main()
{
	Repo repo;
	Service serv(repo);
	serv.servAdd(new BMI("2026.05.12", 20));
	serv.servAdd(new BMI("2026.05.22", 17));
	serv.servAdd(new BP("2026.04.22", 91, 58));
	serv.servAdd(new BP("2026.03.22", 91, 70));
	serv.servAdd(new BP("2026.03.02", 81, 70));
	UI ui(serv);
	ui.run();
	return 0;
}