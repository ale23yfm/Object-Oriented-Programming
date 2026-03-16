#include "PlanetRepository.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

PlanetRepo* createRepo()
{
	PlanetRepo* v = malloc(sizeof(PlanetRepo));
	if (v == NULL)
		return NULL;
	v->planets = createDynamicArray(CAPACITY, &destroyPlanet);

	return v;
}

void destroyRepo(PlanetRepo* v)
{
	if (v == NULL)
		return;

	destroy(v->planets);
	free(v);
}

int findPosOfPlanet(PlanetRepo * v, char * name)
{
	// TODO
	return -1;
}

Planet* find(PlanetRepo* v, char* name)
{
	// TODO
	return NULL;
}

int addPlanet(PlanetRepo* v, Planet* p)
{
	if (v == NULL || p == NULL)
		return 0;

	// TODO: verification if the planet already exists
	addElement(v->planets, p);

	return 1;
}

void deletePlanet(PlanetRepo* v, char* symbol)
{
	// TODO
}

int getRepoLength(PlanetRepo* v)
{
	if (v == NULL)
		return -1;

	return getLength(v->planets);
}

Planet* getPlanetOnPos(PlanetRepo* v, int pos)
{
	if (v == NULL)
		return NULL;
	Planet* p = (Planet*)get(v->planets, pos);
	return p;
}


// Tests
void testAdd()
{
	PlanetRepo* v = createRepo();

	Planet* p1 = createPlanet("Wolf 1061 c", "terrestrial", 13.8);
	addPlanet(v, p1);
	assert(getRepoLength(v) == 1);
	assert(strcmp(getName(getPlanetOnPos(v, 0)), "Wolf 1061 c") == 0);

	Planet* p2 = createPlanet("HAT-P-26b", "Neptune-like", 450);
	assert(addPlanet(v, p2) == 1);
	assert(getRepoLength(v) == 2);

	// now try to add the same planet again -> add must return 0 (after finalizing its implementation)
	// assert(addPlanet(v, p2) == 0);

	// destroy the test repository
	destroyRepo(v);

	// Option 1:
	// if the repository does not store copies, then the memory allocated for the planets will be deallocated
	// in the repository and the two planets should not be deallocated here.

	// Option 2:
	// otherwise, if the repository makes copied, then the memory allocated for the planets must be freed
	/*destroyPlanet(p1);
	destroyPlanet(p2);*/
}

void testsPlanetRepo()
{
	testAdd();
}