#pragma once
#include "dynamicArray.h"
class RepoUser
{
private:
	DynamicArray<Event> da;
public:

	/// <summary>
	/// Adds an element into repo
	/// </summary>
	/// <param name="e">the element to be added</param>
	void repoAddUser(const Event& e);

	/// <summary>
	/// Removes an element from the repo
	/// </summary>
	/// <param name="index">the index of the element</param>
	void repoRemoveUser(int index);

	/// <summary>
	/// Gets the size of the array
	/// </summary>
	/// <returns>the size</returns>
	int repoGetSizeUser() const;

	/// <summary>
	/// Returns the element at that index in dynamic array
	/// </summary>
	/// <param name="index">the index of the element</param>
	/// <returns>the element at that index</returns>
	Event& repoGetUser(int index);

	/// <summary>
	/// Returns the index of the element
	/// </summary>
	/// <param name="e">the wanted element</param>
	/// <returns>the index of the element</returns>
	int repoFindUser(const Event& e);
};