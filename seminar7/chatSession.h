#pragma once
#include "userMessage.h"
#include "observer.h"
#include "subject.h"
#include "message.h"
#include "user.h"
#include <vector>

class ChatSession: public Subject
{
private:
	std::vector<UserMessage> userMessages;

public:
	void add(std::string user, std::string message);
	std::vector<UserMessage> get() { return userMessages; };
};