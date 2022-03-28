nclude <iostream>
#include <iomanip>
#include <cstring>
#include "Employee.h"

using namespace std;

// Default Employee constructor
Employee::Employee()
    {
    name[0] = '\0';
    salary = 0;
    }

// TODO: Alternate Employee constructor

// TODO: getName() accessor method

// TODO: setName() accessor method

// getSalary() accessor method
double Employee::getSalary() const
    {
    return salary;
    }

// setSalary() accessor method
void Employee::setSalary(double newSalary)
{
    salary = newSalary;
}

// TODO: print() method
