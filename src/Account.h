#pragma once
#include "Client.h"
#include <fstream>
#include <iostream>
#include <string>


class Account : Client {
public:
	Account();

	void addAccount();
	void manageAccount();
	void saveAccount();


private:
	int balance;
	string type;
	string number;
	string accountNumberToSaveToFile;

	ifstream accountInFile;
	ofstream accountOutFile;
};