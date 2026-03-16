#include "Service.h"
#include <stdlib.h>
#include <string.h>

Service* createService(PlanetRepo* r, OperationsStack* undoS)
{
	Service* s = malloc(sizeof(Service));
	if (s == NULL)
		return NULL;
	s->repo = r;
	s->undoStack = undoS;

	return s;
}

void destroyService(Service* s)
{
	// first destroy the repository inside
	destroyRepo(s->repo);

	// then the operation stack
	destroyStack(s->undoStack);

	// then free the memory
	free(s);
}

int addPlanetServ(Service* s, char* name, char* type, double distanceFromEarth)
{
	Planet* p = createPlanet(name, type, distanceFromEarth);
	
	int res = addPlanet(s->repo, p);

	if (res == 1) // if the planet was successfully added - register the operation
	{
		Operation* o = createOperation(p, "add");
		push(s->undoStack, o);
	}

	return res;
}

PlanetRepo* getRepo(Service* s)
{
	return s->repo;
}

int undo(Service* s)
{
	if (isEmpty(s->undoStack))
	{
		return 0;
	}

	Operation* operation = pop(s->undoStack);

	if (strcmp(getOperationType(operation), "add") == 0)
	{
		Planet* planet = getPlanet(operation);
		char name[50];
		strcpy(name, getName(planet));
		deletePlanet(s->repo, name);
	}
	else if (strcmp(getOperationType(operation), "remove") == 0)
	{
		// TO DO!!!
	}

	// if a redo stack is used as well, the operation might be pushed there instead of being destroyed
	destroyOperation(operation);

	return 1;
}
