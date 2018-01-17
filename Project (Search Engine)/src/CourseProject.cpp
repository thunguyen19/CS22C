/**
 * ThuMinh Nguyen
 * CIS 22C
 * FileName
 */
#include <fstream>
#include <string>
#include <stdio.h>
#include <cctype>
#include <iostream>
#include "BinarySearchTree.h"
#include "Haiku.h"
#include "Hash_Table.h"
#include "SearchEngine.h"
#include <vector>
#include "WordIDHashTable.h"
#include <stdlib.h>
#include <cstdlib>

using namespace std;

bool isInputFileOpen(fstream &, const string &);
void seedDataFromFiles(string[], int, SearchEngine *, Hash_Table *,
		BinarySearchTree *, string[], int);
bool isBadKeyword(string[], int, string);
vector<string> generateKeywords(string[], int, string);
void insertKeywordsInSearchEngine(SearchEngine *, vector<string>, Haiku);

//Menu Function Prototypes:
Haiku addNewPoem();
string promptForPrimaryKey();
void searchByPrimaryKey(Hash_Table *, string);
void listAllDataBasePoemUnsorted(Hash_Table *, ostream &strm);
//void minYear(BinarySearchTree*, Haiku);

void menu(SearchEngine *, Hash_Table *, BinarySearchTree *, string[], int);
void display_haiku(BinarySearchTree *, Hash_Table *, SearchEngine *, string[],
		int);
void haiku_search(BinarySearchTree *, Hash_Table *, SearchEngine *, string[],
		int);
void insert_haiku(BinarySearchTree *, Hash_Table *, SearchEngine *, string[],
		int);
void delete_haiku(Hash_Table *, BinarySearchTree *, SearchEngine *, string[],
		int);
void display_statistics(SearchEngine , Hash_Table ,	BinarySearchTree, string , int );

int totalPoems = 0;
int main() {
	//Sorted list of words not to be accepted as keywords
	string badKeywords[] = { "along", "and", "any", "between", "but", "can",
			"each", "either", "for", "from", "her", "hers", "his", "how",
			"into", "most", "must", "none", "nor", "onto", "over", "shall",
			"she", "should", "some", "that", "the", "theirs", "them", "these",
			"they", "this", "those", "toward", "towards", "very", "what",
			"where", "will", "with", "within", "you" };
	int badKeywordsSize = sizeof(badKeywords) / sizeof(*badKeywords);

	//Names of 15 files that the project is to be seeded with
	string files[] = { "1.txt", "2.txt", "3.txt", "4.txt", "5.txt", "6.txt",
			"7.txt", "8.txt", "9.txt", "10.txt", "11.txt", "12.txt", "13.txt",
			"14.txt", "15.txt" };
	int filesSize = sizeof(files) / sizeof(*files);

	Hash_Table *databasePtr = new Hash_Table;
	SearchEngine *searchenginePtr = new SearchEngine;
	BinarySearchTree *BSTPtr = new BinarySearchTree;

	//Seed the project with 15 poem files' data
	seedDataFromFiles(files, filesSize, searchenginePtr, databasePtr, BSTPtr,
			badKeywords, badKeywordsSize);

	ofstream output;
	output.open("outfile.txt");
	if (output.fail()) {
		cout << "Output file failed to open.\n";
		exit(-1);
	}
	ofstream outfile;
	outfile.open("output.txt");
	menu(searchenginePtr, databasePtr, BSTPtr, badKeywords, badKeywordsSize);

	//to file
	listAllDataBasePoemUnsorted(databasePtr, outfile);
	//BSTPtr->statistic();
	output.close();

	return 0;

}	//end main

//**********************************************************************
//PROJECT FUNCTIONS BELOW

