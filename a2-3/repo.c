#include "repo.h"
#include "medicine.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

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

void testsRepo()
{
	// --- Test repoCreate ---
	Repo* r = repoCreate();
	assert(r != NULL);
	assert(repoGetLength(r) == 0);

	// --- Test repoAddMedicine (new medicine) ---
	Medicine* m1 = addMedicine("Nurofen", 200, 10, 15);
	int res = repoAddMedicine(r, m1);
	assert(res == 1);
	assert(repoGetLength(r) == 1);

	// Check stored medicine
	Medicine* stored = repoFindMedAtPos(r, 0);
	assert(strcmp(getName(stored), "Nurofen") == 0);
	assert(getConc(stored) == 200);
	assert(getQty(stored) == 10);
	assert(getPrice(stored) == 15);

	// --- Test repoAddMedicine (merge quantity) ---
	Medicine* m2 = addMedicine("Nurofen", 200, 5, 15);
	res = repoAddMedicine(r, m2);
	assert(res == 2);
	assert(repoGetLength(r) == 1);
	assert(getQty(stored) == 15); // 10 + 5

	// --- Test repoFindPosOfMedicine ---
	int pos = repoFindPosOfMedicine(r, "Nurofen", 200);
	assert(pos == 0);

	pos = repoFindPosOfMedicine(r, "Paracetamol", 500);
	assert(pos == -1);

	// --- Test repoUpdateMedicine ---
	res = repoUpdateMedicine(r, "Nurofen", 200, 30);
	assert(res == 1);
	assert(getPrice(stored) == 30);

	// --- Test repoDeleteMedicine ---
	Medicine* fake = addMedicine("Nurofen", 200, 0, 0);
	res = repoDeleteMedicine(r, fake);
	assert(res == 1);
	assert(repoGetLength(r) == 0);
	deleteMedicine(fake);

	// --- Test repoCopy ---
	repoAddMedicine(r, addMedicine("Aspirin", 100, 20, 10));
	repoAddMedicine(r, addMedicine("Strepsils", 50, 15, 12));

	Repo* copy = repoCopy(r);
	assert(repoGetLength(copy) == 2);

	Medicine* c0 = repoFindMedAtPos(copy, 0);
	Medicine* o0 = repoFindMedAtPos(r, 0);
	assert(strcmp(getName(c0), getName(o0)) == 0);
	assert(c0 != o0); // deep copy

	Medicine* c1 = repoFindMedAtPos(copy, 1);
	Medicine* o1 = repoFindMedAtPos(r, 1);
	assert(strcmp(getName(c1), getName(o1)) == 0);
	assert(c1 != o1);

	// --- Cleanup ---
	repoDestroy(r);
	repoDestroy(copy);
}
