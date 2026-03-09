#pragma once

typedef struct {
	char* name;
	char* type;
	double distanceToEarth;
}Planet;

Planet *createPlanet(char* name, char* type, double dist);
void destroyPlanet(Planet* p);
char* getType(Planet* p);

void Test();