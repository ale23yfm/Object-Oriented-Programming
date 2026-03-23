#include "service.h"
#include "medicine.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

Service* servCreate(Repo* r)
{
	Service* serv = malloc(sizeof(Service));
	if (serv == NULL)
		return NULL;

	serv->repo = r;
	serv->undoStack = createDynamicArray(CAPACITY, &repoDestroy);
	serv->redoStack = createDynamicArray(CAPACITY, &repoDestroy);

	return serv;
}

void servDestroy(Service* serv)
{
	if (serv == NULL)
		return;
	repoDestroy(serv->repo);
	destroy(serv->undoStack);
	destroy(serv->redoStack);
	free(serv);
}

int servAddMed(Service* serv, char* name, int conc, int qty, int price)
{
	addElement(serv->undoStack, repoCopy(serv->repo));
	clearDynamicArray(serv->redoStack);

	Medicine* m = addMedicine(name, conc, qty, price);
	
	return repoAddMedicine(serv->repo, m);
}

int servDeleteMed(Service* serv, char* name, int conc)
{
	addElement(serv->undoStack, repoCopy(serv->repo));
	clearDynamicArray(serv->redoStack);

	int pos = repoFindPosOfMedicine(serv->repo, name, conc);
	if (pos == -1)
		return -1;

	Medicine* m = repoFindMedAtPos(serv->repo, pos);

	return repoDeleteMedicine(serv->repo, m);
}

int servUpdateMed(Service* serv, char* name, int conc, int newPrice)
{
	addElement(serv->undoStack, repoCopy(serv->repo));
	clearDynamicArray(serv->redoStack);

	int pos = repoFindPosOfMedicine(serv->repo, name, conc);
	if (pos == -1)
		return -1;

	Medicine* m = repoFindMedAtPos(serv->repo, pos);

	return repoUpdateMedicine(serv->repo, name, conc, newPrice);
}

DynamicArray* servFullNameSearch(Service* serv, char* name)
{
	DynamicArray* result = createDynamicArray(CAPACITY, &deleteMedicine);

	for (int i = 0; i < repoGetLength(serv->repo); i++)
	{
		Medicine* m = repoFindMedAtPos(serv->repo, i);
		if (strcmp(name, getName(m)) == 0)
		{
			Medicine* copy = copyMedicine(m);
			addElement(result, copy);
		}
	}
	for (int i = 0; i < getLength(result) - 1; i++)
		for (int j = i + 1; j < getLength(result); j++)
		{
			Medicine* a = (Medicine*)get(result, i);
			Medicine* b = (Medicine*)get(result, j);

			if (strcmp(getName(a), getName(b)) > 0)
			{
				// swap
				void* temp = result->elems[i];
				result->elems[i] = result->elems[j];
				result->elems[j] = temp;
			}
		}

	return result;
}

DynamicArray* servPartialNameSearch(Service* serv, char* name)
{
	DynamicArray* result = createDynamicArray(CAPACITY, &deleteMedicine);

	for (int i = 0; i < repoGetLength(serv->repo); i++)
	{
		Medicine* m = repoFindMedAtPos(serv->repo, i);
		if (strstr(getName(m), name) != NULL)
		{
			Medicine* copy = copyMedicine(m);
			addElement(result, copy);
		}
	}
	for (int i = 0; i < getLength(result) - 1; i++)
		for (int j = i + 1; j < getLength(result); j++)
		{
			Medicine* a = (Medicine*)get(result, i);
			Medicine* b = (Medicine*)get(result, j);

			if (strcmp(getName(a), getName(b)) > 0)
			{
				// swap
				void* temp = result->elems[i];
				result->elems[i] = result->elems[j];
				result->elems[j] = temp;
			}
		}

	return result;
}

DynamicArray* servPartialNameSearchSortConc(Service* serv, char* name)
{
	DynamicArray* result = createDynamicArray(CAPACITY, &deleteMedicine);

	for (int i = 0; i < repoGetLength(serv->repo); i++)
	{
		Medicine* m = repoFindMedAtPos(serv->repo, i);
		if (strstr(getName(m), name) != NULL)
		{
			Medicine* copy = copyMedicine(m);
			addElement(result, copy);
		}
	}
	for (int i = 0; i < getLength(result) - 1; i++)
		for (int j = i + 1; j < getLength(result); j++)
		{
			Medicine* a = (Medicine*)get(result, i);
			Medicine* b = (Medicine*)get(result, j);

			if (getConc(a) < getConc(b))
			{
				// swap
				void* temp = result->elems[i];
				result->elems[i] = result->elems[j];
				result->elems[j] = temp;
			}
		}

	return result;
}

