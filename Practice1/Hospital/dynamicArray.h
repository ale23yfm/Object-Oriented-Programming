#pragma once
#pragma once
#include "hospital.h"

typedef Hospital TElem;

class DynamicArray
{
private:
	TElem* elems;
	int size;
	int capacity;

	void _resize();

public:
	/// <summary>
	/// Dynamic Array constructor
	/// </summary>
	/// <param name="initCap">the initial capacity</param>
	DynamicArray(int initCap = 10);

	/// <summary>
	/// Copy constructor
	/// </summary>
	/// <param name="other">the dynamic array to be copied</param>
	DynamicArray(const DynamicArray& other);

	/// <summary>
	/// Shallow copy
	/// </summary>
	/// <param name="other"></param>
	/// <param name="other">the dynamic array to be copied</param>
	DynamicArray& operator=(const DynamicArray& other);

	DynamicArray& operator-=(const TElem& elem);

	DynamicArray& operator-(const TElem& elem);

	/// <summary>
	/// Adds an element to dynamic array
	/// </summary>
	/// <param name="element">the element to be added</param>
	void daAdd(TElem element);

	/// <summary>
	/// Removes an element from the dynamic array
	/// </summary>
	/// <param name="index">the index of the element to be deleted</param>
	void daDelete(int index);

	/// <summary>
	/// Returns the element at a given index
	/// </summary>
	/// <param name="index">the element's index</param>
	/// <returns>the element</returns>
	const TElem& operator[](int index) const;

	/// <summary>
	/// Returns the element at a given index
	/// </summary>
	/// <param name="index">the element's index</param>
	/// <returns>the element</returns>
	TElem& operator[](int index);

	/// <summary>
	/// Gets the size of the current dynamic array
	/// </summary>
	/// <returns>the size</returns>
	int daGetSize() const {
		return this->size;
	}

	/// <summary>
	/// Destructor
	/// </summary>
	~DynamicArray();
};