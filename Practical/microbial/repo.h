#pragma once
#include "bacteria.h"
#include "biologist.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

class Repo
{
private:
	std::vector<Bacterium*> bacterias;
	std::vector<Biologist*> biologists;
	std::string bacFile;
	std::string bioFile;

	void loadBiologists();
	void loadBacteria();

public:
	Repo() = default;
	Repo(std::string bioFile, std::string bacFile) :bioFile(bioFile), bacFile(bacFile) {
		loadBacteria();
		loadBiologists();
	};

	void saveBacteria();

	std::vector<Bacterium*> getBacterias() {return this->bacterias; };
	std::vector<Biologist*> getBiologists() { return this->biologists; };
};

