/**
 * ThuMinh Nguyen
 * CIS 22C
 * Palindrome.cpp
 */

#include <string>
#include <ctype.h>
#include "Queue.h"
#include "Stack.h"
#include <fstream>
#include <iostream>

using namespace std;

int main() {
	ifstream input;
	ofstream output;
	input.open("Palindrome.txt");
	if (input.fail()) {
		cout << "Input file failed to open.\n";
		exit(-1);
	}
	output.open("PalindromeOutput.txt");
	if (output.fail()) {
		cout << "Output file failed to open.\n";
		exit(-1);
	}
	Queue storeQ;
	Stack storeS;
	string str, store;
	int length;
	bool isPalindrome;

	while (getline(input, str)) {
		isPalindrome = false;
		length = str.length();
		for (int i = 0; i < length; i++) {
			//ignore all spaces and punctuation, store to queue and stack
			if (isalpha(str[i])) {
				store = tolower(str[i]);
				storeQ.enqueue(store);
				storeS.push(store);
			}
		}
		for (int j = 0; j < storeQ.get_length(); j++) {
			if (storeQ.get_front() != storeS.get_top()) {
				isPalindrome = false;
				break;
			} else {
				isPalindrome = true;
			}
			storeQ.dequeue();
			storeS.pop();
		}
		if (isPalindrome == false) {
			output << str << " (Not a Palindrome)\n";
		} else {
			output << str << " (Palindrome)\n";
		}
		//while loop to empty the queue to store new data
		do {
			storeQ.dequeue();
		} while (storeQ.get_length() > 0);

		//while lopp to empty the stack to store new data
		do {
			storeS.pop();
		} while (storeS.get_length() > 0);

	}
	input.close();
	output.close();
	return 0;
}
/*
 A man, a plan, a canal, Panama. (Palindrome)
 Do geese see God? (Palindrome)
 Never odd. Even. (Not a Palindrome)
 Never odd or even. (Palindrome)
 Eye (Palindrome)
 Ear (Not a Palindrome)
 Able was I ere I saw Elba! (Palindrome)
 Was it Eliot's toilet I saw? (Palindrome)
 Race cars (Not a Palindrome)
 */


