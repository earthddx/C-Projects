// mainLab4.cpp
// This program tests various operations of a linked stack
// Written by Artem Murzo

#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>

#include "LinkedStack.cpp"            // more implementation is necessary

using namespace std;

void title();
void converterTitle();
void converter();
void readData(LinkedStackType<int> & );
void printBaseStack(LinkedStackType<string> &, int);// writes one converted base to the report.
void printOrigOrder(LinkedStackType<int> );
void printReversedOrder(LinkedStackType<int> );
void printSortedStack(LinkedStackType<int> );

ifstream fin ("Input.txt");        /// input file without any errors
ofstream fout("Output.txt"); //output file with all results
ifstream fin2("InputS.txt"); //input file for the converter

int main()
{
	LinkedStackType<int> iStack;    // stack object accepting int inputs
	title();						// prints the title
	readData(iStack);               // read the data into the stack (pass by ref)
    printOrigOrder(iStack);         // demonstrates printing data in orig order as read
    iStack.sortLinkedStack();       // call the class sort function
    printSortedStack(iStack);       // print the sorted stack & write to InputS.txt
    converter();                    // convert each int to its respective base
	fin.close();                    // close the input file (notice it was not used)
	fout.close();					// close the output file
	fin2.close();                   //close the input file with sorted list
    return 0;						// return 0 to indicate OS is ok

}

void title()
{
	cout << setw(63) << "T H E    O R I G I N A L    U N S O R T E D    L I S T" << endl;
	cout << setw(63) << "======================================================" << endl << endl;
	cout << setw(33) << "Written by" << " Artem Murzo" << endl  << endl  << endl;

	fout << setw(63) << "T H E    O R I G I N A L    U N S O R T E D    L I S T" << endl;
	fout << setw(63) << "======================================================" << endl << endl;
	fout << setw(33) << "Written by" << " Artem Murzo" << endl  << endl  << endl;
}

void converterTitle()
{
    cout << endl << endl;
    fout << endl << endl;
    cout << setw(57) << "T H E    B A S E    C O N V E R T E R" << endl;
    cout << setw(57) << "=====================================" << endl;
    cout << setw(49) << "Written by Artem Murzo" << endl << endl;
    fout << setw(57) << "T H E    B A S E    C O N V E R T E R" << endl;
    fout << setw(57) << "=====================================" << endl;
    fout << setw(49) << "Written by Artem Murzo" << endl << endl;


    cout <<"   DECIMAL       HEX                    OCTAL                                  BINARY" << endl;
    cout <<"   -------       ---                    -----                                  ------" << endl;
    fout <<"   DECIMAL       HEX                    OCTAL                                  BINARY" << endl;
    fout <<"   -------       ---                    -----                                  ------" << endl;
}

void readData(LinkedStackType<int> & s)
{
    int number;                  // declare local int for reading
    string str = " -----------------------input error ignored  -------------------";

    fin >> number;                // priming read for the 1st decimal number
    while(!fin.eof())                               //read until the end of file
    {
        try                                         //TRY block
        {
            if (!fin)
                throw str;                          //throw exception (a string object)
                s.push(number);                     //push the int number to stack

        }
        catch (string messageStr)                   //CATCH block (exception is caught and processed)
        {
            cout << messageStr << endl;
            fin.clear();                            //restoring the ifstream to to its good state
            fin.ignore(100, '\n');                  //clears the rest of the input from the file
        }
        fin >> number;              // read the next int
    }
}