DynamicArray* servInShortQty(Service* serv, int givenQty, Operation cmp)
{
	DynamicArray* result = createDynamicArray(CAPACITY, &deleteMedicine);

	for (int i = 0; i < repoGetLength(serv->repo); i++)
	{
		Medicine* m = repoFindMedAtPos(serv->repo, i);
		if (givenQty > getQty(m))
		{
			Medicine* copy = copyMedicine(m);
			addElement(result, copy);
		}
	}
	for (int i = 0; i < getLength(result) - 1; i++)
		for (int j = i + 1; j < getLength(result); j++)
		{
			Medicine* a = (Medicine*)get(result, i);
			Medicine* b = (Medicine*)get(result, j);

			if (cmp(a, b) > 0)
			{
				// swap
				void* temp = result->elems[i];
				result->elems[i] = result->elems[j];
				result->elems[j] = temp;
			}
		}

	return result;
}

DynamicArray* servSearchByPrice(Service* serv, int price, Operation cmp)
{
	DynamicArray* result = createDynamicArray(CAPACITY, &deleteMedicine);

	for (int i = 0; i < repoGetLength(serv->repo); i++)
	{
		Medicine* m = repoFindMedAtPos(serv->repo, i);
		if (getPrice(m) == price)
		{
			Medicine* copy = copyMedicine(m);
			addElement(result, copy);
		}
	}

	for (int i = 0; i < getLength(result) - 1; i++)
		for (int j = i + 1; j < getLength(result); j++)
		{
			Medicine* a = (Medicine*)get(result, i);
			Medicine* b = (Medicine*)get(result, j);

			if (cmp(a, b) > 0)
			{
				// swap
				void* temp = result->elems[i];
				result->elems[i] = result->elems[j];
				result->elems[j] = temp;
			}
		}

	return result;
}

int servUndo(Service* serv) 
{
	if (getLength(serv->undoStack) == 0)
		return 0;

	addElement(serv->redoStack, repoCopy(serv->repo));
	Repo* prev = (Repo*)removeLast(serv->undoStack);
	repoDestroy(serv->repo);
	serv->repo = prev;
	return 1;
}

int servRedo(Service* serv)
{
	if (getLength(serv->redoStack) == 0)
		return 0;

	addElement(serv->undoStack, repoCopy(serv->repo));
	Repo* prev = (Repo*)removeLast(serv->redoStack);

	repoDestroy(serv->repo);
	serv->repo = prev;
	return 1;
}

int cmpDescConc(Medicine *a, Medicine *b)
{
	return getConc(b) - getConc(a);
}

int cmpAscConc(Medicine* a, Medicine* b)
{
	return getConc(a) - getConc(b);
}

int cmpAscQty(Medicine* a, Medicine* b)
{
	return getQty(a) - getQty(b);
}

int cmpDescQty(Medicine* a, Medicine* b)
{
	return getQty(b) - getQty(a);
}


void testsService()
{
	Repo* r = repoCreate();
	Service* s = servCreate(r);

	// --- Test Add ---
	int res = servAddMed(s, "Nurofen", 200, 10, 15);
	assert(res == 1);
	assert(repoGetLength(s->repo) == 1);

	// --- Test Add merge ---
	res = servAddMed(s, "Nurofen", 200, 5, 15);
	assert(res == 2);
	Medicine* m = repoFindMedAtPos(s->repo, 0);
	assert(getQty(m) == 15);

	// --- Test Update ---
	res = servUpdateMed(s, "Nurofen", 200, 30);
	assert(res == 1);
	assert(getPrice(m) == 30);

	// --- Test Delete ---
	res = servDeleteMed(s, "Nurofen", 200);
	assert(res == 1);
	assert(repoGetLength(s->repo) == 0);

	// --- Test Undo Delete ---
	res = servUndo(s);
	assert(res == 1);
	assert(repoGetLength(s->repo) == 1);

	// --- Test Redo Delete ---
	res = servRedo(s);
	assert(res == 1);
	assert(repoGetLength(s->repo) == 0);

	// Add more medicines for search tests
	servAddMed(s, "Aspirin", 100, 20, 10);
	servAddMed(s, "Strepsils", 50, 15, 12);
	servAddMed(s, "Vitamina C", 200, 34, 40);
	servAddMed(s, "Vitamina D", 50, 13, 45);

	// --- Test Full Name Search ---
	DynamicArray* full = servFullNameSearch(s, "Aspirin");
	assert(getLength(full) == 1);
	Medicine* f = (Medicine*)get(full, 0);
	assert(strcmp(getName(f), "Aspirin") == 0);
	destroy(full);

	// --- Test Partial Name Search ---
	DynamicArray* part = servPartialNameSearch(s, "Vitamina");
	assert(getLength(part) == 2);
	destroy(part);
	
servDestroy(s);
}