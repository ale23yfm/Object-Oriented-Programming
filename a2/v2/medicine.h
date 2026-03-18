#pragma once
typedef struct {
	char* name;
	int concentration;
	int quantity;
	int price;
}Medicine;

Medicine* addMedicine(char* name, int concentration, int quantity, int price);
void deleteMedicine(Medicine* m);
Medicine* copyMedicine(Medicine* m);

char* getName(Medicine* m);
int getConc(Medicine* m);
int getQty(Medicine* m);
int getPrice(Medicine* m);

void toString(Medicine* m, char str[], int maxSize);