#include "ui.h"
#include <iostream>

using namespace std;

void UI::run()
{
	int o = 0;
	cout << "WELCOME TO THE MENU!\n";
	while (o != 5)
	{
		this->menu();
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
			uiShowIneff();
			break;
		case 4:
			uiSaveToFile();
			break;
		case 5:
			cout << "\nGOODBYE\n";
			break;
		default:
			cout << "Choose in between 1-5.";
			break;
		}
	}
}

void UI::menu()
{
	cout << "Choose your option:\n";
	cout << "1. Add\n";
	cout << "2. Show all\n";
	cout << "3. Show all inefficient\n";
	cout << "4. Save to file\n";
	cout << "5. Exit\n";
}

void UI::uiAdd()
{
	int type, hf;
	string id, electricityUsageClass;
	bool hasFreezer = false;
	double consumedElectricityForOneHour;
	cout << "What do you want to add? \n1. Refrigerator \n2. DishWasier\n";
	cin >> type;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "id:";
	getline(cin, id);
	if (type == 1)
	{
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "electricityUsageClass: (A or A++)";
		getline(cin, electricityUsageClass);
		cout << "hasFreezer: \n1. YES \n2. NO";
		cin >> hf;
		if (hf == 1) hasFreezer = true;
		this->serv.servAdd(new Refrigerator(id, electricityUsageClass, hasFreezer));
	}
	else
	{
		cout << "consumedElectricityForOneHour: ";
		cin >> consumedElectricityForOneHour;
		this->serv.servAdd(new DishWasher(id, consumedElectricityForOneHour));
	}
	this->uiShowAll();
}

void UI::uiShowAll()
{
	std::vector<Appliance*> all = this->serv.servShowAll();
	cout << "This is your data: \n";
	int i = 1;
	for (auto a : all)
	{
		cout << i << ". " << a->toString() << "\n";
		i++;
	}
}

void UI::uiShowIneff()
{
	std::vector<Appliance*> all = this->serv.servShowIneff();
	cout << "This is your data: \n";
	int i = 1;
	for (auto a : all)
	{
		cout << i << ". " << a->toString() << "\n";
		i++;
	}
}

void UI::uiSaveToFile()
{
	double value;
	string filename;
	cout << "value:";
	cin >> value;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "filename:";
	getline(cin, filename);
	this->serv.servWriteToFile(filename, value);
	cout << "Check " << filename << "\n";
}
