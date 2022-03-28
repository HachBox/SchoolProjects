/*
 * CSCI 480 Assignment 5
 *
 * Author: Harry Chieng
 *
 * PhysicalMemory.h - Physical memory contains the entries of physical frames, which can be an array or a vector. 
 * They are created by the constructor.
 *
 * ***/

#ifndef PhysicalMemory_hpp
#define PhysicalMemory_hpp

#include <string>
#include <vector>

class PhysicalMemory
{
	public:
		PhysicalMemory(int memorySize, int algorithmIn); //Initialize all the data and data structure in the class (e.g. set clock to 0). 
		//The second argument is for testing different page replacement algorithms if you will implement the bonus credits for LRU.
		void access(int frameID);   //access the frame. If LRU update the time stamp and time list 
		void printMemory() const;  //print out the physical memory layout
		int swapIn(std::string item);  //returns the frame ID of the item just swapped in. If FIFO update the timestamp and time list

	private:
		std::vector <std::string> memoryList;   //The physical memory!
		std::vector <int> timeList; //data structure for the replacement algorithm
		int currentTimeIndex;  //current clock for timestamp
		int algorithmFlag; //indicate if using FIFO or LRU
		//For FIFO, the status is only updated when the page is swapped into memory first time (but not later access).  
		//The bigger the number, the later it has been loaded. 
		//The FIFO algorithm replaces the entry with the smallest number.  

		//For LRU, the status of that memory entry is set to the current timestamp for each access. 
		//The bigger the number, the more recent it has been accessed.  
		//The LRU algorithm replaces the entry with the smallest number (unless it is 0, which should not be when the physical memory is full).
		int getNextAvailableFrame();  //get a frame, either available or via replacement
		bool isFull();   //check if the memory is full
};


#endif
