#pragma once
#include "dynamicArray.h"
#include "medicine.h"

typedef struct {
	DynamicArray*medicines;
}Repo;

Repo* repoCreate();
void repoDestroy(Repo *r);
Repo* repoCopy(Repo *r);

int repoAddMedicine(Repo* r, Medicine* m);
int repoDeleteMedicine(Repo* r, Medicine* m);
int repoUpdateMedicine(Repo* r, char* name, int concentration, int newPrice);

int repoFindPosOfMedicine(Repo * r, char* name, int concentration);
Medicine* repoFindMedAtPos(Repo * r, int pos);
int repoGetLength(Repo* r);