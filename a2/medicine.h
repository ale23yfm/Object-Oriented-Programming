#pragma once
typedef struct {
	char *name;
	int concentration;
	int quantity;
	int price;
}medicine;

medicine* addMedicine(char *name, int concentration, int quantity, int price);
void deleteMedicine(medicine* m);
