#include "dynamicArray.h"
#include "medicine.h"
#include <stdlib.h>
#include <assert.h>

DynamicArray* createDynamicArray(int capacity, DestroyFunctionType destroyFct)
{
	//create the array
	DynamicArray* da = malloc(sizeof(DynamicArray));
	if (da == NULL)
		return NULL;
	//assign its components
	da->capacity = capacity;
	da->length = 0;
	//allocate the elements
	da->elems = malloc(capacity * sizeof(TElement));
	if (da->elems == NULL)
	{
		free(da);
		return NULL;
	}
	//associate the destroy function
	da->destroyFct = destroyFct;
	return da;
}

void destroy(DynamicArray* da)
{
	if (da == NULL)
		return;
	//destoy all elements
	for (int i = 0; i < da->length; i++)
		da->destroyFct(da->elems[i]);
	//free the elements, set them to null and free the array
	free(da->elems);
	da->elems = NULL;
	free(da);
}

void clearDynamicArray(DynamicArray* da)
{
	if (da == NULL)
		return;
	//destoy all elements
	for (int i = 0; i < da->length; i++)
		da->destroyFct(da->elems[i]);

	da->length = 0;
}

TElement removeLast(DynamicArray* da)
{
	if (da == NULL || da->length == 0)
		return NULL;

	da->length--;
	return da->elems[da->length];
}

int resize(DynamicArray* da)
{
	if (da == NULL)
		return -1;
	//double the capacity
	da->capacity *= 2;
	//resize to the new capacity 
	TElement* aux = realloc(da->elems, da->capacity * sizeof(TElement));
	if (aux == NULL)
		return -1;
	//updates the pointer to the new memory
	da->elems = aux;
	return 0;
}

void addElement(DynamicArray* da, TElement elem)
{
	if (da == NULL)
		return;
	if (da->elems == NULL)
		return;
	//resize if necessary
	if (da->length == da->capacity)
		resize(da);
	da->elems[da->length++] = elem;
}

void deleteElement(DynamicArray* da, int pos)
{
	if (da == NULL)
		return;
	if (da->elems == NULL)
		return;
	if (pos < 0 || pos >= da->length)
		return;
	da->destroyFct(da->elems[pos]);
	da->elems[pos] = da->elems[da->length - 1];
	da->length -= 1;
}

int getLength(DynamicArray* da)
{
	if (da == NULL)
		return -1;
	return da->length;
}

TElement get(DynamicArray* da, int pos)
{
	if (da == NULL)
		return NULL;
	if (pos < 0 || pos >= da->length)
		return NULL;
	return da->elems[pos];
}

void testsDynamicArray()
{
	DynamicArray* da = createDynamicArray(2, &deleteMedicine);
	if (da == NULL)
		assert(0);
	assert(da->capacity == 2);
	assert(da->length == 0);

	Medicine* m1 = addMedicine("nurofen", 1, 2, 3);
	addElement(da, m1);
	assert(da->length == 1);

	Medicine* m2 = addMedicine("paracetamol", 2, 4, 5);
	addElement(da, m2);
	assert(da->length == 2);

	// length = capacity so capacity should be doubled
	Medicine* m3 = addMedicine("nurofen forte", 5, 6, 2);
	addElement(da, m3);
	assert(da->length == 3);
	assert(da->capacity == 4);

	//delete the medicine on position 0
	//keep a copy of the last element
	Medicine* last = (Medicine*)get(da, da->length - 1);
	assert(strcmp(getName(last), "nurofen forte") == 0);
	deleteElement(da, 0);
	assert(da->length == 2);
	assert(da->capacity == 4);
	//see if the element on position 0 is the last one
	assert(strcmp(getName(get(da, 0)), getName(last)) == 0);
	assert(strcmp(getName(last), "nurofen forte") == 0);

	destroy(da);
}