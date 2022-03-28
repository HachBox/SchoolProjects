//***********************************************************************
//
// CSCI 463 Assignment 5
//
// Author: Harry Chieng
//
// memory.cpp The memory class member function definitions will go here.
//
// **********************************************************************

#include "hex.h"
#include "memory.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <sstream>
#include <fstream>

using std::string;
using std::cout;
using std::vector;
using std::ifstream;
using std::noskipws;
using std::cerr;
using std::endl;

memory::memory ( uint32_t siz ) {
	siz = (siz+15)&0xfffffff0; //round the length up, mod-16 (multiple of 16) 
	for(uint32_t i = 0; i < siz; i++) //Allocate siz bytes in the mem vector
		mem.push_back(0xa5); //initialize every byte/element to 0xa5
}

memory::~memory () { 	
} //in the destructor clean up anything necessary

bool memory::check_illegal ( uint32_t i ) const {

	if (i >= mem.size()) {
		cout << "WARNING: Address out of range: " << hex::to_hex0x32(i) << endl;
		return true;
	}
	else {
		return false;
	}
}

uint32_t memory::get_size () const {
	return mem.size();
}

uint8_t memory::get8 ( uint32_t addr ) const { //this function is crucial in order to establish the other func.
	if(!check_illegal(addr))
		return mem[addr]; //return the value of the byte at addr in mem vector
	else
		return 0;
}

uint16_t memory::get16 ( uint32_t addr ) const {
	uint16_t i = get8(addr);
	uint16_t j = get8(addr+1);
	return i|(j<<8);
}

uint32_t memory::get32 ( uint32_t addr ) const {
	uint32_t i = get16(addr);
	uint32_t j = get16(addr+2);
	return i|(j<<16);
}

int32_t memory::get8_sx ( uint32_t addr ) const { //this function is crucial in order to establish the other func.
	return int8_t(get8(addr));
}

int32_t memory::get16_sx ( uint32_t addr ) const {
	return int16_t(get16(addr));
}

int32_t memory::get32_sx ( uint32_t addr ) const {
	return int32_t(get32(addr));
}

void memory::set8 ( uint32_t addr , uint8_t val ) { //this function is crucial in order to establish the other func.
	if(!check_illegal(addr))
		mem[addr] = val;
	else
		return;
}

void memory::set16 ( uint32_t addr , uint16_t val ) {
	uint16_t i = val >> 8;
	uint16_t j = val & 0xff;
	set8(addr+1,i); //upper half
	set8(addr,j); //lower half
}

void memory::set32 ( uint32_t addr , uint32_t val ) {
	uint32_t i = val >> 16;
	uint32_t j = val & 0xffff;
	set16(addr+2,i);
	set16(addr,j);
}


//i = column, j = column (after 2nd for loop)
void memory::dump () const {
	for(uint32_t i = 0; i < get_size() ;i++) { //first column

		if(i % 0x10 == 0) {

			cout << hex::to_hex32(i) << ": ";

			for(uint32_t j = 0; j < 16; j++) { //second column	
				if(j == 8) 
					cout << " ";
				cout << hex::to_hex8(get8(j+i)) << " ";
			}

			cout << "*";

			for(uint32_t k = 0; k < 16; k++) { //third column
				uint8_t ch = get8(k+i);
				ch = isprint(ch) ? ch : '.'; 
				cout << (char)ch;
			}

			cout << "*";
		}

		if(i % 0x10 == 0x0f)
			cout << endl;
	}
}

bool memory::load_file ( const string & fname ) {

	ifstream infile(fname, std::ios::in | std::ios::binary);

	if (!infile) {
		cerr << "Can't open file 'testdata' for reading.";
		return false;
	}
	else {
		uint8_t i;
		infile >> noskipws;
		for (uint32_t addr = 0; infile >> i; addr++) {
			if (check_illegal(addr)) {
				cerr << "Program too big." << endl;
				return false;
			}
			set8(addr,i); //stores into memory if there is space.	
		}
		return 1;
	}
}
