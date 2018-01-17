#include "Hash_Table.h"
#include "Haiku.h"
#include <assert.h>
#include <iomanip>
#include <iostream>
#include <cctype>

using namespace std;

//Default Constructor
Hash_Table::Hash_Table() {
}

//Destructor
Hash_Table::~Hash_Table() {
}
;

//Private trimString function
//weeds out white spaces and leaves all chars lowercase
string Hash_Table::trimString(string str) {
	string trimmedStr;
	for (unsigned idx = 0; idx < str.length(); idx++) {
		if (isalpha(str[idx]))
			trimmedStr += tolower(str[idx]);
	}
	return trimmedStr;
}

/**Access Functions*/

//Hash Table hash() access function
//hashes a trimmed key and returns idx
int Hash_Table::hash(string key) {
	int index, sum = 0;
	string trimmedKey = trimString(key);
	for (unsigned i = 0; i < trimmedKey.length(); i++) {
		sum += (int) trimmedKey[i];
	}

	index = sum % SIZE;
	return index;
}

//Hash table count_bucket() access function
int Hash_Table::count_bucket(int index) {
	assert(index >= 0 && index < SIZE);
	return Table[index].get_length();
}

//Hash table find() access function
//primary key is the sum of author & title chars
int Hash_Table::find(string primaryKey) {
	int index = hash(primaryKey);

	//if the list at index is empty, return -1
	if (Table[index].is_empty())
		return -1;

	//trim the primary key
	string trimmedPrimaryKey = trimString(primaryKey);

	int listIdx = 1;
	string author, title, trimmedStr;

	//otherwise, traverse the list
	Table[index].begin_cursor();
	while (!Table[index].off_end()) {
		//Trim the title and author strings before comparing to trimmed primary key
		string author = trimString(Table[index].get_cursor().get_author());
		string title = trimString(Table[index].get_cursor().get_title());
		string trimmedStr = title + author;

		//in case author and title are entered in this order
		string reversedStr = author + title;

		if (trimmedStr == trimmedPrimaryKey || reversedStr == trimmedPrimaryKey)
			return listIdx;

		listIdx++;
		Table[index].move_cursor();
	}
	//if the poem is not in the bucket, return -1
	return -1;
}

//Hash_Table search() access function
void Hash_Table::search(string primaryKey, ostream &strm) {
	int hashIdx = hash(primaryKey);
	int listIdx = find(primaryKey);

	if (listIdx == -1) {
		strm << "\nThe haiku poem in NOT in the system.\n";
	} else {
		Table[hashIdx].scroll_to_index(listIdx);

		strm << "\nThe haiku poem is:\n";
		strm << Table[hashIdx].get_cursor().get_haiku() << endl;
		strm << endl;
	}
}

/**Manipulation Procedures*/

//Hash table insert() manipulation function
bool Hash_Table::insert(Haiku h, ostream &strm) {
	int index = hash(h.get_title() + h.get_author());
	//append new node to the list at bucket

	if (!Table[index].is_empty()) {
		if (Table[index].linear_search(h) != -1) {
			strm << "\nThis haiku poem is already in the system.\n";
			return false;
		} else
			Table[index].add_end(h);
	} else
		Table[index].add_end(h);
	return true;

}

//Hash table remove() function
void Hash_Table::remove(string primaryKey, ostream &strm) {
	int hashIdx = hash(primaryKey);
	int listIdx = find(primaryKey);

	//if the book is not in the hash table, do nothing
	if (listIdx == -1) {
		strm
				<< "\nThis haiku poem cannot be removed because it is NOT in the system.\n";
	} else {
		Table[hashIdx].scroll_to_index(listIdx);
		Table[hashIdx].remove_cursor();
		strm << "\nThe haiku poem is removed from the system.\n";
	}
}

/**Additional Functions*/

//Hash table print_bucket() function
void Hash_Table::print_bucket(int index, ostream &strm, int& count) {
	assert(index >= 0 && index < SIZE);

	//if bucket at index is empty, return
	if (Table[index].is_empty()){
		return;
	}

	//otherwise, traverse the list and print data at each node
	Table[index].begin_cursor();
	while (!Table[index].off_end()) {
		count++;
		strm << count << ". ";
		strm << Table[index].get_cursor().get_title() << endl;
		strm << "by " << Table[index].get_cursor().get_author() << endl;
		strm << "Year written: " << Table[index].get_cursor().get_year()
				<< endl;
		strm << "Country of origin: " << Table[index].get_cursor().get_country()
				<< endl;
		strm << Table[index].get_cursor().get_haiku() << endl << endl;
		Table[index].move_cursor();
	}
}

//Access function, returns the haiku object
Haiku Hash_Table::getHaikuText(string primaryKey) {
	int hashIdx = hash(primaryKey);
	int listIdx = find(primaryKey);

	if (listIdx != -1) {
		Table[hashIdx].scroll_to_index(listIdx);
		return Table[hashIdx].get_cursor();
	}
}

//Hash table print_table() function
void Hash_Table::print_table(ostream &strm) {
	int count = 0;
	for (int index = 0; index < SIZE; index++) {
		if (Table[index].is_empty())
			continue;
		else
			print_bucket(index, strm, count);
	}
}

