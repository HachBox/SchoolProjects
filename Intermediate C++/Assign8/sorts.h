/*************************************************************
Program:	CSCI 241 Assign 8
Programmer: 	Harry Chieng
Logon ID:	z1811457
Due Date:	11/29/2017
 *************************************************************/
#ifndef _SORT_H
#define _SORT_H

#include <iostream>
#include <fstream>

	template <class T> 	//std::vectors use standard library
void buildList(std::vector<T>& set, const char* fileName)
{
	std::ifstream inFile;
	T item;	

	inFile.open(fileName, std::ifstream::in);
	//Open inFile for input using fileName as the name of the file to open
	if (!inFile){
		std::cerr << "Error - unable to open input file\n";
		exit(1);
	}
	//Check that the file has been successfully opened

	inFile>>item;	//Read item from input file
	while (!inFile.eof())	//while not end of file
	{
		set.push_back(item);

		inFile>>item;	//Read item from input file	
	}

	inFile.close();
	//Close the input file
}
	template <class T>
void printList(const std::vector<T>& set, int itemWidth, int numPerLine)	//constant reference to a vector of Ts named set
{
	for (int i = 0; i < set.size(); i++)	//casting = (int)
	{
		std::cout << std::setw(itemWidth);
		std::cout << set[i] << " ";
		if(0 == ((i+1) % numPerLine) )	//shifts everything by one, and when 0 
			std::cout << std::endl;
	}	
}

template <class T>
bool lessThan(const T& item1, const T& item2)
{
	if ( item1 < item2 )	//if item 1 is less than item 2
		return true;	//return true
	else
		return false;	//else, return false
}
template <class T>
bool greaterThan(const T& item1, const T& item2)
{
	if ( item1 > item2 )	//if item 1 is greater than item 2
		return true;	//return true
	else
		return false;	//else, return false
}


#endif
