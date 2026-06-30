#pragma once
#include "issue.h"
#include "user.h"
#include <vector>
#include <string>

class Repo
{
private:
	std::vector<Issue*> issues;
	std::vector<User*> users;
	std::string userFile;
	std::string issueFile;

	void loadUsers();
	void loadIssues();

public:
	Repo() = default;
	Repo(std::string userFile,	std::string issueFile) :userFile(userFile), issueFile(issueFile){
		loadUsers();
		loadIssues();
	};

	std::vector<Issue*>& getIssues() { return this->issues; }
	std::vector<User*> getUsers() { return this->users; }

	void saveIssues();
};