#include "planet.h"
#include "dynamicvector.h"
#include <crtdbg.h>

int main(int argc, char** argv)
{
	test();
	testDynamicVector();
	_CrtDumpMemoryLeaks();
	return 0;
}