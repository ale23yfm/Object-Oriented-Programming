#include "medicine.h"
#include <stdlib.h>
#include <stdio.h>

Medicine* addMedicine(char* name, int concentration, int quantity, int price)
{
	Medicine* m = malloc(sizeof(Medicine));
	if (m == NULL)
		return NULL;

	m->name = malloc((strlen(name) + 1) * sizeof(char));
	if (m->name == NULL)
	{
		free(m);
		return NULL;
	}

	m->concentration = concentration;
	m->quantity = quantity;
	m->price = price;
	strcpy_s(m->name, strlen(name) + 1, name);
	return m;
}

void deleteMedicine(Medicine* m)
{
	if (m == NULL)
		return;
	free(m->name);
	free(m);
}

Medicine* copyMedicine(Medicine* m)
{
	if (m == NULL)
		return NULL;
	Medicine* newMed = addMedicine(getName(m), getConc(m), getQty(m), getPrice(m));
	return newMed;
}

char* getName(Medicine* m)
{
	if (m == NULL)
		return NULL;
	return m->name;
}

int getConc(Medicine* m)
{
	if (m == NULL)
		return -1;
	return m->concentration;
}

int getQty(Medicine* m)
{
	if (m == NULL)
		return -1;
	return m->quantity;
}

int getPrice(Medicine* m)
{
	if (m == NULL)
		return -1;
	return m->price;
}

void toString(Medicine* m, char str[], int maxSize)
{
	if (m == NULL)
		return;
	sprintf_s(str, maxSize, "name: %s | concentration: %d | quantity: %d | price: %d ", m->name, m->concentration, m->quantity, m->price);
}