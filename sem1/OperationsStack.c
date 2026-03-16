#include "OperationsStack.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

Operation* createOperation(Planet* p, char* operationType)
{
	Operation* o = malloc(sizeof(Operation));
	if (o == NULL)
		return NULL;
	o->planet = copyPlanet(p);

	if (operationType != NULL)
	{
		o->operationType = malloc(sizeof(char) * (strlen(operationType) + 1));
		if (o->operationType == NULL)
		{
			free(o);
			return NULL;
		}
		strcpy(o->operationType, operationType);
	}
	else
		o->operationType = NULL;

	return o;
}

void destroyOperation(Operation* o)
{
	if (o == NULL)
		return;

	// first destroy the planet
	destroyPlanet(o->planet);
	// then the operationType
	free(o->operationType);
	// then free the operation
	free(o);
}

Operation* copyOperation(Operation * o)
{
	if (o == NULL)
		return NULL;
	Operation* copy = createOperation(getPlanet(o), getOperationType(o));
	return copy;
}

char* getOperationType(Operation* o)
{
	return o->operationType;
}

Planet* getPlanet(Operation* o)
{
	return o->planet;
}

// ---------------------------------------------------------------

OperationsStack* createStack()
{
	OperationsStack* s = malloc(sizeof(OperationsStack));
	if (s == NULL)
		return NULL;
	s->stack = createDynamicArray(CAPACITY, &destroyOperation);
	if (s->stack == NULL)
	{
		free(s);
		return NULL;
	}

	return s;
}

void destroyStack(OperationsStack* s)
{
	if (s == NULL)
		return;

	// first deallocate the memory for the dynamic array
	destroy(s->stack);

	// then free the stack
	free(s);
}

void push(OperationsStack* s, Operation* o)
{
	if (s == NULL || o == NULL)
		return;
	addElement(s->stack, o);
}

Operation* pop(OperationsStack* s)
{
	if (s == NULL)
		return NULL;
	int lastPos = getLength(s->stack) - 1;
	Operation* o = (Operation*)get(s->stack, lastPos); // must cast it to Operation*, as it is a void*
	// make a copy to use it for redo as well
	Operation* lastOp = copyOperation(o);
	deleteElement(s->stack, lastPos);
	return lastOp;
}

int isEmpty(OperationsStack* s)
{
	if (s == NULL)
		return 1;
	return (getLength(s->stack) == 0);
}


// Tests
void testsStack()
{
	// the commented sections should be correct after the deleteElement function of the DynamicArray will be implemented

	OperationsStack* s = createStack();
	
	Planet* p1 = createPlanet("Wolf 1061 c", "terrestrial", 13.8);
	// Planet* p2 = createPlanet("HAT-P-26b", "Neptune-like", 450);
	// Operation* o1 = createOperation(p1, "add");
	// Operation* o2 = createOperation(p2, "add");
	Operation* o3 = createOperation(p1, "remove");

	/*push(s, o1);
	push(s, o2);*/
	push(s, o3);

	assert(isEmpty(s) == 0);
	Operation* o = pop(s);
	assert(strcmp(o->operationType, "remove") == 0);
	// after each pop, the operations must be destroyed
	destroyOperation(o);
	destroyPlanet(p1);

	/*o = pop(s);
	assert(strcmp(o->operationType, "add") == 0);
	destroyOperation(o);

	o = pop(s);
	assert(strcmp(o->operationType, "add") == 0);
	destroyOperation(o);

	assert(isEmpty(s) == 1);*/

	// destroy the stack
	destroyStack(s);
}