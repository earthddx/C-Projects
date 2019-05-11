/* testCCS.cpp  (circle, cylinder, sphere) (Lab2 Starter Files)
   Written by Artem Murzo
   Date:  10/09/2018
   The user program that uses a base class CircleType
   and derives the class CylinderType and SphereType
   implementation files to demonstrate more specific classes.
   This also demonstrates overriding the base class methods for area() & print().
*/

#define M_PI 3.14

#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdlib.h>

#include <cmath>


using namespace std;                    // namespace for standard template library

ifstream fin("ccsInput.txt");           // open the input file;
ofstream fout("ccsOutput.txt");         // open the output file;

#include "CircleType.cpp"               // include implementation files for circle
#include "CylinderType.cpp"             // include implementation files for cylinder
#include "SphereType.cpp"               // include implementation files for sphere

void headings();
void defaultObjects();
void fileProcess();

int main()
{
	headings();                         // display the title, name, and headings
    defaultObjects();                   // processes the default objects
	fileProcess();                      // read and process all input file data
    fin.close();                        //closing input file
	fout.close();                       //closing the ouptut file
	system("pause");                    // pauses execution when .exe file is run
	return 0;                           // returns 0 to op. system; all is well
}

// prints the headings of the output report to both the console and the printer
// prints the headings of the output report to both the console and the printer
void headings()
{
    cout << fixed << showpoint << setprecision(3);  // display only 3 digit precision fixed
    fout << fixed << showpoint << setprecision(3);  // display only 3 digit precision fixed
	cout << "C I R C L E,   C Y L I N D E R,   S P H E R E   C A L C U L A T I O N S" << "\n\n";
	cout << setw(45) << "by Artem Murzo"<< "\n\n\n";
	cout << setw(11) << "Object Name"               // display column headings
         << setw(12) << "Radius"
         << setw(12) << "Circumf"
	     << setw(12) << "Area"
		 << setw(12) << "Height"
		 << setw(12) << "Volume" << endl;
	cout << setw(11) << "-----------"
	     << setw(12) << "------"
	     << setw(12) << "-------"
	     << setw(12) << "----"
		 << setw(12) << "------"
		 << setw(12) << "------" << endl;

	fout << "C I R C L E,   C Y L I N D E R,   S P H E R E   C A L C U L A T I O N S" << "\n\n";
	fout << setw(45) << "by Artem Murzo"<< "\n\n\n";
	fout << setw(11) << "Object Name"
         << setw(12) << "Radius"
         << setw(12) << "Circumf"
	     << setw(12) << "Area"
		 << setw(12) << "Height"
		 << setw(12) << "Volume" << endl;
	fout << setw(11) << "-----------"
	     << setw(12) << "------"
	     << setw(12) << "-------"
	     << setw(12) << "----"
		 << setw(12) << "------"
		 << setw(12) << "------" << endl;
}


// process the default objects specified
void defaultObjects()
{
	CircleType cirDef;              // circle default constructor test
   	cirDef.print(fout);   // rather than this I suggest calling client's showCircleOut() function

   	// cylinder's default constructor test (also print called by constructor)
   	CylinderType cyl;
   	// sphere's default constructor test (also print called by constructor)
    SphereType sph;
    cirDef.setRadius(M_PI);         // set the default circle's radius to constant PI
    cirDef.print(fout);             // print circle c data to console & file

    //required test functions for cylinder & sphere
    cyl.setRadius(M_PI); //set radius of cylinder to PI
    cyl.print(fout);       //print cylinder's data
    sph.setRadius(M_PI);
    sph.print(fout);

    cyl.setHeight(0.142857); //modify cyl height
    cyl.print(fout);            //print it out

    sph.setHeight(0.142857); //modify sph height
    sph.print(fout);            //print it out

}

// processes the data from the file, and closes both files
void fileProcess()
{
   	double rad;                     // declare a double for reading radius
	double heit;                    // declare a double for reading height
    fin >> rad >> heit;             // priming read
        while ( !fin.eof() )// looping while not end of file
    {
        //    processing using the 2 parameter and 1 parameter constructors
        CylinderType ct(rad, heit);
        SphereType st(rad);
        fin >> rad >> heit;
    }// end of the loop
    // close both files (don't forget)
    cout << endl;
    fout << endl;

}
