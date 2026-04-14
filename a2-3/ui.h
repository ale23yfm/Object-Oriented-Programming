#pragma once

#include "service.h"

typedef struct
{
	Service* serv;
} UI;

/// <summary>
/// Creates the ui
/// </summary>
/// <param name="s">service used</param>
/// <returns>the ui</returns>
UI* createUI(Service* s);

/// <summary>
/// Destroys the ui
/// </summary>
/// <param name="ui">the ui to be destroyed</param>
void destroyUI(UI* ui);

/// <summary>
/// Prints the menu
/// </summary>
void printMenu();

/// <summary>
/// Adds a medicine in ui
/// </summary>
/// <param name="ui">ui used</param>
void uiAddMedicine(UI* ui);

/// <summary>
/// Deletes the medicine in ui
/// </summary>
/// <param name="ui">ui used</param>
void uiDeleteMedicine(UI* ui);

/// <summary>
/// Updates a medicine in ui
/// </summary>
/// <param name="ui">ui used</param>
void uiUpdateMedicine(UI* ui);

/// <summary>
/// Searches all medicines having in the name a given string (full match)
/// </summary>
/// <param name="ui">ui used</param>
void uiSearchFullName(UI* ui);

/// <summary>
/// Searches the medicines with quantity less than a given quantity
/// </summary>
/// <param name="ui">ui used</param>
void uiInShortSearch(UI* ui);

/// <summary>
/// Undos the last operation
/// </summary>
/// <param name="ui">ui used</param>
void uiUndo(UI* ui);

/// <summary>
/// Redos the last operation
/// </summary>
/// <param name="ui">ui used</param>
void uiRedo(UI* ui);

/// <summary>
/// Searches all medicines having in their name a given word (partial match)
/// </summary>
/// <param name="ui">ui used</param>
void uiSearchPartialName(UI* ui);

/// <summary>
/// Searches all medicines having a given price
/// </summary>
/// <param name="ui">ui used</param>
void uiSearchByPrice(UI* ui);

/// <summary>
/// Searches all medicines having in their name a given word, sorted descending by concentration
/// </summary>
/// <param name="ui">ui used</param>
void uiSearchPartialNameSortConc(UI* ui);

/// <summary>
/// Lists all medicines in ui
/// </summary>
/// <param name="ui">ui used</param>
void listAllMed(UI* ui);

/// <summary>
/// Starts the ui
/// </summary>
/// <param name="ui">ui used</param>
void startUI(UI* ui);