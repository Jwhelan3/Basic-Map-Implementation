#include "MapTest.h"

void MapTest::ResetScreen()
{
	std::cout.clear();	//Clear the current output buffer
	system("CLS");		//Clear the screen
	std::cin.clear();	//Clear the input buffer
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Fix for std::string - stop an infinite loop resulting from leftover data in the buffer
}

void MapTest::PrintOptions()
{
	//User interface
	ResetScreen();	//Clear the screen before displaying the selection options
	std::cout
		<< "1. Insert new entry" << std::endl
		<< "2. Delete existing entry" << std::endl
		<< "3. Retrieve a value (providing a key)" << std::endl
		<< "4. Update entry associated with key" << std::endl
		<< "5. Print map contents to screen using iterators" << std::endl
		<< "8. Load test data into the map" << std::endl
		<< "9. Exit to list of test cases" << std::endl;
}

//Key: Integer, Value: Integer
void MapTest::IntAndInt()
{
	//Type definitions
	typedef int Tkey;
	typedef int Tvalue;
	std::unique_ptr <Map<Tkey, Tvalue>> pMap(new Map<Tkey, Tvalue>());	//Smart pointer to map object based on type definitions

	//Begin the test program console interface
	bool terminate = false;	//Set the control flag for the main loop

	//Main loop
	while (!terminate)
	{
		//Output a message
		PrintOptions();
		//Await input
		int option;
		std::cin >> option;	//Store the chosen option

		ResetScreen();

		//Check what option the user has selected
		switch (option)
		{
		case 1:	//Insert entry
		{
			//Store the provided values
			Tkey key;
			Tvalue value;

			//User input
			std::cout << "Insert a key: ";
			std::cin >> key;
			std::cout << std::endl << "Insert a value: ";
			std::cin >> value;

			//Try to insert the provided key
			try
			{
				pMap->Insert(key, value);
				std::cout << std::endl << "Key inserted successfully." << std::endl;
			}

			catch (const std::exception& e)
			{
				//The key wasn't unique - inform the user it wasn't inserted
				std::cout << std::endl << "The key already exists - insert failed" << std::endl;
			}

			system("pause");
			break;
		}
		case 2: //Delete an entry
		{
			Tkey keyToDelete;	//Track user input
			std::cout << "Enter a key to delete: " << std::endl;
			std::cin >> keyToDelete;

			//Try to delete the key
			try
			{
				pMap->Delete(keyToDelete);
				std::cout << std::endl << "Key deleted successfully." << std::endl;
			}

			catch (const std::exception& e)
			{
				//Key didn't exist
				std::cout << std::endl << "Deletion failed - key doesn't exist" << std::endl;
			}
			system("pause");
			break;
		}

		case 3: //Retrieve an entry
		{
			//Get the key and store for passing to the class
			Tkey keyToSearch;
			Tvalue resultFromSearch;

			std::cout << "Enter a key to search: " << std::endl;
			std::cin >> keyToSearch;

			//Attempt to find
			try
			{
				resultFromSearch = pMap->Retrieve(keyToSearch);
				std::cout << "The value associated with key: " << keyToSearch << " is: " << resultFromSearch << std::endl;
			}

			catch (const std::exception& e)
			{
				//Key wasn't found
				std::cout << "The provided key does not exist." << std::endl;
			}

			system("pause");
			break;
		}

		case 4: //Update an entry
		{
			Tkey keyToUpdate;	//Track user input
			Tvalue newValue;
			std::cout << "Enter the key of the record to be updated: " << std::endl;
			std::cin >> keyToUpdate;
			std::cout << "Enter the new value: " << std::endl;
			std::cin >> newValue;

			//Try to update the key
			try
			{
				pMap->Update(keyToUpdate, newValue);
				std::cout << std::endl << "Entry successfully updated." << std::endl;
			}

			catch (const std::exception& e)
			{
				//Key didn't exist
				std::cout << std::endl << "Update failed - key wasn't found." << std::endl;
			}

			system("pause");
			break;
		}

		case 5: //Print the array (uses the class's iterator functions)
		{
			ResetScreen();

			auto *beginningReference = pMap->Begin();
			auto *endReference = pMap->End();

			int iterations = 1;
			for (auto i = beginningReference; i < endReference; i++)
			{
				std::cout << iterations++ << ".  Key: " << i->key << " - Value: " << i->value << std::endl;
			}

			system("pause");
			break;
		}

		//Load test data into the map
		case 8:
		{
			for (int i = 0; i < TEST_DATA_VOLUME; i++)
			{
				try {
					pMap->Insert(i, i * 2);
				}
				catch(const std::exception& e)
				{
					std::cout << "An entry with the test key already exists." << std::endl;
				}
			}
			std::cout << TEST_DATA_VOLUME << " test entries created. " << std::endl;
			system("pause");
			break;
		}

		case 9:						//Special case: terminate the loop
			terminate = true;
			break;

		default:					//No valid option entered: try again
			break;
		}
	}
}

