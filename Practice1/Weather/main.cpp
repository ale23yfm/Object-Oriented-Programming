#include <iostream>
#include "ui.h"
using namespace std;

int main()
{
	Repo repo;
	Service serv(repo);
	UI ui(serv);

	serv.servAdd("New York", "Central Park", { "Thermometer, Barometer" });
	serv.servAdd("New York", "JFK Airport", { "Thermometer, Anemometer, Wind Vane" });
	serv.servAdd("London", "Heathrow Airport", { "Thermometer, Anemometer, Wind Vane, Hygrometer" });
	serv.servAdd("London", "Greenwich", { "Hygrometer, Rain Gauge" });
	serv.servAdd("Cluj", "Cetatuie", { "Thermometer, Barometer" });

	ui.uiRun();
	return 0;
}