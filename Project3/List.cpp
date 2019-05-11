// List.cpp (implementation file for the List)
// Originally written by Malik 7th ed.  Commented by Jeff G.
#include "List.h"

// default constructor
template <class Type>
List<Type>::List()
{
    first = nullptr;            // set pointers to null
    last = nullptr;             //  "      "     "   "
    count = 0;                  // zero the count
}

// destructor destroys all nodes that were allocated
template <class Type>
List<Type>::~List()
{
   destroyList();               // call the private destroyList function
   cout << "List is destroyed...." << endl << endl; // demonstration only
}//end destructor

// copy constructor creates a "deep copy" of the other list
template <class Type>
List<Type>::List
                   (const List<Type>& otherList)
{
   	first = nullptr;            // set first pointer to nullptr
    copyList(otherList);        // deep copy the other list
}//end copy constructor

//overload the assignment operator
template <class Type>
const List<Type>& List<Type>::operator=
                      (const List<Type>& otherList)
{
    if (this != &otherList)     //avoid self-copy
    {
        copyList(otherList);    // simply call the copyList function
    }
     return *this;              // now, left side has the assigned list
}


template <class Type>
bool List<Type>::isEmptyList() const
{
    return(first == nullptr);   //checks empty list from initial pointer
}

template <class Type>
void List<Type>::destroyList()
{
    nodeType<Type> *temp;       //pointer to deallocate the memory occupied by node
    while (first != nullptr)    //while there are nodes in the list
    {
        temp = first;           //set temp to the current node
        first = first->link;    //advance first to the next node
        delete temp;            //deallocate the memory occupied by temp
        cout << "Node destroyed." << endl;
    }
    last = nullptr;             //initialize last to nullptr; first has already
                                //been set to nullptr by the while loop
    count = 0;                  // zero the count
}

template <class Type>
void List<Type>::initializeList()
{
	destroyList();              //if the list has any nodes, delete them
}


// length gets the length of the list
template <class Type>
int List<Type>::length() const
{
    return count;               // returns the # of nodes in the list
}  //end length

template <class Type>
Type List<Type>::front() const
{
    assert(first != nullptr);

    return first->stuRecord;         //return the stuRecord of the first node
}//end front

template <class Type>
Type List<Type>::back() const
{
    assert(last != nullptr);

    return last->stuRecord;          //return the stuRecord of the last node
}//end back

template <class Type>
void List<Type>::insertFirst(const Type& item)  // building the list "backwards"
{
    nodeType<Type> *newNode;    //pointer to declare the new node

    newNode = new nodeType<Type>;   //create (allocate) new node

    newNode->stuRecord = item;       //assign item into stuRecord
    newNode->link = first;      //assign old first pointer to the newNode's link
    first = newNode;            //assign first to point to the new first node
    count++;                    //increment count
}//end insertFirst



template <class Type>
void List<Type>::insertLast(const Type& item) // building the list "forwards"
{
    nodeType<Type> *newNode;    //pointer to create the new node

    newNode = new nodeType<Type>;   //create the new node

    newNode->stuRecord = item;       //store the new item in the node
    newNode->link = nullptr;    //set the link field of newNode to nullptr

    if (first == nullptr)       //if list is empty, newNode is both first & last node
    {
        first = newNode;        //assign the new node pointer to first
        last = newNode;         //assign the new node pointer to last
    }
    else                        //list is not empty, insert newNode after last
    {
        last->link = newNode;   //insert newNode after last
        last = newNode;         //make last point to actual last node in the list
    }
    count++;                    // increment count
}//end insertLast


template <class Type>
void List<Type>::copyList(const List<Type>& otherList)
{
    nodeType<Type> *newNode;    //local pointer to create a node
    nodeType<Type> *current;    //local pointer to traverse the list

    if (first != nullptr)       //if the list is not empty
       destroyList();           //then, make it empty

    if (otherList.first == nullptr)  //otherList is empty
    {
        first = nullptr;        //reset pointers
        last = nullptr;         //  "      "
        count = 0;              // zero the count
    }
    else                        //the other list must have data
    {
        current = otherList.first;  //current points to the list to be copied
        count = otherList.count;

        //this section copies only the first node
        first = new nodeType<Type>;     //create (allocate) the node

        first->stuRecord = current->stuRecord;    //copy the stuRecord
        first->link = nullptr;          //set the link field of the node to nullptr
        last = first;                   //make last point to the first node
        current = current->link;        //make current point to the next node

        //copy the remaining list
        while (current != nullptr)
        {
            newNode = new nodeType<Type>;   //create (allocate) the node
            newNode->stuRecord = current->stuRecord;  //copy the stuRecord
            newNode->link = nullptr;           //set the link of newNode to nullptr
            last->link = newNode;           //attach newNode after last
            last = newNode;                 //make last point to the actual last node
            current = current->link;        //make current point to the next node
        }//end while
    }//end else
}//end copyList


