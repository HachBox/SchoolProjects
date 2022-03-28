#include <iostream>
#include "Complex.h"

using namespace std;

Complex::Complex(){
}

Complex::Complex(double rPart, double iPart)
{
	realPart = rPart;
	imaginaryPart = iPart;
}

void Complex::setComplex(double rPart, double iPart)
{
	realPart = rPart;	//assigning stuff
	imaginaryPart = iPart;
}

void Complex::getComplex(double& rPart, double& iPart) const
{
	rPart = realPart;
	iPart = imaginaryPart;	//returning the value
}

void Complex::setRealPart(double rPart)
{
	realPart = rPart;
}

double Complex::getRealPart() const
{
	return realPart;	//the class's local variable = realPart not rPart
}

void Complex::setImaginaryPart(double iPart)
{
	imaginaryPart = iPart;
}

double Complex::getImaginaryPart() const
{
	return imaginaryPart;
}

Complex Complex::operator+(const Complex&rhs) const
{
	Complex addition;
	addition.setRealPart(this->getRealPart() + rhs.getRealPart());
	//used "this" instead of "lhs" because we are a function of a class
	addition.setImaginaryPart(this->getImaginaryPart() + rhs.getImaginaryPart());
	return addition;	//return what we're geting from doing addition
}

Complex Complex::operator*(const Complex&rhs) const
{
	Complex multi;
	multi.setImaginaryPart(this->getImaginaryPart() * rhs.getRealPart()
			+ this->getRealPart() * rhs.getImaginaryPart());
	//i(ad + bc)
	multi.setRealPart(this->getRealPart() * rhs.getRealPart() 
			- this->getImaginaryPart() * rhs.getImaginaryPart());

	return multi;
}

bool Complex::operator==(const Complex&rhs) const
{
return (this->getRealPart() == rhs.getRealPart()) 
	&& (this->getImaginaryPart() == rhs.getImaginaryPart());
}

ostream &operator<<(ostream&lhs, const Complex&rhs)
{	//lhs instead of this-> for friends
	lhs << '(';	//prints a complex object (re, im)
	lhs << rhs.getRealPart();
	lhs << ", ";	//there are two things ',' and ' ' to show in return.
	lhs << rhs.getImaginaryPart();
	lhs << ')';

	return lhs;
}

istream &operator>>(istream&lhs, Complex&rhs) 
{
	char ch;
	double re;
	double im;
	lhs >> ch;	//we assume first char in data is a '('
	lhs >> re;
	rhs.setRealPart(re);	//sets what user inputs for re
	lhs >> ch;
	lhs >> im;
	rhs.setImaginaryPart(im);
	lhs >> ch;

	return lhs;

}

