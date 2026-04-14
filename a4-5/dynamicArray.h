#pragma once
#pragma once
#include "event.h"
#include <stdexcept>

template <typename T>
class DynamicArray
{
private:
	T* elems;
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
	DynamicArray<T>& operator=(const DynamicArray& other);

	DynamicArray<T>& operator-=(const T& elem);

	DynamicArray<T> operator-(const T& elem) const;

	/// <summary>
	/// Adds an element to dynamic array
	/// </summary>
	/// <param name="element">the element to be added</param>
	void daAdd(T element);

	/// <summary>
	/// Removes an element from the dynamic array
	/// </summary>
	/// <param name="index">the index of the element to be deleted</param>
	void daRemove(int index);

	/// <summary>
	/// Returns the element at a given index
	/// </summary>
	/// <param name="index">the element's index</param>
	/// <returns>the element</returns>
	T& operator[](int index);

	/// <summary>
	/// Gets the size of the current dynamic array
	/// </summary>
	/// <returns>the size</returns>
	int daGetSize() const {
		return this->size;
	}

	void sort(bool (*cmp)(const T&, const T&));

	/// <summary>
	/// Destructor
	/// </summary>
	~DynamicArray();
};

template <typename T>
void DynamicArray<T>::_resize()
{
	this->capacity = this->capacity * 2;
	T* aux = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		aux[i] = this->elems[i];
	delete[] this->elems;
	this->elems = aux;
}

template <typename T>
DynamicArray<T>::DynamicArray(int initCap) :size(0), capacity(initCap)
{
	this->size = 0;
	this->capacity = initCap;
	this->elems = new T[capacity];
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other) : capacity(other.capacity), size(other.size)
{
	this->size = other.size;
	this->capacity = other.capacity;
	this->elems = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = other.elems[i];
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other)
{
	if (this == &other)
		return *this;

	delete[] this->elems;
	this->elems = new T[other.capacity];
	this->capacity = other.capacity;
	this->size = other.size;
	for (int i = 0; i < this->size; i++)
		this->elems[i] = other.elems[i];

	return *this;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator-=(const T& elem)
{
	for (int i = 0; i < this->size; i++)
		if (this->elems[i] == elem)
		{
			this->daRemove(i);
			break;
		}
	return *this;
}

template <typename T>
DynamicArray<T> DynamicArray<T>::operator-(const T& elem) const
{
	DynamicArray<T> copy = *this;
	copy -= elem;
	return copy;
}

template <typename T>
void DynamicArray<T>::daAdd(T element)
{
	if (this->size == this->capacity)
		this->_resize();
	this->elems[this->size] = element;
	this->size++;
}

template <typename T>
void DynamicArray<T>::daRemove(int index)
{
	if (index < 0 || index >= this->size)
		return;
	this->elems[index] = this->elems[this->size - 1];
	this->size--;
}

template <typename T>
T& DynamicArray<T>::operator[](int index)
{
	if (index < 0 || index >= this->size)
		throw std::out_of_range("Index out of range");
	return this->elems[index];
}

template <typename T>
void DynamicArray<T>::sort(bool (*cmp)(const T&, const T&))
{
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
			if (!cmp(elems[i], elems[j]))
				std::swap(elems[i], elems[j]);
}

template <typename T>
DynamicArray<T>::~DynamicArray()
{
	delete[] this->elems;
}
