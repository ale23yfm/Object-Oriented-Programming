#include "ui.h"
#include <iostream>
#include <vector>

using namespace std;

void UI::uiRun()
{
	int cmd = 0;
	while (cmd != 5)
	{
		uiPrintMenu();
		cin >> cmd;
		while (cin.fail())
		{
			cout << "Type an integer.";
			cin.clear();
			cin.ignore(1000, '\n');
			cin >> cmd;
		}

		switch (cmd)
		{
		case 1:
			uiAdd();
			break;
		case 2:
			uiPrintAll();
			break;
		case 3: 
			uiPrintByName();
			break;
		case 4:
			uiPrintByMenu();
			break;
		case 5:
			cout << "\nGOODBYE!";
			return;
		default:
			cout << "Invalid input, type an integer";
		}
	}
}

void UI::uiPrintMenu()
{
	cout << "\nMENU\n";
	cout << "1. Add a recipe.\n";
	cout << "2. Show all recipes\n";
	cout << "3. Show by name\n";
	cout << "4. Show number of recipes by the menu and ingredients\n";
	cout << "5. EXIT\n";
	cout << "Choose your option: ";
}

void UI::uiPrintAll()
{
	DynamicArray da = serv.servGetAll();
	for (int i = 0; i < da.daGetSize(); i++)
		//cout << i + 1 << ". " << da[i].getMenu() << " | " << da[i].getName() << " | " << da[i].getPrintIngredients() << '\n';
		cout << i + 1 << ". " << da[i].getMenu() << " | " << da[i].getName() << '\n';
}

void UI::uiAdd()
{
	string menu, name, ingredientsLine;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Menu: ";
	getline(cin, menu);

	cout << "Name: ";
	getline(cin, name);

	cout << "Ingredients(comma separated): ";
	getline(cin, ingredientsLine);

	vector<string> ingredients;
	string current;

	for (char c : ingredientsLine)
		if (c == ',')
		{
			while (!current.empty() && current.front() == ' ')
				current.erase(current.begin());
			while (!current.empty() && current.back() == ' ')
				current.pop_back();
			if (!current.empty())
			{
				ingredients.push_back(current);
			}
		}
		else current += c;
	if (!current.empty())
	{
		ingredients.push_back(current);
	}

	try
	{
		serv.servAdd(menu, name, ingredients);
		cout << "\nThe recipe added successfully. This is your data:\n";
		uiPrintAll();
	}
	catch (exception& e)
	{
		cout << "\nThe recipe already exists. This is your data:\n.";
		uiPrintAll();
	}
}

void UI::uiPrintByName()
{
	string name;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Name: ";
	getline(cin, name);
	cout << "Not implemented....";
}

void UI::uiPrintByMenu()
{
	string menu;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Menu: ";
	getline(cin, menu);
	cout << "Not implemented....";
}