//The functions reads data from the files and seeds the database and
//the search engine with the data
void seedDataFromFiles(string files[], int SIZE, SearchEngine *sePTr,
		Hash_Table *dbPtr, BinarySearchTree *bstPtr, string badKeywords[],
		int badKeywordsSize) {
	//local instance variables
	fstream inputFile;
	string line;
	string text;
	Haiku poem;
	//int year;
	vector<string> keywords;

	for (int x = 0; x < SIZE; x++) {
		text = "";
		if (isInputFileOpen(inputFile, files[x])) {
			//read poem's title
			getline(inputFile, line, '\n');
			if (inputFile)
				poem.set_title(line);

			//read poem's author
			getline(inputFile, line, '\n');
			if (inputFile)
				poem.set_author(line);

			//get country
			getline(inputFile, line, '\n');
			if (inputFile)
				poem.set_country(line);

			//get year
			getline(inputFile, line, '\n');
			if (inputFile) {
				int y = atoi(line.c_str());
				poem.set_year(y);
			}

			//read the poem
			getline(inputFile, line, '\n');
			while (inputFile) {
				text += line;
				//text += '\n';
				getline(inputFile, line, '\n');
			}
		}
		//now poem has all Haiku attributes
		poem.set_haiku(text);
		//generate keywords from the poem's text
		keywords = generateKeywords(badKeywords, badKeywordsSize,
				poem.get_haiku());
		//insert generated keywords into search engine, as well as the poem they are associated with
		insertKeywordsInSearchEngine(sePTr, keywords, poem);
		//clear keywords vector for next poem's keywords
		keywords.clear();
		//insert the poem in a database
		dbPtr->insert(poem, cout);
		bstPtr->insert(poem);
		totalPoems++;
		//close the current file
		inputFile.close();
	}
}

//The function prompts the user for a new poem info
//and returns the newly created Haiku object
Haiku addNewPoem() {
	//Create an instance of a poem
	Haiku poem;
	//Local string
	string line;
	int year;
	//prompt the user for input
	cout << "\nPlease enter the poem's title: ";
	getline(cin, line);
	poem.set_title(line);
	cout << "Please enter the poem's author: ";
	getline(cin, line);
	poem.set_author(line);
	cout << "Please enter the poem's country: ";
	getline(cin, line);
	poem.set_country(line);
	cout << "Please enter the poem's year: ";
	cin >> year;
	cin.ignore();
	poem.set_year(year);
	string text;
	cout << "Please enter first line of haiku poem: ";
	getline(cin, line);
	text += line;
	text += '\n';
	cout << "Please enter second line of haiku poem: ";
	getline(cin, line);
	text += line;
	text += '\n';
	cout << "Please enter third line of haiku poem: ";
	getline(cin, line);
	text += line;
	text += '\n';
	poem.set_haiku(text);
	return poem;
}

//The function prompts for primary key; function will be used in
//the menu to delete/search/list data
string promptForPrimaryKey() {
	string title, author;
	cout << "Please enter the haiku title: ";
	getline(cin, title);
	cout << "Please enter the haiku author: ";
	getline(cin, author);
	string primaryKey = title + author;
	return primaryKey;
}

//The function lists unsorted data in HT database at every bucket
void listAllDataBasePoemUnsorted(Hash_Table *dbPtr, ostream &strm) {
	dbPtr->print_table(strm);
	strm << "End printing unsorted database list\n";
}

//Menu function search haiku by primary key
void searchByPrimaryKey(Hash_Table *dbPtr, string primaryKey) {
	dbPtr->search(primaryKey, cout);
}

//The function checks if the word in poem matches the word on bad list of keywords
bool isBadKeyword(string badKeysArr[], int SIZE, string word) {
	for (int x = 0; x < SIZE; x++) {
		if (word == badKeysArr[x])
			return true;
	}
	return false;
}

