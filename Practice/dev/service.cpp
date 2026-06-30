#include "service.h"
#include <QMessageBox>

void Service::addIssue(const std::string& desc, const std::string& reporter)
{
	if (desc.empty())
	{
		QMessageBox::warning(nullptr, "Error", "Description cannot be empty!");
		return;
	}

	for (auto i : this->getIssues())
		if (desc == i->getDesc())
		{
			QMessageBox::warning(nullptr, "Error", "Description already exists!");
			return;
		}
	repo.getIssues().push_back(new Issue(desc, "open", reporter, ""));
	notify();
}

void Service::resolveIssue(const std::string& desc, const std::string& solver)
{
	auto& issues = this->getIssues();
	for (auto i = issues.begin(); i != issues.end(); i++)
		if (desc == (*i)->getDesc())
		{
			if ((*i)->getStatus() == "closed")
			{
				QMessageBox::warning(nullptr, "Error", "Issue already solved!");
				return;
			}
			(*i)->setStatus("closed");
			(*i)->setSolver(solver);
			notify();
			return;
		}
}

void Service::removeIssue(const std::string& desc)
{
	auto& issues = this->getIssues();
	for (auto i = issues.begin(); i != issues.end(); i++)
		if ((*i)->getDesc() == desc && (*i)->getStatus() == "closed")
		{
			delete* i;
			issues.erase(i);
			notify();
			return;
		}
	QMessageBox::warning(nullptr, "Error", "Issue still opened");
}
