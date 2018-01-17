/**
 * ThuMinh Nguyen
 * CIS 22C
 * BinarySearchTree.cpp
 */
#include "BinarySearchTree.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

int main() {

	ifstream input;
	ofstream output;
	input.open("infile.txt");
	if (input.fail()) {
		cout << "Input file failed to open.\n";
		exit(-1);
	}
	output.open("outfile.txt");
	if (output.fail()) {
		cout << "Output file failed to open.\n";
		exit(-1);
	}
	BinarySearchTree<int> BST;

	string line;
	int count = 0;
	do {
		while (getline(input, line)) {
			stringstream convert(line);
			if (count % 3 == 0) {
				int value = 0;
				while (convert >> value) {
					BST.insert(value);
				}
				BST.preOrderPrint(output);
				BST.inOrderPrint(output);
			}
			if (count % 3 == 1) {
				int findNum = 0;
				while (convert >> findNum) {
					BST.find(findNum);
					if (BST.find(findNum) == true) {
						BST.remove(findNum);
						output << findNum
								<< " was found in the Binary Search Tree.\n";
					} else
						output << findNum << " was not found in the Binary Search Tree.\n";
				}
			}
			if (count % 3 == 2) {
				int addNum = 0;
				while (convert >> addNum) {
					BST.insert(addNum);
				}
				BST.postOrderPrint(output);
				output << "The root of the tree is " << BST.getRoot() << endl;
				output << "The maximum value is " << BST.maximum() << endl;
				output << "The minimum value is " << BST.minimum() << endl;
				output << "The size of the Binary Search Tree is " << BST.getSize() << endl;
				output << "The height of the Binary Search Tree is " << BST.getHeight()
						<< endl << endl;
				BST.~BinarySearchTree();//end of group of three. free memory to store new BST
			}
			count++;
		}
	} while (count < 9);

input.close();
output.close();
return 0;
}
/*Outfile.txt
12 6 3 2 4 9 7 10 45 13
2 3 4 6 7 9 10 12 13 45
4 was found in the Binary Search Tree.
2 3 7 10 9 6 13 45 12
The root of the tree is 12
The maximum value is 45
The minimum value is 2
The size of the Binary Search Tree is 9
The height of the Binary Search Tree is 3

55 18 3 6 9 78
3 6 9 18 55 78
13 was not found in the Binary Search Tree.
9 6 3 18 66 78 55
The root of the tree is 55
The maximum value is 78
The minimum value is 3
The size of the Binary Search Tree is 7
The height of the Binary Search Tree is 4

808 707 505 499 644 909 1001 1200 1190 1592
499 505 644 707 808 909 1001 1190 1200 1592
707 was found in the Binary Search Tree.
78 499 644 505 1190 1592 1200 1001 909 808
The root of the tree is 808
The maximum value is 1592
The minimum value is 78
The size of the Binary Search Tree is 10
The height of the Binary Search Tree is 4
 */
