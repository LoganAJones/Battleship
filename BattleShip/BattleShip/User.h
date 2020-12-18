#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;
#include "Grid.h"
#include "Player.h"
#include <fstream>
#include "WaterVehicle.h"
#pragma once
class User : public Player { //inherits player class 

	public:

		User();
		void getShipsInfo(); 
		void setShips(WaterVehicle&,int);
		int generateRandomNumbers();
		char generateRandomOrient();
		void attackShips(Grid&);
		int changeCharToInt(char);
		void makePlacable(WaterVehicle&, int);
		
};
# endif