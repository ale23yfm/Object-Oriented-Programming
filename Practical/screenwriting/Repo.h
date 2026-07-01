#pragma once
#include "ideea.h"
#include "writer.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

class Repo
{
private:
	std::vector<Idea*> ideas;
	std::vector<Writer*> writers;
	std::string ideaFile;
	std::string writerFile;

	void loadWriter();
	void loadIdea();

public:
	Repo() = default;
	Repo(std::string writerFile, std::string ideaFile) :writerFile(writerFile), ideaFile(ideaFile)
	{
		loadWriter();
		loadIdea();
	};

	std::vector<Idea*> getIdeas() { return this->ideas; };
	std::vector<Writer*> getWriters() { return this->writers; };

	void acceptIdea(Idea* idea)
	{
		idea->setStatus("accepted");
	}

	void addIdea(std::string desc, std::string creator, int act)
	{
		this->ideas.push_back(new Idea(desc, "proposed", creator, act));
	}

	void saveToFile();
};

