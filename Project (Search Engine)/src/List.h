#ifndef LIST_H_
#define LIST_H_

#include <cstddef> //for NULL
#include <iostream>
#include <assert.h>

using namespace std;

template <class listitem>
class List {
    private:
        struct Node
        {
            listitem data;
            Node* next;
            Node* previous;

            Node(listitem data): data(data), next(NULL), previous(NULL) {}
        };

        typedef struct Node* NodePtr;

        NodePtr start;
        NodePtr end;
        NodePtr cursor;

        int length;

        void reverse(NodePtr node);
        //Helper function for the public printReverse() function.
        //Recursively prints the data in a List in reverse.

    public:

        /**Constructors and Destructors*/

        List();
        //Default constructor; initializes an empty list
        //Postcondition: all pointer variables are initialized to NULL,
        //integer variables initialized to 0.

        ~List();
        //Destructor. Frees memory allocated to the list
        //Postcondition: the memory allocated for the list data structure, its nodes and
        //pointers, is freed.

        List(const List &list);
        //Copy constructor. Initializes list to have the same elements as another list
        //Postcondition: a copy list with identical data but different memory locations
        //for its nodes is created

        /**Accessors*/

        listitem get_start();
        //Returns the first element in the list
        //Precondition: the list must not be empty


        listitem get_end();
        //Returns the last element in the list
        //Precondition: the list must not be empty


        listitem get_cursor();
        //Returns the element pointed to by the iterator
        //Precondition: the list must not be empty;
        //the cursor must not be off the list


        bool is_empty();
        //Determines whether a list is empty.


        bool off_end();
        //Determines if the iterator is off the end of the list (i.e. whether cursor is NULL)


        int get_length();
        //Returns the length of the list


        int get_index();
        //Indicates the index of the Node where the cursor is currently pointing
        //Nodes are numbered from 1 to size of the list
        //Pre: !off_end()
        //Pre: length != 0


        int linear_search(listitem value);
        //Searches the list, element by element, from the head of the List to the tail of the List
        //Returns the index of the value, if it is found in the List
        //Returns -1 if the element is not in the List
        //Pre: !empty()



        int binary_search(int low, int high, listitem value);
        //Recursively searches the list by dividing the search space in half
        //Returns the index of the value, if it is found in the List
        //Returns -1 if the value is not in the List
        //Pre: !empty()
        //Pre: List is sorted.
        //Assumes list is sorted when the function is called.


        /**Manipulation Procedures*/

        void scroll_to_index(int index);
        //Moves the cursor to the node whose index is specified by the user
        //Pre: !empty()

        void begin_cursor();
        //Moves the iterator to point to the first element in the list
        //If the list is empty, the iterator remains NULL
        //Postcondition: the iterator points to the first element in the list
        //or if the list is empty, the iterator points to NULL


        void add_cursor(listitem data);
        //Inserts a new element into the list in the position after the iterator
        //Precondition: the iterator is not off the end of the list;
        //cannot use add_cursor() with an empty list.
        //Postcondition: new data is inserted into the list right after the node
        //that the iterator points to;


        void remove_end();
        //Removes the value of the last element in the list
        //Precondition: the list must not be empty
        //Postcondition: the very last node in the list is removed;
        //the length of the list has decremented by 1;

        void remove_start();
        //Removes the value of the first element in the list
        //Precondition: the list must not be empty
        //Postcondition: the node that 'start' used to point to is removed;
        //pointer 'start' points to a new first node (the one that used to be second);
        //the length of the list has decremented by 1.

        void add_end(listitem data);
        //Inserts a new element at the end of the list
        //If the list is empty, the new element becomes both start and end
        //Postcondition: pointer 'end' points to the newly-added node;
        //the length of the list has incremented by 1.

        void add_start(listitem data);
        // a new element at the start of the list
        //If the list is empty, the new element becomes both start and end
        //Postcondition: pointer 'start' points to the newly-added node;
        //the length of the list has incremented by 1.


        void remove_cursor();
        //Removes the element pointed at by the iterator
        //Precondition: the list must not be empty and
        //the cursor must not be off the end of the list.
        //Postcondition: the length of the list has decremented by 1;
        //the node that used to be pointed to by the iterator is removed.

        void move_cursor();
        //Moves the iterator forward by one element in the list
        //Precondition: the list must not be empty; cursor must not point to
        //the end of the list (to NULL);
        //Postcondition: the cursor points to the next node in the list


