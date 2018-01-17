#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include <cstddef>
#include <string>
#include <iostream>
#include "Haiku.h"

using namespace std;

class BinarySearchTree {
private:
	struct Node {
		Haiku data;
		Node* left;
		Node* right;

		Node(Haiku newdata) :
				data(newdata), left(NULL), right(NULL) {
		}
	};

	typedef struct Node* NodePtr;
	NodePtr root;

	/**Private helper functions*/

	void insertHelper(NodePtr root, Haiku h);
	//private helper function for insert
	//recursively inserts a value into the BST

	void inOrderPrintHelper(NodePtr root, ostream &strm, int count);
	//private helper function for inOrderPrint
	//recursively prints tree values in order from smallest to largest

	bool findHelper(NodePtr root, Haiku h);
	//private helper function for find()
	//recursively searches the BST

	Haiku minimumHelper(NodePtr root);
	//private helper function for minimum()
	//recursively finds the minimum value in BST

	NodePtr removeHelper(NodePtr root, Haiku h);
	//private helper function for remove()
	//recursively removes a node in a BST

	int getSizeHelper(NodePtr root);
	//private helper function to getSize()
	//recursively counts number of nodes in the BST

	NodePtr copyConstructorHelper(NodePtr root);
	//private helper function for copy constructor
	//recursively copies the bst during preorder traversal
	//and returns a pointer to the copy

	void DestructorHelper(NodePtr root);
	//private helper function for destructor
	//recursively destroys the bst during postorder traversal

	void insertHelper_year(NodePtr root, Haiku h);

	void insertHelper_author(NodePtr root, Haiku h);

	void insertHelper_country(NodePtr root, Haiku h);

	Haiku maximumHelper(NodePtr root);

public:

	/**Constructors & Destructor*/

	BinarySearchTree();
	//Instantiates a new Binary Search Tree
	//post: a new Binary Search Tree object

	~BinarySearchTree();
	//Destructor. Frees memory allocated to the BST
	//Postcondition: the memory allocated for the BST is freed.

	/**Public access functions*/

	int getSize();
	//returns the size of the tree

	Haiku getRoot();
	//returns the value stored at the root of the Binary Search Tree
	//pre: the Binary Search Tree is not empty

	bool find(Haiku value);
	//returns whether the value is in the tree
	//Pre: !isEmpty()

	bool isEmpty();
	//determines whether the Binary Search Tree is empty

	Haiku minimum();
	//finds the minimum value in the Binary Search Tree and returns it
	//pre: !isEmpty()

	/**Public manipulation functions*/

	void insert(Haiku h);
	//inserts a new value into the Binary Search Tree
	//post: a new value inserted into the Binary Search Tree

	void remove(Haiku h);
	//removes the specified value from the tree
	//Pre: !isEmpty()

	/**Additional functions*/

	void inOrderPrint(ostream &strm);
	//calls the inOrderPrintHelper function to print out the values
	//stored in the Binary Search Tree
	//If the tree is empty, prints nothing

	void insert_year(Haiku h);

	void statistic();

	void insert_author(Haiku h);

	void insert_country(Haiku h);

	Haiku maximum();
};

#endif /* BINARYSEARCHTREE_H_ */
