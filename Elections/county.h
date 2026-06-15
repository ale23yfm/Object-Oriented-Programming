#pragma once
#include <string>

class County
{
protected:
	std::string name;

public:
	County(std::string name) :name(name) {};
	virtual bool eligible() const = 0;
	virtual int mandates() const = 0;
	virtual std::string toString() const = 0;
	virtual ~County() = default;
};