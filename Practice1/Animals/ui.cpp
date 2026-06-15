#include "ui.h"
#include <iostream>
#include <string>

using namespace std;

void UI::uiRun()
{
	cout << "WELCOME!\n";
	int cmd = 0;
	while (cmd != 5)
	{
		uiPrintMenu();
		cin >> cmd;
		while (cin.fail())
		{
			cout << "Type an integer";
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
			uiDelete();
			break;
		case 3:
			uiPrint();
			break;
		case 4:
			uiSenior();
			break;
		case 5:
			cout << "GOODBYE";
			return;
		default:
			cout << "Invalid input";
		}
	}
}

void UI::uiPrintMenu()
{
	cout << "\nMENU:\n";
	cout << "1. Add an animal\n";
	cout << "2. Delete an animal\n";
	cout << "3. See all animals\n";
	cout << "4. See all seniors\n";
	cout << "5. Exit\n";
	cout << "Choose your option: ";
}

void UI::uiAdd()
{
	string name, species, color;
	int age;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Name: ";
	getline(cin, name);
	
	cout << "Species: ";
	getline(cin, species);

	cout << "Age: ";
	cin >> age;
	while (cin.fail())
	{
		cout << "Type integer";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> age;
	}

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Color: ";
	getline(cin, color);

	try
	{
		serv.servAdd(name, species, age, color);
		cout << "Animal added successfully: \n";
		uiPrint();
	}
	catch (exception& e)
	{
		cout << "Animals already exists";
		uiPrint();
	}
}

void UI::uiDelete()
{
	string name, species;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Name: ";
	getline(cin, name);

	cout << "Species: ";
	getline(cin, species);

	try
	{
		cout << "This WAS your data:\n";
		uiPrint();
		serv.servDelete(name, species);
		cout << "Animal deleted successfully. This IS your data: \n";
		uiPrint();
	}
	catch (exception& e)
	{
		cout << "Animals does not exist";
		uiPrint();
	}
}

void UI::uiPrint()
{
	DynamicArray da = serv.servGetAllSorted();
	for (int i = 0; i < da.daGetSize(); i++)
		cout << i + 1 << ". " << da[i].getSpecies() << " | " << da[i].getName() << " | " << da[i].getAge() << " | " << da[i].getColor() << " \n";
}

void UI::uiSenior()
{
	DynamicArray da = serv.servSortByColor();
	for (int i = 0; i < da.daGetSize(); i++)
		cout << i + 1 << ". " << da[i].getSpecies() << " | " << da[i].getName() << " | " << da[i].getAge() << " | " << da[i].getColor() << " \n";
}

