#include "planet.h"
#include <string.h>
#include <assert.h>
#include <stdlib.h>

Planet *createPlanet(char* name, char* type, double dist)
{
	Planet* p = malloc(sizeof(Planet));
	if (p == NULL)
		return NULL;
	p->name = malloc((strlen(name) + 1) * sizeof(char));
	if (p->name == NULL)
	{
		free(p);
		return NULL;
	}
	p->type = malloc((strlen(type) + 1) * sizeof(char)); 
	if (p->type == NULL)
	{
		free(p);
		return NULL;
	}
	p->distanceToEarth = dist;
	strcpy(p->name, name);
	strcpy(p->type, type);
	return p;
}

void destroyPlanet(Planet* p)
{
	free(p->name);
	free(p->type);
	free(p);
}

char* getType(Planet* p)

{
	return p->type;
}

void Test()
{
	Planet *p = createPlanet("earth", "planet", 0.0);
	assert(!strcmp(getType(p), "planet") ==0);
	distroyPlanet(*p);
}