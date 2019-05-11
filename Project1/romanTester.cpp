/**
   romanStarter.cpp (change to romanTester.cpp)
   Written by Artem Murzo
   Date:  09/15/2018
   Tests the romanType class and its member functions.
   Converts the roman numerals to decimal numbers and detects errors.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

#include "RomanType.cpp"   // include the class implementation file

ofstream fout("romanOutput.txt");

void title();
void process(string[]);
const int SIZE = 12;         /// note:  your code should have SIZE = 12

int main()
{
	string roman[] = {"M", "MMIC", "MCIX","MCXLIV", "MMXVIII", "MDCLXVI",
                    "CDXCIX","CCCLIX", "DCCIV", "MIXIT", "NOWAY", "MOM", };  // data for process
	title();			// print the title and headings of the output file
	process(roman);     // process each element as an object
	fout.close();		// flush buffer and close the output file
	system("pause");    // pause the screen if running an .exe file
	return 0;           // return all is ok to the OS
}

// title function with description and col. hdgs
void title()
{
	cout << "     R O M A N   N U M E R A L   C O N V E R T E R\n\n";
	cout << "                   by Artem Murzo                  \n\n";

	fout << "     R O M A N   N U M E R A L   C O N V E R T E R\n\n";
	fout << "                   by Artem Murzo                  \n\n";
}

// process function creates each instance and processes roman to decimal conversions
void process(string roman[])
{
    RomanType rt;

    for(int i = 0; i < 12; i++)//loop for making decimals and printing both numerals out
        {
            rt.setRoman(roman[i]); // calling function mutator (roman numerals to decimals)
            rt.printRomanDecimal(fout);// object constructed (default) M and 1000 decimal
        }
}
