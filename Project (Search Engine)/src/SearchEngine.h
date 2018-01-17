/**
 * ThuMinh Nguyen
 * CIS 22C
 * FileName
 */
#ifndef SEARCHENGINE_H_
#define SEARCHENGINE_H_


#include <string>
#include "BinarySearchTree.h"
#include <iostream>
#include "Haiku.h"
#include "WordID.h"
#include "WordIDHashTable.h"

using namespace std;


class SearchEngine {
public:
    /**Constructors*/

	SearchEngine();
    //default constructor

    ~SearchEngine();
    //destructor

    /**Access Functions*/

    int count_bucket(int index);
    //counts the number of objects at this index
    //returns the count
    //pre: 0<= index < SIZE

    int find(string key);
    //Searches for the key in the pairsHash
    //and returns index at which the key is
    //in the search engine hash

    void searchByKeyword(string key, ostream &strm);
    //Searches by key and displays
    //the titles of poems where the key
    //appears in ascending order

    /**Manipulation Procedures*/

    void insert(string keyword, Haiku h);
    //inserts a new haiku poem into the table
    //at keyword's index
    //calls the hash function on the keyword
    //to determine the correct bucket

    void remove(string keyword, Haiku h);
    //removes object from the table
    //calls the hash function on the key to determine
    //the correct bucket

    /**Additional Functions*/

    void print_bucket(int index, ostream &strm);
    //Prints all the objects at index
    //pre: 0<= index < SIZE


    void print_table(ostream &strm);
    //Prints the first book at each index
    //along with a count of the total books
    //at each index by calling count_bucket
    //as a helper function

    void printPairs(ostream &strm);

private:
    static const int SIZE = 180;
    BinarySearchTree Table[SIZE];
    int idx;
    WordIDHashTable pairsHash;
};


#endif /* SEARCHENGINE_H_ */
