/*
 * CSCI 480 Assignment 5
 *
 * Author: Harry Chieng
 *
 * PageTable.h - You can define a structure for the page table entries. 
 *
 *********************************************************************/

#include "PageTable.hpp"
#include <iostream>

using std::string;

PageTable::PageTable(PhysicalMemory* pmIn, int tableSize){ //initialize all entries to invalid; pmIn = physical memory input
	//Inside it, you will have a data structure that stores the entries (it can be a vector or an array).  
	entryList.resize(tableSize); //The constructor takes the size of the page table that creates the entries, 
	for(size_t i = 0; i < entryList.size(); i++) { //initialize the flags in the entries to false,
		entryList[i].valid = false;
	} 
	numFaults = 0;//and initialize number of faults to 0. 
	mainPhysicalMemory = pmIn; //It also takes a pointer to the PhysicalMemory (for calling some of its methods later). 
}

void PageTable::reference(int pageID, string item) { //reference a logical page,  if not in memory,  call pageFault() 
	//You will write a public method reference(),
	//which will first check if the corresponding entry given pageID is valid. 
	if (entryList[pageID].valid){ //if yes, access the entry in Physical Memory (by calling its access() method),  
		int frameID = entryList[pageID].physicalMemoryIndex; //finding which lecturn it is on 
		mainPhysicalMemory->access(frameID);
	}

	else { //otherwise call the private method pageFault(), which increments the numFaults and calls a method swapIn() of PhysicalMemory to swap in the page. 
		pageFault(pageID, item);
		int frameID = entryList[pageID].physicalMemoryIndex; //finding which lecturn it is on 
		mainPhysicalMemory->access(frameID);
	}
	//It then updates the related entries in the page table by making the original mapping for the frame invalid, and the new mapping valid.
}

int PageTable::getFaults() const {  //return number of faults
	return numFaults;
} 

void PageTable::printTable() const {  //print the layout of page table
	std::cout << "Page Table Snapshot:" << std::endl;
	for(size_t i = 0; i < entryList.size(); i++) { 
		std::cout << "Page Index: " << i << " : Physical Frame Index: " << entryList[i].physicalMemoryIndex << " : In Use: " << (entryList[i].valid?"true":"false") << std::endl;
	}
	std::cout << "PageTable: Current number of page faults: " << numFaults;
}

void PageTable::reset() { //reset the validity flag to false, and  numberoffaults  to 0.
	for(size_t i = 0; i < entryList.size(); i++) { 
		entryList[i].valid = false;
	}
	numFaults = 0;
}

void PageTable::pageFault(int pageID, string item){  // increment numFaults;  need to swap in the item into physical memory by calling the swapIn() of the PhysicalMemory class 
	std::cout << "PageTable: page fault occurred" << std::endl;
	numFaults++;
	int frameID = mainPhysicalMemory->swapIn(item); //puts the book onto the lecturn
	updateReplacedEntry(frameID, pageID);	
}

void PageTable::updateReplacedEntry(int replacedIndex, int pageID) { // after page replacement, update the page table correspondingly by making the original mapping for the frame invalid
	int frameID = replacedIndex;
	for (size_t i = 0; i < entryList.size(); i++) {	
		if(entryList[i].physicalMemoryIndex == frameID) {
			entryList[i].valid = false;
			entryList[i].physicalMemoryIndex = -1;
		}

	}
	entryList[pageID].physicalMemoryIndex = frameID; //records putting a new book onto specific lecturn 
	entryList[pageID].valid = true;
	//The method updateReplacedEntry() is an optional method that can be called by the pageFault() for such updating of the entries.
}
