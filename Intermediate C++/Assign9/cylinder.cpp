#include "Cylinder.h"
#include <iomanip>

Cylinder::Cylinder(std::string cylinderName, int radius, int height)
{

}

double Cylinder::getArea() override
{
return 3.14159*Cylinder.radius*Cylinder.radius*Cylinder.height
}

double Cylinder::getVolume()
{

}

void Cylinder::print() const override
{
cout << cylinderName << endl;
cout << radius << endl;
cout << area << endl;
cout << height << endl;
cout << volume << endl;
Circle::print();
}

