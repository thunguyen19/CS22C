/**
 * @author Thu Nguyen
 * CIS 22C
 * ListTest.cpp
 */
#include "List.h"
#include <iostream>
using namespace std;

int main()
{
	List<int> Tint;
	List<char> Tchar;
	List<double> Tdouble;
	List<string> Tstring;
	//Test list of integer
	Tint.add_start(1);
	cout << "Should print 1:\n";
	Tint.print();
	Tint.add_end(2);
	cout << "Should print 1 2:\n";
	Tint.print();
	Tint.begin_cursor();
	Tint.add_cursor(5);
	Tint.add_cursor(7);
	Tint.remove_cursor();
	Tint.print();
	/*
	cout << "Should print 1 5 2:\n";
	Tint.print();
	List<int> Tint2(Tint);
	cout << "Should print 1 5 2:\n";
	Tint2.print();
	cout << "Should print lists are equal: " << endl;
	if (Tint == Tint2)
		cout << "Lists are equal" << endl;
	else
		cout << "Lists are not equal" << endl;
	Tint.move_cursor();
	Tint.move_cursor();
	cout << "Current cursor should be 2:\n";
	cout << Tint.get_cursor() << endl;
	Tint.add_cursor(4);
	cout << "Should print 1 5 2 4:\n";
	Tint.print();
	cout << "Length should be 4:\n" << Tint.get_length() << endl;
	Tint.remove_cursor();
	cout << "After remove 2, should print 1 5 4:\n";
	Tint.print();
	cout << "Should print lists are not equal: " << endl;
	if (Tint == Tint2)
		cout << "Lists are equal" << endl;
	else
		cout << "Lists are not equal" << endl;

	//Test list of char
	cout << "Size of list should be 0: " << Tchar.get_length() << endl;
	Tchar.add_start('a');
	Tchar.remove_end();
	cout << "Size of list should be 0: " << Tchar.get_length() << endl;
	cout << "List should be empty. Nothing printed to screen: " << endl;
	Tchar.print();
	Tchar.add_start('A');
	Tchar.begin_cursor();
	Tchar.add_cursor('D');
	Tchar.add_start('C');
	Tchar.move_cursor();
	Tchar.add_cursor('B');
	cout << "Should print: C A D B\n";
	Tchar.print();
	cout << "The size of the list should be 4: " << Tchar.get_length() << endl;

	//Test list of double
	Tdouble.add_end(8.8);
	Tdouble.add_start(7.7);
	Tdouble.add_end(9.9);
	cout << "Should print 7.7 8.8 9.9:\n";
	Tdouble.print();

	cout << "Should print iterator is off the end of the List:\n";
	if (Tdouble.off_end())
	{
		cout << "Iterator is off end\n";
	}
	else
	{
		cout << "Iterator is not off end\n";
	}
	Tdouble.begin_cursor();
	Tdouble.move_cursor();
	cout << "Should print 8.8:\n";
	cout << Tdouble.get_cursor() << endl;
	Tdouble.move_cursor();
	Tdouble.remove_end();
	cout << "Should print 7.7 8.8:\n";
	Tdouble.print();
*/
}
/*MyTestFile
 // Should print 1:
1
Should print 1 2:
1 2
Should print 1 5 2:
1 5 2
Should print 1 5 2:
1 5 2
Should print lists are equal:
Lists are equal
Current cursor should be 2:
2
Should print 1 5 2 4:
1 5 2 4
Length should be 4:
4
After remove 2, should print 1 5 4:
1 5 4
Should print lists are not equal:
Lists are not equal
Size of list should be 0: 0
Size of list should be 0: 0
List should be empty. Nothing printed to screen:

Should print: C A D B
C A D B
The size of the list should be 4: 4
Should print 7.7 8.8 9.9:
7.7 8.8 9.9
Should print iterator is off the end of the List:
Iterator is off end
Should print 8.8:
8.8
Should print 7.7 8.8:
7.7 8.8
 */

