#include "ui.h"
#include <iostream>

using namespace std;

void UI::uiRun()
{
	cout << boolalpha;
	cout << "WELCOME!";
	int cmd = 0;
	while (cmd != 5)
	{
		uiPrintMenu();
		cin >> cmd;
		while (cin.fail())
		{
			cout << "Type integer";
			cin.clear();
			cin.ignore();
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
			uiUpdate();
			break;
		case 4:
			uiPrint();
			break;
		case 5:
			cout << "\nGOODBYE!";
			return;
		default:
			cout << "Invalid input, try again.";
		}
	}
}

void UI::uiPrintMenu()
{
	cout << "\nMENU\n";
	cout << "1. Add a patient\n";
	cout << "2. Delete a patient\n";
	cout << "3. Update patient's status\n";
	cout << "4. Print all\n";
	cout << "5. Exit\n";
	cout << "\nChoose your option: ";
}

void UI::uiPrint()
{
	DynamicArray da = serv.servGetAll();
	for (int i = 0; i < da.daGetSize(); i++)
		cout << i + 1 << ". " << da[i].getName() << " | " << da[i].getAge() << " | " << da[i].getInfected() << " | " << da[i].getRoom() << " \n";
}

void UI::uiAdd()
{
	string name;
	int age, room, inf;
	bool infected = false;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Name: ";
	getline(cin, name);

	cout << "Age: ";
	cin >> age;
	while (cin.fail())
	{
		cout << "Type an integer";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> age;
	}

	cout << "Infected(0/1): ";
	cin >> inf;

	if (inf == 1)
		infected = true;

	cout << "Room: ";
	cin >> room;
	while (cin.fail())
	{
		cout << "Type an integer";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> room;
	}

	try
	{
		serv.servAdd(name, age, infected, room);
		cout << "Patient added successfully:\n";
		uiPrint();
	}
	catch (exception& e)
	{
		cout << "Patient already exists:\n";
		uiPrint();
	}
}

void UI::uiDelete()
{
	string name;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Name: ";
	getline(cin, name);

	try
	{
		cout << "This WAS your data:\n";
		uiPrint();
		serv.servDelete(name);
		cout << "Patient deleted successfully. This IS your data:\n";
		uiPrint();
	}
	catch (exception& e)
	{
		cout << "Patient does not exist:\n";
		uiPrint();
	}
}

void UI::uiUpdate()
{
	string name;
	int minAge;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Name: ";
	getline(cin, name);

	cout << "MinAge: ";
	cin >> minAge;
	while (cin.fail())
	{
		cout << "Type an integer";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> minAge;
	}

	try
	{
		Hospital patient = serv.servGetByName(name);
		cout << "This WAS your data:\n";
		uiPrint();
		cout << "Patients' status updated successfully. This IS your data:\n";
		DynamicArray da = serv.servUpdate(patient, minAge);
		for (int i = 0; i < da.daGetSize(); i++)
			cout << i + 1 << ". " << da[i].getName() << " | " << da[i].getAge() << " | " << da[i].getInfected() << " | " << da[i].getRoom() << " \n";
	}
	catch (exception& e)
	{
		cout << "Patient does not exist.";
		uiPrint();
	}
}
