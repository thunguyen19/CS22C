/**
* ThuMinh Nguyen
* CIS 22C
* QueueTest.cpp
*/

#include "Queue.h"
#include <iostream>
using namespace std;

int main() {
	Queue T;
	T.enqueue("1");
	T.enqueue("2");
	T.print();
	T.enqueue("3");
	T.enqueue("test");
	T.dequeue();
	cout << "The queue should be 2 3 test: ";
	T.print();
	cout << "Length should be 3: " << T.get_length() << endl;
	cout << "Get front should be 2: " << T.get_front() << endl;
	Queue T2(T);//make a copy of the original list
	T2.dequeue();
	cout << "The queue T2 should be 3 test: ";
	T2.print();
	cout << "List should not be equal: ";
	if (T2==T)
		cout << "Lists are equal.\n";
	else
		cout << "Lists are not equal.\n";
	cout << "Length T2 should be 2: " << T2.get_length() << endl;
	T2.dequeue();
	T2.dequeue();
	cout << "Queue T2 should be empty: ";
	if (T2.is_empty())
		cout << "Queue T2 is empty.\n";
	else
		cout << "Queue T2 is not empty.\n";
	return 0;
}
/*Result from console
The queue should be 2 3 test: 2 3 test
Length should be 3: 3
Get front should be 2: 2
The queue T2 should be 3 test: 3 test
List should not be equal: Lists are not equal.
Length T2 should be 2: 2
Queue T2 should be empty: Queue T2 is empty.
 */
