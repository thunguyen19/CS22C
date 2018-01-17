/*
 *  List.h
 *
 *  Created on: Oct 2, 2016
 *  Author: Thu Minh Nguyen
 */

#ifndef LIST_H_
#define LIST_H_
#include <cstddef> //for NULL

class List
{
    private:
             struct Node
             {
            	 int data;
            	 Node* next;
            	 Node(int data) : next(NULL), data(data) {}
             };

             typedef struct Node* NodePtr;//refer to a Node* as NodePtr

             NodePtr start;
             NodePtr end;
             NodePtr cursor;

             int length;
    public:

        /**Constructors and Destructors*/

        List();
        //Default constructor; initializes and empty list
        //Postcondition: the list must be created

        ~List();
        //Destructor. Frees memory allocated to the list
        //Postcondition: the list's contain must be deleted

        List(const List &list);
        //Copy construtor. Initializes list to have the same elements as another list
        //Postcondition: the list must have the same elements as another list

        /**Accessors*/

        int get_start();
        //Returns the first element in the list
        //Precondition: the list must be exist


        int get_end();
        //Returns the last element in the list
        //Precondition: the list must be exist


        int get_cursor();
        //Returns the element pointed to by the iterator
        //Precondition: the list must not be empty


        bool is_empty();
        //Determines whether a list is empty.


        bool off_end();
        //Determines if the iterator is off the end of the list (i.e. whether cursor is NULL)


        int get_length();
        //Returns the length of the list


        /**Manipulation Procedures*/

        void begin_cursor();
        //Moves the iterator to point to the first element in the list
        //If the list is empty, the iterator remains NULL
        //Postcondition: cursor points to the first element of the list


        void insert_cursor(int data);
        //Inserts a new element into the list in the position after the iterator
        //Precondition: the list must not be empty
        //Postcondition: a new element was added into the list in the position

        void remove_end();
        //Removes the value of the last element in the list
        //Precondition: the list must not be empty
        //Postcondition: the last element of the list was removed

        void remove_start();
        //Removes the value of the first element in the list
        //Precondition: the list must not be empty
        //Postcondition: the first element must be removed

        void add_end(int data);
        //Inserts a new element at the end of the list
        //If the list is empty, the new element becomes both start and end
        //Postcondition: a new element was added to the end of the list

        void add_start(int data);
        //Inserts a new element at the start of the list
        //If the list is empty, the new element becomes both start and end
        //Postcondition: a new element was added to the start of the list


        void remove_cursor();
        //Removes the element pointed at by the iterator
        //Precondition: the list must not be empty
        //Postcondition: the element pointing by the cursor was removed

        void move_cursor();
        //Moves the iterator forward by one element in the list
        //Precondition: the list must not be empty
        //Postcondition: the iterator was moved to the next location in the list


        /**Additional List Operations*/

        void print();
        //Prints to the console the value of each element in the list sequentially
        //and separated by a blank space
        //Prints nothing if the list is empty
};

#endif /* LIST_H_ */
