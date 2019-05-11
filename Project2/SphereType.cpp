//SphereType.cpp

#include "SphereType.h"

SphereType::SphereType(double r)            // constructor (w/default parameter)
            : CircleType(r)
{
   /// height = h;  not needed                            // assign the private radius
    name = "Sphere";                     // assign the name of the circle

    print(fout);
}



SphereType::~SphereType()               //destructor for Cylinder
{
    // cout << "Sphere destroyed" << endl;
}

void SphereType::print(ostream& outF) const // print function for the object one line
{
    // write the entire detail line to console
	cout << setw(11) << name
         << setw(12) << getRadius()
		 << setw(12) << circumference()
		 << setw(12) << area()
		 << setw(12) << getHeight()//cuz we're in the class (not getHeight)
		 << setw(12) << volume()
		 << endl;
    // write the entire detail line to text file
	outF << setw(11) << name
         << setw(12) << getRadius()
		 << setw(12) << circumference()
		 << setw(12) << area()
         << setw(12) << getHeight()
		 << setw(12) << volume()
		 << endl;
}

double SphereType::area() const
{
    return 4.0 * CircleType::area(); //its good
}


double SphereType::getHeight() const
{
    return 2.0 * getRadius();
}

double SphereType::volume() const
{
    return 4.0/3.0 * CircleType::area() * getRadius(); //change it
}


void SphereType::setHeight(double h)
{
    /// = h;  //set the height to h

    setRadius( h / 2.0 );


}
