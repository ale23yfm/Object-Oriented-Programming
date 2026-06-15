#include "tests.h"
#include <assert.h>

void testRepo()
{
	Repo repo;
	Hospital p1("Jessica_Thompson", 42, false, 3);
	// test adding
	repo.repoAdd(p1);
	assert(repo.repoGetSize() == 1);

	//test adding duplicates
	try {
		repo.repoAdd(p1);
		assert(false);
	}
	catch (...)
	{
		assert(true);
	}
}

void testService()
{
	Repo repo;
	Service serv(repo);

	serv.servAdd("Jessica_Thompson", 42, false, 3);

	assert(serv.servGetSize() == 1);
	try {
		serv.servAdd("Jessica_Thompson", 42, false, 3);
		assert(false);
	}
	catch (...)
	{
		assert(true);
	}
}