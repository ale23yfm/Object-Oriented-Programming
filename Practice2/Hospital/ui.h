#pragma once
#include "service.h"
#include "surgery.h"
#include "neonatal.h"

class UI
{
private:
	Service serv;

public:
	UI(Service serv): serv(serv) {};
	void run();
	void uiMenu();
	void uiAdd();
	void uiShowAll();
	void uiShowAllEfficient();
	void uiSaveToFile();
};