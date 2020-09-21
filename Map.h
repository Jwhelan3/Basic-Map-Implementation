#pragma once
#include <stdexcept>
#include <memory>

/*
Map templated class - supports all data types including user-created objects, as both
a key and a value. Contains 4 front-facing public methods (Create, Retrieve, Update, Delete)
and has 2 protected utilities. (ResizeArray, LinearSearch. The data is stored in an array
that is created at runtime - can be resized via the ResizeArray method when capacity is reached.
*/
template <class TKey, class TValue>
class Map
{
private:
	static const int DEFAULT_SIZE = 2;	//The initial size of the array

	struct sKeyValuePair
	{
		//The struct holds key-value pairs together so they can be stored as a single elements
		TKey key;		//Unique key
		TValue value;	//Value associated with the unique key
	};

protected:
	int mNumberOfElements = 0;	//Keep track of the number of elements currently inside the array
	int mCurrentCapacity = DEFAULT_SIZE;	//The initial capacity of the array - increments as the array grows in size

	sKeyValuePair *pMap;		//Pointer to the array which will act as the map's structure, storing sKeyValuePair elements

	//When the array has reached its capacity, re-size it to a new size of (n = c*2)
	void ResizeArray()
	{
		//Store the old map address
		sKeyValuePair *pOldPosition = pMap;

		//Create a new array with double the capacity
		sKeyValuePair *pNewMap = new sKeyValuePair[mCurrentCapacity * 2];

		//Copy over the data from the old map to the new
		for (int i = 0; i < (mCurrentCapacity); i++)
		{
			pNewMap[i].key = pOldPosition[i].key;
			pNewMap[i].value = pOldPosition[i].value;
		}

		//Delete the old (and temporary) address and point pMap to the new address
		pMap = pNewMap;		
		pNewMap = nullptr;	//Remove a duplicate pointer to pMap
		delete[] pNewMap;
		delete[] pOldPosition;

		mCurrentCapacity *= 2;		//Capacity has doubled - update the tracking variable to reflect this
	}

	/*Linear search (O = n) with a given key, returning the n'th element matching the provided key. 
	Takes the key as a parameter, and results the n'th position in the array that the key is stored at.
	If the key is < 0, the element wasn't found and the calling method can handle this accordingly. */
	int LinearSearch(TKey key)
	{
		int result = -1;			//If the search failed, -1 will be returned
		bool resultFound = false;	//Flag to indicate whether a result was found

		//Search loop - look through each element individually until the key is found
		for (int i = 0; i < mCurrentCapacity; i++)
		{
			//Turn the key into a searchable hash value
			if (pMap[i].key == key)
			{
				resultFound = true;//Update the flag - the key was found
				result = i;	//Return the position of the key
			}
		}

		return result;	//If i is < 0, calling function can handle the throw exception logic
	}

public:
	Map()
	{
		pMap = new sKeyValuePair[mCurrentCapacity]; //Create an array with the defined default size to store the key-value pairs in one data structure
	}

	~Map()
	{
		//Free the memory occupied by the map array on object destruction
		delete[] pMap;
	}

	/*Takes a key and a value - if the key doesn't already exist the entry will be 
	inserted; otherwise an exception will be thrown to avoid duplicating keys. */
	void Insert(TKey key, TValue value)
	{
		//Does the key exist?
		int position = LinearSearch(key);

		//LinearSearch indicated the key is already in use
		if (position != -1)
		{
			//Key found & can't be re-used
			throw std::invalid_argument("Key already exists");
		}

		//Key doesn't exist - is there room in the array?
		if (mNumberOfElements >= mCurrentCapacity)
		{
			//Array needs to be resized
			ResizeArray();
		}

		//Checks complete - insert the new key-value pair
		pMap[mNumberOfElements].key = key;
		pMap[mNumberOfElements].value = value;

		//Increment the tracker
		mNumberOfElements++;
	}

	//Implementation for the Delete method
	void Delete(TKey key)
	{
		//Begin by searching for the key
		int position = LinearSearch(key);

		//LinearSearch returned its default -1 value
		if (position < 0)
		{
			//Key not found - discontinue
			throw std::invalid_argument("Key does not exist");
		}

		/*Key exists - shift everything element after it to the left by 1 (i.e. delete the current entry
		and utilise it's space.*/
		for (int i = position; i < mNumberOfElements; i++)
		{
			pMap[i].key = pMap[i + 1].key;
			pMap[i].value = pMap[i + 1].value;
		}

		//Decrement the tracker
		mNumberOfElements--;
	}

	//Retrieve method takes a key, and if the key exists in the map, returns its associated value
	TValue Retrieve(TKey key)
	{
		//Try to search for the key
		int position = LinearSearch(key);

		//Was the result found?
		if (position < 0)
		{
			//Key not found
			throw std::invalid_argument("Key does not exist");
		}

		//If the program reaches this point, the key was found. Return its associated value
		return pMap[position].value;
	}

	/*Update method - takes a key and a value. First the method will attempt to find the key.
	If the key is found, its associated value will be overwritten with newValue. Otherwise,
	an exception will be thrown.	*/
	void Update(TKey key, TValue newValue)
	{
		//Search for the key
		int position = LinearSearch(key);

		//Check whether the key exists
		if (position < 0)
		{
			//Key not found
			throw std::invalid_argument("Key does not exist");
		}

		//Key exists - update the value associated with it
		pMap[position].value = newValue;
	}

	///Iterators
	//Return the memory address of the first element in the map
	sKeyValuePair* Begin()
	{
		return pMap;
	}

	//Return the address of the last memory address of the map
	sKeyValuePair* End()
	{
		return (pMap + (mNumberOfElements));	//Pointer arithmatic - pointer to map + total number of elements it has in it
	}
};