//The function accepts a poem's text and returns keywords
vector<string> generateKeywords(string badKeysArr[], int SIZE,
		string haiku_text) {
	vector<string> keywords;
	string word;

	//in case there's space in the beginning of the line
	unsigned int x = 0;
	while (x < haiku_text.length() && isspace(haiku_text[x]))
		x++;

	while (x < haiku_text.length()) {
		if (isalpha(haiku_text[x]))
			word += tolower(haiku_text[x]);
		else {
			if (word.length() > 2 && !isBadKeyword(badKeysArr, SIZE, word))
				keywords.push_back(word);
			word = "";
		}
		x++;
	}
	return keywords;
}

//The function inserts keywords and the Haiku object they are associated with into the search engine
void insertKeywordsInSearchEngine(SearchEngine *SEPtr, vector<string> keywords,
		Haiku poem) {
	for (unsigned idx = 0; idx < keywords.size(); idx++) {
		SEPtr->insert(keywords.at(idx), poem);
	}
}

//The function searches if the values matches one of the bad keywords
//in the badKeywords array
int binarySearch(string arr[], int low, int high, string value) {
	if (high < low)
		return -1;

	int mid = low + (high - low) / 2;

	if (arr[mid] == value)
		return mid;
	else if (arr[mid] > value)
		return binarySearch(arr, low, mid - 1, value);
	else
		return binarySearch(arr, mid + 1, high, value);
}

//The function checks if the inputFile has opened successfully
bool isInputFileOpen(fstream &inputFile, const string &fileName) {
	//Open the file stream object in input mode
	//.c_str() used b/c open() works with c-strings
	inputFile.open(fileName.c_str(), ios::in);

	//Check if failbit or hardbit flags are set
	if (inputFile.fail())
		return false;
	else
		return true;
}

void display_haiku(BinarySearchTree *BSTPtr, Hash_Table *databasePtr,
		SearchEngine *searchenginePtr, string badWords[], int badSize) {
	string choice;
	string confirm;
	cout << "\n\tDisplay Haiku" << endl;
	cout << "1. Unsorted Data" << endl;
	cout << "2. Sorted Data (A-Z)" << endl;
	cout << "3. Return to Menu" << endl;
	cout << "4. Quit" << endl;
	cout << "Enter your choice: ";
	getline(cin, choice);
	cout << endl;
	if (choice == "1") {
		listAllDataBasePoemUnsorted(databasePtr, cout);
	} else if (choice == "2") {
		BSTPtr->inOrderPrint(cout);
		cout << "End printing sorted data.\n";
	} else if (choice == "3") {
		menu(searchenginePtr, databasePtr, BSTPtr, badWords, badSize);
	} else if (choice == "4") {
		cout << "Are you sure you want to quit (save files)? (Y/N): ";
		getline(cin, confirm);
		if (confirm == "Y" || confirm == "y") {
			cout << "Thank you for using our program!" << endl;
			exit(-1);
		} else if (confirm == "N" || confirm == "n") {
			menu(searchenginePtr, databasePtr, BSTPtr, badWords, badSize);
		} else {
			cout << "Invalid Entry." << endl;
			menu(searchenginePtr, databasePtr, BSTPtr, badWords, badSize);
		}
	} else {
		cout << "Invalid Entry." << endl;
		display_haiku(BSTPtr, databasePtr, searchenginePtr, badWords, badSize);
	}
}

