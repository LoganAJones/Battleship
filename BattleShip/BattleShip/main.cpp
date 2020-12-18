#include <iostream>
#include "Grid.h"
#include "WaterVehicle.h"
#include "User.h"
#include "Computer.h"
#include <time.h>

int main()
{

	Grid example;
	cout << "Hi! Let's play Battleship!" << endl;
	cout << "If you want to quit the game, click 1 . If you want to continute playing, click 2" << endl << endl;
	cout << "Instructions: " << endl;
	cout << "The board looks something like this: " << endl;
	example.printGrid();
	
    srand(time(NULL));
	int input = 1;
	int players;
	User use1, use2;
	Computer compute;
	use1.getShipsInfo();
	use2.getShipsInfo();
	cout << "Would you like Players(2) or Single Player(1)" << endl;
	cin >> players;
	cout << endl;

	if (players == 1)
	{
		cout << "The following is what your grid looks like : " << endl;
		use1.getGrid().printGrid(); //prints user grid
		cout << "Computer's grid: " << endl;

		cout << endl;
		compute.getShipsInfo(); //computer generates random numbers 
		cout << endl;

		do {

			cout << "It's your turn to shoot torperdo! " << endl;
			use1.attackShips(compute.getGrid());

			compute.getGrid().printUserHitsOnGrid(compute.getGrid());

			//computer shoots
			cout << "Computer has shot it's torpedo " << endl;
			compute.attackShips(use1.getGrid());
			compute.getGrid().printGrid();  //uncomment for testing; it hides the computers grid
			if (compute.hasWon()) {
				cout << "The computer has won the game" << endl;
				input = 2;
			}
			else
				if (use1.hasWon()) {
					cout << "You won the game! Good job! " << endl;
					input = 2;
				}

			cout << "Do you wish to continue? Enter 1 for yes, Enter 2 for no" << endl;
			cin.ignore();//1000,'/n');
			cin >> input;

			if (cin.fail())
			{
				cin.clear();
				cout << "Please enter a number!\n(1 for yes, 2 for no)";
			}
			else if (input != 1 && input != 2) {
				cout << "Input a valid number, Please." << endl;
			}
			else if (input == 2) {
				cout << "Byeeeee! " << endl;
			}

		} while (input == 1);
		system("pause");
		return 0;
		system("pause");
	}
	else if (players == 2)
	{
		cout << "The following is what Player 1's grid looks like : " << endl;
		use1.getGrid().printGrid(); //prints user grid
		cout << "The following is what Player 2's grid looks like : " << endl;
		cout << endl;
		use2.getGrid().printGrid(); //prints user grid		

		do {

			cout << "It's Player 1's turn to shoot torperdo! " << endl;
			use1.attackShips(use2.getGrid());

			cout << "It's Player 2's turn to shoot torperdo! " << endl;
			use2.attackShips(use1.getGrid());

			//compute.getGrid().printGrid();
			if (use2.hasWon()) {
				cout << "Player 2 has won the game" << endl;
				input = 2;
			}
			else
				if (use1.hasWon()) {
					cout << "Player 1 won the game! Good job! " << endl;
					input = 2;
				}

			cout << "Do you wish to continue? Enter 1 for yes, Enter 2 for no" << endl;
			cin.ignore();//1000,'/n');
			cin >> input;

			if (cin.fail())
			{
				cin.clear();
				cout << "Please enter a number!\n(1 for yes, 2 for no)";
			}
			else if (input != 1 && input != 2) {
				cout << "Input a valid number, Please." << endl;
			}
			else if (input == 2) {
				cout << "Byeeeee! " << endl;
			}

		} while (input == 1);
		system("pause");
		return 0;
		system("pause");
	}
	else {
	cout << "Please input either 1 or 2" << endl;
	cin >> players;
	}
}
