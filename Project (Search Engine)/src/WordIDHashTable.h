/**
 * ThuMinh Nguyen
 * CIS 22C
 * FileName
 */
#ifndef WORDIDHASHTABLE_H_
#define WORDIDHASHTABLE_H_

#include <string>
#include <iostream>
#include "List.h"
#include "WordID.h"
using namespace std;


class WordIDHashTable{
public:
    /**Constructors*/

	WordIDHashTable();
    //default constructor

    ~WordIDHashTable();
    //destructor

    /**Access Functions*/

    int hash(string key);
    //returns the hash value for the given key
    //the hash value is the sum of
    //of the ASCII values of each char in the key
    //% the size the of the table

    int count_bucket(int index);
    //counts the number of objects at this index
    //returns the count
    //pre: 0<= index < SIZE

    int find(string key);
    //Searches for object in the table
    //returns the index at which object is located
    //returns -1 if b is not in the table

    /**Manipulation Procedures*/

    void insert(WordID w);
    //inserts a new object into the table
    //calls the hash function on the key to determine
    //the correct bucket


    void remove(WordID w, ostream &strm);
    //removes object from the table
    //calls the hash function on the key to determine
    //the correct bucket

    /**Additional Functions*/

    void print_bucket(int index, ostream &strm);
    //Prints all the objects at index
    //pre: 0<= index < SIZE


    void print_table(ostream &strm);
    //Prints the first object at each index
    //along with a count of the total objects
    //at each index by calling count_bucket
    //as a helper function


private:
    static const int SIZE = 180;
    List<WordID> Table[SIZE];
};

#endif /* WORDIDHASHTABLE_H_ */
