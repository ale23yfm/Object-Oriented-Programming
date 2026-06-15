#include "ui.h"
#include "car.h"
#include "truck.h"
#include <iostream>

using namespace std;

void UI::run()
{
	int o = 0;
	cout << "WELCOME TO THE MENU\n";
	while (o != 6)
	{
		this->menu();
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
			uiShowExpensive();
			break;
		case 4:
			uiSaveToFile();
			break;
		case 5:
			uiRemove();
			break;
		case 6:
			cout << "\nGOODBYE\n";
			return;
		default:
			cout << "\n Invalid, choose in between 1-5\n";
			break;
		}
	}
}

void UI::menu()
{
	cout << "Choose your option: \n";
	cout << "1. Add \n";
	cout << "2. Show all \n";
	cout << "3. Show all ill \n";
	cout << "4. Save to file\n";
	cout << "5. Remove\n";
	cout << "6. Exit\n";
}

void UI::uiAdd()
{
	int type, yearOfManufacture, numberOfSeats, ha;
	string licensePlate, cargoType;
	bool hasAC = false;
	double loadCapacity;
	cout << "What do you want to add: \n1. Car \n2. Truck";
	cin >> type;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "licensePlate:";
	getline(cin, licensePlate);
	cout << "yearOfManufacture: ";
	cin >> yearOfManufacture;
	if (type == 1)
	{
		cout << "numberOfSeats:";
		cin >> numberOfSeats;
		cout << "hasAC: \n1. YES \n2. NO";
		cin >> ha;
		if (ha == 1) hasAC = true;
		this->serv.servAdd(new Car(licensePlate, yearOfManufacture, numberOfSeats, hasAC));
	}
	else
	{
		cout << "loadCapacity:";
		cin >> loadCapacity;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "cargoType:";
		getline(cin, cargoType);
		this->serv.servAdd(new Truck(licensePlate, yearOfManufacture, loadCapacity, cargoType));
	}
	uiShow();
}

void UI::uiRemove()
{
	string licensePlate;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "licensePlate:";
	getline(cin, licensePlate);
	this->serv.servRemove(licensePlate);
	uiShow();
}

void UI::uiShow()
{
	std::vector<Vehicle*> all = this->serv.servShow();
	int i = 1;
	for (auto a : all)
	{
		cout << i << ". " << a->toString() << '\n';
		i++;
	}
}

void UI::uiShowExpensive()
{
	std::vector<Vehicle*> all = this->serv.servShowExpensive();
	int i = 1;
	for (auto a : all)
	{
		cout << i << ". " << a->toString() << '\n';
		i++;
	}
}

void UI::uiSaveToFile()
{
	int year1, year2;
	string filename;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "filename:";
	getline(cin, filename);
	cout << "year1: ";
	cin >> year1;
	cout << "year2: ";
	cin >> year2;
	this->serv.servSaveToFile(filename, year1, year2);
}
