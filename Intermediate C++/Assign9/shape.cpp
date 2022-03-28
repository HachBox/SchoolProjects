#include "shape.h"
#include <iostream>

Shape::Shape(const std::string& shapeName){
	name = shapeName; 
}

void Shape::print() const
{
	std::cout << name;
}
