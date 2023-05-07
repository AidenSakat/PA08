#ifndef SCOOTER_H
#define SCOOTER_H

#include "TwoWheeler.h"
#include <string>
#include <iostream>
#include <fstream>
using std::string;
class Scooter : public TwoWheeler 
{
public:

	// Displays the inventory and puts the type of vehicle in the beginning instead of numbers
	static bool isScooter(const string& str) { return str.substr(0, 1) == "2"; }
	void displayScooterInventory(std::list<string>* inventoryList) // display bicycles and scooters in inventory,
	{
		std::for_each(inventoryList->begin(), inventoryList->end(), [](string item) {
			if (item[0] == '2' && std::isdigit(item.back())) {
				std::cout << "Scooter: " << item.substr(2) << " Horse Power" << std::endl;
			}
			});
	}

	// displays how many of each vehicle there is displayed
	void displayScooterCounts(std::list<string>* inventoryList) // display the number of bicycles and the number of scooters
	{
		int scooterCount = std::count_if(inventoryList->begin(), inventoryList->end(), isScooter);
		std::cout << "Number of scooters: " << scooterCount << std::endl;
	}
}; 
#endif