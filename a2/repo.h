#pragma once
#include "dynamicArray.h"
#include "medicine.h"

typedef struct {
	DynamicArray*medicines;
}Repo;

/// <summary>
/// Creates a new repo
/// </summary>
/// <returns>the created repo</returns>
Repo* repoCreate();

/// <summary>
/// Destroys a given repo
/// </summary>
/// <param name="r">the given repo to be destroyed</param>
void repoDestroy(Repo *r);

/// <summary>
/// Makes a deep copy of the repo, used for undo/redo
/// </summary>
/// <param name="r">the given repo to be copied</param>
/// <returns></returns>
Repo* repoCopy(Repo *r);

/// <summary>
/// Adds a medicine in repo
/// </summary>
/// <param name="r">the repo where to add the medicine</param>
/// <param name="m">the given medicine to be added</param>
/// <returns></returns>
int repoAddMedicine(Repo* r, Medicine* m);

/// <summary>
/// Deletes a medicine in repo
/// </summary>
/// <param name="r">the repo where to add the medicine</param>
/// <param name="m">the given medicine to be deleted</param>
/// <returns></returns>
int repoDeleteMedicine(Repo* r, Medicine* m);

/// <summary>
/// Updates a medicine in repo
/// </summary>
/// <param name="r">the repo where to add the medicine</param>
/// <param name="name">medicine's name</param>
/// <param name="concentration">medicine's concentration</param>
/// <param name="newPrice">the new price to be updated</param>
/// <returns></returns>
int repoUpdateMedicine(Repo* r, char* name, int concentration, int newPrice);

/// <summary>
/// Returns the position of the medicine found at a given position
/// </summary>
/// <param name="r">the repo where to add the medicine</param>
/// <param name="name">medicine's name</param>
/// <param name="concentration">medicine's concentration</param>
/// <returns></returns>
int repoFindPosOfMedicine(Repo * r, char* name, int concentration);

/// <summary>
/// Returns the medicine at a given position
/// </summary>
/// <param name="r">the repo where to add the medicine</param>
/// <param name="pos">the position of the medicine</param>
/// <returns></returns>
Medicine* repoFindMedAtPos(Repo * r, int pos);

/// <summary>
/// Returns the length of a repo
/// </summary>
/// <param name="r">the repo to search the length</param>
/// <returns></returns>
int repoGetLength(Repo* r);

/// <summary>///Tests/// </summary>
void testsRepo();