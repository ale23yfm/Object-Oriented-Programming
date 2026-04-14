#include "medicine.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

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

void testsMedicine()
{
	// --- Test creation ---
	Medicine* m = addMedicine("Nurofen", 200, 10, 15);
	assert(m != NULL);
	assert(strcmp(getName(m), "Nurofen") == 0);
	assert(getConc(m) == 200);
	assert(getQty(m) == 10);
	assert(getPrice(m) == 15);

	// --- Test copyMedicine ---
	Medicine* c = copyMedicine(m);
	assert(c != NULL);

	// Check values
	assert(strcmp(getName(c), "Nurofen") == 0);
	assert(getConc(c) == 200);
	assert(getQty(c) == 10);
	assert(getPrice(c) == 15);

	// Ensure deep copy (different pointers)
	assert(c != m);
	assert(getName(c) != getName(m));

	// --- Test toString ---
	char buffer[200];
	toString(m, buffer, 200);

	// Should contain all fields
	assert(strstr(buffer, "Nurofen") != NULL);
	assert(strstr(buffer, "200") != NULL);
	assert(strstr(buffer, "10") != NULL);
	assert(strstr(buffer, "15") != NULL);

	// --- Test deleteMedicine ---
	deleteMedicine(m);
	deleteMedicine(c);
}