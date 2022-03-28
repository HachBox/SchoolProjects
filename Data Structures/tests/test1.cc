#include <iostream>

void countDown(int count)
{
std::cout << "push " << count << '\n';
if(int x > 0) 		//added to stop
countDown(count - 1); 
}

int main()
{
countDown(5);
return 0;
}
