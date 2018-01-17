/**
 * ThuMinh Nguyen
 * CIS 22C
 * Hash_Table.h
 */

#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_

#include <string>
#include "List.h"
#include <iostream>
#include "Haiku.h"
using namespace std;


class Hash_Table {
public:
    /**Constructors*/

    Hash_Table();
    //default constructor

    ~Hash_Table();
    //destructor
    int hash(string key);

    int count_bucket(int index);

    int find(string primaryKey);

    void search(string primaryKey, ostream &strm);

    bool insert(Haiku h, ostream &strm);

    void remove(string primaryKey, ostream &strm);

    void print_bucket(int index, ostream &strm, int& count);

    void print_table(ostream &strm);

    Haiku getHaikuText(string primaryKey);
    //find and return the Haiku poem


private:
    static const int SIZE = 30;
    List<Haiku> Table[SIZE];
    string trimString(string);
};

#endif /* HASH_TABLE_H_ */
