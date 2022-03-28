#ifndef __COMPLEX_H	//header guards (starts with thrope)
#define __COMPLEX_H

#include <iostream>
class Complex{
private:
	double realPart;
	double imaginaryPart;

public:
	Complex();
	Complex(double,double);
	void setComplex(double, double);
	void getComplex(double&,double&)const;	//all the getters do not modify the object
	void setRealPart(double);
	double getRealPart()const;	//function body is constant
	void setImaginaryPart(double);
	double getImaginaryPart()const;
	Complex operator+(const Complex&)const;
	Complex operator*(const Complex&)const;
	bool operator==(const Complex&)const;
	friend std::ostream &operator<<(std::ostream&, const Complex&);
	friend std::istream &operator>>(std::istream&, Complex&);		//left operand (istream) is a reference to input stream
	//right operand (Complex) is a reference to COmplex class 
	};
#endif