//Integer key + String value test
void MapTest::IntAndString()
{
	//Type definitions
	typedef int Tkey;
	typedef std::string Tvalue;
	std::unique_ptr <Map<Tkey, Tvalue>> pMap(new Map<Tkey, Tvalue>());	//Smart pointer to map object based on type definitions

	//Begin the test program console interface
	bool terminate = false;	//Set the control flag for the main loop

	//Main loop
	while (!terminate)
	{
		//Output a message
		PrintOptions();
		//Await input
		int option;
		std::cin >> option;	//Store the chosen option

		ResetScreen();

		//Check what option the user has selected
		switch (option)
		{
		case 1:	//Insert entry
		{
			//Store the provided values
			Tkey key;
			Tvalue value;

			//User input
			std::cout << "Insert a key: ";
			std::cin >> key;
			std::cout << std::endl << "Insert a value: ";
			std::cin >> value;

			//Try to insert the provided key
			try
			{
				pMap->Insert(key, value);
				std::cout << std::endl << "Key inserted successfully." << std::endl;
			}

			catch (const std::exception & e)
			{
				//The key wasn't unique - inform the user it wasn't inserted
				std::cout << std::endl << "The key already exists - insert failed" << std::endl;
			}

			system("pause");
			break;
		}
		case 2: //Delete an entry
		{
			Tkey keyToDelete;	//Track user input
			std::cout << "Enter a key to delete: " << std::endl;
			std::cin >> keyToDelete;

			//Try to delete the key
			try
			{
				pMap->Delete(keyToDelete);
				std::cout << std::endl << "Key deleted successfully." << std::endl;
			}

			catch (const std::exception & e)
			{
				//Key didn't exist
				std::cout << std::endl << "Deletion failed - key doesn't exist" << std::endl;
			}
			system("pause");
			break;
		}

		case 3: //Retrieve an entry
		{
			//Get the key and store for passing to the class
			Tkey keyToSearch;
			Tvalue resultFromSearch;

			std::cout << "Enter a key to search: " << std::endl;
			std::cin >> keyToSearch;

			//Attempt to find
			try
			{
				resultFromSearch = pMap->Retrieve(keyToSearch);
				std::cout << "The value associated with key: " << keyToSearch << " is: " << resultFromSearch << std::endl;
			}

			catch (const std::exception & e)
			{
				//Key wasn't found
				std::cout << "The provided key does not exist." << std::endl;
			}

			system("pause");
			break;
		}

		case 4: //Update an entry
		{
			Tkey keyToUpdate;	//Track user input
			Tvalue newValue;
			std::cout << "Enter the key of the record to be updated: " << std::endl;
			std::cin >> keyToUpdate;
			std::cout << "Enter the new value: " << std::endl;
			std::cin >> newValue;

			//Try to update the key
			try
			{
				pMap->Update(keyToUpdate, newValue);
				std::cout << std::endl << "Entry successfully updated." << std::endl;
			}

			catch (const std::exception & e)
			{
				//Key didn't exist
				std::cout << std::endl << "Update failed - key wasn't found." << std::endl;
			}

			system("pause");
			break;
		}

		case 5: //Print the array (uses the class's iterator functions)
		{
			ResetScreen();

			auto* beginningReference = pMap->Begin();
			auto* endReference = pMap->End();

			int iterations = 1;
			for (auto i = beginningReference; i < endReference; i++)
			{
				std::cout << iterations++ << ".  Key: " << i->key << " - Value: " << i->value << std::endl;
			}

			system("pause");
			break;
		}

		//Load test data into the map
		case 8:
		{
			for (int i = 0; i < TEST_DATA_VOLUME; i++)
			{
				try {
					pMap->Insert(i, "Test string.");
				}
				catch (const std::exception & e)
				{
					std::cout << "An entry with the test key already exists." << std::endl;
				}
			}
			std::cout << TEST_DATA_VOLUME << " test entries created. " << std::endl;
			system("pause");
			break;
		}

		case 9:						//Special case: terminate the loop
			terminate = true;
			break;

		default:					//No valid option entered: try again
			break;
		}
	}
}

