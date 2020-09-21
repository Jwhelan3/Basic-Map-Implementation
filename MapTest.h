#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "Map.h"
#include "TestClass.h"

/*The MapTest class contains one method for each test case (listed
below) and uses the console to demonstrate how the map handles each
kind of data type. The public methods represent the different test
cases, while the private methods are used as a utility to support
the demonstration interface. */
class MapTest
{
public:
	MapTest() {};			//Initialise objects for testing
	~MapTest() {};			//TODO: Destructor
	void IntAndInt();		//Key: Integer, Value: Integer
	void IntAndString();	//Key: Integer, Value: String
	void IntAndFloat();		//Key: Integer, Value: Float
	void CharAndString();	//Key: Char, Value: String
	void StringAndInt();	//Key: String, Value: Integer
	void IntAndObject();	//Key: Integer, Value: Object
	void ObjectAndString();	//Key: Object, Value: String

private:
	void PrintOptions();	//Output the option selection menu to the console
	void ResetScreen();		//Clear the input buffers and the current output of the console
	const int TEST_DATA_VOLUME = 15;//Total number of elements to create as test data
};

