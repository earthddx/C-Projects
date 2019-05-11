// CircleType.h  Class specifications header file for the base class CircleType
#ifndef H_CircleType
#define H_CircleType

class CircleType
{
    public:
        CircleType(double r = 1.0);
          //Constructor with one default parameter.
          //Radius is set according to the parameter.
          //Postcondition: radius = r or 1.0 if not specified

        ~CircleType();
          //Destructor destroys circle objects [and returns memory to the heap]

        double getRadius() const;
          //Function to return the radius.
          //Postcondition: The value of radius is returned.

        double area() const;
          //Function to return the area of a circle.
          //Postcondition: Area is calculated and returned.

        double circumference() const;
          //Function to return the circumference of a circle.
          //Postcondition: Circumference is calculated and returned.

        void print(ostream& ) const;
          // function to print the radius, area, and circumference
          // of the object (in one complete line)

        string getName() const;
          // function to return the name of the object

        void setRadius(double);
          //Function to set the radius.
          //Postcondition: if (r >= 0) radius = r;
          //               otherwise radius = 1;

    private:
        double radius;
        string name;
};
#endif