        /**Additional List Operations*/

        void print();
        //Prints to the console the value of each element in the list sequentially
        //and separated by a blank space
        //Prints nothing if the list is empty

        bool operator == (const List &list);
        //Tests two lists to determine whether their contents are equal
        //Postcondition: returns true if lists are equal and false otherwise

        void print_reverse();
        //Calls the reverse helper function to print a list in reverse
        //prints nothing if the List is empty
};


/**Constructors and Destructors*/


//Default Constructor
template <class listitem>
List<listitem>::List(): start(NULL), end(NULL), cursor(NULL), length(0) {}


//Copy Constructor
template <class listitem>
List<listitem>::List(const List &originalList) : length(originalList.length)
{
    //If originalList is empty, set all pointers in new list to NULL
    if (!originalList.length)
    {
        start = end = cursor = NULL;
    }
    else
    {
        //else, allocate the first node and copy the data from the originalList's first node
        //set 'start' and 'cursor' to point to it
        start = cursor = new Node(originalList.start->data);

        //create an iterator to traverse the original list; set it to point to 2nd node
        NodePtr originalListCursor = originalList.start->next;

        //traverse the original list
        while (originalListCursor)
        {
            //create a new node
           NodePtr newNode = new Node(originalListCursor->data);

            //connect the pointers
            cursor->next = newNode;
            newNode->previous = cursor;

            //move the original list iterator forward
            originalListCursor = originalListCursor->next;

            //move the copied list iterator forward
            this->move_cursor();
        }
        //set the end pointer to point to the last node in the copied list
        end = cursor;
        //cursor is no longer needed; set the pointer variable to NULL
        cursor = NULL;
    }
}


//Destructor
template <class listitem>
List<listitem>::~List()
{
    //set the iterator
    this->begin_cursor();

    //traverse the list
    while (cursor)
    {
        //deleting first node at each loop iteration
        start = cursor->next;
        delete cursor;
        cursor = start;
    }
}

/**Accessors*/


//List get_start() access member function
template <class listitem>
listitem List<listitem>::get_start()
{
    assert(start != NULL);
    return start->data;

}


//List get_end() access member function
template <class listitem>
listitem List<listitem>::get_end()
{
    assert(end != NULL);
    return end->data;
}


//List get_cursor() access member function
template <class listitem>
listitem List<listitem>::get_cursor()
{
    assert(length != 0);
    assert(cursor != NULL);
    return cursor->data;
}


//List is_empty() access member function
template <class listitem>
bool List<listitem>::is_empty()
{
    return (length == 0);
}


//List off_end: returns whether or not the iterator is off the end of the List, i.e. NULL
template <class listitem>
bool List<listitem>::off_end()
{
    return (cursor == NULL);
}


//List get_length() access member function
template <class listitem>
int List<listitem>::get_length()
{
    return length;
}


//List get_index() access member function
template <class listitem>
int List<listitem>::get_index()
{
    assert(length != 0);
    assert(!off_end());

    int idx = 1;
    NodePtr temp = start;

    while (temp != cursor)
    {
        temp = temp->next;
        idx++;
    }
    return idx;
}


//List linear_search() member function
template <class listitem>
int List<listitem>::linear_search(listitem value)
{
    assert(!is_empty());
    begin_cursor();
    while(!off_end())
    {
        if (get_cursor() == value){
            return get_index();
        }
        move_cursor();
    }
    //if the value is not in the list
    return -1;
}


//List binary_search() access member function
template <class listitem>
int List<listitem>::binary_search(int low, int high, listitem value)
{
    assert(!is_empty());

    //if value is not in the list
    if (high < low)
        return -1;

     //mid formula to avoid int overflow
     int mid = low + (high - low)/2;
     scroll_to_index(mid);

     //return idx if value is found
     if (get_cursor() == value)
         return mid;
     //if not, search upper half of the list
     else if (get_cursor() < value)
        return binary_search(mid + 1, high, value);
     //or lower half of the list
     else
        return binary_search(low, mid - 1, value);
}


/**Manipulation Procedures*/


