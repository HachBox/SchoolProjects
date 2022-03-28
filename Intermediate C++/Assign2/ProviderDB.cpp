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
