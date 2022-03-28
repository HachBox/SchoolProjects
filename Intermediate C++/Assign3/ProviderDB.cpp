#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include "ProviderDB.h"

using namespace std;

ProviderDB::ProviderDB()
{
}

ProviderDB::ProviderDB(const char* database) //1 argument constructor no return types!!!
{
	ifstream inputStream;

        inputStream.open(database,ios::binary); //opens binary input

	if(!inputStream)
	{
		cerr << "ProviderDB - Could not open provide dbFileName";
		exit(1);
	}
	inputStream.read((char*) this, sizeof(ProviderDB));
	inputStream.close();
}

void ProviderDB::processTransactions(const char* fileProvider)
{
	ifstream inputStream;

	inputStream.open(fileProvider); //opens fileProvider

	if(!inputStream)
	{
		cerr << "ProviderDB - Could not open fileProvider";
		exit(1);
	}

	string transType;	//creates string for transType
	inputStream >> transType;
	if(transType == "all")
	{
		sortByName();
		print();
	}
	else if(transType == "specialty")
	{
		char searchSpecialty[41];
		char whiteSpace; 	//char b/c reads ' ' character
		inputStream >> whiteSpace;     //inputStream is the ifstream for transaction file	
	inputStream.getline(searchSpecialty,41);	//the argument is where it will save to
		sortBySpecialty(); 	//calls the method (written below)
		int count = 0;
		for(int i = 0; i<numProviders; i++)
			if(strcmp(searchSpecialty, providers[i].getSpecialty())==0)
				//checks if specialty wanted is specialty has	
				count++;		
		cout << "There are"  << count 
			<< "specialies with" << searchSpecialty 
			<< "." <<  endl;
	}
	else if(transType == "number")
	{
		string providerNumber;
		inputStream >> 	providerNumber;
		sortByProviderNumber();
		int positionInArray = searchForProviderNumber(providerNumber);
		//declared positionInArray, searches for provider number
		if(positionInArray == -1) 
			cerr << "The provider number was not found" << endl;
		else
		{
			cout << positionInArray << endl;
			providers[positionInArray].print();	//it's a function
		}
	}
	inputStream.close();
}

int ProviderDB::searchForProviderNumber(string searchNumber)
{
	int low = 0;
	int high = numProviders - 1;
	int mid;

	while (low <= high)
	{
		mid = (low + high) / 2;

		if (searchNumber == providers[mid].getProviderNumber())
			return mid;

		if (searchNumber < providers[mid].getProviderNumber())
			high = mid - 1;
		else
			low = mid + 1;
	}

	return -1;
}

void ProviderDB::sortByProviderNumber()
{
	//sort the arrayProvider in ascending order
	int i, j;
	Provider bucket; //change data type of bucket to Provider

	for (i = 1; i < numProviders; i++)  //change parameters for 'for' loop
	{
		bucket = providers[i]; //change numbers to arrayProvider objects 

		for (j = i; 
				(j > 0) &&
				strcmp(providers[j-1].getProviderNumber(),
					bucket.getProviderNumber()) > 0; 
				//we are comparing cstrings
				j--) //both calls to get the provider number
		
			providers[j] = providers[j-1];

		providers[j] = bucket; //change bucket to numProviders
	}
}
void ProviderDB::sortBySpecialty()
{
	//sorts the arrayProvider objects in descending order
	int i, j;
        Provider bucket; //change data type of bucket to Provider

        for (i = 1; i < numProviders; i++)  //change parameters for 'for' loop
        {
                bucket = providers[i]; //change numbers to arrayProvider objects

                for (j = i;
                                (j > 0) &&
                                strcmp(providers[j-1].getSpecialty(),
                                        bucket.getSpecialty()) > 0;
                                //we are comparing cstrings
                                j--) //both calls to get the provider number

                        providers[j] = providers[j-1];

                providers[j] = bucket; //change bucket to numProviders
        }

}
void ProviderDB::sortByName()
{
	//sorts the arrayProvider objects in ascending order
	int i, j;
        Provider bucket; //change data type of bucket to Provider

        for (i = 1; i < numProviders; i++)  //change parameters for 'for' loop
        {
                bucket = providers[i]; //change numbers to arrayProvider objects

                for (j = i;
                                (j > 0) &&
                                strcmp(providers[j-1].getName(),
                                        bucket.getName()) > 0;
                                //we are comparing cstrings
                                j--) //both calls to get the provider number

                        providers[j] = providers[j-1];

                providers[j] = bucket; //change bucket to numProviders
        }

}

void ProviderDB::print()
{
	for(int i = 0;i<numProviders;i++)
		providers[i].print();
}
