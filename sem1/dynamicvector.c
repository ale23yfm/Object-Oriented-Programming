#include "DynamicVector.h"
#include <stdlib.h>

DynamicVector* createDynamicVector(int cap)
{
	DynamicVector* dv = malloc(sizeof(DynamicVector));
	if (dv == NULL) return NULL;
	dv->capacity = cap;
	dv->size = 0;
	dv->elems = malloc(cap*sizeof(TElem));
	if (dv->elems == NULL)
	{
		free(dv);
		return NULL;
	}
	return dv;
}
void destoryDynamicVector(DynamicVector* v)
{
	if (v == NULL) return;
	free(v->elems);
	free(v);
}
void addElem(DynamicVector* v, TElem elem)
{
	if (v->size == v->capacity)
		resize(v);
	v->elems[v->size] = elem;
	v->size++;
}

void resize(DynamicVector* v)
{
	v->capacity *= 2;
	TElem* aux = malloc(v->capacity * sizeof(TElem));
	for (int i = 0; i <= v->size; i++)
		aux[i] = v->elems[i];
	free(v->elems);
	v->elems = aux;
}

int getSize(DynamicVector* v)
{ 
	
}

void testDynamicVector()
{
	DynamicVector* dv = createDynamicVector(2);
	addElem(dv, 1);
	addElem(dv, 2);
	addElem(dv, 3);
	assert(getSize(dv) == 3);
	destoryDynamicVector(dv);
}