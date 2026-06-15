#pragma once
#include "service.h"

class UI
{
private:
	Service& serv;
public:
	UI (Service& serv) : serv{serv} {}
	void printMenu();
	void run();
	void uiAdd();
	void uiDelete();
	void uiVintage();
	void uiPrint();
};