#include "subject.h"

void Subject::reg(Observer* obs)
{
	this->obs.push_back(obs);
}

void Subject::notify()
{
	for (auto i : this->obs)
		i->update();
}
