#include "operationsStack.h"
#include "medicine.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

Operation* opCreate(Medicine* m, char* opType)
{
	Operation* op = malloc(sizeof(Operation));
	if (op == NULL)
		return NULL;
	op->medicine = copyMedicine(m);

	if (opType != NULL)
	{
		op->opType = malloc(strlen(opType) + 1);
		if (op->opType == NULL)
		{
			free(op);
			return NULL;
		}
		strcpy_s(op->opType, strlen(opType) + 1, opType);
	}
	else
		op->opType = NULL;
	return op;
}

void opDestroy(Operation* op)
{
	if (op == NULL)
		return;

	deleteMedicine(op->medicine);
	free(op->opType);
	free(op);
}

Operation* opCopy(Operation* op)
{
	if (op == NULL)
		return NULL;
	Operation* copy = opCreate(opGetMed(op), opGetType(op));
	return copy;
}

char* opGetType(Operation* op)
{
	return op->opType;
}

Medicine* opGetMed(Operation* op)
{
	return op->medicine;
}

//---------------------------------------------------------------------------------------------------------------------------------

OpStack* opsCreate()
{
	OpStack* ops = malloc(sizeof(OpStack));
	if (ops == NULL)
		return NULL;
	ops->stack = createDynamicArray(CAPACITY, &opDestroy);
	if (ops->stack == NULL)
	{
		free(ops);
		return NULL;
	}
	return ops;
}

void opsDestroy(OpStack* ops)
{
	if (ops == NULL)
		return;
	destroy(ops->stack);
	free(ops);
}

void push(OpStack* ops, Operation* op)
{
	if (ops == NULL || op == NULL)
		return;
	addElement(ops->stack, op);
}

Operation* pop(OpStack* ops)
{
	if (ops == NULL)
		return NULL;
	int lastPos = getLength(ops->stack) - 1;
	Operation* o = (Operation*)get(ops->stack, lastPos);
	Operation* lastOp = opCopy(o);
	deleteElement(ops->stack, lastPos);
	return lastOp;
}

int isEmpty(OpStack* ops)
{
	if (ops == NULL)
		return 1;
	return (getLength(ops->stack) == 0);
}

void opsClear(OpStack* ops)
{
	destroy(ops->stack);
	ops->stack = createDynamicArray(CAPACITY, &opDestroy);
}

void testsStack()
{
	OpStack* ops = opsCreate();
	Medicine *m1 = addMedicine("nurofen", 1, 2, 3);
	//Medicine *m2 = addMedicine("nurofen forte", 2, 2, 5);
	//Operation *o1 = opCreate(m1, "add");
	Operation *o2 = opCreate(m1, "remove");
	push(ops, o2);
	assert(isEmpty(ops) == 0);
	Operation* o = pop(ops);
	assert(strcmp(o->opType, "remove") == 0);
	opDestroy(o);
	deleteMedicine(m1);
	opsDestroy(ops);
}

