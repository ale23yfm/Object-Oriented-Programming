#include "DynamicArray.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>

DynamicArray* createDynamicArray(int capacity, DestroyFunctionType destroyFct)
{
	DynamicArray* da = malloc(sizeof(DynamicArray));
	// make sure that the space was allocated
	if (da == NULL)
		return NULL;

	da->capacity = capacity;
	da->length = 0;

	// allocate space for the elements
	da->elems = malloc(capacity * sizeof(TElement));
	if (da->elems == NULL)
	{
		free(da);
		return NULL;
	}
	da->destroyFct = destroyFct;

	return da;
}

void destroy(DynamicArray* arr)
{
	if (arr == NULL)
		return;

	// considering that the dynamic array takes responsibility of all the elements, it will have to deallocate the memory for these
	for (int i = 0; i < arr->length; i++)
		arr->destroyFct(arr->elems[i]);
	
	// free the space allocated for the elements
	free(arr->elems);
	arr->elems = NULL;

	// free the space allocated for the dynamic array
	free(arr);
}

// Resizes the array, allocating more space.
// If more space cannot be allocated, returns -1, else it returns 0.
int resize(DynamicArray* arr)
{
	if (arr == NULL)
		return -1;

	arr->capacity *= 2;

	TElement* aux = realloc(arr->elems, arr->capacity * sizeof(TElement));
	if (aux == NULL)
		return -1;
	arr->elems = aux;
	return 0;
}

void addElement(DynamicArray* arr, TElement t)
{
	if (arr == NULL)
		return;
	if (arr->elems == NULL)
		return;

	// resize the array, if necessary
	if (arr->length == arr->capacity)
		resize(arr);
	arr->elems[arr->length++] = t;
}

void deleteElement(DynamicArray* arr, int pos)
{
	// TODO
}

int getLength(DynamicArray* arr)
{
	if (arr == NULL)
		return -1;

	return arr->length;
}

TElement get(DynamicArray* arr, int pos)
{
	if (arr == NULL)
		return NULL;
	if (pos < 0 || pos >= arr->length)
		return NULL;
	return arr->elems[pos];
}

// ------------------------------------------------------------------------------------------------------------
// Tests

void testsDynamicArray()
{
	DynamicArray* da = createDynamicArray(2, &destroyPlanet);
	if (da == NULL)
		assert(0);

	assert(da->capacity == 2);
	assert(da->length == 0);

	Planet* p1 = createPlanet("Wolf 1061 c", "terrestrial", 13.8);
	addElement(da, p1);
	assert(da->length == 1);

	Planet* p2 = createPlanet("HAT-P-26b", "Neptune-like", 450);
	addElement(da, p2);
	assert(da->length == 2);

	// capacity must double
	Planet* p3 = createPlanet("Proxima Centauri b", "terrestrial", 4.2);
	addElement(da, p3);
	assert(da->length == 3);
	assert(da->capacity == 4);

	// delete planet on position 0
	// first get the pointer to the planet, to still be able to access the pointed memory
	Planet* p = (Planet*)get(da, 0);
	assert(strcmp(getName(p), "Wolf 1061 c") == 0);

	// deleteElement(da, 0); - this was commented because it was not yet implemented
	// after the planet is no longer in the array, its memory should also be deallocated
	// destroyPlanet(p); 
	
	// destroy the dynamic array - this will also destroy the planets
	destroy(da);
}