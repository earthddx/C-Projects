// List class header file (specification). No additions, deletions, or changes are allowed.
#ifndef H_List
#define H_List

//Definition of one data node (student record)
struct stuRecord
{
    string name;        // student's "Last, First" name
    string zipCode;     // student's zip code
    char   gender;      // student's sex
    float  fGpa;        // student's gpa as a floating point
};

// definition of the linked list node used
template <class Type>
struct nodeType
{
	Type stuRecord;
	nodeType<Type> *link;
};

// forward declaration of class (and friend functions necessary for templated)
template <class Type>
class List;

template <class Type>
ostream & operator<< (ostream & outfile, const List<Type> &);

template <class Type>
istream & operator>> (istream & infile, List<Type> &);
// end of forward declarations of the List class

template <class Type>
class List
{
    friend ostream & operator<< <>(ostream & outfile, const List<Type> &);
    friend istream & operator>> <>(istream & infile, List<Type> &);

  public:

    List();                                             // default constructor
    List(const List<Type>& otherList);                  // copy constructor
    ~List();                                            // destructor

    const List<Type>& operator= (const List<Type> &);   // overload assignment operator
    void initializeList();                              // list cleared to an empty state
    bool isEmptyList() const;                           // determines if list is empty
    int length() const;                                 // returns number of records in list
    Type front() const;                                 // returns first element in list
    Type back() const;                                  // returns last element in list
    void insertFirst(const Type& newItem);              // inserts newItem in list beginning
    void insertLast(const Type& newItem);               // inserts newItem at end of list
    bool deleteNode(const Type& deleteItem);            // deletes record from list
    void sortLinkedList(string field);                  // optimized bubble sort on one field



  private:
    int count;                                          // number of records in list
    nodeType<Type> *first;                              // pointer to first node of list
    nodeType<Type> *last;                               // pointer to last node of list
    bool swapData(Type &, Type & );                     // swaps records for sorting
    void copyList(const List<Type>& );                  // makes a copy of the list.
    void destroyList();                                 // deletes all the nodes from list.
};
#endif
