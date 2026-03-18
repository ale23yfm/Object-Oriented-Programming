#include "service.h"
#include "medicine.h"
#include <stdlib.h>
#include <string.h>

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

DynamicArray* servInShortQty(Service* serv, int givenQty, int sortType)
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

			if ((getQty(a) > getQty(b) && sortType == 1) || (getQty(a) < getQty(b) && sortType == 2))
			{
				// swap
				void* temp = result->elems[i];
				result->elems[i] = result->elems[j];
				result->elems[j] = temp;
			}
		}

	return result;
}

DynamicArray* servSearchByPrice(Service* serv, int price)
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