/**
 * ThuMinh Nguyen
 * CIS 22C
 * StackTest.cpp
 */

#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
	Stack ST;
	ST.push("dog");
	ST.push("cat");
	ST.push("pig");
	ST.push("bird");
	ST.pop();
	cout << "The stack should be pig cat dog: ";
	ST.print();
	cout << "Length should be 3: " << ST.get_length() << endl;
	cout << "Get top should be pig: " << ST.get_top() << endl;
	Stack ST2(ST); //make a copy of the original list
	ST2.pop();
	cout << "The stack ST2 should be cat dog: ";
	ST2.print();
	cout << "List should not be equal: ";
	if (ST2 == ST)
		cout << "Lists are equal.\n";
	else
		cout << "Lists are not equal.\n";
	cout << "Length ST2 should be 2: " << ST2.get_length() << endl;
	return 0;
}
/* Result from console
 The stack should be pig cat dog: pig cat dog
 Length should be 3: 3
 Get top should be pig: pig
 The stack ST2 should be cat dog: cat dog
 List should not be equal: Lists are not equal.
 Length ST2 should be 2: 2
 */
