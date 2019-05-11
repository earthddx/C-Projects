/* RomanType.h
   Written by Jeff Goldstein, TCC Adjunct Professor, VB Campus
   Updated 07/22/2018
   Header file (Specifications for the RomanType class)
   Conditions:  a Roman Numeral is a string input (such as MCMXVII)
   The class will convert the roman numerals to a decimal number (such as 1917)
   This file must not be altered.  Each of these functions should be implemented
*/

#ifndef ROMAN_TYPE_H
#define ROMAN_TYPE_H

class RomanType
{
	public:
		RomanType(string s = "");		            // constr. w/ one default string parameter
		~RomanType();					            // destructor
        //RomanType(const RomanType & rhs);         // copy constructor (done in future Labs)

		int getDecimal() const;			            // returns the private field myDecimal;
		string getRoman() const;		            // gets the private field myRoman
		void setRoman(string);			            // sets the private field myRoman
		void printRomanDecimal(ofstream &) const;   // echo prints roman numeral & decimal
		int makeDecimal() const;		            // converts myRoman to myDecimal

	private:
		string myRoman;	 				            // private fields for the class
		int myDecimal;					            // private field converted as decimal
};

#endif // ROMAN_TYPE_H
