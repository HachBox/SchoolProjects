/*
 * CSCI 463 - Assignment 5
 *
 * Author: Harry Chieng
 *
 * RISC-V Simulator - cpu_single_hart.h
 *
 ****************************************/

#ifndef cpu_single_hart_h
#define cpu_single_hart_h
#include "rv32i_hart.h"

class cpu_single_hart : public rv32i_hart
{
	public:

		/*
		 * The constructor for cpu single hart.
		 *
		 * @param mem the memory from memory
		 *
		 * **********************************************************/
		cpu_single_hart(memory &mem) : rv32i_hart(mem) {}

		/*
		 * After the disassembly, construct and reset() your CPU like this
		 *
		 * @param exec_limit The limit for executive function.
		 *
		 ***********************************************************/
		void run(uint64_t exec_limit);
};
#endif