//Integer key with a float value
void MapTest::IntAndFloat()
{
	//Type definitions
	typedef int Tkey;
	typedef float Tvalue;
	std::unique_ptr <Map<Tkey, Tvalue>> pMap(new Map<Tkey, Tvalue>());	//Smart pointer to map object based on type definitions

	//Begin the test program console interface
	bool terminate = false;	//Set the control flag for the main loop

	//Main loop
	while (!terminate)
	{
		//Output a message
		PrintOptions();
		//Await input
		int option;
		std::cin >> option;	//Store the chosen option

		ResetScreen();

		//Check what option the user has selected
		switch (option)
		{
		case 1:	//Insert entry
		{
			//Store the provided values
			Tkey key;
			Tvalue value;

			//User input
			std::cout << "Insert a key: ";
			std::cin >> key;
			std::cout << std::endl << "Insert a value: ";
			std::cin >> value;

			//Try to insert the provided key
			try
			{
				pMap->Insert(key, value);
				std::cout << std::endl << "Key inserted successfully." << std::endl;
			}

			catch (const std::exception & e)
			{
				//The key wasn't unique - inform the user it wasn't inserted
				std::cout << std::endl << "The key already exists - insert failed" << std::endl;
			}

			system("pause");
			break;
		}
		case 2: //Delete an entry
		{
			Tkey keyToDelete;	//Track user input
			std::cout << "Enter a key to delete: " << std::endl;
			std::cin >> keyToDelete;

			//Try to delete the key
			try
			{
				pMap->Delete(keyToDelete);
				std::cout << std::endl << "Key deleted successfully." << std::endl;
			}

			catch (const std::exception & e)
			{
				//Key didn't exist
				std::cout << std::endl << "Deletion failed - key doesn't exist" << std::endl;
			}
			system("pause");
			break;
		}

		case 3: //Retrieve an entry
		{
			//Get the key and store for passing to the class
			Tkey keyToSearch;
			Tvalue resultFromSearch;

			std::cout << "Enter a key to search: " << std::endl;
			std::cin >> keyToSearch;

			//Attempt to find
			try
			{
				resultFromSearch = pMap->Retrieve(keyToSearch);
				std::cout << "The value associated with key: " << keyToSearch << " is: " << resultFromSearch << std::endl;
			}

			catch (const std::exception & e)
			{
				//Key wasn't found
				std::cout << "The provided key does not exist." << std::endl;
			}

			system("pause");
			break;
		}

		case 4: //Update an entry
		{
			Tkey keyToUpdate;	//Track user input
			Tvalue newValue;
			std::cout << "Enter the key of the record to be updated: " << std::endl;
			std::cin >> keyToUpdate;
			std::cout << "Enter the new value: " << std::endl;
			std::cin >> newValue;

			//Try to update the key
			try
			{
				pMap->Update(keyToUpdate, newValue);
				std::cout << std::endl << "Entry successfully updated." << std::endl;
			}

			catch (const std::exception & e)
			{
				//Key didn't exist
				std::cout << std::endl << "Update failed - key wasn't found." << std::endl;
			}

			system("pause");
			break;
		}

		case 5: //Print the array (uses the class's iterator functions)
		{
			ResetScreen();

			auto* beginningReference = pMap->Begin();
			auto* endReference = pMap->End();

			int iterations = 1;
			for (auto i = beginningReference; i < endReference; i++)
			{
				std::cout << iterations++ << ".  Key: " << i->key << " - Value: " << i->value << std::endl;
			}

			system("pause");
			break;
		}

		//Load test data into the map
		case 8:
		{
			for (int i = 0; i < TEST_DATA_VOLUME; i++)
			{
				try {
					pMap->Insert(i, (float)i * 2);
				}
				catch (const std::exception & e)
				{
					std::cout << "An entry with the test key already exists." << std::endl;
				}
			}
			std::cout << TEST_DATA_VOLUME << " test entries created. " << std::endl;
			system("pause");
			break;
		}

		case 9:						//Special case: terminate the loop
			terminate = true;
			break;

		default:					//No valid option entered: try again
			break;
		}
	}
}

