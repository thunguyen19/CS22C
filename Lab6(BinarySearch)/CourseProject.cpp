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

using namespace std;

bool isInputFileOpen(fstream &, const string &);
void seedDataFromFiles(string[], int, SearchEngine *, Hash_Table *,
		BinarySearchTree *, string[], int);
bool isBadKeyword(string[], int, string);
vector<string> generateKeywords(string[], int, string);
void insertKeywordsInSearchEngine(SearchEngine *, vector<string>, Haiku);
int binarySearch(string[], int, int, string);
//Menu Function Prototypes:
Haiku addNewPoem();
string promptForPrimaryKey();
void deletePoem(Hash_Table *, SearchEngine*, Haiku);
void searchByPrimaryKey(Hash_Table *, string);
void listAllDataBasePoemUnsorted(Hash_Table *);

void menu();
void display_haiku();
void haiku_search();
void insert_haiku();
void delete_haiku();
void display_statistics();

Hash_Table *databasePtr = new Hash_Table;
SearchEngine *searchenginePtr = new SearchEngine;
BinarySearchTree *BSTPtr = new BinarySearchTree;

int main() {
	//List of words not to be accepted as keywords
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

	//Create pointers to a Hash_Table & SearchEngine objects
	//Hash_Table *databasePtr = new Hash_Table;
	//SearchEngine *searchenginePtr = new SearchEngine;

	//Seed the project with 15 poem files' data
	seedDataFromFiles(files, filesSize, searchenginePtr, databasePtr, BSTPtr, badKeywords, badKeywordsSize);

	ofstream hashTable;
	hashTable.open("outfile.txt");
	if (hashTable.fail()) {
		cout << "Output file failed to open.\n";
		exit(-1);
	}
	ofstream output;
	output.open("WordIDHash_Table.txt");
	if (output.fail()) {
		cout << "Output file failed to open.\n";
		exit(-1);
	}
	//**** MENU
	menu();
//save to file
}	//end main

//**********************************************************************
void seedDataFromFiles(string files[], int SIZE, SearchEngine *sePTr,
		Hash_Table *dbPtr, BinarySearchTree *bstPtr, string badKeywords[], int badKeywordsSize)
{
	//local instance variables
	fstream inputFile;
	string line;
	string text;
	Haiku poem;
	vector<string> keywords;

	for (int x = 0; x < SIZE; x++)
	{
		text = "";
		if (isInputFileOpen(inputFile, files[x]))
		{
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
			if (inputFile)
				poem.set_year(line);

			//read the poem
			getline(inputFile, line, '\n');
			while (inputFile)
			{
				text += line;
				getline(inputFile, line, '\n');
			}
		}
		//now poem has all Haiku attributes
		poem.set_haiku(text);
		//generate keywords from the poem's text
		keywords = generateKeywords(badKeywords, badKeywordsSize, poem.get_haiku());

		//insert generated keywords into search engine, as well as the poem they are associated with
		insertKeywordsInSearchEngine(sePTr, keywords, poem);
		//clear keywords vector for next poem's keywords
		keywords.clear();
		//insert the poem in a database
		dbPtr->insert(poem, cout);
		BSTPtr->insert(poem);
		//close the current file
		inputFile.close();
	}
}


//The function prompts the user for a new poem info
//and returns the newly created Haiku object
Haiku addNewPoem()
{
	//Create an instance of a poem
	Haiku poem;

	//Local string
	string line;

	//prompt the user for input
	cout << "\nPlease enter the poem's title:\n";
	getline(cin, line);
	poem.set_title(line);

	cout << "\nPlease enter the poem's author:\n";
	getline(cin, line);
	poem.set_author(line);

	string text;

	cout << "\nPlease enter first line of haiku poem:\n";
	getline(cin, line);
	text += line;
	text += '\n';
	cout << "\nPlease enter second line of haiku poem:";
	getline(cin, line);
	text += line;
	text += '\n';
	cout << "\nPlease enter third line of haiku poem:";
	getline(cin, line);
	text += line;
	text += '\n';
	poem.set_haiku(text);

	return poem;
}


