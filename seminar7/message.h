#pragma once
#include <string>
#include <ctime>

class Message
{
private:
	std::time_t mt;
	std::string message;

private:
	Message(std::time_t mt, std::string message) :mt(mt), message(message){};
};