template <class Type>
bool List<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current;            //pointer to traverse the list
    nodeType<Type> *trailCurrent;       //pointer just before current
    bool found;

    if (first == nullptr)               //Case 1; the list is empty.
        cout << "Cannot delete from an empty list."
             << endl;
    else
    {
        if (first->stuRecord.name == deleteItem.name)  //Case 2
        {
            current = first;
            first = first->link;
            count--;
            if (first == nullptr)       //the list has only one node
                last = nullptr;
            delete current;
            found=true;
        }
        else //search the list for the node with the given stuRecord
        {
            found = false;
            trailCurrent = first;       //set trailCurrent to point
                                        //to the first node
            current = first->link;      //set current to point to
                                        //the second node

            while (current != nullptr && !found)
            {
                if (current->stuRecord.name != deleteItem.name)
                {
                    trailCurrent = current;
                    current = current-> link;
                }
                else
                    found = true;
            }//end while

            if (found) //Case 3; if found, delete the node
            {
                trailCurrent->link = current->link;
                count--;

                if (last == current)     //node to be deleted
                                         //was the last node
                    last = trailCurrent; //update the value
                                         //of last
                delete current;          //delete the node from the list
            }
            else
                {
                     return false;
                }
        }//end else
    }//end else
    return found;
}//end deleteNode


template <class Type>
void List<Type>::sortLinkedList(string field)
{
    //curr(to first) pointer and next pointer
    nodeType<Type> *curr;                   //curr is local pointer to node
    nodeType<Type> *next;                   //next is local pointer to node also
	bool swapped = true;      				 // assume exchanges will happen


	for(int i = 0; swapped && i < count; i++) // outer loop//count is private but we're in the class
	{
        curr = first;                       // copy first pointer to curr
        next = curr->link;                     //link ptr follows curr
	    swapped = false;					 //   reset the flag for no exchanges
    	for(int j = 0; j < count - i - 1; j++)//   inner loop does not check sorted items
		{
            if (field == "GPA")
            {

                if(curr->stuRecord.fGpa < next->stuRecord.fGpa)		 //    gpa sort
                {
           		swapped = swapData(curr->stuRecord, next->stuRecord);    			 //       swap just happened.  set a flag
                }
                curr = curr->link;//advance link to next nodes
                next = next->link;
            }
            else
            {

                if(curr->stuRecord.name > next->stuRecord.name)		 //    name sort
                {
           		swapped = swapData(curr->stuRecord, next->stuRecord);    			 //       swap just happened.  set a flag
                }
                curr = curr->link;//advance link to next nodes
                next = next->link;
            }

        }
	}
}


template <class Type>
bool List<Type>::swapData(Type &obj1, Type &obj2 )
{
    Type temp;          // local type stuRecord temp
    temp = obj1;        //assign obj1 to temp
    obj1 = obj2;        //copy obj2 to obj1
    obj2 = temp;        //copy temp to obj2

     return true;       //always returns true

}

template <class Type>
istream & operator>> (istream & infile, List<Type> & obj)//obj is list1
{
  Type stuRecord;  //declare local Type
  string lname, fname, fullName;
  string zip;
  char sex;
  float gpa;

  //priming read
  infile >> lname >> fname >> zip >> sex >> gpa;

  while (!infile.eof()) //read the whole file
  {
      fullName= lname + ", " + fname; //concatenate name
      stuRecord.name = fullName;      //make new nodes in stuRecord containing full name of student
      stuRecord.zipCode = zip;        //their zip code
      stuRecord.gender = sex;         //gender
      stuRecord.fGpa = gpa;           //and GPA

      //insert this record into the list
      obj.insertFirst(stuRecord);
      infile >> lname >> fname >> zip >> sex >> gpa;

  }
  return infile;
}


template <class Type>
ostream & operator<< (ostream & outfile, const List<Type> & obj) //overloading << operator
{
  outfile << fixed  << showpoint  << setprecision(2); //print to outer file
  nodeType<Type> *current;
  current=obj.first;//it doesnt know which first is, thats way its first of the OBJECT(obj)

  while (current!=nullptr) //until the end of list
  {

        outfile << "        "<< setw(9) //print the list to the file
                << left << setw(18)
                << current->stuRecord.name
                << right
                << setw(7) << current->stuRecord.zipCode
                << setw(4) << current->stuRecord.gender
                << setw(7) << current->stuRecord.fGpa << endl;

        current = current->link; //advance pointer to next node

  }
return outfile;
}
