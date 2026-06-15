#include <iostream>
#include <string>
#include "ui.h"

using namespace std;

void UI::uiRun()
{
	cout << "WELCOME";
	int cmd = 0;
	while (cmd != 4)
	{
		uiPrintMenu();
		cin >> cmd;
		while (cin.fail())
		{
			cout << "Invalid input";
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
			uiPrint();
			break;
		case 3:
			uiPrintType();
			break;
		case 4:
			cout << "\nGOODBYE!";
			return;
		default:
			cout << "\nInvalid input";
		}
	}
}

void UI::uiAdd()
{
	string location, name, senzorsLine;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Location: ";
	getline(cin, location);

	cout << "Name: ";
	getline(cin, name);

	cout << "Senzors(comma separated): ";
	getline(cin, senzorsLine);

	vector<string> senzors;
	string current;

	for (char c : senzorsLine)
		if (c == ',')
		{
			while (!current.empty() && current.front() == ' ')
				current.erase(current.begin());
			while (!current.empty() && current.back() == ' ')
				current.pop_back();
			if (!current.empty())
			{
				senzors.push_back(current);
			}
		}
		else current += c;
	if (!current.empty())
	{
		senzors.push_back(current);
	}

	try
	{
		serv.servAdd(location, name, senzors);
		cout << "The station added successfully";
		uiPrint();
	}
	catch (exception& e)
	{
		cout << "The station already exists";
		uiPrint();
	}
}

void UI::uiDelete()
{
}

void UI::uiPrint()
{
	DynamicArray da = serv.servGetAll();
	for (int i = 0; i < da.daGetSize(); i++)
		cout << i + 1 << ". " << da[i].getLocation() << " | " << da[i].getName() << " | " << da[i].getSenzorsAsString() << '\n';
}

void UI::uiPrintMenu()
{
	cout << "\nMENU\n";
	cout << "1. Add a station\n";
	cout << "2. Print all\n";
	cout << "3. See weather stations with a senzor\n";
	cout << "4. Exit\n";
	cout << "Choose your option:\n";
}

void UI::uiPrintType()
{
	string senzor;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Senzor: ";
	getline(cin, senzor);

	auto result = serv.servGetAllBySenzor(senzor);
	cout << "Stations with senzor '" << senzor << "' :\n";
	for (auto& x : result)
	{
		cout << x.first << "(" << x.second << ")\n";
	}
}