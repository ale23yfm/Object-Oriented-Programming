#include "ui.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

UI* createUI(Service* s)
{
	UI* ui = malloc(sizeof(UI));
	if (ui == NULL)
		return NULL;
	ui->serv = s;
	return ui;
}

void destroyUI(UI* ui)
{
	servDestroy(ui->serv);
	free(ui);
}

void printMenu()
{
	printf("\nPlease choose an option:\n");
	printf("1. Add a medicine.\n");
	printf("2. Delete a medicine.\n");
	printf("3. Update a medicine.\n");
	printf("4. Search for a medicine by full name.\n");
	printf("5. See medicines less than a quantity (+bonus c).\n");
	printf("6. Undo.\n");
	printf("7. Redo.\n");
	printf("8. Search for a medicine by partial name (extra).\n");
	printf("9. Search for a medicine by price (bonus b).\n");
	printf("10. Print the data base.\n");
	printf("11. Exit.\n");
}

//1
void uiAddMedicine(UI* ui)
{
	char name[50];
	int conc, qty, price;

	printf("You chose to add a medicine. You have to type: \n");
	printf("name: ");
	scanf_s(" %[^\n]", name, (unsigned)_countof(name));
	printf("concentration: ");
	scanf_s("%d", &conc);
	printf("quantity: ");
	scanf_s("%d", &qty);
	printf("price: ");
	scanf_s("%d", &price);

	int res = servAddMed(ui->serv, name, conc, qty, price);
	if (res < 0)
		printf("\nSomething went wrong. Try again.");
	else
	{
		printf("\nMedicine added successfully! Look there:\n");
		listAllMed(ui);
	}
}

//2
void uiDeleteMedicine(UI* ui)
{
	char name[50];
	int conc;

	printf("You chose to delete a medicine. You have to type: \n");
	printf("name: \n");
	scanf_s(" %[^\n]", name, (unsigned)_countof(name));
	printf("concentration: ");
	scanf_s("%d", &conc);

	printf("\nThis WAS your data base:\n");
	listAllMed(ui);

	int res = servDeleteMed(ui->serv, name, conc);

	if (res < 0)
		printf("\nSomething went wrong. Try again.");
	else
	{
		printf("\nMedicine deleted successfully! Look there at the NEW data base:\n");
		listAllMed(ui);
	}
}

//3
void uiUpdateMedicine(UI* ui)
{
	char name[50];
	int conc, newPrice;

	printf("You chose to update a medicine. You have to type: \n");
	printf("name: \n");
	scanf_s(" %[^\n]", name, (unsigned)_countof(name));
	printf("concentration: ");
	scanf_s("%d", &conc);
	printf("new price: ");
	scanf_s("%d", &newPrice);

	printf("\nThis WAS your data base:\n");
	listAllMed(ui);

	int res = servUpdateMed(ui->serv, name, conc, newPrice);

	if (res < 0)
		printf("\nSomething went wrong. Try again.");
	else
	{
		printf("\nMedicine updated successfully! Look there at the NEW data base:\n");
		listAllMed(ui);
	}
}

//4
void uiSearchFullName(UI* ui)
{
	char name[50];

	printf("You chose to search a medicine by full name. You have to type: \n");
	printf("name: \n");
	scanf_s(" %[^\n]", name, (unsigned)_countof(name));

	DynamicArray *res = servFullNameSearch(ui->serv, name);

	if (getLength(res) == 0)
	{
		printf("\nNo medicine found! Look there at the entire data base:\n");
		listAllMed(ui);
		destroy(res);
		return;
	}

	for (int i = 0; i < getLength(res); i++)
	{
		Medicine* m = (Medicine*)get(res, i);
		char buffer[200];
		toString(m, buffer, 200);
		printf("%s\n", buffer);
	}

	destroy(res);
}

