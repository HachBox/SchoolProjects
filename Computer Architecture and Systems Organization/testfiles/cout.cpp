//*******************************************************************
//
// CSCI 463 test - cout
//
// Author: Harry Chieng
//
// *****************************************************************

#include <iostream>
#include <iomanip>

int main() 
{
	int a[100];

	//fill the array with recognizable values
	for (int i=0; i<sizeof(a)/sizeof(a[0]); ++i)
		a[i] = i*10;
	
	for (int i=0; i<sizeof(a)/sizeof(a[0]); ++i)
	{
		if (i && i%10 == 0)
			std::cout << " XXX" << std::endl;
		if (i%10 == 0)
			std::cout << "IX " << std::setfill(' ') << std::setw(4) << i << ": ";
		else if (i%5 == 0)
			std::cout << ' ';

		//std::cout << a[i] << " ";
		std::cout << " " << std::setfill('0') << std::setw(4) << a[i];
	}

	if (sizeof(a)/sizeof(a[0]) > 0)
		std::cout << " YYY" << std::endl;

	return 0;
}
