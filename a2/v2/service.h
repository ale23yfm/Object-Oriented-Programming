#pragma once

#include "repo.h"
#include "dynamicArray.h"

typedef struct {
	Repo* repo;
	DynamicArray* undoStack; 
	DynamicArray * redoStack;
}Service;

Service* servCreate(Repo* r);
void servDestroy(Service *serv);

int servAddMed(Service* serv, char* name, int conc, int qty, int price);
int servDeleteMed(Service* serv, char* name, int conc);
int servUpdateMed(Service* serv, char* name, int conc, int newPrice);

DynamicArray* servFullNameSearch(Service* serv, char* name);
DynamicArray* servPartialNameSearch(Service* serv, char* name);
DynamicArray* servInShortQty(Service* serv, int givenQty, int sortType);
DynamicArray* servSearchByPrice(Service* serv, int price);

int servUndo(Service* serv);
int servRedo(Service* serv);