//5
void uiInShortSearch(UI* ui)
{
	int givenQty, sort;

	printf("You chose to see all medicines in short supply. Which sorting do you want?\n");
	printf("1. ascending sorting\n");
	printf("2. descending sorting\n");
	printf("Your option:");
	scanf_s("%d", &sort);

	printf("Now you have to type : \n");
	printf("quantity: ");
	scanf_s("%d", &givenQty);

	DynamicArray *res = servInShortQty(ui->serv, givenQty, sort);

	if (getLength(res) == 0)
	{
		printf("\nNo medicine found! Look there at the entire data base:\n");
		listAllMed(ui);
		destroy(res);
		return;
	}

	printf("\nMedicines with quantity < %d: \n", givenQty);

	for (int i = 0; i < getLength(res); i++)
	{
		Medicine* m = (Medicine*)get(res, i);
		char buffer[200];
		toString(m, buffer, 200);
		printf("%s\n", buffer);
	}

	destroy(res);
}

//6
void uiUndo(UI* ui)
{
	printf("\nThis WAS your data base:\n");
	listAllMed(ui);
	if (servUndo(ui->serv))
	{
		printf("Undo successful.\n");
		printf("Look there at the entire data base:\n");
		listAllMed(ui);
	}
	else
		printf("Nothing to undo.\n");
}

//7
void uiRedo(UI* ui)
{
	printf("\nThis WAS your data base:\n");
	listAllMed(ui);
	if (servRedo(ui->serv))
	{
		printf("Redo successful.\n");
		printf("Look there at the entire data base:\n");
		listAllMed(ui);
	}
	else
		printf("Nothing to redo.\n");
}

//8
void uiSearchPartialName(UI* ui)
{
	char name[50];

	printf("You chose to search a medicine by partial name. You have to type: \n");
	printf("name: \n");
	scanf_s(" %[^\n]", name, (unsigned)_countof(name));

	DynamicArray* res = servPartialNameSearch(ui->serv, name);

	if (getLength(res) == 0)
	{
		printf("\nNo medicine found! Look there at the entire data base:\n");
		listAllMed(ui);
		destroy(res);
		return;
	}

	for (int i = 0; i < getLength(res); i++)
	{
		Medicine* m = (Medicine*)get(res, i);
		char buffer[200];
		toString(m, buffer, 200);
		printf("%s\n", buffer);
	}

	destroy(res);
}

//9
void uiSearchByPrice(UI* ui)
{
	int price;

	printf("You chose to search a medicine by price. You have to type: \n");
	printf("price: ");
	scanf_s("%d", &price);

	DynamicArray* res = servSearchByPrice(ui->serv, price);

	if (getLength(res) == 0)
	{
		printf("\nNo medicine found! Look there at the entire data base:\n");
		listAllMed(ui);
		destroy(res);
		return;
	}

	for (int i = 0; i < getLength(res); i++)
	{
		Medicine* m = (Medicine*)get(res, i);
		char buffer[200];
		toString(m, buffer, 200);
		printf("%s\n", buffer);
	}

	destroy(res);
}

void listAllMed(UI* ui)
{
	int len = repoGetLength(ui->serv->repo);
	for (int i = 0; i < len; i++)
	{
		Medicine* m = repoFindMedAtPos(ui->serv->repo, i);
		char str[200];
		toString(m, str, 200);
		printf("%s\n", str);
	}
}

void startUI(UI *ui)
{
	int cmd = -1;
	printf("Hi, John! Here is your Smiles Pharmacy stock =)!\n");
	while (cmd != 11)
	{
		printMenu();
		printf("Your option:");
		scanf_s("%d", &cmd);
		switch (cmd)
		{
		case 1:
			uiAddMedicine(ui);
			break;
		case 2:
			uiDeleteMedicine(ui);
			break;
		case 3:
			uiUpdateMedicine(ui);
			break;
		case 4:
			uiSearchFullName(ui);
			break;
		case 5:
			uiInShortSearch(ui);
			break;
		case 6:
			uiUndo(ui);
			break;
		case 7:
			uiRedo(ui);
			break;
		case 8:
			uiSearchPartialName(ui);
			break;
		case 9:
			uiSearchByPrice(ui);
			break;
		case 10:
			listAllMed(ui);
			break;
		case 11:
			printf("\nGoodbye, Johnny!\n");
			break;
		default:
			printf("\nWrong input, Johnny. Try again with a number between 1-8.\n");
		}
	}
}
