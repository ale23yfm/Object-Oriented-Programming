#pragma once
#include <string>

class UserMessage
{
private:
	std::string user;
	std::string message;

public:
	UserMessage(std::string& user, std::string& message) :user(user), message(message) {};
	std::string getUser() { return this->user; };
	std::string getMessage() { return this->message; };
};