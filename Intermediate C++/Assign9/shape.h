#ifndef _SHAPE_H
#define _SHAPE_H

#include <iostream>
#include <string>

class Shape
{
private:
        std::string name;

public:
        Shape(const std::string& shapeName);
        virtual ~Shape();
        virtual void print() const;
        virtual double getArea() = 0;
}

#endif
