#include "ui.h"
#include <iostream>

using namespace std;

void UI::run()
{
	int o = 0;
	cout << "WELCOME TO THE MENU\n";
	while (o != 5)
	{
		menu();
		cin >> o;
		switch (o)
		{
		case 1:
			uiAdd();
			break;
		case 2:
			uiShowAll();
			break;
		case 3:
			uiShowAllParliament();
			break;
		case 4:
			uiSaveToFile();
			break;
		case 5:
			cout << "\nGOODBYE\n";
			return;
		default:
			cout << "\Invalid option choose 1-5\n";
			break;
		}
	}
}

void UI::menu()
{
	cout << "Choose your option:\n";
	cout << "1. Add\n";
	cout << "2. Show all\n";
	cout << "3. Show all that will form Parliament\n";
	cout << "4. Save to file\n";
	cout << "5. Exit\n";
}

void UI::uiAdd()
{
	string name, names;
	int votes, type, number;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "name:";
	getline(cin, name);
	//cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "names:";
	getline(cin, names);
	cout << "votes: ";
	cin >> votes;
	cout << "What to add? \n1. Party \n2. Alliance \n3. Independent\n";
	cin >> type;
	if (type == 1)
	{
		this->serv.Add(new Party(name, names, votes));
	}
	else if (type == 2)
	{
		cout << "number:";
		cin >> number;
		this->serv.Add(new Alliance(name, names, votes, number));
	}
	else
	{
		this->serv.Add(new Independent(name, names, votes));
	}
	uiShowAll();
}

void UI::uiShowAll()
{
	cout << "Your data:\n";
	std::vector<County*> all = this->serv.getAll();
	int i = 1;
	for (auto a : all)
	{
		cout << i << ". " << a->toString() << '\n';
		i++;
	}
}

void UI::uiShowAllParliament()
{
	cout << "Eligible:\n";
	std::vector<County*> all = this->serv.servShowAllParliament();
	int i = 1;
	for (auto a : all)
	{
		cout << i << ". " << a->toString() << '\n';
		i++;
	}
}

void UI::uiSaveToFile()
{
	this->serv.writeToFile();
	cout << "Check election.txt\n";
}
