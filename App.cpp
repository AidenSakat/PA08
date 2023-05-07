//------------------------------------------------------------------------------
// inventory_app.cpp : base class declaration and definition
//------------------------------------------------------------------------------
// C:\\Users\\User\\inventory.txt
#include "Scooter.h"
#include "Bicycle.h"
#include "TwoWheeler.h"
#include <fstream>
#include <vector>
#include <iostream>
using std::cout;
//------------------------------------------------------------------------------
// Entry Point
//------------------------------------------------------------------------------
int main() {
	TwoWheeler tw;
	Scooter sc;
	Bicycle bi;

	// asks user for inventory txt file
	std::string filename;
	cout << "Welcome user! Please enter your inventory filename to begin: ";
	std::cin >> filename;

	std::list<string>* inventory = tw.readInventory(filename);

	if (inventory) {
		// displays the inventory with bicycle: or scooter:
		bi.displayBicycleInventory(inventory);
		sc.displayScooterInventory(inventory);

		// displays how many of each there are by couting the 1s and 2s
		bi.displayBicycleCounts(inventory);
		sc.displayScooterCounts(inventory);
		delete tw.readInventory(filename);
	}
}