//Char key with a String value
void MapTest::CharAndString()
{
	//Type definitions
	typedef char Tkey;
	typedef std::string Tvalue;
	std::unique_ptr <Map<Tkey, Tvalue>> pMap(new Map<Tkey, Tvalue>());	//Smart pointer to map object based on type definitions

	//Begin the test program console interface
	bool terminate = false;	//Set the control flag for the main loop

	//Main loop
	while (!terminate)
	{
		//Output a message
		PrintOptions();
		//Await input
		int option;
		std::cin >> option;	//Store the chosen option

		ResetScreen();

		//Check what option the user has selected
		switch (option)
		{
		case 1:	//Insert entry
		{
			//Store the provided values
			Tkey key;
			Tvalue value;

			//User input
			std::cout << "Insert a key: ";
			std::cin >> key;
			std::cout << std::endl << "Insert a value: ";
			std::cin >> value;

			//Try to insert the provided key
			try
			{
				pMap->Insert(key, value);
				std::cout << std::endl << "Key inserted successfully." << std::endl;
			}

			catch (const std::exception & e)
			{
				//The key wasn't unique - inform the user it wasn't inserted
				std::cout << std::endl << "The key already exists - insert failed" << std::endl;
			}

			system("pause");
			break;
		}
		case 2: //Delete an entry
		{
			Tkey keyToDelete;	//Track user input
			std::cout << "Enter a key to delete: " << std::endl;
			std::cin >> keyToDelete;

			//Try to delete the key
			try
			{
				pMap->Delete(keyToDelete);
				std::cout << std::endl << "Key deleted successfully." << std::endl;
			}

			catch (const std::exception & e)
			{
				//Key didn't exist
				std::cout << std::endl << "Deletion failed - key doesn't exist" << std::endl;
			}
			system("pause");
			break;
		}

		case 3: //Retrieve an entry
		{
			//Get the key and store for passing to the class
			Tkey keyToSearch;
			Tvalue resultFromSearch;

			std::cout << "Enter a key to search: " << std::endl;
			std::cin >> keyToSearch;

			//Attempt to find
			try
			{
				resultFromSearch = pMap->Retrieve(keyToSearch);
				std::cout << "The value associated with key: " << keyToSearch << " is: " << resultFromSearch << std::endl;
			}

			catch (const std::exception & e)
			{
				//Key wasn't found
				std::cout << "The provided key does not exist." << std::endl;
			}

			system("pause");
			break;
		}

		case 4: //Update an entry
		{
			Tkey keyToUpdate;	//Track user input
			Tvalue newValue;
			std::cout << "Enter the key of the record to be updated: " << std::endl;
			std::cin >> keyToUpdate;
			std::cout << "Enter the new value: " << std::endl;
			std::cin >> newValue;

			//Try to update the key
			try
			{
				pMap->Update(keyToUpdate, newValue);
				std::cout << std::endl << "Entry successfully updated." << std::endl;
			}

			catch (const std::exception & e)
			{
				//Key didn't exist
				std::cout << std::endl << "Update failed - key wasn't found." << std::endl;
			}

			system("pause");
			break;
		}

		case 5: //Print the array (uses the class's iterator functions)
		{
			ResetScreen();

			auto* beginningReference = pMap->Begin();
			auto* endReference = pMap->End();

			int iterations = 1;
			for (auto i = beginningReference; i < endReference; i++)
			{
				std::cout << iterations++ << ".  Key: " << i->key << " - Value: " << i->value << std::endl;
			}

			system("pause");
			break;
		}

		//Load test data into the map
		case 8:
		{
				try {
					pMap->Insert('a', "Entry 1");
					pMap->Insert('b', "Entry 2");
					pMap->Insert('c', "Entry 3");
					pMap->Insert('d', "Entry 4");
					pMap->Insert('e', "Entry 5");
					pMap->Insert('f', "Entry 6");
					pMap->Insert('g', "Entry 7");
					pMap->Insert('h', "Entry 8");
					pMap->Insert('i', "Entry 9");
					pMap->Insert('j', "Entry 10");
					std::cout << "Inserted 10 chars" << std::endl;
				}
				catch (const std::exception & e)
				{
					std::cout << "An entry with the test key already exists." << std::endl;
				}
			system("pause");
			break;
		}

		case 9:						//Special case: terminate the loop
			terminate = true;
			break;

		default:					//No valid option entered: try again
			break;
		}
	}
}

