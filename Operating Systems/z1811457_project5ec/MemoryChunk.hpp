/*
 * CSCI 480 Assignment 5
 *
 * Author: Harry Chieng
 *
 * MemoryChunk.h - structure of the the page table entry
 *
 * ***/

#ifndef MemoryChunk_hpp
#define MemoryChunk_hpp

struct PageTableEntry {
	bool valid = false;
	int physicalMemoryIndex = -1;	
};

#endif
