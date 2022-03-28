#include <iostream>
#include <iomanip>

int main()
{
	int a[100];

	//fill the array with recognizable values
	for (int i=0; i<sizeof(a)/sizeof(a[0]); ++i)
		a[i] = i*10;
	for (int i=0; i<sizeof(a)/sizeof(a[0]); ++i)
		std::cout << a[i] << " ";
	return 0;
}
