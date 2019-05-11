//Implementation File for the class CircleType
// CircleType.cpp
// This is only a start.  More functions need to be implemented
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

#include "CircleType.h"

using namespace std;

CircleType::CircleType(double r)            // constructor (w/default parameter)
{
    radius = r;                             // assign the private radius
    name = "2D Circle";                     // assign the name of the circle
}

CircleType::~CircleType()
{
    //cout << "circle destructor called" << endl;
}

void CircleType::setRadius(double r)        // "setter" mutator for the radius
{
    if (r >= 0)                             // must be positive
        radius = r;
    else
        radius = 1;                         // otherwise the radius is 1
}

double CircleType::getRadius() const
{
    return radius;
}

void CircleType::print(ostream& outF) const // print function for the object one line
{
	cout << setw(11) << name
         << setw(12) << radius              // write the entire detail line to console
		 << setw(12) << circumference()
		 << setw(12) << area()
		 << endl;
	outF << setw(11) << name
         << setw(12) << radius              // write the entire detail line to text file
		 << setw(12) << circumference()
		 << setw(12) << area()
		 << endl;
}

double CircleType::circumference() const    //gets the circumference for client
{
  return 2.0 * M_PI * radius;              // returns object's circumference

}

double CircleType::area() const
{
   return  M_PI * radius * radius;

}





