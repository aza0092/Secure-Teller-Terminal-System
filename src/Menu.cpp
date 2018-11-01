#include "Menu.h"

//default constructor
Menu::Menu()
{
	userInput = 0;
}

/*
* constructor.
*/
Menu::Menu(int optionInput) {
	userInput = optionInput;
}

/*
* getter for user input.
*/
int Menu::getUserInput() {
	return userInput;
}

/*
* setter for user input.
*/
void Menu::setUserInput(int input) {
	userInput = input;
}

/*
* Handling invalid user input during the very first menu at the start of the program.
*/
void Menu::firstAdminMenu() {
	while (userInput != 1 && userInput != 2) {
		cout << "\nPlease only enter 1, or 2.\n";
		cout << "\n1) Login\n2) Quit\n\nPlease choose an option: ";
		cin >> userInput;
	}
}

/*
* Handling invalid user input for game options
*/
void Menu::secondAdminMenu() {
	while (userInput != 1 && userInput != 2 && userInput != 3 && userInput != 4 && userInput != 5 && userInput != 6) {
		cout << "\nPlease only enter 1,2, 3, 4, 5, or 6.\n";
		cout << "\n1) Client and Account Management\n2) Add a branch staff member\n3) Delete a branch staff member\n4) Display branch staff\n5) Change password\n6) Exit\n\nPlease choose an option: ";
		cin >> userInput;
	}
}

void Menu::role1Menu() {
	while (userInput != 1 && userInput != 2) {
		cout << "\nPlease only enter 1, or 2.\n";
		cout << "\nRole(1/ Administrator; 2/ Branch Staff): ";
		cin >> userInput;
	}
}

void Menu::role2Menu() {
	while (userInput != 1 && userInput != 2) {
		cout << "\nPlease only enter 1, or 2.\n";
		cout << "\n1) Confirm\n2) Cancel\n\nPlease choose an option: ";
		cin >> userInput;
	}
}

void Menu::firstBranchMenu() {
	while (userInput != 1 && userInput != 2 && userInput != 3) {
		cout << "\nPlease only enter 1, 2, or 3.\n";
		cout << "\n1) Client and Account Management\n2) Change password\n3) Exit\n\nPlease choose an option: ";
		cin >> userInput;
	}
}

void Menu::secondBranchMenu() {
	while (userInput != 1 && userInput != 2 && userInput != 3 && userInput != 4 && userInput != 5 && userInput != 6 && userInput != 7) {
		cout << "\nPlease only enter 1,2, 3, 4, 5, 6, or 7.\n";
		cout << "\n1) Add a client\n2) Add an account\n3) Edit Client information\n4) Manage an account\n5) Save Client Information\n6) Save Account Information\n7) Exit\n\nPlease choose an option: ";
		cin >> userInput;
	}
}