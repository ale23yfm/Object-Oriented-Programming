#include "ui.h"
#include <iostream>

using namespace std;

void UI::printMenu()
{ 
	cout << "\nChoose your option:\n";
	cout << "1. Add a car\n";
	cout << "2. Delete a car\n";
	cout << "3. Show all cars\n";
	cout << "4. Show vintage cars\n";
	cout << "5. Exit\n";
}

void UI::run()
{
	cout << "WELCOME TO THE MENU!\n";
	int cmd = 0;
	while (cmd != 5)
	{
		printMenu();
		cout << "Your option: ";
		cin >> cmd;
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
			uiVintage();
			break;
		case 5:
			cout << "Good bye, car lover!\n";
			return;
		default:
			cout << "Wrong input, car lover!";
		}
	}
}

void UI::uiAdd()
{
	string name, model, color;
	int year;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Name: ";
	getline(cin, name); 

	cout << "Model: ";
	getline(cin, model);

	cout << "Year: ";
	cin >> year;
	while (cin.fail())
	{
		cout << "\nOnly an integer is available: ";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> year;
	}

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Color:";
	getline(cin, color);

	try 
	{
		serv.servAdd(name, model, year, color);
		cout << "\nCar added successfully:\n";
		uiPrint();
	}
	catch (const exception& e)
	{
		cout << "\nCar already exists:\n";
		uiPrint();
	}
}

void UI::uiDelete()
{
	string model;
	int year;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Model: ";
	getline(cin, model);

	cout << "Year: ";
	cin >> year;
	while (cin.fail())
	{
		cout << "\nOnly integers are available!";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> year;
	}

	try
	{
		cout << "\nThis WAS your data:\n";
		uiPrint();
		serv.servDelete(model, year);
		cout << "\nCar deleted successfully.\nThis IS your data:\n";
		uiPrint();
	}
	catch (const exception& e)
	{
		cout << "\nCar could not be deleted:\n";
		uiPrint();
	}
}

void UI::uiVintage()
{ 
	DynamicArray da = serv.servGetVintage();
	int n = da.daGetSize();
	for (int i = 0; i < n; i++)
	{
		Cars car = da[i];
		cout << i + 1 << ". " << car.getName() << " | " << car.getModel() << " | " << car.getYear() << " | " << car.getColor() << '\n';
	}
}

void UI::uiPrint()
{
	DynamicArray da = serv.servGetAllSorted();
	int n = da.daGetSize();
	for (int i = 0; i < n; i++)
	{
		Cars car = da[i];
		cout << i + 1 << ". " << car.getName() << " | " << car.getModel() << " | " << car.getYear() << " | " << car.getColor() << '\n';
	}
}
