/**
 * ThuMinh Nguyen
 * CIS 22C
 * Book.h
 */

#ifndef BOOK_H_
#define BOOK_H_

#include <string>
using namespace std;

class WordID {
private:
	int id;
	string word;
public:
	WordID(string w, int i);
	string getWord();
	int getId();
};

#endif /* BOOK_H_ */