//The function prompts for primary key; function will be used in
//the menu to delete/search/list data
string promptForPrimaryKey()
{
	string title, author;
	cout << "\nPlease enter the haiku title:\n";
	getline(cin, title);
	cout << "\nPlease enter the haiku author:\n";
	getline(cin, author);
	string primaryKey = title + author;
	return primaryKey;
}


//The function lists unsorted data in HT database at every bucket
void listAllDataBasePoemUnsorted(Hash_Table *dbPtr)
{
	int dataBaseSize = 30;

	cout << "\n\nUnsorted Database List:\n\n";
	cout << "****************************\n\n";

	for (int idx = 0; idx < dataBaseSize; idx++)
		dbPtr->print_bucket(idx, cout);

	cout << "\n\n****************************\n\n";
}


//Menu function delete haiku by primary key
void deletePoemByPrimaryKey(Hash_Table *dbPtr, string primaryKey)
{
	dbPtr->remove(primaryKey, cout);
}


//Menu function search haiku by primary key
void searchByPrimaryKey(Hash_Table *dbPtr, string primaryKey)
{
	dbPtr->search(primaryKey, cout);
}


//The function checks if the word in poem matches the word on bad list of keywords
bool isBadKeyword(string badKeysArr[], int SIZE, string word)
{
	return (binarySearch(badKeysArr, 0, SIZE, word) != -1);
}


//The function accepts a poem's text and returns keywords
vector<string> generateKeywords(string badKeysArr[], int SIZE, string haiku_text)
{
	vector<string> keywords;
	string word;

	//in case there's space in the beginning of the line
	unsigned int x = 0;
	while (x < haiku_text.length() && isspace(haiku_text[x]))
		x++;

	while(x < haiku_text.length())
	{
		if (isalpha(haiku_text[x]))
				word += tolower(haiku_text[x]);
		else
		{
			if (word.length() > 2 && !isBadKeyword(badKeysArr, SIZE, word))
				keywords.push_back(word);

			word = "";
		}
		x++;
	}

	return keywords;
}


//The function inserts keywords and the Haiku object they are associated with into the search engine
void insertKeywordsInSearchEngine(SearchEngine *SEPtr, vector<string> keywords, Haiku poem)
{
	for (unsigned idx = 0; idx < keywords.size(); idx++)
	{
		SEPtr->insert(keywords.at(idx), poem);
	}
}


//The function searches if the values matches one of the bad keywords
//in the badKeywords array
int binarySearch(string arr[], int low, int high, string value)
{
	if (high < low)
		return -1;
	int mid = low + (high - low)/2;

	if (arr[mid] == value)
		return mid;
	else if (arr[mid] > value)
		return binarySearch(arr, low, mid - 1, value);
	else
		return binarySearch(arr, mid + 1, high, value);
}

//The function checks if the inputFile has opened successfully
bool isInputFileOpen(fstream &inputFile, const string &fileName)
{
    //Open the file stream object in input mode
    //.c_str() used b/c open() works with c-strings
    inputFile.open(fileName.c_str(), ios::in);

    //Check if failbit or hardbit flags are set
    if (inputFile.fail())
        return false;
    else
        return true;
}

void display_haiku() {
	string choice;
	string confirm;
	cout << "\n\tDisplay Haiku" << endl;
	cout << "1. Unsorted Data" << endl;
	cout << "2. Sorted Data (A-Z)" << endl;
	cout << "3. Return to Menu" << endl;
	cout << "4. Quit" << endl;
	cout << "Enter your choice: ";
	getline(cin, choice);
	if (choice == "1") {
		listAllDataBasePoemUnsorted(databasePtr);
	} else if (choice == "2") {
		BSTPtr->inOrderPrint(cout);
		cout << "End printing sorted data.\n";
	} else if (choice == "3") {
		menu();
	} else if (choice == "4") {
		cout << "Are you sure you want to quit (save files)? (Y/N): ";
		getline(cin, confirm);
		if (confirm == "Y" || confirm == "y") {
			cout << "Thank you for using our program!" << endl;
			exit(-1);
		} else if (confirm == "N" || confirm == "n") {
			menu();
		} else {
			cout << "Invalid Entry." << endl;
			menu();
		}
	} else {
		cout << "Invalid Entry." << endl;
		display_haiku();
	}
}

