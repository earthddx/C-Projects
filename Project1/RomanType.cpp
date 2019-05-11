// RomanType.cpp (Implementation file)
// A simple class of roman numerals, and conversions to decimals
// Written by Artem Murzo
// Date: 09/15/2018

#include "RomanType.h"

RomanType::RomanType(string st)         // constructor with one string parameter
{
    // assign roman numeral st to myRoman
    st = myRoman;

}

RomanType::~RomanType()			        // destructor
{
	cout << "I'm destroyed." << endl;   // displays to show instance is destroyed when called
}

string RomanType::getRoman() const
{

     return myRoman;                       // gets private member roman numeral
}

void RomanType::setRoman(string st)     // mutator reassigns a roman numeral to st input param
{
	// sets the private member
	// assigns decimal once called
   myRoman = st;
   myDecimal = makeDecimal();
}

int RomanType::getDecimal() const       // accessor "getter" to get the private decimal member
{

	return myDecimal;                          // returns the decimal to the client
}

// displays the roman numeral and the decimal equivalent to the console and output file
void RomanType::printRomanDecimal(ofstream & out) const
{
    cout << setw(5) << getRoman();				//  output roman numeral
	cout << setw(8) << getDecimal() << endl;	//  output decimal equivalent
    out << setw(5) << getRoman();				//  output roman numeral
	out << setw(8) << getDecimal() << endl;	    //  output decimal equivalent
}

// makes a decimal out of the roman numerals
int RomanType::makeDecimal() const
{
    int result = 0;                     // zero out the variables

    for (int i = 0; i < myRoman.size(); i++ )  // convert the roman numeral to decimal equivalent
	{

		switch (myRoman[i])
		{
		    ///1000
            case 'M': result += 1000;   break;

            ///500
            case 'D':
			    if((i + 1) != myRoman.size() &&myRoman[i+1] == 'M')//checking if the next element of the roman number is the last one and not equal to M
                                        result -= 500;             //if so, add 500 to the result //otherwise -500
                                else
                                        result += 500;
                                        break;

            ///100
			case 'C':
			   if((i + 1) != myRoman.size() && myRoman[i+1] == 'M' || myRoman[i+1] == 'D') //same concept here as mentioned above
                                        result -= 100;
                               else
                                        result += 100;
                                        break;
            ///50
			case 'L':
			    if((i + 1) != myRoman.size() && myRoman[i+1] == 'M' || myRoman[i+1] == 'C')
                                        result -= 50;
                               else
                                        result += 50;
                                        break;
            ///10
			case 'X':
			    if((i + 1) != myRoman.size() && myRoman[i+1] == 'M' || myRoman[i+1] == 'L'||myRoman[i+1] == 'C')
                                        result -= 10;
                               else
                                        result += 10;
                                        break;

            ///5
			case 'V': result += 5;      break;

			///1
			case 'I':
				if (myRoman[i + 1] != 'I' && (i + 1) != myRoman.size())
                                        result-=1;
                                else
                                        result+=1;
                                        break;
           //if the input is wrong display -1
            default: return -1;
		}

	}
	return result; // returns converted roman numeral to decimal

}
