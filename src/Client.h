#pragma once
#include "Menu.h"
#include <fstream>

class Client:Menu {
public:
	Client();

	string getClientName();

	void addClient();
	void editClient();
	void saveClient();

private:
	string name; //temporary variable
	string address;
	string ssn;
	string employer;
	int income;
	string nameToSaveToFile; //used fixed
protected:
	ifstream clientInFile;
	ofstream clientOutFile;
};