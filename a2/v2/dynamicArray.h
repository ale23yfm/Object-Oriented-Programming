#pragma once
#define CAPACITY 10

typedef void* TElement;

typedef void (*DestroyFunctionType)(TElement);

typedef struct {
	TElement* elems;
	int length;
	int capacity;
	DestroyFunctionType destroyFct;
}DynamicArray;

DynamicArray* createDynamicArray(int capacity, DestroyFunctionType destroyFct);
void destroy(DynamicArray* da);
void clearDynamicArray(DynamicArray* da);

TElement removeLast(DynamicArray* da);

void addElement(DynamicArray* da, TElement elem);
void deleteElement(DynamicArray* da, int pos);
int getLength(DynamicArray* da);
TElement get(DynamicArray* da, int pos);
void testsDynamicArray();