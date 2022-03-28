/*
 * CSCI 480 Assignment 5
 *
 * Author: Harry Chieng
 *
 * PhysicalMemory.h - Physical memory contains the entries of physical frames, which can be an array or a vector. 
 * They are created by the constructor.
 *
 * ***/

#include "PhysicalMemory.hpp"

#include <iostream>

using std::string;

PhysicalMemory::PhysicalMemory(int memorySize, int algorithmIn) {
	currentTimeIndex = 0; //Initialize all the data and data structure in the class (e.g. set clock to 0). 
	algorithmFlag = algorithmIn; //The second argument is for testing different page replacement algorithms if you will implement the bonus credits for LRU.
	memoryList.resize(memorySize);
}

void PhysicalMemory::access(int frameID){   //access the frame. If LRU update the time stamp and time list 
	std::cout << "Physical: Accessed frameID: " << frameID << " contains: " << memoryList[frameID] << std::endl;
	std::cout << std::endl;	
	//Note that if you plan to implement the LRU algorithm, the method you need to modify is access() because that is where the timelist is updated differently.
}

void PhysicalMemory::printMemory() const { //print out the physical memory layout
	std::cout << "Physical Memory Layout:" << std::endl;
	for(size_t i = 0; i < memoryList.size(); i++) {
		std::cout << "Frame: " << i <<  " contains: " << memoryList[i] << std::endl;	
	}	
	std::cout << std::endl;
}

int PhysicalMemory::swapIn(string item) {  //returns the frame ID of the item just swapped in. If FIFO update the timestamp and time list
	//int swapIn(string item); -- It needs to get the next available frame by calling getNextAvailableFrame(),  and update the memory list.  
	//For FIFO, it also updates the time stamp and the time list (because that is how your program keeps track of when the content of the frame is in). 
	int frameID = getNextAvailableFrame();
	currentTimeIndex++;
	//TODO timeList	
	std::cout << "Physical: Swap In: " << item << std::endl;
	memoryList[frameID] = item;
	return frameID;//Return the frame id.

}

int PhysicalMemory::getNextAvailableFrame() {  //get a frame, either available or via replacement
	int frameID = currentTimeIndex%memoryList.size(); //this should be the first location (frame)
	//returns the frame that will be used by PageTable to store info when there is a page fault.  
	//It can be a currently empty frame, or a victim as the result of replacement.  
	//If there is empty frame, then return the available frame in a sequence starting from 0. 
	return frameID;//Otherwise, uses FIFO (or LRU for bonus credit).
}

bool PhysicalMemory::isFull(){	//check if the memory is full
	//The method isFull() can be implemented using the initial value of timeList or memoryList.  
	//For example, the timeList can be initialized to 0.  
	return 0;//So if a time list has a status of 0, it means that physical frame is empty (initial status).
}