// a function to convert a decimal number to base n
// cleverly converts an input index to a one letter string corresponding to base digits
void converter()
{
    converterTitle(); //call title function of the converter
    LinkedStackType<string> lStack;  //local stack accepting strings(remainders)
    string getString[] = {"0", "1", "2", "3", "4", "5", "6", "7",
                          "8", "9", "A", "B", "C", "D", "E", "F" }; //local array with hex and oct numbers
    int deciSave,
        deciOrig,
        quotient,
        divisor,
        remainder;
    string stRemainder = "";//string with results of the conversion
    int base[] = {16, 8, 2}; //array of base n

    fin2 >> deciOrig; //priming read
    while(!fin2.eof()) //while not end of inputS.txt
    {
        deciSave = deciOrig;    //save original deci number
        cout << setw(10)<< deciOrig<< setw(10);
        fout << setw(10)<< deciOrig<< setw(10);
            for (int i = 0; i < sizeof(base)/sizeof(base[0]); i++) //loop through each of the 3 base array numbers:16, 8,2
            {
                divisor = base[i];      //assign divisor to either 16,8 or 2
                do
                {
                   quotient = deciSave/divisor;
                   remainder = deciSave%divisor;   //get the remainder of the division
                   stringstream intToString;       //convert integer remainder to string
                   intToString << remainder;
                   stRemainder = intToString.str();//assign numbers over 9 to A, B, C etc.
                   if (remainder > 9)
                   {
                       switch(remainder)
                       {
                           case 10: stRemainder = getString[10]; break; //A
                           case 11: stRemainder = getString[11]; break; //B
                           case 12: stRemainder = getString[12]; break; //C
                           case 13: stRemainder = getString[13]; break; //D
                           case 14: stRemainder = getString[14]; break; //E
                           case 15: stRemainder = getString[15]; break; //F
                       }
                   }

                   lStack.push(stRemainder);  //push the string remainder onto local stack
                   deciSave = quotient;
                }
                while (quotient != 0);       //do this process until quotent is equal to 0

                deciSave = deciOrig;
                printBaseStack(lStack, i);    //output of the elements of the stack lStack
                stRemainder = "";             //reassign string remainder to an empty string
            }
            cout << endl;
            fout << endl;
            fin2 >> deciOrig;    //read the next int from file

    }
    cout << endl << endl;



}

// displays the data in last in, first out (LIFO).  (backwards stack)
void printReversedOrder(LinkedStackType<int> stk)
{
	while(!stk.isEmptyStack())
	{
		cout << setw(40) << stk.top() << endl;      // look, but don't remove
		fout << setw(40) << stk.top() << endl;      // look, but don't remove
		stk.pop();                                  // remove the top integer
	}
	cout << endl;
    cout << setw(67) << "Oops! This output should be in the same order as the data!\n";
    cout << setw(67) << "Perhaps, you can fix it so it shows same order as read in?\n";
    cout << setw(68) << "(note:  The 7 should be the first number printed.........)\n\n";
	fout << endl;
    fout << setw(67) << "Oops! This output should be in the same order as the data!\n";
    fout << setw(67) << "Perhaps, you can fix it so it shows same order as read in?\n";
    fout << setw(68) << "(note:  The 7 should be the first number printed.........)\n\n";
    fout << endl;
}

//displays the data in the original order
void printOrigOrder(LinkedStackType<int> stk)
{


    LinkedStackType<int> cStack;  //create a local stack
    while (!stk.isEmptyStack())   // loop until stk(input) is empty
    {
        cStack.push(stk.top());   //push top of stack onto local stack
        stk.pop();                //pop the stk stack
    }
    //now print the local stack and it will be original order
    printReversedOrder(cStack);//standard LIFO print
}

//displays the sorted data
void printSortedStack(LinkedStackType<int> stk)
{

    cout << setw(53) << "T H E    S O R T E D    L I S T" << endl;
    cout << setw(53) << "===============================" << endl << endl;

    fout << setw(53) << "T H E    S O R T E D    L I S T" << endl;
    fout << setw(53) << "===============================" << endl << endl;

    while(!stk.isEmptyStack())
	{
		cout << setw(40) << stk.top() << endl;      // look, but don't remove
		fout << setw(40) << stk.top() << endl;      // look, but don't remove
		stk.pop();                                  // remove the top integer
	}
}

// writes one converted base to the report.
void printBaseStack(LinkedStackType<string> &stk, int base)
{
    string save="";   //local string ("pop each of the remainders into a concatenated string")
    while (!stk.isEmptyStack())
    {
        save+=stk.top(); //concatenate string
        stk.pop();     //pop the stk stack
    }
    switch(base)
    {
        case 0: //Hex representation of a decimal number
        {
            cout << setw(10) << save;
            fout << setw(10) << save;
            break;
        }

        case 1: //Octal
        {
            cout << setw(25) << save;
            fout << setw(25) << save;
            break;
        }

        case 2: //Binary
        {
            cout << setw(40) << save;
            fout << setw(40) << save;
            break;
        }
    }
}







