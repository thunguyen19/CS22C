/**
 * @author Thu Nguyen
 * CIS 22C
 * ListTest.cpp
 */
#include "List.h"
#include <iostream>
using namespace std;

int main() {
	List<int> Tint;
	Tint.add_end(2);
	Tint.add_start(5);
	Tint.add_start(1);
	Tint.add_end(7);
	cout << "Should print 1 5 2 7: ";
	Tint.print();
	cout << "Reverse list should print 7 2 5 1: ";
	Tint.print_reverse();
	Tint.begin_cursor();
	Tint.move_cursor();
	Tint.move_cursor();
	cout << "Cursor is pointing to 2: " << Tint.get_cursor() << endl;
	cout << "Index of the cursor should be 3: " << Tint.get_index() << endl;
	Tint.add_cursor(9);
	Tint.add_cursor(3);
	cout << "New list should print 1 5 2 3 9 7: ";
	Tint.print();
	cout << "Cursor is still pointing to 2: " << Tint.get_cursor() << endl;
	Tint.scroll_to_index(5);
	cout << "Now, cursor is pointing to 9: " << Tint.get_cursor() << endl;
	cout << "Linear search - Value 26 not on the list. Return -1: " << Tint.linear_search(26) << endl;
	cout << "Linear search - Value 7 at index 6: " << Tint.linear_search(7) << endl;
	List<int> Tint2;
	Tint2.add_start(7);
	Tint2.add_start(5);
	Tint2.add_start(4);
	Tint2.add_start(2);
	Tint2.add_start(1);
	Tint2.add_end(15);
	cout << "List in reverse 15 7 5 4 2 1: ";
	Tint2.print_reverse();
	cout << "List sorted should print 1 2 4 5 7 15: ";
	Tint2.print();
	cout << "Binary search - Value 1 at index 1: " << Tint2.binary_search(1, 6, 1) << endl;
	cout << "Binary search - Value 7 at index 5: "<< Tint2.binary_search(1, 6, 7) << endl;
	cout << "Binary search - Value 99 not on the list. Return -1: " << Tint2.binary_search(1, 6, 99);
}
/*
Should print 1 5 2 7: 1 5 2 7
Reverse list should print 7 2 5 1: 7 2 5 1
Cursor is pointing to 2: 2
Index of the cursor should be 3: 3
New list should print 1 5 2 3 9 7: 1 5 2 3 9 7
Cursor is still pointing to 2: 2
Now, cursor is pointing to 9: 9
Linear search - Value 26 not on the list. Return -1: -1
Linear search - Value 7 at index 6: 6
List in reverse 15 7 5 4 2 1: 15 7 5 4 2 1
List sorted should print 1 2 4 5 7 15: 1 2 4 5 7 15
Binary search - Value 1 at index 1: 1
Binary search - Value 7 at index 5: 5
Binary search - Value 99 not on the list. Return -1: -1
*/
