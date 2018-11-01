#pragma once
#include <iostream>
#include <string>
#include "AdminAndBranch.h"
#include "stdafx.h"

using namespace std;

AdminAndBranch::AdminAndBranch() {
	inFile.open("staff.txt"); // admin and branch staff file
	if (inFile.fail()) {
		cout << "\nstaff file opening failed. If the staff file is not created yet, please create one. Otherwise, if the file already exists. make sure it is named with all letters in lowercase" << endl;
		cout << "\n\nPress any key to continue...";
		cin.ignore().get();
		exit(0);
	}
}

//string AdminAndBranch::getUsername() {
//	return username;
//}
//
//string AdminAndBranch::getPassword() {
//	return password;
//}
//
//void AdminAndBranch::setUsername(string u) {
//	username = u;
//}
//
//void AdminAndBranch::setPassword(string p) {
//	password = p;
//}

void AdminAndBranch::addBranchStaff() {
	int userInput = 0;
	int role = 0;
	int firstTime = 0;
	//username = ""; //reset username and password so that they not filled with existing u and p
	password = "";

	cout << "Username: ";
	cin >> username;

	while (password.length() < 4) {
		if (firstTime == 1) {
			cout << "\nPassword must have a min of 4 characters.\n";
			cout << "Password: ";
			cin >> password;
		}
		else {
			cout << "Password: ";
			cin >> password;
			firstTime = 1;
		}
	}
	cout << "\nRole ( 1/ Administrator; 2/ Branch Staff): ";
	cin >> role;
	setUserInput(role);
	role1Menu();
	role = getUserInput(); //get the correct input for next game option

	cout << "\n1) Confirm\n2) Cancel\n\nPlease choose an option: ";
	cin >> userInput;
	setUserInput(userInput);
	role2Menu();
	userInput = getUserInput(); //get the correct input for next game option
	if (userInput == 1) {
		cout << "\nA new staff member is added!\n";
		cout << "Username: " << username << " Role: ";
		if (role == 1) {
			cout << "System Administrator";
		}

		else {
			cout << "Branch Staff";
		}

		//write new staff to file
		outFile.open("staff.txt",ios::app);
		outFile << username << endl;
		outFile << password << endl;
		if (role == 1) {
			outFile << "System_Administrator" << endl;
		}

		else {
			outFile << "Branch_Staff" << endl;
		}

		outFile.close();

		cout << "\n\nPress any key to continue.. ";
		cin.ignore().get();
	}
	else {
		exit(0);
	}
}

bool AdminAndBranch::checkStaffFileIsEmpty() {

	if (inFile.peek() == std::ifstream::traits_type::eof())
	{
		return true;
	}
	else {
		return false;
	}
}

void AdminAndBranch::displayBranchStaff() {
	inFile.clear();                 // clear fail and eof bits
	inFile.seekg(0, std::ios::beg); // back to the start!
	string line = "";
	int countUsers = 0;
	ofstream outFile;
	outFile.open("staff.txt", ios::app);
	while (inFile >> line) {
		countUsers++;
	}
	inFile.clear();
	inFile.seekg(0, std::ios::beg); 

	cout << "\nThere are " << countUsers / 3 << " users in the system.\n";
	while (inFile >> line) {
		cout << line << endl;
	}
}

