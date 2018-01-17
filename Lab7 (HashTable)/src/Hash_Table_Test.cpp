/**
 * ThuMinh Nguyen
 * CIS 22C
 * Hash_Table_Test.cpp
 */

#include <iostream>
#include "Hash_Table.h"

using namespace std;

int main() {
	Hash_Table HT;
	Book pp("Pride and Prejudice", "Jane Austen", 1234567, 4.95);
	Book c("Contact", "Carl Sagan", 99993339, 9.95);
	Book hg("The Hunger Games", "Suzanne Collins", 12388888, 13.55);
	Book hp("Harry Potter", "J.K. Rowlings", 55555678, 12.99);
	Book mhc("The Man in the High Castle", "Philip K Dick", 95959595, 15.95);
	Book bh("Bleak House", "Charles Dickens", 473890238, 8.00);

	HT.insert(pp);
	HT.insert(c);
	HT.insert(hg);
	HT.insert(mhc);
	HT.insert(bh);
	//Table does not have book Harry Potter

	HT.print_bucket(4);
	HT.print_bucket(9);
	HT.print_bucket(1);//Bucket is empty
	HT.print_table();

	cout << "Find it? Should return -1: " << HT.find(hp) << endl;//Harry Potter is not in the table
	cout << "Find it? Should return an integer (not -1): " << HT.find(mhc) << endl;
	HT.remove(mhc);
	cout << "Find it? Should return -1: " << HT.find(mhc) << endl;
	HT.print_bucket(9);
	HT.remove(hg);
	cout << "After removing all books in bucket 9. Should be empty bucket.\n";
	HT.print_bucket(9);
}
/*
Printing bucket: 4

Contact
by Carl Sagan
ISBN#: 99993339
Price: $9.95

Printing bucket: 9

The Hunger Games
by Suzanne Collins
ISBN#: 12388888
Price: $13.55

The Man in the High Castle
by Philip K Dick
ISBN#: 95959595
Price: $15.95

Printing bucket: 1

Bucket is empty.
<----------------------->
Bucket: 0
Bleak House
by Charles Dickens
ISBN#: 473890238
Price: $8.00
Number of book at this bucket: 1
<----------------------->

<----------------------->
Bucket: 2
Pride and Prejudice
by Jane Austen
ISBN#: 1234567
Price: $4.95
Number of book at this bucket: 1
<----------------------->

<----------------------->
Bucket: 4
Contact
by Carl Sagan
ISBN#: 99993339
Price: $9.95
Number of book at this bucket: 1
<----------------------->

<----------------------->
Bucket: 9
The Hunger Games
by Suzanne Collins
ISBN#: 12388888
Price: $13.55
Number of book at this bucket: 2
<----------------------->

Find it? Should return -1: -1
Find it? Should return an integer (not -1): 9
Find it? Should return -1: -1
Printing bucket: 9

The Hunger Games
by Suzanne Collins
ISBN#: 12388888
Price: $13.55

After removing all books in bucket 9. Should be empty bucket.
Printing bucket: 9

Bucket is empty.

*/

