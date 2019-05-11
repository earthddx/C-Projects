// SphereType.h  Class specifications header file for the derived class SphereType
#ifndef H_SphereType
#define H_SphereType

class SphereType : public CircleType
{
    public:
        SphereType(double rad = 1.0);
          //Constructor with one default parameter.  Client assigned.
          //Postcondition: if parameters are given:  radius = r
          //       without parameters:   radius = 1.0
          //       name is assigned "Sphere"

        ~SphereType();
          //Destructor destroys sphere objects [and returns memory to the heap]

        double area() const;
          //Function to return the surface area of a sphere
          //Overrides the circle's area function.
          //Postcondition: Surface area is calculated and returned.

        double volume() const;
          //Function to return the volume of a sphere
          //Postcondition: Volume is calculated and returned.

        void print(ostream& ) const;
          // function to override circle's print
          // displays the radius, height, surface area, and volume

        double getHeight() const;
          // Function to return the height of a sphere (really the same as diameter)
          // Postcondition:  height (diameter) is calculated and returned

        string getName() const;
          // gets the name of the object

        void setHeight(double);
          // sets the height (diameter) of a sphere
          // by setting the circle’s radius to half the sphere’s height

    private:
        string name;
};
#endif
