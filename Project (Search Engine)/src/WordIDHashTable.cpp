/**
 * ThuMinh Nguyen
 * CIS 22C
 *
 */

#include "Hash_Table.h"
#include "WordID.h"
#include "WordIDHashTable.h"
#include <assert.h>
#include <iomanip>
#include <iostream>

using namespace std;

#include "WordIDHashTable.h"
#include <assert.h>
#include <iostream>

//Default Constructor
WordIDHashTable::WordIDHashTable(){}

//Destructor
WordIDHashTable::~WordIDHashTable(){};


/**Access Functions*/

//WordIDHashTable hash() access function
int WordIDHashTable::hash(string key)
{
    int index, sum = 0;
    for(unsigned i = 0; i < key.length(); i++)
    {
		sum += (int)key[i];
    }
    index = sum % SIZE;
    return index;
}


//WordIDHashTable count_bucket() access function
int WordIDHashTable::count_bucket(int index)
{
	assert(index >= 0 && index < SIZE);
	return Table[index].get_length();
}


//WordIDHashTable find() access function
//Returns the index assigned to a given keyword
//if the keyword is found
int WordIDHashTable::find(string key)
{
	int index = hash(key);

	//if the list at index is empty, return -1
	if (Table[index].is_empty())
		return -1;

	//otherwise, traverse the list
	Table[index].begin_cursor();
	while (!Table[index].off_end())
	{
		if (Table[index].get_cursor().getWord() == key)
			return Table[index].get_cursor().getId();

		Table[index].move_cursor();
	}
	return -1;
}


/**Manipulation Procedures*/


//WordIDHashTable insert() manipulation function
void WordIDHashTable::insert(WordID w)
{
	int index = hash(w.getWord());
	Table[index].add_end(w);
}


//WordIDHashTable remove() function
void WordIDHashTable::remove(WordID w, ostream &strm)
{
	int hashIdx = hash(w.getWord());
	int listIdx = find(w.getWord());

	if (listIdx != -1)
	{
		Table[hashIdx].scroll_to_index(listIdx);
		Table[hashIdx].remove_cursor();
	}
}


/**Additional Functions*/


//WordIDHashTable print_bucket() function
void WordIDHashTable::print_bucket(int index, ostream &strm)
{
	assert(index >= 0 && index < SIZE);

	//if bucket at index is empty, return
	if (Table[index].is_empty())
		return;

	strm << "Printing bucket: " << index << "\n\n";

	//otherwise, traverse the list and print data at each node
	Table[index].begin_cursor();
	while (!Table[index].off_end())
	{
		strm << Table[index].get_cursor().getWord() << endl;
		strm << "at " << Table[index].get_cursor().getId() << endl;
		strm << endl;
		Table[index].move_cursor();
	}
}

//WordIDHashTable print_table() function
void WordIDHashTable::print_table(ostream &strm)
{
	for (int idx = 0; idx < SIZE; idx++)
	{
		if (Table[idx].is_empty())
			continue;
		else
		{
			strm << "<----------------------->" << endl;
			strm << Table[idx].get_start().getWord() << endl;
			strm << "at " << Table[idx].get_start().getId() << endl;
			strm << endl;
			strm << "Number of WordID pairs at this bucket: " << count_bucket(idx) << endl;
			strm << "<----------------------->" << endl;
			strm << endl;
		}
	}
}
