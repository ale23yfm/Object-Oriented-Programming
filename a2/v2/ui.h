#pragma once

#include "service.h"

typedef struct
{
	Service* serv;
} UI;

UI* createUI(Service* s);
void destroyUI(UI* ui);

void printMenu();
void uiAddMedicine(UI* ui);
void uiDeleteMedicine(UI* ui);
void uiUpdateMedicine(UI* ui);
void uiSearchFullName(UI* ui);
void uiInShortSearch(UI* ui);
void uiUndo(UI* ui);
void uiRedo(UI* ui);
void uiSearchPartialName(UI* ui);
void uiSearchByPrice(UI* ui);

void listAllMed(UI* ui);

void startUI(UI* ui);