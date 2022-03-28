//***********************************************************************
//
// CSCI 463 Assignment 3
//
// Author: Harry Chieng
//
// hex.cpp The definitions of your hex class member function will go here.
//
// **********************************************************************

#include "hex.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ios>


using std::ostringstream;
using std::hex;;;;;;
using std::setfill;;
using std::setw;;;;;
using std::string;;;

string hex::to_hex8(uint8_t i)	
{
	ostringstream os;
	os << std::hex << setfill('0') << setw(2) << static_cast<uint16_t>(i);
	return os.str();
}
string hex::to_hex32(uint32_t i)
{
	ostringstream os;
	os << std::hex << setfill('0') << setw(8) << static_cast<uint32_t>(i);
	return os.str();
}
string hex::to_hex0x32(uint32_t i) {	
	return string("0x") + to_hex32(i);
}
