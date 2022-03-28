/*
 * CSCI 463 - Assignment 5
 *
 * Author: Harry Chieng
 *
 * RISC-V Simulator - cpu_single_hart.cpp
 *
 ****************************************/

#include "cpu_single_hart.h"
#include <iostream>

using std::cout;
using std::endl;

void cpu_single_hart::run(uint64_t exec_limit) {
	regs.set(2, mem.get_size());
	//note the number of bytes in the memory ios also the address of the first byte past the end of the simulated memory.
	if(exec_limit == 0)
		while (is_halted() == false) {
			tick();
		}
	else
		while (!is_halted() && exec_limit > get_insn_counter()){
			tick();
		}
	if(is_halted() == true) {
		cout << "Execution terminated. Reason: " << get_halt_reason() << endl;
	}
	cout << get_insn_counter() << " instructions executed" << endl;	
}
