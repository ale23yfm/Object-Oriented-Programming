#pragma once
#include "PlanetRepository.h"
#include "OperationsStack.h"

typedef struct
{
	PlanetRepo* repo;
	OperationsStack* undoStack;
} Service;

Service* createService(PlanetRepo* r, OperationsStack* undoS);
void destroyService(Service* s);

/// <summary>
/// Adds a planet to the repository of planets.
/// </summary>
/// <param name="s">Pointer to theService.</param>
/// <param name = "name">A string, the name of the planet.</param>
/// <param name = "type">A string, the planet's type.</param>
/// <param name = "distanceFromEarth">Double, the distance from the planet to Earth, in light years.</param>
/// <returns>1 - if the planet was sucessfully added; 0 - if the planet could not be added, as another planet with the same symbol already exists.</returns>
int addPlanetServ(Service* s, char* name, char* type, double distanceFromEarth);

PlanetRepo* getRepo(Service* s);

/// <summary>
/// Undoes the last performed operation.
/// </summary>
/// <param name="s">Pointer to theService.</param>
/// <returns>1, if the undo operation could be done, 0 otherwise.</returns>
int undo(Service* s);
