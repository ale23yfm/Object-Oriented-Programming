#include "repo.h"
#include "medicine.h"
#include <stdlib.h>
#include <string.h>

Repo* repoCreate()
{
	Repo* r = malloc(sizeof(Repo));
	if (r == NULL)
		return NULL;
	r->medicines = createDynamicArray(CAPACITY, &deleteMedicine);
	return r;
}

void repoDestroy(Repo* r)
{
	if (r == NULL)
		return;
	destroy(r->medicines);
	free(r);
}

Repo* repoCopy(Repo* r)
{
	Repo* newRepo = repoCreate();
	for (int i = 0; i < repoGetLength(r); i++)
	{
		Medicine* m = repoFindMedAtPos(r, i);
		Medicine* copy = copyMedicine(m);
		repoAddMedicine(newRepo, copy);
	}
	return newRepo;
}

int repoAddMedicine(Repo* r, Medicine* m)
{
	if (r == NULL || m == NULL)
		return -1;
	int pos = repoFindPosOfMedicine(r, getName(m), getConc(m));
	if (pos == -1)
	{
		addElement(r->medicines, m);
		return 1;
	}
	else
	{
		Medicine* med = (Medicine*)get(r->medicines, pos);
		med->quantity += m->quantity;
		deleteMedicine(m);
		return 2;
	}
}

int repoDeleteMedicine(Repo* r, Medicine* m)
{
	if (r == NULL || m == NULL)
		return -1;
	int pos = repoFindPosOfMedicine(r, getName(m), getConc(m));
	if (pos == -1)
		return -1;
	
	deleteElement(r->medicines, pos);
	return 1;
}

int repoUpdateMedicine(Repo* r, char* name, int concentration, int newPrice)
{
	if (r == NULL)
		return -1;

	int pos = repoFindPosOfMedicine(r, name, concentration);
	if (pos == -1)
		return -1;

	Medicine* m = (Medicine*)get(r->medicines, pos);
	m->price = newPrice;
	return 1;
}

int repoFindPosOfMedicine(Repo* r, char* name, int concentration) 
{
	for (int i = 0; i < getLength(r->medicines); i++)
	{
		Medicine* m = (Medicine*)get(r->medicines, i);
		if (strcmp(name, getName(m)) == 0 && concentration == getConc(m))
			return i;
	}
	return -1;
}

Medicine* repoFindMedAtPos(Repo* r, int pos)
{
	return (Medicine*)get(r->medicines, pos);
}

int repoGetLength(Repo* r)
{
	return getLength(r->medicines);
}