void haiku_search() {
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
	if (choice == "1") {
		string primaryKey = promptForPrimaryKey();
		databasePtr->search(primaryKey, cout);
	} else if (choice == "2") {
		cout << "Enter a keyword: ";
		getline(cin, keywords);
		searchenginePtr->searchByKeyword(keywords, cout);
	} else if (choice == "3") {
		menu();
	} else if (choice == "4") {
		cout << "Are you sure you want to quit (save files)? (Y/N): ";
		getline(cin, confirm);
		if (confirm == "Y" || confirm == "y") {
			cout << "Thank you for using our program!" << endl;
			exit(-1);
		} else if (confirm == "N" || confirm == "n") {
			menu();
		} else {
			cout << "Invalid Entry." << endl;
			haiku_search();
		}
	} else {
		cout << "Invalid Entry." << endl;
		haiku_search();
	}
}

void insert_haiku() {
	string choice;
	string confirm;
	cout << "\n\tInsert" << endl;
	cout << "1. Insert Haiku" << endl;
	cout << "2. Return to Main menu" << endl;
	cout << "3. Quit" << endl;
	cout << "Enter your choice: ";
	getline(cin, choice);
	if (choice == "1") {
		Haiku poem = addNewPoem();
		databasePtr->insert(poem, cout);
		BSTPtr->insert(poem);
	} else if (choice == "2") {
		menu();
	} else if (choice == "3") {
		cout << "Are you sure you want to quit (save files)? (Y/N): ";
		getline(cin, confirm);
		if (confirm == "Y" || confirm == "y") {
			cout << "Thank you for using our program!" << endl;
			exit(-1);
		} else if (confirm == "N" || confirm == "n") {
			menu();
		} else {
			cout << "Invalid Entry." << endl;
			menu();
		}
	} else {
		cout << "Invalid Entry." << endl;
		menu();
	}
}

void delete_haiku() {
	string confirm;
	string choice;
	cout << "\n\tDelete" << endl;
	string primaryKey = promptForPrimaryKey();
	cout << "Are you sure? (Y/N): ";
	getline(cin, confirm);
	if (confirm == "Y" || confirm == "y") {
		deletePoemByPrimaryKey(databasePtr, primaryKey);
		menu();
	} else if (confirm == "N" || confirm == "n") {
		cout << "1. Delete Haiku" << endl;
		cout << "2. Return to Main menu" << endl;
		cout << "3. Quit" << endl;
		cout << "Enter your choice: ";
		getline(cin, choice);
		if (choice == "1") {
			delete_haiku();
		} else if (choice == "2") {
			menu();
		} else if (choice == "3") {
			cout << "Are you sure you want to quit (save files)? (Y/N): ";
			getline(cin, confirm);
			if (confirm == "Y" || confirm == "y") {
				cout << "Thank you for using our program!" << endl;
				exit(-1);
			} else if (confirm == "N" || confirm == "n") {
				menu();
			} else {
				cout << "Invalid Entry." << endl;
				menu();
			}
		} else {
			cout << "Invalid Entry." << endl;
			menu();
		}
	} else {
		cout << "Invalid Entry." << endl;
		menu();
	}
}

void display_statistics() {
	string choice;
	cout << "\n" << endl;
	cout << "\tStatistics" << endl;
	BSTPtr->statistic();
	menu();

}

void menu() {
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
			haiku_search();
		} else if (choice == "2") {
			insert_haiku();
		} else if (choice == "3") {
			delete_haiku();
		} else if (choice == "4") {
			display_haiku();
		} else if (choice == "5") {
			cout << "Done";
		} else if (choice == "6") {
			display_statistics();
		}
	}
	cout << "Are you sure you want to quit (save files)? (Y/N): ";
	getline(cin, confirm);
	if (confirm == "Y" || confirm == "y") {
		cout << "Thank you for using our program!" << endl;
		return;
	} else if (confirm == "N" || confirm == "n") {
		menu();
	} else {
		cout << "Invalid Entry." << endl;
		menu();
	}
}
