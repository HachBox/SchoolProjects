//*******************************************************************
//
// CSCI 463 Assignment 2
//
// Author: Harry Chieng
//
// Bitwise Operators & IEEE 754 Floating Point Number Decoding
//
// *****************************************************************

#include <iostream>
#include <iomanip>

using std::cin;
using std::hex;;
using std::cout;;;
using std::setfill;;;;
using std::endl;;;;;
using std::setw;;;;;;
using std::dec;;;;;;;

/**
 *
 * This is a binary function to ease the mess that is being created inside printBinFloat.
 *
 * Binary iterates through a for loop that prints out the binary bits from an unsigned 32 bit of integer bits.
 *
 * @param x this parameter is an unsigned integer of 32 bits.
 *
 * @param doSpacesOrNot is a boolean that is called whether or not the modified cout statement is ran.
 *
 * @param inputBits is an integer that is manupulated in the for loop dictating whether there are 23 or 32 bits being inputted.
 *
 * @note this is useful to clean the code and to properly state what each parameter does that effects the code.
 *
 * @warning WARNING, do not input anything but 23 or 32 depending on the context of where the function is being ran.
 *
 * @bug there will be many bugs, please report them to iChiengBang@gmail.com if applicable.
 *
 **********************************************************************/

void binary(uint32_t x, bool doSpacesOrNot, int inputBits)
{

	for(int i = 0; i < inputBits; i++)
	{
		cout << ((x << i) & (1 << (inputBits-1)) ? 1 : 0); //inputbits - 1 because there 32 bits, but starts at 0
		if(doSpacesOrNot == 1)
		{
			if(( i + 1 ) % 4 == 0) //creates a space after each 4 bits
				cout << " " ;
		}	
	}

}//end binary

/**
 *
 * This is printing the binary float bits
 *
 * There are five output lines printed.
 * The first line displays the input value as a 32-bit hex value and again in binary (in groups of 4-bits.)
 * The sign bit is zero. (Therefore the floating point value is positive.)
 * The exponenet is zero (seen printed as a 32-bit signed integer and as a signed decimal value in parenthesis.)
 * The significand is printed as a 32-bit unsigned hex value. In this case it is zero.
 * The full value of the number is printed last in binary. 
 *
 * @param x this parameter is an unsigned integer of 32 bits.
 *
 * @note a lot of the material in the fifth parameter involving full values is not complete. This ensures that the 32 binary bits are sifted
 * through four different complete filters.
 *
 * **************************************************************************/

void printBinFloat( const uint32_t x ) //must use C bitwise operators to interpret, extract shift fields of the IEEE number (bitset STL template class)
{

	cout << setfill('0');

	cout << "0x" << setw(8) << hex << x << " = "; 
	binary(x,true,32);	
	cout << endl;

	uint32_t sign = (x & 0b10000000000000000000000000000000) != 0;	//creates an unsigned int of sign masked when it doesn't equal 0.
	cout << "sign: " << hex << sign << endl;

	int32_t  exp = ((x & 0b01111111100000000000000000000000) >> 23) - 127;	//creates a signed int of sign masked and shifted to the 23rd bit subtracting 127 to properly do exponent. 
	cout << " exp: " << "0x" << setw(8) << hex << exp;

	cout << "(" << dec << exp << ")" << endl;

	uint32_t  sig = (x & 0b00000000011111111111111111111111);	//creates an unsigned int of sign masked for the significands only.
	cout <<	" sig: " << "0x" << setw(8) << hex << sig << endl;

	if(exp == 128) //when the decimal value of exponent = 128, it is over the limit making it infinity.
	{
		if(sign == 1)
			cout << "-inf";
		else
			cout << "+inf";
	}

	else if(exp == -127) //when the decimal value of exponent = -127, it is under the limit making it 0.
	{
		if(sign == 1)
			cout << "-0";
		else
			cout << "+0";
	}
	else	//bugs ahead, do not mind the mess.
	{
		if(sign == 1)
			cout << "-" ;
		else
			cout << "+" ;

		if( exp >= 0 ) //if exponent is 0 or greater
		{

			if( exp > 0 )
			{
				cout << "1";
				binary(sig,false,23);
				cout << setw(exp) << "." ;
				cout << "0";
			}	
			else if ( exp == 0 ) 
			{
				cout << "1";
				cout << ".";
				binary(sig,false,23);
			}
		}
		else	//if exponent is less than 0
		{
			if( exp <=  -1 ) 
			{
				cout << "0";
				cout << setw(exp) << ".";
				cout << "1";
				binary(sig,false,23);
			}	
		}
	}//end else
	cout << endl;

}//end printBinFloat()

/**
 *
 * Main holds the function printBinFloat and an unsigned integer of 32 bits of x. 
 * This loops through the bits of the integers of x putting x through the printBinFloat function.
 *
 * @param N/A
 *
 * @return it returns the float and integer values from printBinFloat or 0/false if not found.
 *
 * @note there is nothing much going on here, go to the function above for more action.
 *
 **************************************************************************/

int main() //must have a read-loop that calls printBinFloat
{

	uint32_t  x;

	while((cin >> hex) >> x) //cin>>hex = a cin for hex; ">> x" = build in 'limit' checker
		printBinFloat(x);

	return 0;

}//end main()