void haiku_search(SearchEngine *searchenginePtr, Hash_Table *databasePtr,
		BinarySearchTree *BSTPtr, string badWords[], int badSize) {
	string choice;
	string keywords;
	string confirm;
	cout << "\n\tSearch " << endl;
	cout << "1. Search by Primary Key" << endl;
	cout << "2. Search by Keyword" << endl;
	cout << "3. Return to Main menu" << endl;
	cout << "4. Quit" << endl;
	cout << "Enter your choice: ";
	getline(cin, choice);
	cout << endl;
	if (choice == "1") {
		string primaryKey = promptForPrimaryKey();
		databasePtr->search(primaryKey, cout);
		menu(searchenginePtr, databasePtr, BSTPtr, badWords, badSize);
	} else if (choice == "2") {
		cout << "Enter a keyword: ";
		getline(cin, keywords);
		searchenginePtr->searchByKeyword(keywords, cout);
		menu(searchenginePtr, databasePtr, BSTPtr, badWords, badSize);
	} else if (choice == "3") {
		menu(searchenginePtr, databasePtr, BSTPtr, badWords, badSize);
	} else if (choice == "4") {
		cout << "Are you sure you want to quit (save files)? (Y/N): ";
		getline(cin, confirm);
		if (confirm == "Y" || confirm == "y") {
			cout << "Thank you for using our program!" << endl;
			exit(-1);
		} else if (confirm == "N" || confirm == "n") {
			menu(searchenginePtr, databasePtr, BSTPtr, badWords, badSize);
		} else {
			cout << "Invalid Entry." << endl;
			haiku_search(searchenginePtr, databasePtr, BSTPtr, badWords,
					badSize);
		}
	} else {
		cout << "Invalid Entry." << endl;
		haiku_search(searchenginePtr, databasePtr, BSTPtr, badWords, badSize);
	}
}

void insert_haiku(BinarySearchTree *BSTPtr, Hash_Table *databasePtr,
		SearchEngine *searchenginePtr, string badWords[], int badSize) {
	string choice;
	string confirm;
	cout << "\n\tInsert" << endl;
	cout << "1. Insert Haiku" << endl;
	cout << "2. Return to Main menu" << endl;
	cout << "3. Quit" << endl;
	cout << "Enter your choice: ";
	getline(cin, choice);
	cout << endl;
	if (choice == "1") {
		Haiku poem = addNewPoem();
		if (databasePtr->insert(poem, cout)) {
			vector<string> keys = generateKeywords(badWords, badSize,
					poem.get_haiku());
			insertKeywordsInSearchEngine(searchenginePtr, keys, poem);
			keys.clear();
			BSTPtr->insert(poem);
			totalPoems++;
		} else
			cout << "Error. Poem could not be inserted" << endl;
	} else if (choice == "2") {
		menu(searchenginePtr, databasePtr, BSTPtr, badWords, badSize);
	} else if (choice == "3") {
		cout << "Are you sure you want to quit (save files)? (Y/N): ";
		getline(cin, confirm);
		if (confirm == "Y" || confirm == "y") {
			cout << "Thank you for using our program!" << endl;
			exit(-1);
		} else if (confirm == "N" || confirm == "n") {
			menu(searchenginePtr, databasePtr, BSTPtr, badWords, badSize);
		} else {
			cout << "Invalid Entry." << endl;
			menu(searchenginePtr, databasePtr, BSTPtr, badWords, badSize);
		}
	} else {
		cout << "Invalid Entry." << endl;
		menu(searchenginePtr, databasePtr, BSTPtr, badWords, badSize);
	}
}

