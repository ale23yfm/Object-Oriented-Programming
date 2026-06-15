#pragma once
#include "service.h"
#include "party.h"
#include "alliance.h"
#include "independent.h"

class UI
{
private:
	Service serv;

public:
	UI(Service serv) : serv(serv) {};
	void run();
	void menu();
	void uiAdd();
	void uiShowAll();
	void uiShowAllParliament();
	void uiSaveToFile();
};