#include "circle.h"
#include <iostream>

int Circle::getRadius() const{
	 return radius;
}

Cirlce::Circle(int circleRadius, std::string circleName){
	Shape::Shape(circleName);
	radius = circleRadius;
}

double Cicle::getArea() override const
{
return 3.14159*radius*radius;
}

void Circle::print() const override
{
	cout << radius endl;
	Shape::print();	
}
