#pragma once
#include "medicine.h"

typedef struct {
	medicine *items[100];
	int count;
}repo;

repo *repoInit();
int addMedicineToRepo(repo *r, medicine *m);
void deleteMedicineFromRepo(repo *r, char *name, int con);
void updateMedicineFromRepo(repo* r, char* name, int con, int price);
repo *searchForMedicinePartialName(repo* r, char *word);
repo *searchForMedicineFullName(repo* r, char *word);
void printMedicines(repo *r);