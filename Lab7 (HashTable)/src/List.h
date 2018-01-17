/**
 * @author Thu Nguyen
 * CIS 22C
 * List.h
 */
#ifndef LIST_H_
#define LIST_H_
#include <cstddef> //for NULL
#include <assert.h>
#include <iostream>
using namespace std;

template<class listitem> // allow list to hold any type of data
class List {
private:
	struct Node {
		listitem data;
		Node* next;
		Node* previous;
		Node(listitem data) :
				next(NULL), previous(NULL), data(data) {
		}
	};

	typedef struct Node* NodePtr; //refer to a Node* as NodePtr

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

	bool operator==(const List &list);
	//Tests two lists to determine whether their contents are equal
	//Postcondition: returns true if lists are equal and false otherwise

	/**Accessors*/

	listitem get_start();
	//Returns the first element in the list
	//Precondition: the list must be exist

	listitem get_end();
	//Returns the last element in the list
	//Precondition: the list must be exist

	listitem get_cursor();
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

	void add_cursor(listitem data);
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

	void add_end(listitem data);
	//Inserts a new element at the end of the list
	//If the list is empty, the new element becomes both start and end
	//Postcondition: a new element was added to the end of the list

	void add_start(listitem data);        //take in generic data
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

	void scroll_to_index(int index);
	//Moves the iterator to the node whose index is specified by the user
	//Pre: length!=0

	int linear_search(listitem item);
	//Searchs the list, element by element, from the start of the List to the end of the List
	//Returns the index of the element, if it is found in the List
	//Returns -1 if the element is not in the List
	//Pre: length != 0

	listitem print();
	//Prints to the console the value of each element in the list sequentially
	//and separated by a blank space
	//Prints nothing if the list is empty
};
#endif /* LIST_H_ */

template<class listitem>
List<listitem>::List() :
		start(NULL), end(NULL), cursor(NULL), length(0) {
}

//destructor
template<class listitem>
List<listitem>::~List() {
	cursor = start;
	NodePtr temp;
	while (cursor != NULL) {
		temp = cursor->next;
		delete cursor;
		cursor = temp;
	}
}
template<class listitem>
List<listitem>::List(const List &list) :
		length(list.length) {
	if (list.start == NULL) //If the original list is empty, make an empty list for this list
	{
		start = end = cursor = NULL;
	} else {
		start = new Node(list.start->data); //using second Node constructor
		NodePtr temp = list.start; //set a temporary node pointer to point at the start of the original list
		cursor = start; //set iterator to point to start of the new list
		while (temp->next != NULL) {
			temp = temp->next; //advance up to the next node in the original list
			cursor->next = new Node(temp->data); //using node constructor to create a new node with copy of data
			cursor = cursor->next; //advance to this new node
		}
		end = cursor; //Why do I need this line of code?
		cursor = NULL;
	}
}
template<class listitem>
bool List<listitem>::operator==(const List& list) {
	if (length != list.length)
		return false;
	NodePtr temp1 = start;
	NodePtr temp2 = list.start;
	while (temp1 != NULL) {
		if (temp1->data != temp2->data)
			return false;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	return true;
}

template<class listitem>
listitem List<listitem>::print() {
	NodePtr temp = start; //create a temporary iterator
	while (temp != NULL) {
		cout << temp->data;
		temp = temp->next;
	}
	cout << endl;
}

template<class listitem>
void List<listitem>::add_start(listitem data) {
	if (length == 0) //Why is this necessary?
			{
		start = new Node(data);
		end = start;
	} else {
		NodePtr N = new Node(data); //create the new node by calling the node constructor
		N->next = start; //set the new node's next field to point to the start
		start->previous = N; //Need to update the previous pointer of start to point back at
		start = N; //make the start be the new node
	}
	length++;
}
template<class listitem>
void List<listitem>::remove_start() {
	assert(length != 0);
	if (length == 1) {
		delete start;
		start = end = cursor = NULL;
		length = 0;
	} else {
		if (cursor == start) {
			cursor = NULL;
		}
		NodePtr temp = start; //store original start node in a temporary variable
		start = start->next; //make the start pointer point to the second node in the List
		delete temp; //delete the original start
		length--;
	}
}
template<class listitem>
void List<listitem>::add_end(listitem data) {
	if (length == 0) {
		start = new Node(data);
		end = start;
	} else {
		NodePtr N = new Node(data); //create the new node by calling the node constructor
		end->next = N;
		N->previous = end;
		end = N; //make the end be the new node
		end->next = NULL;
	}
	length++;
}
template<class listitem>
void List<listitem>::remove_end() {
	assert(length != 0);
	if (length == 1) {
		delete end;
		start = end = cursor = NULL;
		length = 0;
	} else {
		NodePtr temp = end; //store original start node in a temporary variable
		end = end->previous; //make the start pointer point to the second node in the List
		end->next = NULL;
		delete temp; //delete the original start
		length--;
	}
}
template<class listitem>
void List<listitem>::add_cursor(listitem data) {
	NodePtr N = new Node(data);
	if (cursor == end) {
		add_end(data);
	} else {
		N->next = cursor->next;
		N->next->previous = N;
		N->previous = cursor;
		cursor->next = N;
		length++;
	}
}

template<class listitem>
void List<listitem>::remove_cursor() {
	assert(cursor != NULL);
	if (cursor == start) {
		this->remove_start();
	} else if (cursor == end) {
		this->remove_end();
	} else {
		//connect the links around the node that is to be removed
		cursor->previous->next = cursor->next;
		cursor->next->previous = cursor->previous;
		//delete the node pointed at by the cursor
		delete cursor;
		length--;
	}
	cursor = NULL;
}

template<class listitem>
int List<listitem>::linear_search(listitem data) {
	assert(length != 0);
	NodePtr temp = start;
	int index = 1;
	do {
		if (data == temp->data) {
			return index;
		}
		index++;
		temp = temp->next;
	} while (temp != NULL);
	return -1;
}

template<class listitem>
void List<listitem>::scroll_to_index(int index) {
	assert(length != 0);
	cursor = start;
	for (int i = 1; i < index; ++i) {
		move_cursor();
	}
}

template<class listitem>
void List<listitem>::begin_cursor() {
	assert(length != 0);
	cursor = start;
}
template<class listitem>
void List<listitem>::move_cursor() {
	assert(cursor != NULL);
	cursor = cursor->next;
}
template<class listitem>
bool List<listitem>::is_empty() {
	return (length == 0);
}
template<class listitem>
bool List<listitem>::off_end() {
	return (cursor == end);
}
template<class listitem>
int List<listitem>::get_length() {
	return length;
}
template<class listitem>
listitem List<listitem>::get_start() {
	assert(start != NULL);
	return start->data;
}
template<class listitem>
listitem List<listitem>::get_end() {
	assert(end != NULL);
	return end->data;
}
template<class listitem>
listitem List<listitem>::get_cursor() {
	assert(cursor != NULL);
	return cursor->data;
}