//List scroll_to_index() manipulation member function
template <class listitem>
void List<listitem>::scroll_to_index(int index)
{
    assert(!is_empty());
    //index cannot be less or equal to 0 and
    //bigger than the length of the list
    assert(index > 0 && index <= get_length());

    //node 1 is at index 1
    begin_cursor();

    while(index > 1)
    {
        move_cursor();
        index--;
    }
}


//List begin_cursor() setter member function
template <class listitem>
void List<listitem>::begin_cursor()
{
    cursor = start;
}


//List add_cursor() manipulation member function
template <class listitem>
void List<listitem>::add_cursor(listitem data)
{
    assert(cursor != NULL);

    if (cursor == end)
    {
        this->add_end(data);
    }
    else
    {
        NodePtr newNode = new Node(data);
        //First connect new node's pointers to the list
        newNode->next = cursor->next;
        newNode->previous = cursor;
        //Connect the rest of the list to the new node
        cursor->next->previous = newNode;
        //Connect the first part of the list to the new node
        cursor->next = newNode;
        length++;
    }
}


//List move_cursor() manipulation member function
template <class listitem>
void List<listitem>::remove_cursor()
{
    assert (cursor != NULL);

    if (cursor == start)
    {
        this->remove_start();
    }
    else if (cursor == end)
    {
        this->remove_end();
    }
    else
    {
        //connect the links around the node that is to be removed
        cursor->previous->next = cursor->next;
        cursor->next->previous = cursor->previous;
        //delete the node pointed at by the cursor
        delete cursor;
        length--;
    }
    cursor = NULL;
}


//List move_cursor() manipulation member function
template <class listitem>
void List<listitem>::move_cursor()
{
    assert(cursor != NULL);
    cursor = cursor->next;
}


//List add_start() manipulation member function
template <class listitem>
void List<listitem>::add_start(listitem newData)
{
    //create the new node
    NodePtr newNode = new Node(newData);

    if (!length)
    {
        //If the list is empty, have 'start' & 'end'
        //pointers point to the new node.
        start = end = newNode;

    }
    else
    {
        start->previous = newNode;           //connect the former first node to the new one
        newNode->next = start;               //new node's 'previous' pointer already points to NULL
        start = newNode;                     //make the start point to the new node
    }
    length++;
}


//List add_end() or append manipulation member function
template <class listitem>
void List<listitem>::add_end(listitem newData)
{
    //create the new node
    NodePtr newNode = new Node(newData);

    if (!length)
    {
        //If the list is empty, have 'start' & 'end'
        //pointers point to the new node.
        start = end = newNode;
    }
    else
    {
        end->next = newNode;                 //connect new node to the former last node in the list
        newNode->previous = end;             //new node's 'next' pointer already points to NULL
        end = newNode;                       //reset 'end' pointer
    }
    length++;
}


//List remove_start() manipulation member function
template <class listitem>
void List<listitem>::remove_start()
{
    assert(length != 0);

    if (length == 1)
    {
        delete start;
        start = end = NULL;
    }
    else
    {
        //move 'start' to second node
        start = start->next;
        //delete first node;
        delete start->previous;
        //set first node's 'previous' ptr
        start->previous = NULL;
    }
    length--;
}


template <class listitem>
void List<listitem>::remove_end()
{
    assert(length != 0);

    if (length == 1)
    {
        delete start;
        start = end = NULL;
    }
    else
    {
        //move 'end' one node back
        end = end->previous;
        //delete the last node in the list
        delete end->next;
        //set the current last node's 'next' ptr
        end->next = NULL;
    }
    length--;
}


/**Additional List Operations*/


//List print() class member method
template <class listitem>
void List<listitem>::print()
{
    NodePtr temp = start;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


//Overloaded == operator
template <class listitem>
bool List<listitem>::operator == (const List &list)
{
    if (length != list.length)
        return false;

    NodePtr leftList = start;
    NodePtr rightList = list.start;

    while(leftList)
    {
        if (leftList->data != rightList->data)
            return false;

        leftList = leftList->next;
        rightList = rightList->next;
    }
    return true;
}


//List private reverse() method
template <class listitem>
void List<listitem>::reverse(NodePtr node)
{
    if (node == NULL)           //base case
        return;
    else
    {
        reverse(node->next);    //will call itself until node->next == NULL
        cout << node->data << " ";
    }
}


//List print_reverse() public member method
template <class listitem>
void List<listitem>::print_reverse()
{
    reverse(start);
}

#endif /* LIST_H_ */
