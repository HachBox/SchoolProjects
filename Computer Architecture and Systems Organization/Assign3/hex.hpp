//***********************************************************************
//
// CSCI 463 Assignment 3
//
// Author: Harry Chieng
//
// hex.hpp The declaration of your hex formatting class will go here.
//
// **********************************************************************

#ifndef hex_hpp
#define hex_hpp

#include<string>

using std::string;

class hex
{
	public:
		/* 
		 * This outputs 2 hex digits from an 8 bit format.
		 *
		 * This function must return a std::string with exactly 
		 * 2 hex digits representing the 8 bits of the i argument. 
		 *
		 * @param i is a type of unsigned 8 bit integer.
		 *
		 * @return This returns an output string of unsigned 
		 * integers.
		 *
		 * ************************************************/
		static string to_hex8(uint8_t i);

		/*
		 * This outputs 8 hex digits from a 32 bit format.
		 *
		 * This function must return a std::string with 8 hex digits 
		 * representing the 32 bits of the i argument.
		 *
		 * @param i is a type of unsigned 8 bit integer.
		 * 
		 * @return This returns an output string of unsigned 
		 * integers.
		 *
		 * ************************************************/
		static string to_hex32(uint32_t i);

		/* 
		 * This starts wotj a "0x" and outputs 8 hex digits
		 * from another 32 bit format.
		 *
		 * This function must return a std::string beginning 
		 * with 0x, followed by the 8 hex digits representing 
		 * the 32 bits of the i argument.
		 *
		 * @param i is a type of unsigned 8 bit integer.
		 * @return This returns an output string of unsigned 
		 * integers.
		 *
		 * ************************************************/
		static string to_hex0x32(uint32_t i);
};
#endif
