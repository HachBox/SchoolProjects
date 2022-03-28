//***********************************************************************
//
// CSCI 463 Assignment 3
//
// Author: Harry Chieng
//
// main.cpp Memory Simulator
//
// **********************************************************************

#include "hex.h"
#include "memory.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <iostream>
#include <sstream>

using std::hex;
using std::cerr;
using std::endl;
using std::cout;

/*
 * The usage() function prints an error.
 *
 * The provided usage() function prints an appropriate “Usage” error 
 * message and “Pattern” to stderr and terminates the program in the 
 * traditional manner as discussed here: 
 * https://en.wikipedia.org/wiki/Usage_message
 *
 * @bug This should not have any bugs as it was written by professor Winans.
 *
 * ***************************************************************************/
static void usage()
{
	cerr << " Usage : rv32i [ - m hex - mem - size ] infile " << endl ;
	cerr << " -m specify memory size ( default = 0 x100 )" << endl ;
	exit (1);
}

/*
 * The main() runs the output with the given parameters.
 *
 * The output is arranged in hex in sets of 8, 32, and 0x32 in an 8/16/32 
 * bit configuration. As it loads the file seeing where the vector's limit is.
 * 
 * @param argc Argc is called the argument count. This will be the number of 
 * strings pointed to by argv. Passing an integer.
 * @param argv Argv is called the argument vector. This will be the array of 
 * arguments. This passes a character.
 * 
 * @return This returns 0 for ending the code.
 *
 * @note The main function should be in proper order as it was given initially.
 *
 * @warning When copy and pasting this, there will be copy errors. Watch out for 
 * extra spacing.
 *
 * ***************************************************************************/
int main( int argc , char **argv )
{
	uint32_t memory_limit = 0x100; // default memory size is 0x100

	int opt;
	while (( opt = getopt ( argc , argv , " m:")) != -1)
	{
		switch(opt)
		{
			case 'm':
				{
					std::istringstream iss ( optarg );
					iss >> hex >> memory_limit;
				}
				break;
			default:
				usage();
		}
	}
	if ( optind >= argc )
		usage (); // missing filename
	memory mem ( memory_limit );
	mem.dump();

	if (!mem.load_file( argv [optind]))
		usage();

	mem.dump();

	cout << mem.get_size () << endl ;
	cout << hex::to_hex32 ( mem.get8 (0)) << endl;
	cout << hex::to_hex32 ( mem.get16 (0)) << endl;
	cout << hex::to_hex32 ( mem.get32 (0)) << endl;

	cout << hex::to_hex0x32 ( mem.get8 (0)) << endl;
	cout << hex::to_hex0x32 ( mem.get16 (0)) << endl;
	cout << hex::to_hex0x32 ( mem.get32 (0)) << endl;

	cout << hex::to_hex8 ( mem.get8 (0)) << endl;
	cout << hex::to_hex8 ( mem.get16 (0)) << endl;
	cout << hex::to_hex8 ( mem.get32 (0)) << endl;

	cout << hex::to_hex0x32 ( mem.get32 (0x1000)) << endl;

	mem.set8 (0x10 , 0x12);
	mem.set16 (0x14 , 0x1234);
	mem.set32 (0x18 , 0x87654321);

	cout << hex::to_hex0x32 ( mem.get8_sx (0x0f)) << endl;
	cout << hex::to_hex0x32 ( mem.get8_sx (0x7f)) << endl;
	cout << hex::to_hex0x32 ( mem.get8_sx (0x80)) << endl;
	cout << hex::to_hex0x32 ( mem.get8_sx (0xe3)) << endl;
	cout << hex::to_hex0x32 ( mem.get16_sx (0xe0)) << endl;
	cout << hex::to_hex0x32 ( mem.get32_sx (0xe0)) << endl;

	mem.dump();
	return 0;
}





