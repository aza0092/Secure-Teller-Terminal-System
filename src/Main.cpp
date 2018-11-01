/*
*  	   Created on: April, 28, 2017
*      Author: Abdullah Alali - AZA0092
*	   Filenames: Main.cpp - Client.cpp - Account.cpp - Menu.cpp - AdminAndBranch.cpp - stdafx.cpp
*      For: COMP 2710 - Project 2
*	   INSTRUCTIONS:	1) the staff text file MUST follow the following format in order for the program to work properly(my zip code already has a staff text file filled with a similar format): 
*										staff_name
*										staff_password
*										staff_role ** MUST either be: "System_Administrator or "Branch_Staff" ** (EXACT wording must be followed)
*
*	                	2) In my program, I assumed that all the staff (admin + branch) as well as the clients have unique names (as assumed in the project pdf file on canvas on pages 2 and 5). If names are not unique, my program may not work properly.
*	                	3) Please cretae the following files before executing the program: "staff.txt", "client-info.txt", "account-info.txt". You may leave these files empty or you may choose to fill them(please follow exact format if you choose to fill them).
*	                	4) Passwords for "adding new branch staff" must be at least 4 characters long.
*                       5) A new client + their account info will not be saved if you do not select the save option after creating a new client or account. Also, editing a client info + managing teir account(deposit/withdraw) info will not be saved if option 5 or 6 are not selected at the end. To save any new or updated client and account info for future use, please choose option "5" to save client info or choose option "6" to save the account info. Please do this before closing the program.
*						6) Please follow the same format for the client and account text files in the zip code if you need to create your own text file for testing purposes.
*/

#include "Client.h"
#include "Account.h"
#include "stdafx.h"
#include "Menu.h"
#include "AdminAndBranch.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <limits>

using namespace std;
using std::ifstream;
using std::ofstream;

void keyPress(); // function for user input

