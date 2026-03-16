#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "repo.h"

int main(int argc, char** argv)
{
	printf("Hi, John! Here is your Smiles Pharmacy stock =)!\n");
	char o;
	char name[100], word[100];
	int con, qty, p;
	repo *pharmacy = repoInit();

	while (1)
	{
		printf("\nPlease choose an option:\n");
		printf("1. Add a medicine.\n");
		printf("2. Delete a medicine.\n");
		printf("3. Update a medicine.\n");
		printf("4. Search for a medicine.\n");
		printf("5. See medicines less than a quantity.\n");
		printf("6. Undo.\n");
		printf("7. Redo.\n");
		printf("8. Extra requirement.\n");
		printf("9. Exit.\n");
		printf("Your option is:");

		scanf_s(" %c", &o);
		while (getchar() != '\n');

		printf("\n");

		if(!isdigit(o))
			printf("Wrong input, Johnny. Try again with a number between 1-8.\n");

		else if (o < '1' || o > '9')
			printf("Wrong input, Johnny. Try again with a number between 1-8.\n");

		//Add a medicine
		else if (o == '1')
		{
			printf("You chose to add a medicine. You have to type \n");
			printf("<name>\n<concentration> <quantity> <price>\n");
			scanf_s(" %99[^\n]", name, 100);
			scanf_s(" %d %d %d", &con, &qty, &p);

			medicine* m = addMedicine(name, con, qty, p);
			addMedicineToRepo(pharmacy, m);
			printf("Added successfully! \nLook there:\n");
			printMedicines(pharmacy);
		}

		//Delete a medicine
		else if (o == '2')
		{
			printf("You chose to delete a medicine. You have to type \n<name> <concentration>\n");
			scanf_s(" %99[^\n]", name, 100);
			scanf_s(" %d", &con);

			printf("\nThis WAS your data:\n");
			printMedicines(pharmacy);

			deleteMedicineFromRepo(pharmacy, name, con);

			printf("\nNOW! This IS your data:\n");
			printMedicines(pharmacy);						
		}

		//Update a medicine
		else if (o == '3')
		{
			printf("You chose to update a medicine. You have to type \n");
			printf("<name>\n<concentration> <new price>\n");
			scanf_s(" %99[^\n]", name, 100);
			scanf_s(" %d %d", &con, &p);

			printf("\nThis WAS your data:\n");
			printMedicines(pharmacy);

			updateMedicineFromRepo(pharmacy, name, con, p);

			printf("Updated successfully! \nLook there:\n");
			printMedicines(pharmacy);
		}

		//Search for a medicine
		else if (o == '4')
		{
			printf("You chose to search for a medicine. You have to type \n<word>\n");
			int read = scanf_s("%99[^\n]", word, 100);
			while (getchar() != '\n');

			repo* result;

			if (read != 1)
				result = pharmacy;
			else
				result = searchForMedicinePartialName(pharmacy, word);

			if (result->count == 0)
			{
				printf("There is no medicine containing this name. \nThis is your data base:\n");
				printMedicines(pharmacy);
			}
			else
			{
				medicine* temp;
				for (int i = 0; i < result->count - 1; i++)
					for (int j = i + 1; j < result->count; j++)
						if (strcmp(result->items[i]->name, result->items[j]->name) > 0)
						{
							temp = result->items[i];
							result->items[i] = result->items[j];
							result->items[j] = temp;
						}
				printMedicines(result);
			}
			free(result);
		}

		//See medicines less than a quantity
		else if (o == '5')
		{
		}

		//Undo
		else if (o == '6')
		{
		}

		//Redo
		else if (o == '7')
		{
		}

		//For a given medication name, see all medications, sorted descending by price.
		else if (o == '8')
		{
			printf("You chose to see all specified medicines sorted descending by price. \nYou have to type \n<name>\n");
			int read = scanf_s("%99[^\n]", word, 100);
			while (getchar() != '\n');

			repo* result;

			if (read != 1)
				result = pharmacy;
			else
				result = searchForMedicineFullName(pharmacy, word);

			if (result->count == 0)
			{
				printf("There is no medicine containing this name. \nThis is your data base:\n");
				printMedicines(pharmacy);
			}
			else
			{
				medicine* temp;
				for (int i = 0; i < result->count - 1; i++)
					for (int j = i + 1; j < result->count; j++)
						if (result->items[i]->price < result->items[j]->price)
						{
							temp = result->items[i];
							result->items[i] = result->items[j];
							result->items[j] = temp;
						}
				printMedicines(result);
			}
			free(result);
		}

		//Exit
		else if (o == '9')
		{
			printf("Goodbye!\n");
			destroyRepo(pharmacy);
			return 0;
		}
	}
	return 0;
}