void delete_haiku(Hash_Table *databasePtr, BinarySearchTree *BSTPtr,
		SearchEngine *searchenginePtr, string badWords[], int badSize) {
	string confirm;
	string choice;
	cout << "\n\tDelete" << endl;
	string primaryKey = promptForPrimaryKey();
	cout << "Are you sure? (Y/N): ";
	getline(cin, confirm);
	if (confirm == "Y" || confirm == "y") {
		//remove from search engine by keys
		Haiku haiku = databasePtr->getHaikuText(primaryKey);
		if (databasePtr->find(primaryKey) != -1) {
			vector<string> keysToDelete = generateKeywords(badWords, badSize,
					haiku.get_haiku());
			for (unsigned int x = 0; x < keysToDelete.size(); x++)
				searchenginePtr->remove(keysToDelete[x], haiku);
			//remove from database by primary key
			databasePtr->remove(primaryKey, cout);
			//remove from BST
			BSTPtr->remove(haiku);
			totalPoems--;
		} else {
			cout << "The poem you are trying to remove is not in the system.\n";
		}
		menu(searchenginePtr, databasePtr, BSTPtr, badWords, badSize);
	} else if (confirm == "N" || confirm == "n") {
		cout << "1. Delete Haiku" << endl;
		cout << "2. Return to Main menu" << endl;
		cout << "3. Quit" << endl;
		cout << "Enter your choice: ";
		getline(cin, choice);
		cout << endl;
		if (choice == "1") {
			delete_haiku(databasePtr, BSTPtr, searchenginePtr, badWords,
					badSize);
		} else if (choice == "2") {
			menu(searchenginePtr, databasePtr, BSTPtr, badWords, badSize);
		} else if (choice == "3") {
			cout << "Are you sure you want to quit (save files)? (Y/N): ";
			getline(cin, confirm);
			if (confirm == "Y" || confirm == "y") {
				cout << "Thank you for using our program!" << endl;
				exit(-1);
			} else if (confirm == "N" || confirm == "n") {
				menu(searchenginePtr, databasePtr, BSTPtr, badWords, badSize);
			} else {
				cout << "Invalid Entry." << endl;
				menu(searchenginePtr, databasePtr, BSTPtr, badWords, badSize);
			}
		} else {
			cout << "Invalid Entry." << endl;
			menu(searchenginePtr, databasePtr, BSTPtr, badWords, badSize);
		}
	} else {
		cout << "Invalid Entry." << endl;
		menu(searchenginePtr, databasePtr, BSTPtr, badWords, badSize);
	}
}

void display_statistics(SearchEngine *searchenginePtr, Hash_Table *databasePtr,
		BinarySearchTree *BSTPtr, string badWords[], int badSize) {
	string choice;
	cout << "\n" << endl;
	cout << "\tStatistics" << endl;
	cout << "Total number of poems in the system is " << totalPoems << endl;
	BSTPtr->statistic();
	menu(searchenginePtr, databasePtr, BSTPtr, badWords, badSize);

}

void menu(SearchEngine *searchenginePtr, Hash_Table *databasePtr,
		BinarySearchTree *BSTPtr, string badWords[], int badSize) {
	string choice;
	string confirm;
	while (choice != "7") {
		cout << "\tMenu" << endl;
		cout << "1. Search Haiku" << endl;
		cout << "2. Insert new Haiku" << endl;
		cout << "3. Delete Haiku" << endl;
		cout << "4. Display Haiku" << endl;
		cout << "5. Save File" << endl;
		cout << "6. Display Statistics" << endl;
		cout << "7. Quit" << endl;
		cout << "Enter your choice: ";
		getline(cin, choice);
		if (choice == "1") {
			haiku_search(searchenginePtr, databasePtr, BSTPtr, badWords,
					badSize);
		} else if (choice == "2") {
			insert_haiku(BSTPtr, databasePtr, searchenginePtr, badWords,
					badSize);
		} else if (choice == "3") {
			delete_haiku(databasePtr, BSTPtr, searchenginePtr, badWords,
					badSize);
		} else if (choice == "4") {
			display_haiku(BSTPtr, databasePtr, searchenginePtr, badWords,
					badSize);
		} else if (choice == "5") {
			cout << "Done";
		} else if (choice == "6") {
			display_statistics(searchenginePtr, databasePtr, BSTPtr, badWords,  badSize);
		}
	}
	cout << "Are you sure you want to quit (save files)? (Y/N): ";
	getline(cin, confirm);
	if (confirm == "Y" || confirm == "y") {
		cout << "Thank you for using our program!" << endl;
		return;
	} else if (confirm == "N" || confirm == "n") {
		menu(searchenginePtr, databasePtr, BSTPtr, badWords, badSize);
	} else {
		cout << "Invalid Entry." << endl;
		menu(searchenginePtr, databasePtr, BSTPtr, badWords, badSize);
	}
}