int main() {
	int input = 0;

	cout << "===========================================================\n|       Welcome to the Auburn Branch of Tiger Bank!       |\n===========================================================\n1) Login\n2) Quit\n\nPlease choose an option: ";
	cin >> input;
	Menu menu(input); //check for invalid input
	menu.firstAdminMenu();
	input = menu.getUserInput();
	int usernameLineAt = 0; //position of username to check if the user's password is right after their username
	int passwordLineAt = 0;
	string role = ""; // to use to determine which menu to show for admin/branch staff


	if (input == 1) { //User chooses to login
		AdminAndBranch admin;
		Account account;
		Client client;
		bool end = false; //to use to determine when to close program 
		string username = "";
		string password = "";
		cout << "===========================================================\n|       Login to Access the Teller Terminal System        |\n===========================================================\n";
		if ((admin.checkStaffFileIsEmpty()) == true) { //no previous staff created/first login
			cout << "Username: ";
			cin >> username;
			cout << "Password: ";
			cin >> password;
			while (username != "admin" || password != "0000") { // check if username is not "admin" and password is not "0000" (no staff created yet/first time ever login)
				cout << "\nThe user name or password is incorrect. Try again!\n";
				cout << "\nUsername: ";
				cin >> username;
				cout << "Password: ";
				cin >> password;
			}
			ofstream outFile;
			outFile.open("staff.txt", ios::app);
			outFile << "admin" << endl;
			outFile << "0000" << endl;
			outFile << "System_Administrator" << endl;
		}

		else if ((admin.checkStaffFileIsEmpty()) == false) { // prev staff exist in staff file
			int userAtLine = 0;
			string line;
			ifstream inStream;
			bool usernameFound = false;
			bool passwordFound = false;

			inStream.open("staff.txt");

			//cout << "prev staff exist";
			// prev staff exist. check username and password here
			while (usernameFound != true || passwordFound != true) {
				cout << "Username: ";
				cin >> username;
				cout << "Password: ";
				cin >> password;

				//if (username == "admin" && password == "0000") { //if prev staff exist, remember to also check for the default log in
				//	usernameFound = true;
				//	passwordFound = true;
				//	break;
				//}
				//else

					//find matching username
				while (inStream >> line) {
					usernameLineAt++;
					if (line.find(username, 0) != string::npos) {
						//cout << "found: " << line;
						usernameFound = true;
						break;
					}
				}

				int findRole = 0;
				passwordLineAt = usernameLineAt;
				//find matching password
				while (inStream >> line) {
					usernameLineAt++;
					findRole++;
					//string us = sizeof(username);
					//size_t
					//count s;
					if (line.find(password, 0) != string::npos) {
						if (passwordLineAt == usernameLineAt - 1) { //find if password is one line after username line
							if (line.length() == password.length()) { //make sure length match
							//	cout << "found password: ";
								passwordFound = true;
							}
							//else cout << "password not found";
							//break;
						}
					}
					else if (findRole == 2) { //role will be 3rd line. find role here
						role = line;
					}
				}
				usernameLineAt = 0; //reset
				passwordLineAt = 0;

				if ((usernameFound != true) || (passwordFound != true)) { //if either is wrong
					cout << "\nThe user name or password is incorrect. Try again!\n";
				}
				inStream.clear();                 // clear fail and eof bits
				inStream.seekg(0, std::ios::beg); // back to the start!
			}
		}

		if (role == "System_Administrator") { //menu for admin

			cout << "===========================================================\n|       Teller Terminal System – System Administration    |\n===========================================================\n1) Client and Account management\n2) Add a branch staff member\n3) Delete a branch staff member\n4) Display branch staff\n5) Change password\n6) Exit\n\nPlease choose an option: ";
			cin >> input;
			menu.setUserInput(input);
			menu.secondAdminMenu();
			input = menu.getUserInput(); //get the correct input

			if (input == 1) { 				//client and account management (for admin not branch staff)

				if (input == 1) { 				// client and account mangement
					cout << "===========================================================\n| Teller Terminal System – Client and Account Management  |\n===========================================================\n1) Add a Client\n2) Add an Account\n3) Edit Client Information\n4) Manage an Account\n5) Save Client Information\n6) Save Account Information\n7) Exit\n\nPlease choose an option: ";
					cin >> input;
					menu.setUserInput(input);
					menu.secondBranchMenu();
					input = menu.getUserInput(); //get the correct input

					while (end == false) { //close program
						if (input == 1) { //add client
							client.addClient();
						}

						else if (input == 2) { //add account
							account.addAccount();
						}

						else if (input == 3) { // edit client
							client.editClient();
						}

						else if (input == 4) { //manage acct
							account.manageAccount();
						}


						else if (input == 5) { //save client to txt file
							client.saveClient();
						}

						else if (input == 6) { //save account to txt file
							account.saveAccount();
						}

						else if (input == 7) { //exit option
							exit(0);
						}

						if (end == false) { //keep displaying the menu until user quits
							input = 0;
							// cin.clear();
							cout << "===========================================================\n| Teller Terminal System – Client and Account Management  |\n===========================================================\n1) Add a Client\n2) Add an Account\n3) Edit Client Information\n4) Manage an Account\n5) Save Client Information\n6) Save Account Information\n7) Exit\n\nPlease choose an option: ";
							//cin.get(input);
							cin.clear();
							//	 cin.ignore().get();
							cin >> input;
							//cin.ignore();
							menu.setUserInput(input);
							menu.secondBranchMenu();
							input = menu.getUserInput(); //get the correct input
						}
					}

				}
			}

			if (input == 2) { //add branch staff
				admin.addBranchStaff();
			}

			if (input == 3) { //delete staff
				admin.deleteBranchStaff();
			}

			if (input == 4) { //display branch staff
				admin.displayBranchStaff();
				keyPress();
			}

			if (input == 5) { //change user's password
				admin.changePassword(username);
			}

			if (input == 6) { //User chooses to quit the second menu (option# 6)
				exit(0);
			}
		}

		else if (role == "Branch_Staff") { //menu for branch staff
			cout << "===========================================================\n|       Teller Terminal System – Branch Staff             |\n===========================================================\n1) Client and Account management\n2) Change Password\n3) Exit\n\nPlease choose an option: ";
			cin >> input;
			menu.setUserInput(input);
			menu.firstBranchMenu();
			input = menu.getUserInput(); //get the correct input

			if (input == 1) { 				// client and account mangement
				cout << "===========================================================\n| Teller Terminal System – Client and Account Management  |\n===========================================================\n1) Add a Client\n2) Add an Account\n3) Edit Client Information\n4) Manage an Account\n5) Save Client Information\n6) Save Account Information\n7) Exit\n\nPlease choose an option: ";
				cin >> input;
				menu.setUserInput(input);
				menu.secondBranchMenu();
				input = menu.getUserInput(); //get the correct input
				while (end == false) { //close program
					if (input == 1) { //add client
						client.addClient();
					}

					else if (input == 2) { //add account
						account.addAccount();
					}

					else if (input == 3) { //edit client
						client.editClient();
					}

					else if (input == 4) { //manage acct
						account.manageAccount();
					}

					else if (input == 5) { //save client to txt file
						client.saveClient();
					}

					else if (input == 6) { //save account to txt file
						account.saveAccount();
					}

					else if (input == 7) { //exit option
						exit(0);
					}

					if (end == false) { //keep displaying the menu until user quits
						input = 0;
						// cin.clear();
						cout << "===========================================================\n| Teller Terminal System – Client and Account Management  |\n===========================================================\n1) Add a Client\n2) Add an Account\n3) Edit Client Information\n4) Manage an Account\n5) Save Client Information\n6) Save Account Information\n7) Exit\n\nPlease choose an option: ";
						//cin.get(input);
						cin.clear();
						//	 cin.ignore().get();
						cin >> input;
						//cin.ignore();
						menu.setUserInput(input);
						menu.secondBranchMenu();
						input = menu.getUserInput(); //get the correct input
					}
				}
			}

			if (input == 2) { //change password
				admin.changePassword(username);
			}

			else if (input == 3) { //exit
				exit(0);
			}
		}

		else if (username != "admin") { //role is written incorrectly in staff text file. Must be either "System_Administrator" or "Branch_Staff"
			cout << "\n\nPassword is correct. However, the system cannot proceed.\nMake sure the role in the staff text file is either\n\nSystem_Administrator\n\nor\n\nBranch_Staff";
			keyPress();
		}
	}

	else { //User chooses to quit the first main menu 
		exit(0);
	}
	return 0;
}

/*
* to pause screen and prevent it from closing immediately
*/
void keyPress() {
	cout << "\n\nPress any key to continue...";
	cin.ignore().get(); //Pause Command for Linux Terminal
}