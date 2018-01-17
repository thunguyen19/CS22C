//============================================================================
// Name        : List.cpp
// Author      : ThuN.
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "List.h"

#include <iostream>
using namespace std;

//inline contructor
List::List(): start(NULL), end(NULL), cursor(NULL), length(0) {}

//destructor
List::~List()
{
    cursor = start;
    NodePtr temp;
    while(cursor != NULL)
    {
        temp = cursor->next;

        delete cursor;

        cursor = temp;

    }
}

void List::print()
{
    NodePtr temp = start; //create a temporary iterator
    while (temp != NULL) {
    	cout << temp->data << " ";
    	temp = temp->next;
        //What two lines of code go here?
        //Hint: One statement should contain a cout

    }
    cout << endl; //What does this do? Go to new line after display the list
}

void List::add_start(int data)
{
    if (length==0) //Why is this necessary?
    {
        start = new Node(data);
        end = start;

    }
    else
    {
        NodePtr N = new Node(data);//create the new node by calling the node constructor
        N->next = start;//set the new node's next field to point to the start
        start = N;//make the start be the new node
    }

    length++;

}

void List::add_end(int data)
{
    if (length==0)
    {
        start = new Node(data);
        end = start;

    }
    else
    {
    	NodePtr temp = start;
        NodePtr N = new Node(data);//create the new node by calling the node constructor
        while (temp->next != NULL)
        {
        	temp = temp->next;//find the last element that points to NULL
        }
        temp->next = N;//
        N->next = NULL;//set the new node's next field to point to NULL
        end = N;//make the end be the new node

    }

    length++;

}

bool List::is_empty()
{
    return (length==0);
}

int List::get_length()
{
    return length;
}

int List::get_start()
{
    return start -> data;
}

int List::get_end()
{
    return end -> data;
}

