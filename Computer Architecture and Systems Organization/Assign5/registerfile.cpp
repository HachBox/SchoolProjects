/*
 * CSCI 463 - Assignment 5
 *
 * Author: Harry Chieng
 *
 * RISC-V Simulator - registerfile.cpp 
 *
 ******************************************/

#include "registerfile.h"
#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::vector;
using std::setw;
using std::endl;
using std::right;

//Initialize register x0 to zero, and all other registers to 0xf0f0f0f0.
void registerfile::reset() {
	for (uint32_t i = 1; i < vec.size(); i++)
		vec[i] = 0xf0f0f0f0;
	vec[0] = 0;
}

//Assign register r the given val. If r is zero then do nothing.
void registerfile::set(uint32_t r, int32_t val) {
	if (r == 0)
		return;
	vec[r] = val;
}

//Return the value of register r. If r is zero then return zero.
int32_t registerfile::get(uint32_t r) const {
	if (r == 0)
		return 0;
	else
		return vec[r];
}

void registerfile::dump(const std::string &hdr) const {
	for(uint32_t i = 0; i < vec.size(); i++) { //first column

		if(i % 0x08 == 0) {
			std::stringstream ss;
			ss << "x" << i;
			cout << hdr << right << setw(3) << ss.str();

			for(uint32_t j = 0; j < 8; j++) { //second column	
				if(j == 4) 
					cout << " ";
				cout << " " << hex::to_hex32(get(j+i));
			}
		}

		if(i % 0x08 == 0x07)
			cout << endl;
	}
}
registerfile::registerfile(){
	vec.resize(32);
	reset();
}
