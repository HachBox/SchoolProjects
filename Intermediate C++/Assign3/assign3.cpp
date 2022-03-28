/*
Programmer: Harry Chieng
This assignment reviews object-oriented programming concepts 
such as classes, methods, constructors, accessor methods, and 
access modifiers. It makes use of an array of objects as a class 
data member, and introduces the concept of object serialization 
or "binary I/O".
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>

#include "ProviderDB.h"

int main()
{
	ProviderDB database("providerdb");

	database.processTransactions("transactions.txt");

	return 0;
}
