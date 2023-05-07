//------------------------------------------------------------------------------
// TwoWheeler.h : base class declaration and definition
//------------------------------------------------------------------------------
#pragma once
#include <string>
#include <iostream>
#include <list>
#include <fstream>
#include <algorithm>
#include <sstream>
#include "Exceptions.h"
using std::string;

//------------------------------------------------------------------------------
// constants : identify type of two-wheel vehicle
//------------------------------------------------------------------------------
constexpr int ID_BASE = 0;
constexpr int ID_BICYCLE = 1;
constexpr int ID_SCOOTER = 2;

//------------------------------------------------------------------------------
// TwoWheeler
//------------------------------------------------------------------------------
class TwoWheeler {
protected:
	int typeId;
	string mfr;
	string model;
	std::list<string>* inventory;
public:
	// constructors
	TwoWheeler() : typeId(ID_BASE), inventory(new std::list<string>()) { }
	TwoWheeler(string _mfr, string _model) :
		typeId(ID_BASE), mfr(_mfr), model(_model), inventory(new std::list<string>()) { }

	int getTypeId() const { return typeId; }
	const string& getMfr() const { return mfr; }
	const string& getModel() const { return model; }

	// reads the inventor of file and throws exceptions if needed and stores the contents of the file into a list
	std::list<string>* readInventory(const string& filename) // read data from file into your std::list,
	{
		std::ifstream file(filename);
		try {
			if (!file.is_open())
			{
				throw FileOpenException();
			}
		}
		catch (const std::exception& ex)
		{
			std::cerr << ex.what();
			return 0;
		}
		std::stringstream buffer;
		buffer << file.rdbuf();
		file.close();
		string line;
		int lineCount = 0;
		while (getline(buffer, line))
		{
			lineCount++;

			try {
				if (line[0] == '1' || line[0] == '2') {
					inventory->push_back(line);
				}
				else {
					throw FileFormatException(lineCount);
				}
			}
			catch (const std::exception& ex) {
				std::cerr << ex.what();
			}
		}

		return inventory;
	};

	void destroyListItems(std::list<string*>* inventoryList)
	{
		for (const auto& inventory : *inventoryList) {
			delete inventory;
		}
		inventoryList->clear();
	}
};
