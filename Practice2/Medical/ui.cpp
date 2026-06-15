#include "ui.h"
#include "bmi.h"
#include "bp.h"
#include <iostream>

using namespace std;

void UI::run()
{
	int o = 0;
	cout << "WELCOME TO THE MENU\n";
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
			uiShow();
			break;
		case 3:
			uiShowIll();
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
	int type, systolicValue, diastolicValue;
	string data;
	double value;
	cout << "What do you want to add: \n1. BMI \n2. BP";
	cin >> type;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "data: (yyyy.mm.dd):";
	getline(cin, data);
	if (type == 1)
	{
		cout << "value:";
		cin >> value;
		this->serv.servAdd(new BMI(data, value));
	}
	else
	{
		cout << "systolicValue:";
		cin >> systolicValue;
		cout << "diastolicValue:";
		cin >> diastolicValue;
		this->serv.servAdd(new BP(data, systolicValue, diastolicValue));
	}
	uiShow();
}

void UI::uiRemove()
{
	string data;
	cout << "What do you want to add: \n1. BMI \n2. BP";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "data: (yyyy.mm.dd):";
	getline(cin, data);
	this->serv.servRemove(new BMI(data, 0.00));
	uiShow();
}

void UI::uiShow()
{
	std::vector<MedicalAnalysis*> all = this->serv.servShowAll();
	int i = 1;
	for (auto a : all)
	{
		cout << i << ". " << a->toString() << '\n';
		i++;
	}
}

void UI::uiShowIll()
{
	int month;
	cout << "month: ";
	cin >> month;
	bool ok = this->serv.servShowIfIll(month);
	if (ok == true) 
		cout << "Person is not ill.";
	else cout << "Person is ill.";
}

void UI::uiSaveToFile()
{
	int month1, month2;
	string filename;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "filename:";
	getline(cin, filename);
	cout << "month1: ";
	cin >> month1;
	cout << "month2: ";
	cin >> month2;
	this->serv.servSaveToFile(filename, month1, month2);
}
