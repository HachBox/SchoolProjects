//***********************************************************************
//
// CSCI 463 Assignment 5
//
// Author: Harry Chieng
//
// main.cpp RV32I Disassembler
//
// insn = instruction
//
//***********************************************************************

#include "cpu_single_hart.h"
#include "rv32i_hart.h"

#include <sstream>
#include <unistd.h>
#include <iostream>


using std::istringstream;
using std::cout;
using std::endl;
using std::cerr;

void disassemble(const memory &mem) //& = when func is called, don't need to make a copy
{
	for (uint32_t i = 0; i < mem.get_size(); i+=4) {
		uint32_t addr = i;
		uint32_t insn = mem.get32(addr);
		cout << hex::to_hex32(addr) << ": " << hex::to_hex32(insn) << rv32i_decode::decode(addr, insn) << endl;
	}	
}

static void usage()
{
	cerr << "Usage: rv32i [-d] [-i] [-r] [-z] [-l exec-limit] [-m hex-mem-size] infile" << endl ;
	cerr << "    -d show disassembly before program execution" << endl;
	cerr << "    -i show instruction printing during execution" << endl;
	cerr << "    -l maximum number of instructions to exec" << endl;
	cerr << "    -m specify memory size (default = 0x100)" << endl;
	cerr << "    -r show register printing during execution" << endl;
	cerr << "    -z show a dump of the regs & memory after simulation" << endl;
	exit (1);
}

int main(int argc, char **argv)
{
	uint32_t memory_limit = 0x100; // default memory size = 256 bytes
	uint32_t execution_limit = 0;
	int opt;
	bool disass = false;
	bool print = false;
	bool isSim = false;
	bool isHalt = false;
	while ((opt = getopt(argc, argv, "dirzl:m:")) != -1)
	{
		switch (opt)
		{
			case 'd':
				{
					disass = true;
				}
				break;

			case 'i':
				{
					print = true;
				}
				break;

			case 'l':
				{
					istringstream iss(optarg);
					iss >> std::hex >> execution_limit;
					//execution_limit = 1
					//cout << "this is inside case l" << endl;
				}
				break;

			case 'm':
				{
					istringstream iss(optarg);
					iss >> std::hex >> memory_limit;
				}
				break;

			case 'r':
				{
					isSim =  true;
				}
				break;

			case 'z':
				{
					isHalt = true;
				}
				break;

			default: /* ’?’ */
				usage();
		}
	}
	if (optind >= argc){
		std::cerr << "Error here";
		usage(); // missing filename
	}
	memory mem(memory_limit);
	if (!mem.load_file(argv[optind])) {
		usage();
	}
	if (disass == true)
		disassemble(mem);
	//if (execution_limit == false) {}

	cpu_single_hart csh(mem);
	csh.reset();	
	csh.set_show_instructions(print);
	csh.set_show_registers(isSim);
	csh.run(execution_limit);
	if(isHalt) {
		csh.dump();
		mem.dump();
	}	
	return 0;
}
