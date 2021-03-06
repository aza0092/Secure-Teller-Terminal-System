# Secure Teller Terminal System - C++ based software

![main screen](https://github.com/aza0092/Secure-Teller-Terminal-System/blob/master/src/rsz_1atm.jpg)

## Description

The teller terminal system comprises of multiple branches where each account contains a unique account number, a balance, as well as other important information.

In this system, there are 3 types of users – system administrators, branch staff, and clients. Any system administrator can add a new branch staff member to access the system or delete existing staff members from the system.

The system authenticates each access request to the system. Also, the teller terminal is either in the idle state or the active state.

In the Idle State: displays a login menu. It invites a branch employee to enter a userid and password and either (i) to manage client and account information or (ii) add/delete a user (branch staff) if the user is a system administrator or (iii) to change his/her password. In all the cases, the information provided is checked for validity.

In Active State: For system administrators, the teller terminal displays a “System Administration” main menu that invites an administrator to manage information of branch staff members, clients, and accounts or change password. For branch staff, the teller displays a “Branch Staff” main menu that invites a branch staff member to manage client and account information or change password.


## Technical 
- `Account` holds and manages accounts info for a client. 
- `AdminAndBranch` holds functionalities for admin and branch staff.
- `Client` holds and manages client's info.
- `Main` displays the menus for the terminal and takes input from user.
- `Menu` creates the menus for the different user roles.
- `account-info.txt` stores account info for a client (account number - account type - balance).
- `client-info.txt` stores clients info (name - address - SSN- Employer - Employer).
- `staff.txt` used store admin and branch staff info (role - ID - name).

## Images
| ![](https://github.com/aza0092/Secure-Teller-Terminal-System/blob/master/src/media/admin_login.PNG) | ![](https://github.com/aza0092/Secure-Teller-Terminal-System/blob/master/src/media/branch_login.PNG) |
|:---:|:---:|
| Admin login and options available for this role  | Branch Staff login and options available for this role   |



| ![](https://github.com/aza0092/Secure-Teller-Terminal-System/blob/master/src/media/add_new_client.PNG) |
|:---:|
| Add a new Client to ther teller system |



|![](https://github.com/aza0092/Secure-Teller-Terminal-System/blob/master/src/media/add_new_account.PNG) |
|:---:|
| Add a new account to an existing Client |



| ![](https://github.com/aza0092/Secure-Teller-Terminal-System/blob/master/src/media/display_staff.PNG) |
|:---:|
| All options available for an admin (shown: display all existing admin and staff in the system |



| ![](https://github.com/aza0092/Secure-Teller-Terminal-System/blob/master/src/media/client_options.PNG) |
|:---:|
| All the options available to assist a Client |
