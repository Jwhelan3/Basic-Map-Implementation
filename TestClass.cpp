#include "TestClass.h"

//Implementation of TestClass - used to overload the constructor called when no params are provided
TestClass::TestClass()
{
	//Default constructor - no parameters provided
	SetPrivateField("Manually inserted test object");
}

TestClass::~TestClass()
{
	//No cleanup required
}