#include "cone.h"
#include <iomanip>

Cone::Cone(std::string coneName, int radius, int height)
{

}

double Cone::getArea(int radius, int height)
{
return (1/2)*3.14159*radius*radius*height;
}

double Cone::getVolume(int radius, int height)
{
return 
}

void Cone::print() override const
{
cout << std::string coneName endl;
cout << radius << endl;
cout << area << endl;
cout << height << endl;
cout << getVolume << endl;
Circle::print();
}

