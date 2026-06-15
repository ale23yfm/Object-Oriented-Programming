#include "ui.h"
#include <iostream>

using namespace std;

void UI::run()
{
	int o = 0;
	cout << "WELCOME TO THE MENU!";
	while (o != 5)
	{
		uiMenu();
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
			uiShowAllEfficient();
			break;
		case 4:
			uiSaveToFile();
			break;
		case 5:
			cout << "\nGOODBYE!\n";
			return;
		default:
			cout << "Invalid option";
			break;
		}
	}
}

void UI::uiMenu()
{
	cout << "\nChoose your option:\n";
	cout << "1. Add department\n";
	cout << "2. Show all departments\n";
	cout << "3. Show all efficients departments\n";
	cout << "4. Save to file\n";
	cout << "5. Exit\n";
}

void UI::uiAdd()
{
	int type, numberOfDoctors, numberOfPatients, numberOfBabies, numberOfMothers;
	double averageGrade;
	string hotelName;
	cout << "Do you want to add a:\n1. Surgery \n2. Neonatal\n";
	cin >> type;
	cout << "Type numberOfDoctors:\n";
	cin >> numberOfDoctors;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Type hotelName:";
	getline(cin, hotelName);
	
	if (type == 1)
	{
		cout << "Type numberOfPatients:\n";
		cin >> numberOfPatients;
		HospitalDepartment* d = new Surgery(numberOfPatients, hotelName, numberOfDoctors);
		serv.servAdd(d);
	}
	else
	{
		cout << "Type numberOfBabies:\n";
		cin >> numberOfBabies;
		cout << "Type numberOfMothers:\n";
		cin >> numberOfMothers;
		cout << "Type averageGrade:\n";
		cin >> averageGrade;
		HospitalDepartment* d = new NeonatalUnit(numberOfMothers, numberOfBabies, averageGrade, hotelName, numberOfDoctors);
		serv.servAdd(d);
	}
	uiShowAll();
}

void UI::uiShowAll()
{
	cout << "\nThis is your data:\n";
	auto all = this->serv.servGetAll();
	int i = 0;
	for (auto a : all)
	{
		cout << i + 1 << ". " << a->toString() << '\n';
		i++;
	}
}

void UI::uiShowAllEfficient()
{
	cout << "\nThis is your data:\n";
	auto all = this->serv.servGetAllEfficient();
	int i = 0;
	for (auto a : all)
	{
		cout << i + 1 << ". " << a->toString() << '\n';
		i++;
	}
}

void UI::uiSaveToFile()
{
	string filename;
	cout << "Filename:";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, filename);
	this->serv.writeToFile(filename);
}
