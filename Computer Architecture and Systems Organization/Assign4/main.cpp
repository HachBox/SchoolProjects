//***********************************************************************
//
// CSCI 463 Assignment 4
//
// Author: Harry Chieng
//
// main.cpp RV32I Disassembler
//
// insn = instruction
//
//***********************************************************************

#include "hex.h"
#include "memory.h"
#include "rv32i_decode.h"

#include <sstream>
#include <unistd.h>
#include <iostream>

using std::istringstream;
using std::cout;
using std::endl;
using std::cerr;

/*
 * The disassemble() function prints the output from the decode function.
 *
 * The function decodes each of the 32-bit words in the simulated memory and 
 * prints out the memory address, instruction hex value, and the instruction
 * mnemonic.
 *
 * @param &mem is calling the memory file allocating it as mem to use in the 
 * function.
 *
 * ***************************************************************************/

void disassemble(const memory &mem) //& = when func is called, don't need to make a copy
{
	for (uint32_t i = 0; i < mem.get_size(); i+=4) {
		uint32_t addr = i;
		uint32_t insn = mem.get32(addr);
		cout << hex::to_hex32(addr) << ": " << hex::to_hex32(insn) << rv32i_decode::decode(addr, insn) << endl;
	}	
}
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
 * The main() function calls the file and uses 
 * 
 * The  
 * 
 * @param argc Argc is called the argument count. This will be the number of 
 * strings pointed to by argv. Passing an integer.
 *
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

int main(int argc, char **argv)
{
	uint32_t memory_limit = 0x100; // default memory size = 256 bytes
	int opt;
	while ((opt = getopt(argc, argv, "m:")) != -1)
	{
		switch (opt)
		{
			case 'm':
				{
					istringstream iss(optarg);
					iss >> std::hex >> memory_limit;
				}
				break;
			default: /* ’?’ */
				usage();
		}
	}
	if (optind >= argc)
		usage(); // missing filename
	memory mem(memory_limit);
	if (!mem.load_file(argv[optind]))
		usage();
	disassemble(mem);
	mem.dump();
	return 0;
}

