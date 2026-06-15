#pragma once
#include "observer.h"
#include <vector>

class Subject
{
private:
	std::vector<Observer*> obs;

public:
	void reg(Observer* obs);
	//void remove(Observer* obs);
	void notify();
};