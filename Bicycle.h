#pragma once
#include "TwoWheeler.h"
class Bicycle : public TwoWheeler
{
public:

	// Displays the inventory and puts the type of vehicle in the beginning instead of numbers
	static bool isBicycle(const string& str) { return str.substr(0, 1) == "1"; }
	void displayBicycleInventory(std::list<string>* inventoryList) // display bicycles and scooters in inventory,
	{
		std::for_each(inventoryList->begin(), inventoryList->end(), [](string item) {
			if (item[0] == '1' && std::isdigit(item.back())) {
				std::cout << "Bicycle: " << item.substr(2) << " Serial Number" << std::endl;
			}
			});
	}

	// displays how many of each vehicle there is displayed
	void displayBicycleCounts(std::list<string>* inventoryList) // display the number of bicycles and the number of scooters
	{
		int bicycleCount = std::count_if(inventoryList->begin(), inventoryList->end(), isBicycle);
		std::cout << "Number of bicycles: " << bicycleCount << std::endl;
	}
};