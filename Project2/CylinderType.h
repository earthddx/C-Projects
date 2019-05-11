// CylinderType.h  Class specifications header file for the derived class CylinderType
#ifndef H_CylinderType
#define H_CylinderType

class CylinderType : public CircleType
{
    public:
        CylinderType(double rad = 1.0, double heit = 1.0);
          //Constructor with two default parameters.  Client assigned.
          //Postcondition: if parameters given:  radius = r;  height = h;
          //       without parameters:   radius = 1.0; and  height = 1.0;
          //       name is assigned "Cylinder"

        ~CylinderType();
          //Destructor destroys cylinder objects [and returns memory to the heap]

        double area() const;
          //Function to return the surface area of a cylinder.
          //Overrides the circle's area function.
          //Postcondition: Surface area is calculated and returned.

        double volume() const;
          //Function to return the volume of a cylinder.
          //Postcondition: Volume is calculated and returned.

        void print(ostream& ) const;
          // function to override circle's print
          // displays the radius, surface area, and volume

        double getHeight() const;
          // set the height of the cylinder

        string getName() const;
          // gets the name of the object

        void setHeight(double);
          // set the height of the cylinder

    private:
        double height;
        string name;
};
#endif
