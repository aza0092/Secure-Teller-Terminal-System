#pragma once
#include "Client.h"
#include <iostream>
#include <string>
#include "stdafx.h"
#include "Account.h"

Account::Account() {
	accountInFile.open("account-info.txt"); // account file
	if (accountInFile.fail()) {
		cout << "\naccount-info file opening failed. If the account-info file is not created yet, please create one. Otherwise, if the file already exists. make sure it is named with all letters in lowercase" << endl;
		cout << "\n\nPress any key to continue...";
		cin.ignore().get();
		exit(0);
	}
}

void Account::addAccount() {

	if (clientInFile.peek() == std::ifstream::traits_type::eof()) //check client info txt file is empty
	{
		cout << "\n\nAdding an account is not possible. No Client is present in the system since the client-info text file is empty\n\nPress any key to continue...";
		cin.ignore().get();
		exit(0);
	}

	else {
		string name = "";
		string str = "";
		bool nameFound = false;

		cout << "\nChoose a client: ";
		cin.ignore();
		getline(cin, name);
		while (getline(clientInFile, str)) { //first time entering client name
			if (str == name) {
				nameFound = true;
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
					break;
				}
			}
		}

		if (nameFound == true) {
			cout << "\nA new account will be created for " << name << "...\n\n";
			cout << "Account number: ";
			getline(cin, accountNumberToSaveToFile);
			cout << "Account type: ";
			getline(cin, type);
			cout << "Balance: ";
			cin >> balance;
			cout << "\n\nA new account was created for " << name << "\nMake sure to save it to file(option 6)\n\nPress any key to continue...\n\n";
			cin.ignore().get();
		}
	}
}

void Account::saveAccount() {
	accountOutFile.open("account-info.txt"); // account file
	if (accountOutFile.fail()) {
		cout << "\naccount-info file creation failed. Make sure it is written in lowercase" << endl;
		cout << "\n\nPress any key to continue...";
		cin.ignore().get();
		//exit(0);
	}

	else
		accountOutFile << accountNumberToSaveToFile << endl;
	accountOutFile << type << endl;
	accountOutFile << balance << endl;

	cout << "\nAccount information has been saved in the account-info file\n\nPress any key to continue...";
	cin.ignore().get();
	//exit(0);
}

void Account::manageAccount() {

	if (accountInFile.peek() == std::ifstream::traits_type::eof()) //check client info txt file is empty
	{
		cout << "\n\nEditing an Account is not possible. The account-info text file is empty\n\nPress any key to continue...";
		cin.ignore().get();
		exit(0);
	}
	else {

		string num = ""; //account #
		string str = "";
		int deposit = 0;
		int withdraw = 0;
		bool numberFound = false;
		string line = "";
		int userInput = 0;
		int count = 0;
		bool end = false; //used to determine when to stop displaying the deposit/withdraw/cancel menu


		cout << "\nWhich Account will be managed? ";
		cin.ignore();
		getline(cin, num);
		while (getline(accountInFile, str)) { //first time entering acct number
			if (str == num) {
				numberFound = true;
				accountNumberToSaveToFile = num;
				break;
			}
		}

		while (numberFound == false) { //keep checking if account number isnt in system
			cout << "\nError! The account number " << num << " is not in the system.\n";
			str = "";
			num = "";
			accountInFile.clear();
			accountInFile.seekg(0, std::ios::beg);
			cout << "\nWhich Account will be managed? ";
			//cin.ignore();
			getline(cin, num);
			while (getline(accountInFile, str)) {
				if (str == num) {
					numberFound = true;
					accountNumberToSaveToFile = num;
					break;
				}
			}
		}
		accountInFile.clear();
		accountInFile.seekg(0, std::ios::beg);
		if (numberFound == true) {

			//get balance from acct file
			for (int i = 0; i < 3; i++) { 	// from http://stackoverflow.com/questions/5207550/in-c-is-there-a-way-to-go-to-a-specific-line-in-a-text-file
				getline(accountInFile, line);
				if (i == 1) { //set acct type 
					type = line;
				}
			}
			int value = atoi(line.c_str()); // convert from string to int
			balance = value; //save to acct 

			//get client name from client txt file
			for (int i = 0; i < 1; i++) {
				getline(clientInFile, line);
			}

			cout << "\nManage account " << accountNumberToSaveToFile << " for " << line;
			cout << "\n1) Deposit\n2) Withdraw\n3) Cancel\n\nPlease choose an option: ";
			cin >> userInput;
			while (userInput != 1 && userInput != 2 && userInput != 3) {
				cout << "\nPlease only enter 1, 2, or 3.\n";
				cout << "\n1) Deposit\n2) Withdraw\n3) Cancel\n\nPlease choose an option: ";
				cin >> userInput;
			}
			while (end == false) {
				if (userInput == 1) { //deposit
					cout << "\nDeposit amount: ";
					cin >> deposit;
					balance += deposit;
					cout << "New Balance for account# " << accountNumberToSaveToFile << " is: " << balance;
				}

				else if (userInput == 2) { //withdraw
					cout << "\nWithdraw amount: ";
					cin >> withdraw;
					balance -= withdraw;
					cout << "New Balance for account# " << accountNumberToSaveToFile << " is: " << balance;
				}

				else if (userInput == 3) { //cancel
					end = true;
					cin.get();
				}

				if (end == false) {
					cout << "\n\nManage account " << accountNumberToSaveToFile << " for " << getClientName();
					cout << "\n1) Deposit\n2) Withdraw\n3) Cancel\n\nPlease choose an option: ";
					cin >> userInput;
					while (userInput != 1 && userInput != 2 && userInput != 3) {
						cout << "\nPlease only enter 1, 2, or 3.\n";
						cout << "\n1) Deposit\n2) Withdraw\n3) Cancel\n\nPlease choose an option: ";
						cin >> userInput;
					}
				}
			}

		}
	}
}