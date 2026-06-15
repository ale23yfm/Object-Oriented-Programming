#pragma once
#include "service.h"

class UI
{
private:
	Service serv;

public:
	UI(Service serv) : serv(serv) {};
	void run();
	void menu();
	void uiAdd();
	void uiRemove();

	void uiShow();	
	void uiShowExpensive();
	void uiSaveToFile();	
};