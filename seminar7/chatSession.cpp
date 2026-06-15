#include "chatSession.h"

void ChatSession::add(std::string user, std::string message)
{
	UserMessage um{user, message};
	this->userMessages.push_back(um);
	this->notify();
}
