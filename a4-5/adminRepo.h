#pragma once
#include "dynamicArray.h"
class RepoAdmin
{
private:
	DynamicArray<Event> da;
public:

	/// <summary>
	/// Adds an element into repo
	/// </summary>
	/// <param name="e">the element to be added</param>
	void repoAddAdmin(const Event& e);

	/// <summary>
	/// Removes an element from the repo
	/// </summary>
	/// <param name="index">the index of the element</param>
	void repoRemoveAdmin(int index);

	/// <summary>
	/// Updates an element
	/// </summary>
	/// <param name="index">the index of the element to be modified</param>
	/// <param name="newEvent">event with the new information</param>
	void repoUpdateAdmin(int index, const Event & newEvent);

	/// <summary>
	/// Gets the size of the array
	/// </summary>
	/// <returns>the size</returns>
	int repoGetSizeAdmin() const;

	/// <summary>
	/// Returns the element at that index in dynamic array
	/// </summary>
	/// <param name="index">the index of the element</param>
	/// <returns>the element at that index</returns>
	Event& repoGetAdmin(int index);

	/// <summary>
	/// Returns the index of the element
	/// </summary>
	/// <param name="e">the wanted element</param>
	/// <returns>the index of the element</returns>
	int repoFindAdmin(const Event& e);
};