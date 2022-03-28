#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack()
{
	sArray = nullptr;
	sCapacity = 0;
	sSize = 0;
}

Stack::~Stack() 	//destructor
{
	delete[] sArray;
	//for(int i = 0; i < sCapacity; i++)
	//	delete &sArray[i];	//reference to sArray's object
}

Stack::Stack(const Stack& other)
{
	sSize = 0;
	sArray = nullptr;
	reserve(other.sCapacity);	//copy constructor copies size of other to
	sSize = other.sSize;
	for(int i = 0; i < sSize; i++)	//each itteration of?
	{
		sArray[i] = other.sArray[i];
	}
}


Stack& Stack::operator=(const Stack& other)
{
	if(this == &other) return *this;	//bug pointed!
	sSize = 0;
	reserve(other.sCapacity);
	sSize = other.sSize;
	for(int i = 0; i < sSize; i++)
		sArray[i] = other.sArray[i];
	return *this;
}

ostream& operator<<(ostream& lhs, const Stack& rhs)
{
	for(int i = 0; i < rhs.sSize; i++)
		lhs<<rhs.sArray[i]<< " ";
	return lhs;	//returns the cout object (lhs)
}

void Stack::clear()
{
	sSize = 0;
}

size_t Stack::size() const
{
	return sSize;
}

size_t Stack::capacity() const
{
	return sCapacity;
}

bool Stack::empty() const
{
	if(sSize == 0)
		return 1;
	else
		return 0;
}

int Stack::top() const
{
	return sArray[sSize-1];
}

void Stack::push(int val)
{
	if (sSize == sCapacity)
	{
		if (sCapacity == 0)
			reserve(1);
		else
			reserve(sCapacity * 2);
	}
	sArray[sSize] = val;
	sSize++;
}

void Stack::pop()
{
	sSize--;
}

void Stack::reserve(size_t n)
{
	if (n< sSize || n == sCapacity)
		return;

	int* tempArray = new int[n];
	
	for (size_t i = 0; i < sSize; i++)
	{
		tempArray[i] = sArray[i];
	}
	if(sArray)
	delete[] sArray;
	//for(int i = 0; i < sCapacity; i++)
	//	delete &sArray[i];
	sCapacity = n;			
	sArray = tempArray;
}

int Stack::operator[](size_t n) const
{
	return sArray[n];
}

int& Stack::operator[](size_t n)
{
	return sArray[n];
}

bool Stack::operator==(const Stack& rhs) const
{
	if(sSize != rhs.sSize)
		return false;

	for(int i = 0; i < sSize; i++)
		if(sArray[i] != rhs.sArray[i])
			return false;
	return true;		//returns with the result of oth stacks being the same
}

