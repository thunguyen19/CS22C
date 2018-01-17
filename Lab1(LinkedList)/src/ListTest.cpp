/*
 * ListTest.cpp
 *
 *  Created on: Oct 3, 2016
 *  Author: Thu Minh Nguyen
 */

#include "List.h"
#include <iostream>

using namespace std;

int main()
{
    //creating a new list object T
    List T;

    T.add_start(8);
    T.add_end(3);

    cout << "List should contain: " ;
    T.print();

    cout << "The start of the list should be 8: " << T.get_start() << endl;
    cout << "The end of the list should be 3: " << T.get_end() << endl;

    T.add_end(7);
    T.add_start(11);
    cout << "List should contain: " ;
    T.print();
    cout << "The start of the list should be 11: " << T.get_start() << endl;
    cout << "The end of the list should be 7: " << T.get_end() << endl;
    cout << "The length of the list should be 4: " << T.get_length() << endl;

    if (T.is_empty())
    	cout << "List is empty." << endl;
    else
    	cout << "List is not empty." << endl;

    //YOU MUST ADD MORE TESTS HERE TO RECEIVE CREDIT FOR THIS LAB!!!
}
/*
List should contain: 8 3
The start of the list should be 8: 8
The end of the list should be 3: 3
List should contain: 11 8 3 7
The start of the list should be 11: 11
The end of the list should be 7: 7
The length of the list should be 4: 4
List is not empty.
*/
