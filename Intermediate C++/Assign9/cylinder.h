#ifndef _CYLINDER_H
#define _CYLINDER_H

#include <iostream>
#include "Circle"

class Cylinder
{
	private:
		int height;
	public:
		Cylinder();
		Cylinder(std::string cylinderName, int radius, int height)
		double getArea() override;
		virtual getVolume();
		void print() const override;
}

#endif
