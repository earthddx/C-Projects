// LinkedStack.cpp (Implementation file for the LinkedStack)

#include "LinkedStack.h"

//Default constructor
template <class Type>
LinkedStackType<Type>::LinkedStackType()
{
    stackTop = NULL;
    size = 0;
}

//copy constructor
template <class Type>
LinkedStackType<Type>::LinkedStackType(const LinkedStackType<Type>& otherStack)
{
    stackTop = NULL;
    copyStack(otherStack);
}//end copy constructor

//destructor
template <class Type>
LinkedStackType<Type>::~LinkedStackType()
{
    initializeStack();
}//end destructor

    //overloading the assignment operator
template <class Type>
const LinkedStackType<Type>& LinkedStackType<Type>::operator=
    			  (const LinkedStackType<Type>& otherStack)
{
    if (this != &otherStack) //avoid self-copy
        copyStack(otherStack);

    return *this;
}//end operator=

template <class Type>
bool LinkedStackType<Type>::isEmptyStack() const
{
    return(stackTop == NULL);       //stack is empty if stackTop is NULL
} //end isEmptyStack

template <class Type>
bool LinkedStackType<Type>:: isFullStack() const
{
    return false;                   //a linked stack is virtually never full
} //end isFullStack

template <class Type>
void LinkedStackType<Type>:: initializeStack()
{
    nodeType<Type> *temp;           //pointer to delete the node

    while (stackTop != NULL)        //while there are elements in the stack
    {
        temp = stackTop;            //set temp to point to the current node
        stackTop = stackTop->link;  //advance stackTop to the next node
        delete temp;                //deallocate memory occupied by temp
    }
} //end initializeStack

template <class Type>
void LinkedStackType<Type>::push(const Type& newElement)
{
    nodeType<Type> *newNode;        //pointer to create the new node

    newNode = new nodeType<Type>;   //create the node

    newNode->info = newElement;     //store newElement in the node
    newNode->link = stackTop;       //insert newNode before stackTop
    stackTop = newNode;             //set stackTop to point to the
                                    //top node
    size++;                         // add 1 to size
} //end push


template <class Type>
Type LinkedStackType<Type>::top() const
{
    assert(stackTop != NULL);       //if stack is empty, terminate the program
    return stackTop->info;          //return the top element
}//end top

template <class Type>
void LinkedStackType<Type>::pop()
{
    nodeType<Type> *temp;           //pointer to deallocate memory

    if (stackTop != NULL)
    {
        temp = stackTop;            //set temp to point to the top node

        stackTop = stackTop->link;  //advance stackTop to the
                                    //next node
        delete temp;                //delete the top node
        size--;                     //reduce size by 1
    }
    else
        cout << "Cannot remove from an empty stack." << endl;
}//end pop

template <class Type>
void LinkedStackType<Type>::copyStack
                     (const LinkedStackType<Type>& otherStack)
{
    nodeType<Type> *newNode, *current, *last;

    if (stackTop != NULL)               //if stack is nonempty, make it empty
        initializeStack();

    if (otherStack.stackTop == NULL)
        stackTop = NULL;
    else
    {
        current = otherStack.stackTop; //set current to point to stack to be copied
        size = otherStack.size;         // size of stacks are the same
        //copy the stackTop element of the stack
        stackTop = new nodeType<Type>;  //create the node

        stackTop->info = current->info; //copy the info
        stackTop->link = NULL;          //set the link field of the node to NULL
        last = stackTop;                //set last to point to the node
        current = current->link;        //set current to point to the next node

        //copy the remaining stack
        while (current != NULL)         /// these lines need to be commented
        {                               /// to notify reader what is going on?
            newNode = new nodeType<Type>;
            newNode->info = current->info;
            newNode->link = NULL;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }//end while
    }//end else
} //end copyStack

template <class Type>
int LinkedStackType<Type>::getSize() const
{
    return size;                    // returns the size of the stack
}


template <class Type>
void LinkedStackType<Type>::sortLinkedStack()
{
    nodeType<Type> *curr;                   //curr is local pointer to node
    nodeType<Type> *next;                   //next is local pointer to node also
	bool swapped = true;      				 // assume exchanges will happen
	if (stackTop == NULL) //if theres no list
            return;       //returns control to client


	for(int i = 0; swapped && i < size; i++) // outer loop
	{
        curr = stackTop;                       // copy stackTop pointer to curr
        next = stackTop->link;                 //link ptr follows curr
	    swapped = false;					   //reset the flag for no exchanges
    	for(int j = 0; j < size - i - 1; j++)  //inner loop does not check sorted items
		{

 	       	if(curr->info > next->info)		 //    numbers ascending
			{
           		swapped = swapData(curr->info, next->info);    			 //swap just happened.  set a flag
        	}
        	curr = curr->link;   //advance link to next nodes
        	next = next->link;

    	}//end of inner loop

	}//end of outer loop

}

template <class Type>
bool LinkedStackType<Type>::swapData(Type &obj1, Type &obj2 )
{
    Type temp;          // local type Type temp
    temp = obj1;        //assign obj1 to temp
    obj1 = obj2;        //copy obj2 to obj1
    obj2 = temp;        //copy temp to obj2

     return true;       //always returns true

}

