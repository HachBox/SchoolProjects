/*
 * CSCI 463 - Assignment 5
 *
 * Author: Harry Chieng
 *
 * RISC-V Simulator - registerfile.h 
 *
 ******************************************/

#include "hex.h"
#include "rv32i_decode.h"
#include <stdint.h>
#include <vector>

class registerfile : public hex {
	private: 
		std::vector <int32_t> vec;

	public:

		/**
		 * Initialize register x0 to zero, and all other registers to 0xf0f0f0f0.
		 * 
		 * It resets the registers to f0f0f0f0 unless its the first one vec[0].
		 *
		 * @note ensure that the vector's size is allocated in memory.
		 *
		 *************************************************************************/
		void reset();

		/*
		 * Assign register r the given val. If r is zero then do nothing.
		 *
		 * @param r This the parameter for register, this is an unsigned interger 
		 * of 32 bits
		 * 
		 * @param val This is a signed integer of 32 bits. 
		 *
		 * ***********************************************************************/
		void set(uint32_t r, int32_t val);

		/*
		 * Return the value of register r. If r is zero then return zero.
		 *
		 * @param r This the parameter for register, this is an unsigned interger 
		 * of 32 bits
		 *
		 * **********************************************************************/
		int32_t get(uint32_t r) const;

		/*
		 * use the hex class (hex32() funct) to simplify printing the register values.
		 *
		 * @param hdr returns the string passed to it.
		 *
		 ************************************************************************/
		void dump(const std::string &hdr) const;

		registerfile();
};
