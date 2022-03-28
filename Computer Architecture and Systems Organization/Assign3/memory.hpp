//***********************************************************************
//
// CSCI 463 Assignment 3
//
// Author: Harry Chieng
//
// memory.hpp The definition of your memory class will go here.
//
// **********************************************************************

#ifndef memory_hpp
#define memory_hpp

#include <vector>

using std::vector;

class memory
{
	public :
		/*
		 * This is the constructor of the memory.
		 *
		 * The constuctor allocates siz bytes in the mem 
		 * vector and initialize every byte/element to 0xa5. 
		 *
		 * @param s THIS is a type of unsigned integer of 32 
		 * bits.
		 *
		 * @note This rounds the length of the size allocated
		 * in memory.
		 *
		 * **********************************************/
		memory ( uint32_t s );

		/* 
		 * Destruct0r
		 *
		 * In the destructor clean up anything necessary
		 *
		 * ************************************************/
		~ memory ();

		/* 
		 * Checks if the given value is within the vector.
		 *
		 * Return true if the given address is not in your 
		 * simulated memory. If the given address is not in 
		 * your simulated memory then print a warning message 
		 * to stdout and return true.
		 * Obviously, formatting this warning message will 
		 * involve using your hex::to_hex0x32() function
		 *
		 * @param addr This is a type of unsigned integer 
		 * of 32 bits of the address in the vector.
		 *
		 * @return Returns a string if true if it the size 
		 * of the vector is passed. Returns false if the 
		 * size is not surpassed.
		 * 
		 * @note This function checks if it is **NOT** within 
		 * the given size parameter of the vector.
		 *
		 * ************************************************/
		bool check_illegal ( uint32_t addr ) const ;

		/* 
		 * Obtains the size of the vector.
		 *
		 * Return the (rounded up) number of bytes in the 
		 * simulated memory. This allows access to the size
		 * of the given vector.
		 *
		 * @return It returns the size of the mem vector.
		 *
		 * ************************************************/
		uint32_t get_size () const ;

		/* 
		 * This GETS the integer at the address (addr) in the 
		 * vector (mem).
		 *
		 * Check to see if the given addr is in your mem by 
		 * calling check_illegal(). If addr is in the valid 
		 * range then return the value of the byte from your 
		 * simulated memory at the given address. If addr is
		 * not in the valid range then return zero to the 
		 * caller. Note that this is the only code that will 
		 * ever read values from the mem vector.
		 *
		 * @param addr This is a type of unsigned integer 
		 * of 32 bits of the address in the vector.
		 *
		 * @note This function is important as it will be 
		 * called in several other functions.
		 * 
		 * @return This returns the address (addr) from the 
		 * vector (mem) if the address is within the vector's size.
		 *
		 * ************************************************/
		uint8_t get8 ( uint32_t addr ) const ;
		
		/* 
		 * This GETS the integer at the address (addr) in the 
		 * vector (mem).
		 *
		 * This function must call your get8() function twice 
		 * to get two bytes and then combine them in little-endian1 
		 * order to create a 16-bit return value. Because you are 
		 * using your get8() function, the job of validating 
		 * the addresses of the two bytes will be taken care 
		 * of there. Do not redundantly check the validity 
		 * in this function.
		 *
		 * @param addr This is a type of unsigned integer 
		 * of 32 bits of the address in the vector.
		 *
		 * @return This return the address of both addresses
		 * with one shifting 8 bits to the right by little 
		 * endian.
		 *
		 * ************************************************/
		uint16_t get16 ( uint32_t addr ) const ;

		/*
		 * This GETS the integer at the address (addr) in the 
		 * vector (mem).
		 *
		 * This function must call get16() function twice 
		 * and combine the results in little-endian order 
		 * similar to the implementation of get16().
		 *
		 * @param addr This is a type of unsigned integer 
		 * of 32 bits of the address in the vector.
		 *
		 * @return This return the address of both addresses
		 * with one shifting 16 bits to the right by little 
		 * endian.
		 *
		 * ************************************************/
		uint32_t get32 ( uint32_t addr ) const ;

		/* 
		 * This GETS the integer at the address (addr) in the 
		 * vector (mem).
		 * 
		 * This function will call get8() and then return 
		 * the sign-extended value of the byte as a 32-bit 
		 * signed integer.
		 *
		 * @param addr This is a type of unsigned integer 
		 * of 32 bits of the address in the vector.
		 *
		 * @return This returns the type of integer of 8 bits 
		 * calling the get8() function with the address (addr).
		 *
		 * ************************************************/
		int32_t get8_sx ( uint32_t addr ) const ;

