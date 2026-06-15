#pragma once
#include "service.h"
#include "dishWasher.h"
#include "refrigerator.h"

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
	void uiShowIneff();
	void uiSaveToFile();
};