#include "dynamicArray.h"
#include <stdexcept>

void DynamicArray::_resize()
{
	this->capacity = this->capacity * 2;
	TElem* aux = new TElem[this->capacity];
	for (int i = 0; i < this->size; i++)
		aux[i] = this->elems[i];
	delete[] this->elems;
	this->elems = aux;
}

DynamicArray::DynamicArray(int initCap) :size(0), capacity(initCap)
{
	this->elems = new TElem[this->capacity];
}

DynamicArray::DynamicArray(const DynamicArray& other) : capacity(other.capacity), size(other.size)
{
	this->elems = new TElem[this->capacity]();
	for (int i = 0; i < this->size; i++)
		this->elems[i] = other.elems[i];
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other)
{
	if (this == &other)
		return *this;

	delete[] this->elems;
	this->elems = new TElem[other.capacity]();
	this->capacity = other.capacity;
	this->size = other.size;
	for (int i = 0; i < this->size; i++)
		this->elems[i] = other.elems[i];

	return *this;
}

DynamicArray& DynamicArray::operator-=(const TElem& elem)
{
	for (int i = 0; i < this->size; i++)
		if (this->elems[i] == elem)
		{
			this->daDelete(i);
			break;
		}
	return *this;
}

DynamicArray& DynamicArray::operator-(const TElem& elem)
{
	for (int i = 0; i < this->size; i++)
		if (this->elems[i] == elem)
		{
			this->daDelete(i);
			break;
		}
	return *this;
}

void DynamicArray::daAdd(TElem element)
{
	if (this->size == this->capacity)
		this->_resize();
	this->elems[this->size] = element;
	this->size++;
}

void DynamicArray::daDelete(int index)
{
	if (index < 0 || index >= this->size)
		return;
	this->elems[index] = this->elems[this->size - 1];
	this->size--;
}

const TElem& DynamicArray::operator[](int index) const
{
	if (index < 0 || index >= this->size)
		throw std::out_of_range("Index out of range");
	return this->elems[index];
}

TElem& DynamicArray::operator[](int index)
{
	if (index < 0 || index >= this->size)
		throw std::out_of_range("Index out of range");
	return this->elems[index];
}

DynamicArray::~DynamicArray()
{
	delete[] this->elems;
}