//String key with an integer value
void MapTest::StringAndInt()
{
	//Type definitions
	typedef std::string Tkey;
	typedef int Tvalue;
	std::unique_ptr <Map<Tkey, Tvalue>> pMap(new Map<Tkey, Tvalue>());	//Smart pointer to map object based on type definitions

	//Begin the test program console interface
	bool terminate = false;	//Set the control flag for the main loop

	//Main loop
	while (!terminate)
	{
		//Output a message
		PrintOptions();
		//Await input
		int option;
		std::cin >> option;	//Store the chosen option

		ResetScreen();

		//Check what option the user has selected
		switch (option)
		{
		case 1:	//Insert entry
		{
			//Store the provided values
			Tkey key;
			Tvalue value;

			//User input
			std::getline(std::cin, key);
			std::cout << std::endl << "Insert a value: ";
			std::cin >> value;

			//Try to insert the provided key
			try
			{
				pMap->Insert(key, value);
				std::cout << std::endl << "Key inserted successfully." << std::endl;
			}

			catch (const std::exception & e)
			{
				//The key wasn't unique - inform the user it wasn't inserted
				std::cout << std::endl << "The key already exists - insert failed" << std::endl;
			}

			system("pause");
			break;
		}
		case 2: //Delete an entry
		{
			Tkey keyToDelete;	//Track user input
			std::cout << "Enter a key to delete: " << std::endl;
			std::getline(std::cin, keyToDelete);

			//Try to delete the key
			try
			{
				pMap->Delete(keyToDelete);
				std::cout << std::endl << "Key deleted successfully." << std::endl;
			}

			catch (const std::exception & e)
			{
				//Key didn't exist
				std::cout << std::endl << "Deletion failed - key doesn't exist" << std::endl;
			}
			system("pause");
			break;
		}

		case 3: //Retrieve an entry
		{
			//Get the key and store for passing to the class
			Tkey keyToSearch;
			Tvalue resultFromSearch;

			std::cout << "Enter a key to search: " << std::endl;
			std::getline(std::cin, keyToSearch);

			//Attempt to find
			try
			{
				resultFromSearch = pMap->Retrieve(keyToSearch);
				std::cout << "The value associated with key: " << keyToSearch << " is: " << resultFromSearch << std::endl;
			}

			catch (const std::exception & e)
			{
				//Key wasn't found
				std::cout << "The provided key does not exist." << std::endl;
			}

			system("pause");
			break;
		}

		case 4: //Update an entry
		{
			Tkey keyToUpdate;	//Track user input
			Tvalue newValue;
			std::cout << "Enter the key of the record to be updated: " << std::endl;
			std::getline(std::cin, keyToUpdate);
			std::cout << "Enter the new value: " << std::endl;
			std::cin >> newValue;

			//Try to update the key
			try
			{
				pMap->Update(keyToUpdate, newValue);
				std::cout << std::endl << "Entry successfully updated." << std::endl;
			}

			catch (const std::exception & e)
			{
				//Key didn't exist
				std::cout << std::endl << "Update failed - key wasn't found." << std::endl;
			}

			system("pause");
			break;
		}

		case 5: //Print the array (uses the class's iterator functions)
		{
			ResetScreen();

			auto* beginningReference = pMap->Begin();
			auto* endReference = pMap->End();

			int iterations = 1;
			for (auto i = beginningReference; i < endReference; i++)
			{
				std::cout << iterations++ << ".  Key: " << i->key << " - Value: " << i->value << std::endl;
			}

			system("pause");
			break;
		}

		//Load test data into the map
		case 8:
		{
			for (int i = 0; i < TEST_DATA_VOLUME; i++)
			{
				try {
					pMap->Insert("String " + std::to_string(i), i);
				}
				catch (const std::exception & e)
				{
					std::cout << "An entry with the test key already exists." << std::endl;
				}
			}
			std::cout << TEST_DATA_VOLUME << " test entries created. " << std::endl;
			system("pause");
			break;
		}

		case 9:						//Special case: terminate the loop
			terminate = true;
			break;

		default:					//No valid option entered: try again
			break;
		}
	}
}

