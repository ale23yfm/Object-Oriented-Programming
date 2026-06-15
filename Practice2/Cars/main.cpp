#include <iostream>
#include "ui.h"
#include "truck.h"
#include "car.h"

using namespace std;

int main()
{
	Repo repo;
	Service serv(repo);
	UI ui(serv);
	serv.servAdd(new Car("licensePlate1", 2000, 2, true));
	serv.servAdd(new Truck("licensePlate2", 1982, 3000, "cargoType1"));
	ui.run();
	return 0;
}