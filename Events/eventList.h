#pragma once
#include "event.h"
#include <vector>

class EventList
{
protected:
	std::vector<Event> events;
	int current;

public:
	EventList();

	// Adds a song to the playlist.
	void add(const Event& e);

	// Returns the event that is currently displaying.
	Event getCurrentEvent();

	// Starts the list event - shows the first event.
	void play();

	// Shows the next event in the list.
	void next();

	// Checks if the list events is empty.
	bool isEmpty();

	virtual ~EventList() {};
};