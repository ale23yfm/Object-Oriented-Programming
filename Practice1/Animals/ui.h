#pragma once
#include "service.h"

class UI
{
private:
	Service& serv;
public:
	UI(Service& serv) : serv{ serv } {}
	void uiRun();
	void uiPrintMenu();
	void uiAdd();
	void uiDelete();
	void uiPrint();
	void uiSenior();
};