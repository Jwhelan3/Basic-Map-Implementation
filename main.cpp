#ifdef _DEBUG //Memory leak checks (debug only)
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif // _DEBUG

#include <iostream>
#include <memory>
#include <string>
#include "MapTest.h"

/*This file acts as the entry point for the program. The main method is a driver
to bring the map and the test cases together.*/

//Create an object for the map test
MapTest *pMapTest = new MapTest;	//This is a raw pointer to demonstrate the memory-safety when using _CrtDumpMemoryLeaks();

//Reset the screen
void ResetScreen()
{
	std::cout.clear();	//Clear the current output buffer
	system("CLS");		//Clear the screen
	std::cin.clear();	//Clear the input buffer
}

//Print the options
void PrintOptions()
{
	//User interface
	std::cout
		<< "Choose a map test to enter: " << std::endl
		<< "1. Integer + Integer map test" << std::endl
		<< "2. Integer + String map test" << std::endl
		<< "3. Integer + Float map test" << std::endl
		<< "4. Char + String map test" << std::endl
		<< "5. String + Integer map test" << std::endl
		<< "6. Integer + Object map test" << std::endl
		<< "7. Object + String map test" << std::endl
		<< "9. Exit" << std::endl;
}

//Test program driver
int main()
{
	//Set control flag
	bool terminate = false;

	//Begin main program loop
	while (!terminate)
	{
		ResetScreen();
		PrintOptions();

		int option;	//Store the user choice
		std::cin >> option;//Get the user's choice

		//Test scenarios based on chosen option
		switch (option)
		{
		case 1:	//Integer + Integer
		{
			pMapTest->IntAndInt();
			break;
		}

		case 2:	//Integer + String
		{
			pMapTest->IntAndString();
			break;
		}

		case 3: //Int and float
		{
			pMapTest->IntAndFloat();
			break;
		}

		case 4: //Char + string
		{
			pMapTest->CharAndString();
			break;
		}

		case 5: //String + int
		{
			pMapTest->StringAndInt();
			break;
		}

		case 6: //Integer + object
		{
			pMapTest->IntAndObject();
			break;
		}

		case 7: //Object + string
		{
			pMapTest->ObjectAndString();
			break;
		}

		case 9:						//Special case: terminate the loop
			terminate = true;
			break;

		default:					//No valid option entered: try again
			break;
		}
	}

	delete pMapTest;	//No longer required - delete before the memory leaks are dumped

#ifdef _DEBUG
	//Memory leak check
	_CrtDumpMemoryLeaks();
#endif // _DEBUG

	return 0;
}