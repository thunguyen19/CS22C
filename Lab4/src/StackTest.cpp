/**
 * ThuMinh Nguyen
 * CIS 22C
 * StackTest.cpp
 */
#include <iostream>
#include "Stack.h"
using namespace std;
int main() {
	Stack ST; // call a new Stack
	ST.push(5); // push data into the stack
	ST.push(9);
	ST.push(2);
	ST.push(4);
	cout << "Stack 1 should print 4 2 9 5: ";
	ST.print(); // print the stack
	cout << "The length of stack 1 should be 4: " << ST.get_size() << endl;
	Stack ST2(ST); // call the new second stack
	cout << "Stack 2 should print 4 2 9 5: ";
	ST2.print(); // print stack 2 .Should print similar value with stack 1
	cout << "The length of the stack 2 should be 4: " << ST2.get_size() << endl;
	cout << "Compare stack 1 and stack 2. Should be equal: ";
	if (ST2 == ST) //compare 2 stacks
		cout << "Stacks are equal.\n";
	else
		cout << "Stacks are not equal.\n";
	ST.pop(); // remove top from stack 1
	cout << "Stack 1 should print 2 9 5: ";
	ST.print();  // print stack 1.
	cout << "The length of the stack 1 should be 3: " << ST.get_size() << endl;
	cout << "Compare stack 1 and stack 2. Should NOT be equal: ";
	if (ST2 == ST) //compare 2 stacks
		cout << "Stacks are equal.\n";
	else
		cout << "Stacks are not equal.\n";
	ST.pop();//remove top from stack 1
	cout << "Stack 1 should print 9 5:";
	ST.print();
	cout << "The length of the stack 1 should be 2: " << ST.get_size() << endl;
	ST.pop();
	ST.pop();
	cout << "Stack 1 is now empty. Length should be 0: " << ST.get_size();
}
/*
Stack 1 should print 4 2 9 5: 4 2 9 5
The length of stack 1 should be 4: 4
Stack 2 should print 4 2 9 5: 4 2 9 5
The length of the stack 2 should be 4: 4
Compare stack 1 and stack 2. Should be equal: Stacks are equal.
Stack 1 should print 2 9 5: 2 9 5
The length of the stack 1 should be 3: 3
Compare stack 1 and stack 2. Should NOT be equal: Stacks are not equal.
Stack 1 should print 9 5:9 5
The length of the stack 1 should be 2: 2
Stack 1 is now empty. Length should be 0: 0
*/
