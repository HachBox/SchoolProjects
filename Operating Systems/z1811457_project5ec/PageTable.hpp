/*
 * CSCI 480 Assignment 5
 *
 * Author: Harry Chieng
 *
 * PageTable.h - You can define a structure for the page table entries. 
 *
 * ***/

#ifndef PageTable_hpp
#define PageTable_hpp

#include "PhysicalMemory.hpp"
#include "MemoryChunk.hpp"

#include <string>
#include <vector>

class PageTable
{
	public:
		PageTable(PhysicalMemory* pmIn, int tableSize); //initialize all entries to invalid
		void reference(int pageID, std::string item); //reference a logical page,  if not in memory,  call pageFault() 
		int getFaults() const;  //return number of faults
		void printTable() const;  //print the layout of page table
		void reset();//reset the validity flag to false, and  numberoffaults  to 0.

	private:
		std::vector<PageTableEntry> entryList;  //the page table!
		int numFaults;
		PhysicalMemory* mainPhysicalMemory;
		void pageFault(int pageID, std::string item);  // increment numFaults;  need to swap in the item into physical memory by calling the swapIn() of the PhysicalMemory class 
		void updateReplacedEntry(int replacedIndex, int pageID); // after page replacement, update the page table correspondingly by making the original mapping for the frame invalid
};

#endif
