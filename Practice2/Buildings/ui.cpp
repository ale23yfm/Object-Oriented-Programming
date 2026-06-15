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
			uiShow();
			break;
		case 3:
			this->serv.writeToFileRestore("restore.txt");
			this->serv.writeToFileDemolished("demolished.txt");
			cout << "Verify files restore.txt and demolished.txt";
			break;
		case 4:
			uiShowSorted();
			break;
		case 5:
			cout << "\n GOODBYE \n";
			return;
		default:
			cout << "Invalid";
			break;
		}
	}
}

void UI::menu()
{
	cout << "\nChoose your option:\n";
	cout << "1. Add\n";
	cout << "2. Show all\n";
	cout << "3. Save\n";
	cout << "4. Show all sorted\n";
	cout << "5. Exit\n";
}

std::sort(all.begin(), all.end(), []

void UI::uiAdd()
{
	string address, type;
	int t, constructionYear, h, totalApartments, occupiedApartments;
	bool isHistorical = false;
	cout << "What do you want to add? \n1. Block \n2. House\n";
	cin >> t;
	if (t == 1)
	{
		cout << "constructionYear: ";
		cin >> constructionYear;
		cout << "occupiedApartments:\n";
		cin >> occupiedApartments;
		cout << "totalApartments:\n";
		cin >> totalApartments;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "address: ";
		getline(cin, address);
		try {
			this->serv.servAdd(new Block(address, constructionYear, totalApartments, occupiedApartments));
		}
		catch (const exception& e) {
			cout << e.what();
		}
	}
	else
	{
		cout << "constructionYear: ";
		cin >> constructionYear;
		cout << "isHistorical: \n1. yes \n2. no\n";
		cin >> h;
		if (h == 1) isHistorical = true;
		else if (h == 2) isHistorical = false;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "address: ";
		getline(cin, address);
		cout << "type: ";
		getline(cin, type);
		try {
			this->serv.servAdd(new House(address, constructionYear, type, isHistorical));
		}
		catch (const exception& e) {
			cout << e.what();
		}
	}
	uiShow();
}

void UI::uiShow()
{
	cout << "Your data: \n";
	vector<Building*> all = this->serv.servGetAll();
	int i = 0;
	for (auto b : all)
	{
		cout << i + 1 << ". " << b->toString() << '\n';
		i++;
	}
}

void UI::uiShowSorted()
{
	cout << "Your data: \n";
	vector<Building*> all = this->serv.servGetAllSorted();
	int i = 0;
	for (auto b : all)
	{
		cout << i + 1 << ". " << b->toString() << '\n';
		i++;
	}
}
