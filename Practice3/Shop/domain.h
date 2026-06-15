#pragma once
#include <string>

class Shop
{
private:
	std::string category;
	std::string name;
	int quantity;

public:
	Shop(std::string category,std::string name,int quantity) :category(category), name(name), quantity(quantity){};
	std::string getCategory() { return this->category;};
	std::string getName() { return this->name;};
	int getQuantity() { return this->quantity;};
};