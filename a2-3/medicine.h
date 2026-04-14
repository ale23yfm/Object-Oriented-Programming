#pragma once
typedef struct {
	char* name;
	int concentration;
	int quantity;
	int price;
}Medicine;

/// <summary>
/// Creates a medicine
/// </summary>
/// <param name="name">medicine's name</param>
/// <param name="concentration">medicine's concentration</param>
/// <param name="quantity">medicine's quantity</param>
/// <param name="price">medicine's price</param>
/// <returns></returns>
Medicine* addMedicine(char* name, int concentration, int quantity, int price);

/// <summary>
/// Deletes a medicine
/// </summary>
/// <param name="m">the medicine to be deleted</param>
void deleteMedicine(Medicine* m);

/// <summary>
/// Makes a deep copy of the medicine
/// </summary>
/// <param name="m">the medicine to be copied</param>
/// <returns>the copy of the medicine</returns>
Medicine* copyMedicine(Medicine* m);

/// <summary>
/// Gets medicine's name
/// </summary>
/// <param name="m">the given medicine</param>
/// <returns>medicine's name</returns>
char* getName(Medicine* m);

/// <summary>
/// Gets medicine's concentration
/// </summary>
/// <param name="m">the given medicine</param>
/// <returns>medicine's concentration</returns>
int getConc(Medicine* m);

/// <summary>
/// Gets medicine's quantity
/// </summary> 
/// <param name="m">the given medicine</param>
/// <returns>medicine's quantity</returns>
int getQty(Medicine* m);

/// <summary>
/// Gets medicine's price
/// </summary>
/// <param name="m">the given medicine</param>
/// <returns>medicine's price</returns>
int getPrice(Medicine* m);

/// <summary>
/// Prints the medicine
/// </summary>
/// <param name="m">the given medicine</param>
/// <param name="str">where is stored</param>
/// <param name="maxSize">maximum size of the print</param>
void toString(Medicine* m, char str[], int maxSize);

/// <summary>///Tests/// </summary>
void testsMedicine();