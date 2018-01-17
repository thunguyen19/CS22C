/**
 * ThuMinh Nguyen
 * CIS 22C
 * FileName
 */
#include "SearchEngine.h"
#include "BinarySearchTree.h"
#include <assert.h>
#include <iostream>

using namespace std;

//Default Constructor
SearchEngine::SearchEngine()
{
	idx = 0;
}

//Destructor
SearchEngine::~SearchEngine(){};


/**Access Functions*/

//SearchEngine count_bucket() access function
int SearchEngine::count_bucket(int index)
{
	assert(index >= 0 && index < SIZE);
	return Table[index].getSize();
}


//SearchEngine find() access function
//Calls the pairsHash find() function
int SearchEngine::find(string key)
{
	return pairsHash.find(key);
}


//SearchEngine searchByKeyword() function
//If the word is found, prints all the poems at the bucket
void SearchEngine::searchByKeyword(string key, ostream &strm)
{
	if (find(key) != -1)
		print_bucket(pairsHash.find(key), strm);
	else
		strm << "Word \'" << key << "\' is NOT in the system.\n";
}

/**Manipulation Procedures*/


//SearchEngine insert() function
void SearchEngine::insert(string keyword, Haiku h)
{
	//If the key is not in the pairsHash yet,
	//create a new WordID pair object and insert it
	//into pairsHash. Also insert a poem corresponding
	//to the keyword into the Table hash at assigned idx
	if (pairsHash.find(keyword) == -1)
	{
		WordID pair(keyword, idx);
		pairsHash.insert(pair);
		Table[pair.getId()].insert(h);
		idx++;
	}
	//Else, return the index assigned to the keyword and
	//insert a new poem at that index
	else
	{
		Table[pairsHash.find(keyword)].insert(h);
	}
}

//SearchEngine remove() function
void SearchEngine::remove(string keyword, Haiku h)
{

	//if the book is not in the hash table, do nothing
	if (pairsHash.find(keyword) == -1)
		return;

	if (!Table[pairsHash.find(keyword)].isEmpty())
			Table[pairsHash.find(keyword)].remove(h);
}


/**Additional Functions*/


//SearchEngine print_bucket() function
void SearchEngine::print_bucket(int index, ostream &strm)
{
	assert(index >= 0 && index < SIZE);

	//if bucket at index is empty, return
	if (Table[index].isEmpty())
	{
		strm << "\nThe poem is NOT in the system.\n" << endl;
		return;
	}
	//otherwise, traverse the list and print data at each node
	//in sorted order
	Table[index].inOrderPrint(strm);

}


//SearchEnging print_table() function
//Prints the first poem in each bucket, unless bucket is empty.
//If bucket is empty, prints nothing
void SearchEngine::print_table(ostream &strm)
{
	for (int idx = 0; idx < SIZE; idx++)
	{
		if (Table[idx].isEmpty())
			continue;
		else
		{
			strm << "<----------------------->" << endl;
			strm << "Bucket: " << idx << endl;
			strm << Table[idx].getRoot().get_title() << endl;
			strm << "by " << Table[idx].getRoot().get_author() << endl;
			strm << Table[idx].getRoot().get_haiku() << endl;
			strm << "Number of haikus at this bucket: " << count_bucket(idx) << endl;
			strm << "<----------------------->" << endl;
			strm << endl;
		}
	}
}

void SearchEngine::printPairs(ostream &strm)
{
	pairsHash.print_table(cout);
}
