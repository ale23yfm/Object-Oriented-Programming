#include "repo.h"
#include <stdlib.h>
#include <stdio.h>

repo *repoInit()
{
	repo* r = malloc(sizeof(repo));
	if (r == NULL)
		return NULL;
	r->count = 0;
	for (int i = 0; i < 100; i++)
		r->items[i] = NULL;
	return r;
}

int addMedicineToRepo(repo *r, medicine *m)
{
	for (int i = 0; i < r->count; i++)
		if ((strcmp(r->items[i]->name, m->name) == 0) && (r->items[i]->concentration == m->concentration))
		{
			r->items[i]->quantity += m->quantity;
			deleteMedicine(m);
			return 0;
		}
	
	if (r->count >= 100) 
		return -1;

	r->items[r->count] = m;
	r->count++;
	return 1;
}

void deleteMedicineFromRepo(repo *r, char *name, int con)
{
	int index = -1;
	for (int i = 0; i < r->count; i++)
		if ((strcmp(r->items[i]->name, name) == 0) && (r->items[i]->concentration == con))
		{
			index = i;
			i = r->count;
		}

	if (index != -1)
	{
		deleteMedicine(r->items[index]);
		for (int i = index; i < r->count-1; i++)
			r->items[i] = r->items[i + 1];
		r->count--;
	}
}

void updateMedicineFromRepo(repo* r, char* name, int con, int price)
{
	int index = -1;
	for (int i = 0; i < r->count; i++)
		if ((strcmp(r->items[i]->name, name) == 0) && (r->items[i]->concentration == con))
			r->items[i]->price = price;
}

repo* searchForMedicinePartialName(repo* r, char* word)
{
	repo* found = repoInit();
	for (int i = 0; i < r->count; i++)
		if (strstr(r->items[i]->name, word) != NULL)
		{
			found->items[found->count] = r->items[i];
			found->count++;
		}
	return found;
}

repo *searchForMedicineFullName(repo *r, char* word)
{
	repo *found = repoInit();
	for (int i = 0; i < r->count; i++)
		if (strcmp(r->items[i]->name, word) == 0)
		{
			found->items[found->count] = r->items[i];
			found->count++;
		}
	return found;
}

void printMedicines(repo* r)
{
	for (int i = 0; i < r->count; i++)
	{
		medicine* m = r->items[i];
		if (m)
			printf("Name: %s | Concentration: %d | Quantity: %d | Price: %d\n", m->name, m->concentration, m->quantity, m->price);
	}
}

void destroyRepo(repo* r)
{
	if (r == NULL)
		return;
	for (int i = 0; i < r->count; i++)
		deleteMedicine(r->items[i]);
	free(r);
}