//Integer key with an object value
void MapTest::IntAndObject()
{
	//Type definitions
	typedef int Tkey;
	typedef TestClass Tvalue;
	std::unique_ptr <Map<Tkey, Tvalue>> pMap(new Map<Tkey, Tvalue>());	//Smart pointer to map object based on type definitions

	//Begin the test program console interface
	bool terminate = false;	//Set the control flag for the main loop

	//Main loop
	while (!terminate)
	{
		//Override the default menu options
		//Output a message
		ResetScreen();
		std::cout
			<< "1. Insert a new object with a given key" << std::endl
			<< "2. Delete entry" << std::endl
			<< "3. Retrieve a value stored inside a stored object" << std::endl
			<< "5. Print map to screen" << std::endl
			<< "8. Load test data (8 objects)" << std::endl
			<< "9. Exit to list of test cases" << std::endl;

		//Await input
		int option;
		std::cin >> option;	//Store the chosen option

		ResetScreen();

		//Check what option the user has selected
		switch (option)
		{
		case 1:	//Insert entry
		{
			//Store the provided values
			Tkey key;
			Tvalue value;

			//User input
			std::cout << "Insert a key: ";
			std::cin >> key;

			//Try to insert the provided key
			try
			{
				pMap->Insert(key, value);
				std::cout << std::endl << "Key inserted successfully." << std::endl;
			}

			catch (const std::exception & e)
			{
				//The key wasn't unique - inform the user it wasn't inserted
				std::cout << std::endl << "The key already exists - insert failed" << std::endl;
			}

			system("pause");
			break;
		}
		case 2: //Delete an entry
		{
			Tkey keyToDelete;	//Track user input
			std::cout << "Enter a key to delete: " << std::endl;
			std::cin >> keyToDelete;

			//Try to delete the key
			try
			{
				pMap->Delete(keyToDelete);
				std::cout << std::endl << "Key deleted successfully." << std::endl;
			}

			catch (const std::exception & e)
			{
				//Key didn't exist
				std::cout << std::endl << "Deletion failed - key doesn't exist" << std::endl;
			}
			system("pause");
			break;
		}

		case 3: //Retrieve an entry
		{
			//Get the key and store for passing to the class
			Tkey keyToSearch;
			Tvalue resultFromSearch;

			std::cout << "Enter a key to search: " << std::endl;
			std::cin >> keyToSearch;

			//Attempt to find
			try
			{
				resultFromSearch = pMap->Retrieve(keyToSearch);
				std::cout << "The value associated with key: " << keyToSearch << " is: " << resultFromSearch.GetPrivateFied() << std::endl;
			}

			catch (const std::exception & e)
			{
				//Key wasn't found
				std::cout << "The provided key does not exist." << std::endl;
			}

			system("pause");
			break;
		}

		case 5: //Print the array (uses the class's iterator functions)
		{
			ResetScreen();

			auto* beginningReference = pMap->Begin();
			auto* endReference = pMap->End();

			int iterations = 1;
			for (auto i = beginningReference; i < endReference; i++)
			{
				std::cout << iterations++ << ".  Key: " << i->key << " - Value: " << i->value.GetPrivateFied() << std::endl;
			}

			system("pause");
			break;
		}

		//Load test data into the map
		case 8:
		{
				try {
					//Create the pointers
					std::unique_ptr <Tvalue> pTestPtr1(new Tvalue("Object 1's Text Member"));
					std::unique_ptr <Tvalue> pTestPtr2(new Tvalue("Object 2's Text Member"));
					std::unique_ptr <Tvalue> pTestPtr3(new Tvalue("Object 3's Text Member"));
					std::unique_ptr <Tvalue> pTestPtr4(new Tvalue("Object 4's Text Member"));
					std::unique_ptr <Tvalue> pTestPtr5(new Tvalue("Object 5's Text Member"));
					std::unique_ptr <Tvalue> pTestPtr6(new Tvalue("Object 6's Text Member"));
					std::unique_ptr <Tvalue> pTestPtr7(new Tvalue("Object 7's Text Member"));
					std::unique_ptr <Tvalue> pTestPtr8(new Tvalue("Object 8's Text Member"));

					//Insert into map
					pMap->Insert(1, *pTestPtr1);
					pMap->Insert(2, *pTestPtr2);
					pMap->Insert(3, *pTestPtr3);
					pMap->Insert(4, *pTestPtr4);
					pMap->Insert(5, *pTestPtr5);
					pMap->Insert(6, *pTestPtr6);
					pMap->Insert(7, *pTestPtr7);
					pMap->Insert(8, *pTestPtr8);

					//Output message
					std::cout << "8 test cases added. " << std::endl;
				}
				catch (const std::exception & e)
				{
					std::cout << "Unable to load duplicate test data" << std::endl;
				}

			system("pause");
			break;
		}

		case 9:						//Special case: terminate the loop
			terminate = true;
			break;

		default:					//No valid option entered: try again
			break;
		}
	}
}

