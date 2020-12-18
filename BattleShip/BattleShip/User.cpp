#include <iostream>
using namespace std;
#include "User.h"
#include <string>
#include <ctype.h>

User::User() {
	
}

//get information from the user 
void User::getShipsInfo() {
	int x = generateRandomNumbers();
	int y = generateRandomNumbers();


	//Submarine
	WaterVehicle sub(generateRandomOrient(), x, y, 1, 3);
	submarine = sub;
	setShips(sub, 3);

	x = generateRandomNumbers();
	y = generateRandomNumbers();

	//Cruiser
	WaterVehicle cru(generateRandomOrient(), x, y, 3, 4);
	cruiser = cru;
	setShips(cru, 4);

	x = generateRandomNumbers();
	y = generateRandomNumbers();

	//Destroyer
	WaterVehicle dest(generateRandomOrient(), x, y, 2, 5);
	destroyer = dest;
	setShips(dest, 5);

	x = generateRandomNumbers();
	y = generateRandomNumbers();

	//Carrier
	WaterVehicle carr(generateRandomOrient(), x, y, 5, 6);
	carrier = carr;
	setShips(carr, 6);

	x = generateRandomNumbers();
	y = generateRandomNumbers();

	//BattleShip
	WaterVehicle battle(generateRandomOrient(), x, y, 4, 7);
	battleship = battle;
	setShips(battle, 7);

}


//This sets the ship
void User::setShips(WaterVehicle& ship, int num)  //checks if ships is placed, if not then genrates another random numbers
{
	if (!vec.setShipPosition(ship, num, ship.printShipName(num)))
	{
		makePlacable(ship, num);
	}

}
void User :: attackShips(Grid& computer) { //allows user to attack 

	
	bool isValid = true; //checks if inputs are valid
	char col;
	    int row, column;

			cout << "Enter the letter of the column you want to shoot:  " << endl;
			cin >> col;

			cout << "Enter the number of the row that you want to shoot:  " << endl;
			cin >> row;
			
			column = changeCharToInt(col);
			try {
				while (row < 1 && row > 11) {
					isValid = false;
					cout << "Row is invalid. It is not a number between 1-10 " << endl;
					cin >> row;


				}
				while (column == 11) {
					isValid = false;
					cout << "Column is invalid. It's not a letter between A-J." << endl;
					cin >> col;
					break;

				}
				if (cin.fail())
				{
					isValid = false;
					cin.clear();
					cout << "Please enter valid inputs\n";
				}
				if (isValid) {
					cout << endl << endl;
					cout << "_________________________________" << endl << endl;
					cout << "An O will be printed if you miss" << endl;
					cout << "A X will be printed if you hit " << endl;
					cout << "_________________________________" << endl;

					int theRow = row - 1;
					int theColumn = column - 1;
					if (computer.isHit(theRow, theColumn)) {//checks if ship is hit
					    computer.getVector()[theRow][theColumn] = 1;
						cout << "Computer's ";
						int n = computer.whichShip(theRow, theColumn);
						hit(computer, n);
					}
				}
			}
			catch (const out_of_range& e) {
				cout << "cannot shoot at that spot" << endl;
			}
}

int User :: changeCharToInt(char letter) { //changes the columns from letters to numbers 

	if (letter == 'A' || letter == 'a') 
		return 1;
	if (letter == 'B' || letter == 'b')
		return 2;
	if (letter == 'C' || letter == 'c')
		return 3;
	if (letter == 'D' || letter == 'd')
		return 4;
	if (letter == 'E' || letter == 'e')
		return 5;
	if (letter == 'F' || letter == 'f')
		return 6;
	if (letter == 'G' || letter == 'g')
		return 7;
	if (letter == 'H' || letter == 'h')
		return 8;
	if (letter == 'I' || letter == 'i')
		return 9;
	if (letter == 'J' || letter == 'j')
		return 10;
	else
		return 11;
}


int User::generateRandomNumbers() {
	return rand() % 10 + 1;

}
char User::generateRandomOrient() {

	int randomOrient = rand() % 2;
	char orient;

	if (randomOrient == 0)
		orient = 'h';
	else
		orient = 'v';
	return orient;
}
void User::makePlacable(WaterVehicle& ship, int shipNum) {
	ship.setX(generateRandomNumbers());
	ship.setY(generateRandomNumbers());
	if (!vec.setShipPosition(ship, shipNum, ship.printShipName(shipNum))) {
		makePlacable(ship, shipNum);
	}
}