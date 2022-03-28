#ifndef _CONE_H
#define _CONE_H

#include <iostream>
#include <string>
#include "circle.h"

class Cone
{
	private:
		int height();
	public:
		cone(std::string coneName(int, int));
		double getArea(int, int) override;
		virtual double getVolume(int, int);
		void print()override const;
}

#endif