//Object key with a string value
void MapTest::ObjectAndString()
{
	//Type definitions
	typedef TestClass* Tkey;
	typedef std::string Tvalue;
	std::unique_ptr <Map<Tkey, Tvalue>> pMap(new Map<Tkey, Tvalue>());	//Smart pointer to map object based on type definitions

	//Begin the test program console interface
	bool terminate = false;	//Set the control flag for the main loop

	//Create 9 test objects
	TestClass *pTestPtr1 = new TestClass("Test Pointer 1");
	TestClass *pTestPtr2 = new TestClass("Test Pointer 2");
	TestClass *pTestPtr3 = new TestClass("Test Pointer 3");
	TestClass *pTestPtr4 = new TestClass("Test Pointer 4");
	TestClass *pTestPtr5 = new TestClass("Test Pointer 5");
	TestClass *pTestPtr6 = new TestClass("Test Pointer 6");
	TestClass *pTestPtr7 = new TestClass("Test Pointer 7");
	TestClass *pTestPtr8 = new TestClass("Test Pointer 8");
	TestClass *pTestPtr9 = new TestClass("Test Pointer 9 (Duplicate test)");

	//Main loop
	while (!terminate)
	{
		//Output a message
		PrintOptions();
		//Await input
		int option;
		std::cin >> option;	//Store the chosen option

		ResetScreen();

		//Check what option the user has selected
		switch (option)
		{
		case 1:	//Insert entry
		{
			//Store the provided values
			Tkey key;
			std::string textField;

			//User input
			std::cout << "Create a text field for the new object: ";
			std::cin >> textField;

			//Try to insert the provided key
			try
			{
				pMap->Insert(pTestPtr9, textField);
				std::cout << std::endl << "Key inserted successfully." << std::endl;
			}

			catch (const std::exception & e)
			{
				//The key wasn't unique - inform the user it wasn't inserted
				std::cout << std::endl << "The key already exists - insert failed" << std::endl;
			}

			system("pause");
			break;
		}


		case 5: //Print the array (uses the class's iterator functions)
		{
			ResetScreen();

			auto* beginningReference = pMap->Begin();
			auto* endReference = pMap->End();

			int iterations = 1;
			for (auto i = beginningReference; i < endReference; i++)
			{
				std::cout << iterations++ << ".  Key: " << i->key->GetPrivateFied() << " - Value: " << i->value << std::endl;
			}

			system("pause");
			break;
		}

		//Load test data into the map
		case 8:
		{
				try {
					//Insert test objects
					pMap->Insert(pTestPtr1, "Pointer 1");
					pMap->Insert(pTestPtr2, "Pointer 2");
					pMap->Insert(pTestPtr3, "Pointer 3");
					pMap->Insert(pTestPtr4, "Pointer 4");
					pMap->Insert(pTestPtr5, "Pointer 5");
					pMap->Insert(pTestPtr6, "Pointer 6");
					pMap->Insert(pTestPtr7, "Pointer 7");
					pMap->Insert(pTestPtr8, "Pointer 8");
					std::cout << "Test data loaded." << std::endl;
				}
				catch (const std::exception & e)
				{
					std::cout << "An entry with the test key already exists." << std::endl;
				}
			}
			system("pause");
			break;

		case 9:						//Special case: terminate the loop
			terminate = true;
			break;

		default:					//No valid option entered: try again
			break;
		}
	}

	//Delete the test objects
	delete pTestPtr1;
	delete pTestPtr2;
	delete pTestPtr3;
	delete pTestPtr4;
	delete pTestPtr5;
	delete pTestPtr6;
	delete pTestPtr7;
	delete pTestPtr8;
	delete pTestPtr9;
}