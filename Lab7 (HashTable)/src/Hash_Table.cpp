/**
 * ThuMinh Nguyen
 * CIS 22C
 * Hash_Table.cpp
 */

#include "Hash_Table.h"

Hash_Table::Hash_Table() {
}

Hash_Table::~Hash_Table() {
}

int Hash_Table::hash(string key) {
	int index, sum = 0;
	for (int i = 0; i < key.length(); ++i) {
		sum += (int) key[i];
	}
	index = sum % SIZE;
	return index;
}

int Hash_Table::count_bucket(int index) {
	if (Table[index].get_length()==0){
		cout << "Bucket is empty.\n";
		return 0;
	}
	int count = 0;
	Table[index].begin_cursor();
	for (int i = 0; i < Table[index].get_length(); ++i) {
		Table[index].move_cursor();
		count++;
	}
	return count;
}

int Hash_Table::find(Book b){
	int index = hash(b.get_title() + b.get_author());
	if (Table[index].linear_search(b) == -1){
		return -1;
	}
	else
		return index;
}

void Hash_Table::remove(Book b) {
	int index = hash(b.get_title() + b.get_author());
		Table[index].begin_cursor();
		for (int i = 0; i < Table[index].get_length(); ++i) {
			if (b.get_isbn() == Table[index].get_cursor().get_isbn()) {
				Table[index].remove_cursor();
				break;
			} else {
				Table[index].move_cursor();
			}
		}
}

void Hash_Table::insert(Book b) {
	int index = hash(b.get_title() + b.get_author());
	Table[index].add_end(b);
}

void Hash_Table::print_bucket(int index) {
	if (index >= 0 && index < SIZE) {
		if (Table[index].get_length() == 0) {
			cout << "Printing bucket: " << index << endl << endl;
			cout << "Bucket is empty.\n"; //print nothing
		} else {
			cout << "Printing bucket: " << index << endl << endl;
			Table[index].begin_cursor();
			for (int i = 0; i < Table[index].get_length(); ++i) {
				Table[index].get_cursor().print_book();
				Table[index].move_cursor();
				cout << endl;
			}
		}
	} else
		cout << "Input error.\n";
}

void Hash_Table::print_table() {
	for (int index = 0; index < SIZE; ++index) {
		if (Table[index].get_length() == 0) {
			cout << ""; //print nothing
		} else {
			Book b = Table[index].get_start();
			cout << "<----------------------->\n";
			cout << "Bucket: " << index << endl;
			b.print_book();
			cout << "Number of book at this bucket: " << count_bucket(index)
					<< endl;
			cout << "<----------------------->\n";
			cout << endl;
		}
	}
}

