#pragma once
#include <iostream>
using namespace std;

/*
* Menu class- used to handle all user invalid inputs.
*/
class Menu
{
public:
	Menu();
	Menu(int);

	void firstAdminMenu();
	void secondAdminMenu();
	void role1Menu();
	void role2Menu();
	void firstBranchMenu();
	void secondBranchMenu();


	int getUserInput();
	void setUserInput(int);

private:
	int userInput;
};