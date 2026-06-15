#pragma once
#include <string>
class User
{
private:
	std::string UserName;
	std::string name;
public:
	User(std::string UserName, std::string name) : UserName(UserName), name(name) {};
};