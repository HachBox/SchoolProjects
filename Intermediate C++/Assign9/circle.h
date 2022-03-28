#ifndef _CIRCLE_H
#define _CIRCLE_H

#include <iostream>
#include "shape.h" 

class Circle:Shape
{
	private: 
		int radius;

	public:
		int getRadius() const;
		Circle(int, std::string);
		double getArea() override;
		void print() const override;

}

#endif
