#pragma once
#include <iostream>
#include <string>

//This class is a bare, basic class in order to provide a test object for the map class.
class TestClass
{
public:
	TestClass();	//Default constructor - overloaded in TestClass.cpp
	TestClass(std::string Input) { mPrivateField = Input; }	//If a parameter is provided, use this to set the private field
	~TestClass();
	std::string GetPrivateFied() { return mPrivateField; }	//The the contents of the private member
	void SetPrivateField(std::string newValue) { mPrivateField = newValue; }	//Test the map's update functionality
private:
	std::string mPrivateField;	//Accessed via getter, setter & the constructors.
};

