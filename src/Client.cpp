#pragma once
#include <iostream>
#include <string>
#include "Client.h"
#include "stdafx.h"


Client::Client() {
	clientInFile.open("client-info.txt"); // client file
	if (clientInFile.fail()) {
		cout << "\nclient-info file opening failed. If the client-info file is not created yet, please create one. Otherwise, if the file already exists. make sure it is named with all letters in lowercase" << endl;
		cout << "\n\nPress any key to continue...";
		cin.ignore().get();
		exit(0);
	}
}

void Client::addClient() {
	cout << "\nA new Client will be added:\n\nClient name: ";
	cin.ignore();
	getline(cin, nameToSaveToFile);
	cout << "Address: ";
	getline(cin, address);
	cout << "Social Security Number: ";
	getline(cin, ssn);
	cout << "Employer: ";
	getline(cin, employer);
	cout << "Annual Income: ";
	cin >> income;
	cout << "\n\nA new client was added!\nMake sure to save it to file(option 5)\n\nPress any key to continue...";
	cin.ignore().get();
}

string Client::getClientName() {
	return nameToSaveToFile;
}

void Client::saveClient() {
	clientOutFile.open("client-info.txt"); // client file
	if (clientOutFile.fail()) {
		cout << "client-info file creation failed. Make sure it is written in lowercase" << endl;
		cout << "\n\nPress any key to continue...\n\n\n";
		cin.ignore().get();
	}

	else
		clientOutFile << nameToSaveToFile << endl;
	clientOutFile << address << endl;
	clientOutFile << ssn << endl;
	clientOutFile << employer << endl;
	clientOutFile << income << endl;

	cout << "\nClient information has been saved in the client-info file\n\nPress any key to continue...";
	cin.ignore().get();
}

void Client::editClient() {
	string name = "";
	string str = "";
	bool nameFound = false;
	int userInput = 0;
	int count = 0;

	if (clientInFile.peek() == std::ifstream::traits_type::eof()) //check client info txt file is empty before proceeding
	{
		cout << "\n\nEditing a client is not possible. No client is present in the system since the client-info text file is empty\n\nPress any key to continue...";
		cin.ignore().get();
		exit(0);
	}
	else

	cout << "\nChoose a client: ";
	cin.ignore();
	getline(cin, name);
	while (getline(clientInFile, str)) { //first time entering client name
		if (str == name) {
			nameFound = true;
			nameToSaveToFile = name;
			break;
		}
	}

	while (nameFound == false) { //keep checking if client isnt in system
		cout << "\nError! The client is not in the system.\n";
		str = "";
		name = "";
		clientInFile.clear();
		clientInFile.seekg(0, std::ios::beg);
		cout << "\nChoose a client: ";
		//cin.ignore();
		getline(cin, name);
		while (getline(clientInFile, str)) {
			if (str == name) {
				nameFound = true;
				nameToSaveToFile = name;
				break;
			}
		}
	}

	if (nameFound == true) {
		str = "";
		clientInFile.clear();
		clientInFile.seekg(0, std::ios::beg);
		cout << "\n\nDisplay " << name << " information:\n";
		while (getline(clientInFile, str)) { //display current client info to screen
			count++;
			if (count == 1) {
				cout << "Client Name: " << str << endl;
			}
			if (count == 2) {
				cout << "Address: " << str << endl;
			}
			if (count == 3) {
				cout << "Social Security Number: " << str << endl;
			}
			if (count == 4) {
				cout << "Employer: " << str << endl;
			}
			if (count == 5) {
				cout << "Annnual Income: " << str << endl;
			}
		}
		cout << "\n\nClient " << name << "'s will be updated...\n1) Confirm\n2) Cancel\n\nPlease choose an option: ";
		cin >> userInput;
		setUserInput(userInput);
		role2Menu();
		userInput = getUserInput(); //get the correct input for next game option
		if (userInput == 1) {
			cout << "\n\nAddress: ";
			cin.ignore();
			getline(cin, address);
			cout << "Social Security Number: ";
			getline(cin, ssn);
			cout << "Employer: ";
			getline(cin, employer);
			cout << "Annual Income: ";
			cin >> income;
			cout << "\nClient " << name << "'s information was updated.\nMake sure to save it to file(option 5)\n\nPress any key to continue...";
			cin.ignore().get();
		}
		else if (userInput == 2) {
			exit(0);
		}
	}
}