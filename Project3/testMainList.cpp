// This program tests various operation of a linked list
// Originally written by author: Malik, but did not work
// Severely modified by Jeff Goldstein, TCC Adjunct Professor, VB Campus
// "... a good start!"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;
//client functions add student , delete student, system data to be added also


ifstream fin ("listIn.txt");
ofstream fout("listOut.txt");

#include "List.cpp"

void process(List<stuRecord> );//process(list2)
void showList(List<stuRecord> &, string);
void deleteStudent(List<stuRecord> &, string);
void addStudent(List<stuRecord> &list, string , string , char , float );
void title();
int main()
{

    List<stuRecord> list1;
    List<stuRecord> list2;
    //int num;
    fin >> list1;           // read the entire list from text file
    fin.close();              //close input file
    list2 = list1;          // copy entire list1 into list2
    cout << endl;

    process(list2); //call process and pass list2 by value
    showList(list1, "      Original list2"); //show original list2(which was originally list1)  before the sorting and etc was done to it
    return 0;
}

void process(List<stuRecord> listObj)
{
    title();                               //calling title function that prints out the name of the lab and time
    showList(listObj, "      Unsorted"); //printing original unsorted list
    listObj.sortLinkedList("GPA");          //sort this list by gpa
    showList(listObj, "      GPA sorted");  //and print it
    deleteStudent(listObj, "Probie, Ima");  //delete nodes
    deleteStudent(listObj, "Lizt, President's");
    deleteStudent(listObj, "Close, Soo");
    deleteStudent(listObj, "Right, Ima");   //trying to delete a node that isnt in the list
    showList(listObj, "      GPA sorted");
    addStudent(listObj, "Dawg, Top", "23452", 'M', 3.92 );  //add node to the list
    listObj.sortLinkedList("Name"); // and sort it by name
    showList(listObj, "      Name sorted"); //then print it

}


void showList(List<stuRecord> &list, string msg)  //function to print out the list of students
{

    cout<< "  "<< msg <<endl;               //msg is either GPA or NAME
    cout<<"       --------------------------------------" << endl;
    cout<< list;
    cout << endl;
    cout<<"       --------------------------------------" << endl;
    cout << setw(16) << list.length()
         << " student records." << endl << endl << endl;


    //mirror printing to outer file listOut.txt
    fout<< "  "<< msg <<endl;
    fout<<"  -------------------------------------------" << endl;
    fout<< list;
    fout << endl;
    fout<<"  -------------------------------------------" << endl;
    fout << setw(16) << list.length()
         << " student records." << endl << endl << endl;


}


void deleteStudent(List<stuRecord> &list, string fName) //function to delete a student record
{
    stuRecord stuRec;            //create a local student record

    stuRec.name = fName;        //assign it to full name
   if (list.deleteNode(stuRec)) //if the node was in the list and got deleted
   {
       cout << "        "
            << fName << " was deleted from the list." << endl;
       fout << "        "
            << fName << " was deleted from the list." << endl;
   }

    else                        //otherwise, its not found
    {
        cout << "        "
            << fName <<  " was not found in the list." << endl;
        fout << "        "
            << fName <<  " was not found in the list." << endl;
    }
}

void addStudent(List<stuRecord> &list, string fName, string zip, char sex, float gpa ) //function to add a student record
{https://vk.com/vulgar_bunker?z=video-133878684_456240591%2F76180b4f2fb37a021d%2Fpl_wall_-133878684
   stuRecord stuRec;
   stuRec.name= fName;
   stuRec.fGpa= gpa;
   stuRec.gender = sex;
   stuRec.zipCode = zip;
   list.insertLast(stuRec); //add node to the list with the parameters above

     cout << "        "
            << fName << " was added to the list." << endl;
       fout << "        "
            << fName << " was added to the list." << endl;


}

void title()    //function to print out the heading with current time and date
{
    cout << "      L I N K E D   L I S T   G P A   R E P O R T" << endl;

    time_t now = time(0);
    // convert now to string form
    char* dt = ctime(&now);
    cout << "     Current date and time:" << dt;
    cout << "                           by                        " << endl;
    cout << "                      Artem Murzo                    " << endl << endl;
    cout << "        LastName, First   ZipCode  Sex  GPA" << endl;
    cout << "        ---------------   -------  ---  ---" << endl;

    fout << "     Current date and time:" << dt;
    fout << "                           by                        " << endl;
    fout << "                      Artem Murzo                    " << endl << endl;
    fout << "        LastName, First   ZipCode  Sex  GPA" << endl;
    fout << "        ---------------   -------  ---  ---" << endl;

}

