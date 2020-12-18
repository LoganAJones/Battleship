#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <vector>
#include <string>
#include "WaterVehicle.h"
using namespace std;

class Grid
{
	private:
		vector<vector<int>> vec;

	public:

		Grid();

		//functions
		void printGrid();//prints grid
        bool setShipPosition(WaterVehicle&, int, string);//sets ships and return true if it's set 
		bool isPlacable(WaterVehicle&, int, int, int);//checks if ship is placable
		bool isHit(int, int);
		int whichShip(int, int);
		void printUserHitsOnGrid(Grid&);
		vector<vector<int>>& getVector() { return vec; }
};
#endif