#pragma once

typedef int TElem;

typedef struct {
	int capacity, size;
	TElem* elems;
}DynamicVector;

DynamicVector* createDynamicVector(int cap);
void destoryDynamicVector(DynamicVector* v);
void addElem(DynamicVector* v, TElem elem);
void resize(DynamicVector* v);
int getSize(DynamicVector* v);
void testDynamicVector();