void AdminAndBranch::deleteBranchStaff() {
	inFile.clear();
	inFile.seekg(0, std::ios::beg);
	string usernameToDelete = ""; //store username to delete
	int userInput = 0;
	bool userFound = false; //check if user is in system


	cout << "\nDelete a user - User Name: ";
	cin.ignore();
	//cin >> usernameToDelete;
	getline(cin, usernameToDelete);
	string line = "";
	string passwordToDelete = "";  //store password to delete
	string roleToDelete = "";  //store role to delete
	while (inFile >> line) { //get the info that needs to be deleted (username, password, and role)
		//goToLine++;
		if (line == usernameToDelete) {
			userFound = true;
			int stop = 0;
			while (inFile >> line) {
				stop++;
				if (stop == 1) { //second line is the password
					passwordToDelete = line;
				}
				else if (stop == 2) { //third line is the role
					roleToDelete = line;
					break;
				}
			}
		}
	}

	if (userFound == true) {
		outFile.open("temp.txt"); //store all users except deletd one in a temp file
		if (outFile.fail()) {
			cout << "\ntemp file opening failed."<< endl;
			cout << "\n\nPress any key to continue...";
			cin.ignore().get();
			exit(0);
		}	
		inFile.clear();
		inFile.seekg(0, std::ios::beg);
		line = "";
		while (inFile >> line) { //loop again from beginning to rewrite in temp file
			//if (line.find(usernameToDelete) == string::npos) { //username is found
			if (line != usernameToDelete && line != passwordToDelete && line != roleToDelete) { //copy everything but the users info who will be deleted
				//userFound = true;
				//cout << line << endl;
				outFile << line << endl;
			}
		}
	}

	 if (userFound == false) { //if no matching user found
		cout << "\nWarning! User " << usernameToDelete << " is not in the system. No user is deleted!\n\nPress any key to continue...";
		cin.get();
		exit(0);
	}

	else //if user targeted to be deleted is found in the system

		cout << "\n1) Confirm\n2) Cancel\n\nPlease choose an option: ";
	cin >> userInput;
	setUserInput(userInput);
	role2Menu();
	userInput = getUserInput(); //get the correct input for next game option

	if (userInput == 1) { //if user chooses confirm
		cout << "\nUser " << usernameToDelete << " was deleted!";
		cout << "\nPress any key to continue...";
		cin.ignore().get();

		outFile.close();
		inFile.close();
		remove("staff.txt");
		rename("temp.txt", "staff.txt");
		exit(0);
	}

	else { //user chooses to cancel
		exit(0);
	}
}

void AdminAndBranch::changePassword(string username) {
	string passwordToChange = "";
	string thisNEWPS = "";
	outFile.open("temp.txt"); //store all users except the current password



	inFile.clear();
	inFile.seekg(0, std::ios::beg);
	//string usernameToDelete = ""; //store username to delete
	int userInput = 0;
	//bool userFound = false; //check if user is in system
//	outFile.open("temp.txt"); //store all users except deletd one in a temp file


//	cout << "\nDelete a user - User Name: ";
//	cin >> usernameToDelete;
	string line = "";
	string currentPassword = "";  //store password to delete
	string replacePasswordInNewFile = "";
	//string roleToDelete = "";  //store role to delete
	while (inFile >> line) {
		if (line == username) {
			int stop = 0;
			while (inFile >> line) {
				stop++;
				if (stop == 1) { //second line is the current password
					currentPassword = line; //second line in staff text file will be user's current password

					cout << "\nNew Password: ";
					cin >> passwordToChange;

					while (currentPassword == passwordToChange || passwordToChange.length() < 4) {
						cout << "\nError! Your new password must be different from the old one!\nAlso, make sure the new password has at least 4 characters.\n";
						cout << "\nNew Password: ";
						cin >> passwordToChange;
					}
					//break;
					if (currentPassword != passwordToChange) {
						//replacePasswordInNewFile = line.replace(line.find(currentPassword),line.length(), passwordToChange);
						thisNEWPS = passwordToChange;
						break;
					}
				}
			}
		}
	}

	inFile.clear();
	inFile.seekg(0, std::ios::beg);
	line = "";

	while (inFile >> line) { //loop again from beginning to rewrite in temp file
		if (line == currentPassword) { //copy everything but the users info who will be deleted
			line = thisNEWPS;
		}
		outFile << line << endl;
	}

	outFile.close();
	inFile.close();
	remove("staff.txt");
	rename("temp.txt", "staff.txt");

	cout << "\n\nPassword was changed!Check staff file for the updated password.\nPress any key to continue...";
	cin.ignore().get();
}