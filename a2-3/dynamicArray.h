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

/// <summary>
/// Creates a dynamic array of generic elements, with a given capacity.
/// </summary>
/// <param name="capacity">integer, the capacity of the array</param>
/// <param name="destroyFct">DestroyFunctionType, the function that destroys</param>
/// <returns>the createdd dynamic array</returns>
DynamicArray* createDynamicArray(int capacity, DestroyFunctionType destroyFct);

/// <summary>
/// Destorys the created dynamic array
/// </summary>
/// <param name="da">the given dynamic array to be destroyed</param>
void destroy(DynamicArray* da);

/// <summary>
/// Clears the dynamic array in order to reuse it
/// </summary>
/// <param name="da">the given dynamic array to be cleaned</param>
void clearDynamicArray(DynamicArray* da);

/// <summary>
/// Removes the last element in the dynamic array
/// </summary>
/// <param name="da">the given dynamic array from which we delete the last element</param>
/// <returns>the new last element</returns>
TElement removeLast(DynamicArray* da);

/// <summary>
/// Adds an element in the dynamic array
/// </summary>
/// <param name="da">the given dynamic array</param>
/// <param name="elem">the element to be added</param>
void addElement(DynamicArray* da, TElement elem);

/// <summary>
/// Deletes the element from a given position and moves the last element on this position
/// </summary>
/// <param name="da">the given dynamic array</param>
/// <param name="pos">the position of the deleted element</param>
void deleteElement(DynamicArray* da, int pos);

/// <summary>
/// Returns the length of the array
/// </summary>
/// <param name="da">the given dynamic array</param>
/// <returns>the length of the array</returns>
int getLength(DynamicArray* da);

/// <summary>
/// Returns the element on the given position
/// </summary>
/// <param name="da">the given dynamic array</param>
/// <param name="pos">the posiiton of the wanted element</param>
/// <returns>the found element</returns>
TElement get(DynamicArray* da, int pos);

/// <summary>///Tests/// </summary>
void testsDynamicArray();