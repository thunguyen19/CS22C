/**
 * ThuMinh Nguyen
 * CIS 22C
 * BinarySearchTreeTest.cpp
 */
#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main() {
	BinarySearchTree<char> BST;
	BST.insert('j');
			BST.insert('p');
			BST.insert('d');
			BST.insert('f');
			BST.insert('s');
			BST.insert('b');
			BST.insert('n');
			BST.insert('k');
			BST.insert('e');
			BST.insert('w');
			BST.insert('c');
			BST.insert('r');
			BST.insert('g');
			cout << "in order print: ";
			BST.inOrderPrint();
			cout << "post: ";
			BST.postOrderPrint();
			cout << "pre order print: ";
			BST.preOrderPrint();

	/*
	BinarySearchTree<int> BST1;
	BST1.insert(8);
	BST1.insert(5);
	BST1.insert(6);
	BST1.insert(7);
	BST1.insert(10);
	BST1.insert(1);
	BST1.insert(14);
	BST1.insert(9);
	BST1.insert(3);
	cout << "BST1 in-order print: ";
	BST1.inOrderPrint();
	cout << "BST1 Pre-order print: ";
	BST1.preOrderPrint();
	cout << "BST1 post-order print: ";
	BST1.postOrderPrint();
	cout << "Root should be 8: " << BST1.getRoot() << endl;
	cout << "Height should be 3: " << BST1.getHeight() << endl;
	cout << "Size should be 9: " << BST1.getSize() << endl;
	cout << "Minimum value should be 1: " << BST1.minimum() << endl;
	cout << "Maximum value should be 14: " << BST1.maximum() << endl;
	cout << "Found value 100. 1(true), 0(false): " << BST1.find(100) << endl;
	cout << "Found value 5. 1(true), 0(false): " << BST1.find(5) << endl;
	cout << "Found value 81. 1(true), 0(false): " << BST1.find(81) << endl;
	cout << "Found value 14. 1(true), 0(false): " << BST1.find(14) << endl;
	//BST1.remove(1000); //assert fails
	BST1.remove(8);
	cout << "After remove 8. Root should be 9: " << BST1.getRoot() << endl;
	cout << "BST1 in pre-order is: ";
	BST1.preOrderPrint();
	BinarySearchTree<int> BST2(BST1);
	cout << "BST2 is: ";
	BST2.inOrderPrint();
	cout << "Size of BST2 should be 8: " << BST2.getSize() << endl;
	cout << "Found value 14. 1(true), 0(false): " << BST2.find(14) << endl;
	BST2.remove(14);
	BST2.remove(6);
	cout << "BST2 is: ";
	BST2.inOrderPrint();
	//cout << "Found value 8. 1(true), 0(false): " << BST2.find(8) << endl; //assert fails
	cout << "Size of BST2 should be 6: " << BST2.getSize() << endl;
	cout << "Height of BST2 should be 3: " << BST2.getHeight() << endl;
	cout << "BST2 in-order print: ";
	BST2.inOrderPrint();
	cout << "BST2 Pre-order print: ";
	BST2.preOrderPrint();
	cout << "BST2 post-order print: ";
	BST2.postOrderPrint();
	*/
}
/*
BST1 in-order print: 1 3 5 6 7 8 9 10 14
BST1 Pre-order print: 8 5 1 3 6 7 10 9 14
BST1 post-order print: 3 1 7 6 5 9 14 10 8
Root should be 8: 8
Height should be 3: 3
Size should be 9: 9
Minimum value should be 1: 1
Maximum value should be 14: 14
Found value 100. 1(true), 0(false): 0
Found value 5. 1(true), 0(false): 1
Found value 81. 1(true), 0(false): 0
Found value 14. 1(true), 0(false): 1
After remove 8. Root should be 9: 9
BST1 in pre-order is: 9 5 1 3 6 7 10 14
BST2 is: 1 3 5 6 7 9 10 14
Size of BST2 should be 8: 8
Found value 14. 1(true), 0(false): 1
BST2 is: 1 3 5 7 9 10
Size of BST2 should be 6: 6
Height of BST2 should be 3: 3
BST2 in-order print: 1 3 5 7 9 10
BST2 Pre-order print: 9 5 1 3 7 10
BST2 post-order print: 3 1 7 5 10 9
 */
