#pragma once
#include "Menu.h"
#include <fstream>


class AdminAndBranch : Menu {
public:
	AdminAndBranch();

	//string getPassword();
	//void setPassword(string);
	//string getUsername();
	//void setUsername(string);
	void addBranchStaff();
	void deleteBranchStaff();
	void displayBranchStaff();
	void changePassword(string);
	bool checkStaffFileIsEmpty();

private:
	string password;
	string username;
	ifstream inFile;
	ofstream outFile;
};