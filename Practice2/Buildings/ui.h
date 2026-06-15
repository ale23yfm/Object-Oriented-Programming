#pragma once
#include "serv.h"
#include "house.h"
#include "block.h"

class UI
{
private:
	Serv serv;

public:
	UI(Serv serv) : serv(serv) {};
	void run();
	void menu();
	void uiAdd();
	void uiShow();
	void uiShowSorted();
};