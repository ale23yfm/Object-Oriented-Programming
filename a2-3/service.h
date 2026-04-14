#pragma once

#include "repo.h"
#include "dynamicArray.h"

typedef int (*Operation)(Medicine*, Medicine*);

typedef struct {
	Repo* repo;
	DynamicArray* undoStack; 
	DynamicArray * redoStack;
}Service;

/// <summary>
/// Creates a service
/// </summary>
/// <param name="r">reffered repo</param>
/// <returns>the created service</returns>
Service* servCreate(Repo* r);

/// <summary>
/// Destroys the service
/// </summary>
/// <param name="serv">the service to be distroyed</param>
void servDestroy(Service *serv);

/// <summary>
/// Adds a medicine in service
/// </summary>
/// <param name="serv">the given service</param>
/// <param name="name">medicine's name</param>
/// <param name="conc">medicine's concentration</param>
/// <param name="qty">medicine's quantity</param>
/// <param name="price">medicine's price</param>
/// <returns>medicine added in repo</returns>
int servAddMed(Service* serv, char* name, int conc, int qty, int price);

/// <summary>
/// Deletes a medicine in service
/// </summary>
/// <param name="serv">the given service</param>
/// <param name="name">medicine's name</param>
/// <param name="conc">medicine's concentration</param>
/// <returns>medicine deleted in repo</returns>
int servDeleteMed(Service* serv, char* name, int conc);

/// <summary>
/// Updates a medicine in service
/// </summary>
/// <param name="serv">the given service</param>
/// <param name="name">medicine's name</param>
/// <param name="conc">medicine's concentration</param>
/// <param name="newPrice">medicine's new price</param>
/// <returns>medicine updated in repo</returns>
int servUpdateMed(Service* serv, char* name, int conc, int newPrice);

/// <summary>
/// Searches medicines by full name
/// </summary>
/// <param name="serv">the given service</param>
/// <param name="name">medicine's name</param>
/// <returns>the found medicines</returns>
DynamicArray* servFullNameSearch(Service* serv, char* name);

/// <summary>
/// Searches medicines by partial name
/// </summary>
/// <param name="serv">the given service</param>
/// <param name="name">medicine's name</param>
/// <returns>the found medicines</returns>
DynamicArray* servPartialNameSearch(Service* serv, char* name);

/// <summary>
/// Searches medicines by partial name, sorted descending by concentration
/// </summary>
/// <param name="serv"></param>
/// <param name="name"></param>
/// <returns></returns>
DynamicArray* servPartialNameSearchSortConc(Service* serv, char* name);

/// <summary>
/// Searches medicines having quantity less than a given quantity
/// </summary>
/// <param name="serv">the given service</param>
/// <param name="givenQty">given quantity</param>
/// <param name="cmp">the type of comparison</param>
/// <returns>the found medicines</returns>
DynamicArray* servInShortQty(Service* serv, int givenQty, Operation cmp);

/// <summary>
/// Searches medicines by price
/// </summary>
/// <param name="serv">the given service</param>
/// <param name="price">the price to be searched</param>
/// <param name="cmp">the type of comparison</param>
/// <returns>the found medicines</returns>
DynamicArray* servSearchByPrice(Service* serv, int price, Operation cmp);

/// <summary>
/// Undos the last operation
/// </summary>
/// <param name="serv">the given service</param>
/// <returns>the last snapshot of the array</returns>
int servUndo(Service* serv);

/// <summary>
/// Redos the last operation
/// </summary>
/// <param name="serv">the given service</param>
/// <returns>the last snapshot of the array</returns>
int servRedo(Service* serv);

/// <summary>
/// Compares to medicines by concentration descending 
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns></returns>
int cmpDescConc(Medicine* a, Medicine* b);

/// <summary>
/// Compares to medicines by concentration ascending 
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns></returns>
int cmpAscConc(Medicine* a, Medicine* b);

/// <summary>
/// Compares to medicines by quantity descending 
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns></returns>
int cmpDescQty(Medicine* a, Medicine* b);

/// <summary>
/// Compares to medicines by quantity ascending 
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns></returns>
int cmpAscQty(Medicine* a, Medicine* b);

/// <summary>///Tests/// </summary>
void testsService();