		/*
		 * This GETS the integer at the address (addr) in the 
		 * vector (mem).
		 * 
		 * This function will call get16() and then return 
		 * the sign-extended value of the 16-bit value as a 
		 * 32-bit signed integer.
		 *
		 * @param addr This is a type of unsigned integer 
		 * of 32 bits of the address in the vector.
		 *
		 * @return This returns the type of integer of 16 bits 
		 * calling the get8() function with the address (addr).
		 *
		 * ************************************************/
		int32_t get16_sx ( uint32_t addr ) const ;
		
		/*
		 * This GETS the integer at the address (addr) in the 
		 * vector (mem).
		 *
		 * This function will call get32() and then return 
		 * the value as a 32-bit signed integer.
		 *
		 * @param addr This is a type of unsigned integer 
		 * of 32 bits of the address in the vector.
		 *
		 * @return This returns the type of integer of 32 bits 
		 * calling the get8() function with the address (addr).
		 *
		 * ************************************************/	
		int32_t get32_sx ( uint32_t addr ) const ;

		/*
		 * This SETS the value (val) with what is passed in 
		 * address (addr) into the vector (mem).
		 *
		 * This function will call check_illegal() to verify 
		 * the the addr argument is valid. If addr is valid
		 * then set the byte in the simulated memory at that 
		 * address to the given val. If addr is not valid
		 * then discard the data and return to the caller.
		 * Note that this, and the constructor, are the only 
		 * code that will ever write values into the mem vector.
		 *
		 * @param addr This is a type of unsigned integer 
		 * of 32 bits of the address in the vector.
		 *
		 * @param val This is the value being passed to the
		 * next functions. This is also a type of unsigned
		 * integer of 8 bits storing a value.
		 *
		 * ************************************************/
		void set8 ( uint32_t addr , uint8_t val );
		
		/*
		 * This SETS the value (val) with what is passed in 
		 * address (addr) into the vector (mem).
		 *
		 * This function will call set8() twice to store the 
		 * given val in little-endian order into the simulated 
		 * memory starting at the address given in the addr 
		 * argument.
		 *
		 * @param addr This is a type of unsigned integer 
		 * of 32 bits of the address in the vector.
		 *
		 * @param val This is the value being passed to the
		 * next functions, stores legal address. This is 
		 * also a type of unsigned integer of 16 bits storing 
		 * a value. 
		 *
		 * ************************************************/	
		void set16 ( uint32_t addr , uint16_t val );

		/*
		 * This SETS the value (val) with what is passed in 
		 * address (addr) into the vector (mem).
		 * 
		 * This function will call set16() twice to store the 
		 * given val in little-endian order into the simulated 
		 * memory starting at the address given in the addr 
		 * argument.
		 *
		 * @param addr This is a type of unsigned integer 
		 * of 32 bits of the address in the vector.
		 *
		 * @param val This is the value being passed to the
		 * next functions. This is also a type of unsigned
		 * integer of 32 bits storing a value.
		 *
		 * ************************************************/
		void set32 ( uint32_t addr , uint32_t val );

		
		/* 
		 * The function dumps the entire vector in hex format. 
		 *
		 * Dump the entire contents of your simulated memory 
		 * in hex with the corresponding ASCII2 characters on 
		 * the right exactly, space-for-space in the format 
		 * shown in the output section below.                 
		 * This code fragment will leave the character to be 
		 * printed in the ASCII portion of the dump in the ch 
		 * variable.   
		 *
		 * ************************************************/
		void dump () const ;

		/*
		 * The load file inputs the file and sets the values 
		 * based on the set8() function.
		 *
		 * Open the file named fname in binary mode and read 
		 * its contents into your simulated memory. If the file 
		 * can not be opened, then print a suitable message to 
		 * stderr including the name of the file and return false
		 * You must make certain that the file can fit into your 
		 * memory! One simple way to do that is to read the file 
		 * one byte at-a-time and check the byte address before 
		 * you write to it by calling check_illegal(). If the 
		 * address is valid, keep going. If the address is not 
		 * valid, then print the following message to stderr, 
		 * close the file, and return false: Program too big.
		 * If the file loads OK then close the file and return 
		 * true.
		 *
		 * @param fname A string constant being read.
		 *
		 * @return Function returns false if the file can not 
		 * be opened, returns true if the file is opened. 
		 *
		 * @note The function iterates over each value in the 
		 * fname until it is no longer able to iterate anymore,
		 * in which case it prints out a string "Program too big."
		 * Then returns false.
		 *
		 * ************************************************/
		bool load_file ( const std :: string & fname );

	private :
		/*
		 * A vector of 8 unsigned integer bits called mem.
		 *
		 * A vector of bytes representing the simulated memory. 
		 * Initialize it with the given size in your constructor.
		 *
		 * @param uint8_t Is a type of unsigned integer of 8 bits.
		 *
		 * ************************************************/
		vector < uint8_t > mem ;
};

#endif
