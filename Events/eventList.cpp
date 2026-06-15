#include "eventList.h"

EventList::EventList()
{
	this->current = 0;
}

void EventList::add(const Event& e)
{
	this->events.push_back(e);
}

Event EventList::getCurrentEvent()
{
	return this->events[this->current];
}

void EventList::play()
{
	if (this->events.size() == 0)
		return;
	this->current = 0;
	Event currentEvent = this->getCurrentEvent();
	currentEvent.play();
}

void EventList::next()
{ 
	if (this->events.size() == 0)
		return;
	this->current++;
	Event currentEvent = this->getCurrentEvent();
	currentEvent.play();
}

bool EventList::isEmpty()
{ 
	return this->events.size() == 0;
}