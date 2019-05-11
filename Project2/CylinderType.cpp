//CylinderType.cpp

#include "CylinderType.h"

CylinderType::CylinderType(double r, double h)            // constructor (w/default parameter)
            : CircleType(r)
{
   height = h;                             // assign the private radius
    name = "Cylinder";                     // assign the name of the circle

    print(fout);
}



CylinderType::~CylinderType()               //destructor for Cylinder
{
    // cout << "Cylinder destroyed" << endl;
}

void CylinderType::print(ostream& outF) const // print function for the object one line
{
    // write the entire detail line to console
	cout << setw(11) << name
         << setw(12) << getRadius()
		 << setw(12) << circumference()
		 << setw(12) << area()
		 << setw(12) << height//cuz we're in the class (not getHeight)
		 << setw(12) << volume()
		 << endl;
    // write the entire detail line to text file
	outF << setw(11) << name
         << setw(12) << getRadius()
		 << setw(12) << circumference()
		 << setw(12) << area()
         << setw(12) << height
		 << setw(12) << volume()
		 << endl;
}

double CylinderType::area() const
{
    return 2.0 * CircleType::area() + height * circumference();
}

double CylinderType::getHeight() const
{
    return height;
}

double CylinderType::volume() const
{
    return CircleType::area() * height;
}


void CylinderType::setHeight(double h)
{
    height = h;  //set the height to h
}
