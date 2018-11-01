# Secure Teller Terminal System - C++ based software

![main screen](https://github.com/aza0092/Secure-Teller-Terminal-System/blob/master/src/rsz_1atm.jpg)

## Description

The teller terminal system comprises of multiple branches where each account contains a unique account number, a balance, as well as other important information.

In this system, there are 3 types of users – system administrators, branch staff, and clients. Any system administrator can add a new branch staff member to access the system or delete existing staff members from the system.

The system authenticates each access request to the system. Also, the teller terminal is either in the idle state or the active state.

In the Idle State: displays a login menu. It invites a branch employee to enter a userid and password and either (i) to manage client and account information or (ii) add/delete a user (branch staff) if the user is a system administrator or (iii) to change his/her password. In all the cases, the information provided is checked for validity.

In Active State: For system administrators, the teller terminal displays a “System Administration” main menu that invites an administrator to manage information of branch staff members, clients, and accounts or change password. For branch staff, the teller displays a “Branch Staff” main menu that invites a branch staff member to manage client and account information or change password.


## Technical 
- `Card` stores the value (health) of the card which is linked to a player. 
- `CharacterAI` makes an abstraction for new AI player for the game.
- `DifficultCharacterAI` creates a new AI player for the game with a hard difficulty. This puts the human player in the last position in the first round to put them at a disadvantage health-wise.
- `MediumCharacterAI` creates a new AI player for the game with a meduim difficulty. This puts the human player 3 positions behind in the first round to put them at a disadvantage health-wise.
- `EasyCharacterAI` creates a new AI player for the game with an easy difficulty. This puts the human player at any position randomly without a disadvantage health-wise.
- `Form1` draws the template of the game and includes the main functionalities (update health, change positions, check last position, move players, draw cards, indicate a dead player).- `Form1` draws the template of the game and includes the main functionalities (update health, change positions, check last position, move players, draw cards, indicate a dead player).
- `Form2` used to start a new game when the initial game ends.
- `IGameObject` used to link graphics to the card face.
- `Player` used to hold info for the human player (health, position, card chosen, check death).
- `Shark` used to damage the player's health when they are in the last position of the card set.
- `Unit` used to link cards' colors.


## Images
| ![](https://github.com/aza0092/Get-Bit-Card-Game/blob/master/GetBit%20Project/media/startGame.png) | ![](https://github.com/aza0092/Get-Bit-Card-Game/blob/master/GetBit%20Project/media/botDifficulty.png) |
|:---:|:---:|
| Start Game  | Bot difficulty Options |



| ![](https://github.com/aza0092/Get-Bit-Card-Game/blob/master/GetBit%20Project/media/cardColors.png) | ![](https://github.com/aza0092/Get-Bit-Card-Game/blob/master/GetBit%20Project/media/cardSets.PNG) |
|:---:|:---:|
| Colors of cards in the game and the shark | Card sets options to choose from each round(1-7) |



| ![](https://github.com/aza0092/Get-Bit-Card-Game/blob/master/GetBit%20Project/media/health.PNG) | ![](https://github.com/aza0092/Get-Bit-Card-Game/blob/master/GetBit%20Project/media/status.PNG) |
|:---:|:---:|
| Players' heatlh updates after every round | Players' statuses updates after every round |



| ![](https://github.com/aza0092/Get-Bit-Card-Game/blob/master/GetBit%20Project/media/limbs.PNG) | ![](https://github.com/aza0092/Get-Bit-Card-Game/blob/master/GetBit%20Project/media/dead.PNG) |
|:---:|:---:|
| players losing limb when getting in last position | player who lost all their limb no longer in the game (card removed ) |



| ![](https://github.com/aza0092/Get-Bit-Card-Game/blob/master/GetBit%20Project/media/healthDead.png) | ![](https://github.com/aza0092/Get-Bit-Card-Game/blob/master/GetBit%20Project/media/winner.png) |
|:---:|:---:|
| dead player indicated | winner annoucned at end of game (player with highest health)|
