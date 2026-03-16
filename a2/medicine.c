#include "medicine.h"
#include <stdlib.h>

medicine *addMedicine(char *name, int concentration, int quantity, int price)
{
	medicine *m = malloc(sizeof(medicine));
	if (m == NULL)
		return NULL;

	m->name = malloc((strlen(name)+1)*sizeof(char));
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

void deleteMedicine(medicine* m)
{
	if (m == NULL)
		return;
	free(m->name);
	free(m);
}

